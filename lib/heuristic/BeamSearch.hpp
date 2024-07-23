
#include <algorithm>
#include <cstddef>
#include <memory>
#include <set>
#include <vector>

/*
struct Ops {};
struct State {
  using op_type = Ops;
  using cost_type = u64;
  using hash_type = u64;
  std::vector<op_type> enumerate_ops() {}
  void apply(Ops op) {}
  void rollback(Ops op) {}
  cost_type calc_cost() const {  }
  hash_type calc_hash() const { }
  bool is_finished() const {  }
};

struct BMTask {
  using state_type = State;

  static state_type init_state;
};
*/

template <class T>
concept TaskState = requires(T &x, T::op_type op) {
  typename T::op_type;
  typename T::cost_type;

  { x.enumerate_ops() } -> std::same_as<std::vector<typename T::op_type>>;
  x.apply(op);
  { x.calc_cost() } -> std::same_as<typename T::cost_type>;
  { x.is_finished() } -> std::same_as<bool>;
};

template <class T>
concept HashableState = requires(T &x) {
  typename T::hash_type;
  { x.calc_hash() } -> std::same_as<typename T::hash_type>;
};

template <class T>
concept RollbackableState = requires(T &x, T::op_type op) { x.rollback(op); };

template <class T>
concept BeamSearchableTask = requires(T &x) {
  typename T::state_type;
  requires TaskState<typename T::state_type> &&
               HashableState<typename T::state_type> &&
               RollbackableState<typename T::state_type>;
  requires std::same_as<decltype(T::init_state), typename T::state_type>;
};

template <BeamSearchableTask BeamSearchTask, size_t BEAMSEARCH_WIDTH>
class BeamSearch {
private:
  using state_type = typename BeamSearchTask::state_type;
  using op_type = typename state_type::op_type;
  using cost_type = typename state_type::cost_type;
  using hash_type = typename state_type::hash_type;

  struct Node;
  using node_ptr = Node *;
  struct Node {
    op_type op;
    node_ptr par;
    node_ptr child;
    node_ptr right;
    node_ptr left;

    Node() : par(nullptr), child(nullptr), right(nullptr), left(nullptr) {}
    Node(op_type op_, node_ptr par_, node_ptr child_, node_ptr right_,
         node_ptr left_)
        : op(op_), par(par_), child(child_), right(right_), left(left_) {}

    node_ptr push_child(op_type op_) {
      node_ptr newnode = new Node(op_, this, nullptr, child, nullptr);
      if (child)
        child->left = newnode;
      child = newnode;

      return newnode;
    }

    bool is_root() const { return !par; }
    bool is_single_child() const { return !right && !left; }
    bool is_leftest_child() const { return !left; }
    bool has_child() { return child; }

    ~Node() {
      if (is_root()) {
        return;
      }

      if (is_single_child()) {
        delete par;
        return;
      }

      if (is_leftest_child()) {
        // replace par->child
        par->child = right;
        right->left = nullptr;
        return;
      }

      // middle child
      left->right = right;
      if (right)
        right->left = left;
    }
  };

  struct Cand {
    node_ptr leaf;
    op_type op;
    cost_type cost;
    hash_type hash;
    Cand(node_ptr leaf_, op_type op_, cost_type cost_, hash_type hash_)
        : leaf(leaf_), op(op_), cost(cost_), hash(hash_) {}

    bool operator<(const Cand &rhs) const { return cost < rhs.cost; }
  };

  std::vector<op_type> get_op_seq(node_ptr now) {
    std::vector<op_type> ops;
    while (!now->is_root()) {
      ops.emplace_back(now->op);
      now = now->par;
    }
    std::reverse(ops.begin(), ops.end());
    return ops;
  }

public:
  BeamSearch() {}

  std::vector<op_type> run() {
    node_ptr root = new Node();
    std::vector<node_ptr> leafs;

    while (true) {
      state_type state = BeamSearchTask::init_state;
      std::vector<Cand> cands;
      std::vector<Cand> finished_cands;

      node_ptr now = root;
      size_t has_right_cnt = 0;
      while (true) {
        // go down to leaf
        while (now->child) {
          now = now->child;
          if (now->right)
            has_right_cnt++;
          state.apply(now->op);
        }

        // gen cands
        for (op_type op : state.enumerate_ops()) {
          state.apply(op);

          cost_type cost = state.calc_cost();
          hash_type hash = state.calc_hash();

          if (state.is_finished()) {
            finished_cands.emplace_back(now, op, cost, hash);
          } else {
            cands.emplace_back(now, op, cost, hash);
          }

          state.rollback(op);
        }

        // go upward
        while (has_right_cnt != 0 && !now->right) {
          state.rollback(now->op);
          now = now->par;
        }

        if (has_right_cnt == 0)
          break;

        // move right
        state.rollback(now->op);
        now = now->right;
        if (!now->right)
          has_right_cnt--;
        state.apply(now->op);
      }

      if (!finished_cands.empty()) {
        std::sort(finished_cands.begin(), finished_cands.end());

        const auto &[leaf, op, cost, hash] = finished_cands[0];
        auto ops = get_op_seq(leaf);
        ops.emplace_back(op);

        for (node_ptr e : leafs) {
          delete e;
        }
        return ops;
      }

      std::sort(cands.begin(), cands.end());

      std::vector<node_ptr> next_leafs;
      std::set<hash_type> hash_set;
      size_t count = 0;
      for (const auto &[leaf, op, cost, hash] : cands) {
        if (count == BEAMSEARCH_WIDTH)
          break;
        if (hash_set.contains(hash))
          continue;

        node_ptr newleaf = leaf->push_child(op);
        next_leafs.emplace_back(newleaf);
        count++;
      }

      for (node_ptr e : leafs) {
        if (!e->has_child())
          delete e;
      }

      leafs = next_leafs;
    }
  }
};
