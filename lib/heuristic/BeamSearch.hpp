
#include <algorithm>
#include <cstddef>
#include <memory>
#include <numeric>
#include <set>
#include <vector>

#include "../utility/type_alias.hpp"

// ref: https://eijirou-kyopro.hatenablog.com/entry/2024/02/01/115639

template <class T>
concept BeamSearchStateConcept = requires(T &x, T::op_type op,
                                          T::cand_type cand) {
  typename T::op_type;
  typename T::cand_type;
  typename T::cand_type::score_type;
  typename T::cand_type::hash_type;
  x.apply(op);
  x.rollback(op);
  { x.enumerate_cands() } -> std::same_as<std::vector<typename T::cand_type>>;
  requires std::same_as<decltype(T::cand_type::op), typename T::op_type>;
  requires std::same_as<decltype(T::cand_type::score), typename T::score_type>;
  requires std::same_as<decltype(T::cand_type::hash), typename T::hash_type>;
};

template <BeamSearchStateConcept State, size_t BEAM_WIDTH> class BeamSearch {
private:
  using leaf_idx_type = i32;
  static_assert(BEAM_WIDTH <= std::numeric_limits<leaf_idx_type>::max());

  using state_type = State;
  using op_type = state_type::op_type;
  using cand_type = state_type::cand_type;
  using score_type = cand_type::score_type;
  using hash_type = cand_type::hash_type;

  class NewLeaf {
    friend BeamSearch;

  private:
    leaf_idx_type par_idx;

  public:
    cand_type cand;
    NewLeaf(cand_type cand_, leaf_idx_type par_idx_)
        : par_idx(par_idx_), cand(cand_) {}
    NewLeaf() : par_idx(-1) {}
  };

  struct Edge {
    op_type op;
    leaf_idx_type leaf_idx; // -1: apply , -2: rollback ,  positive: leaf
    static constexpr leaf_idx_type APPLY = -1;
    static constexpr leaf_idx_type ROLLBACK = -2;
    Edge(op_type op_, leaf_idx_type leaf_idx_) : op(op_), leaf_idx(leaf_idx_) {}
  };

  const state_type init_state;
  std::vector<Edge> now_tree, next_tree;
  std::vector<NewLeaf> accept_leaf[BEAM_WIDTH];

public:
  using leaf_type = NewLeaf;
  BeamSearch(state_type init_state_) : init_state(init_state_) {}

  void step() {
    state_type state = init_state;
    if (now_tree.empty()) {
      std::vector<cand_type> cands = state.enumerate_cands();
      std::ranges::sort(cands, std::ranges::greater(), &cand_type::score);
      cands.resize(std::min(cands.size(), BEAM_WIDTH));
      for (size_t i = 0; i < cands.size(); i++) {
        now_tree.emplace_back(cands[i].op, i);
      }
      return;
    }

    std::vector<NewLeaf> new_leaves;
    score_type threshold = std::numeric_limits<score_type>::min();

    for (const auto &edge : now_tree) {
      if (edge.leaf_idx == Edge::APPLY) {
        state.apply(edge.op);
      } else if (edge.leaf_idx == Edge::ROLLBACK) {
        state.rollback(edge.op);
      } else {
        state.apply(edge.op);

        std::vector<cand_type> cands = state.enumerate_cands();
        for (const auto &cand : cands) {
          if (cand.score >= threshold) {
            new_leaves.emplace_back(cand, edge.leaf_idx);
          }
        }
        if (new_leaves.size() > BEAM_WIDTH * 2) {
          std::ranges::sort(new_leaves, std::ranges::greater(),
                            [](auto &&v) { return v.cand.score; });
          new_leaves.resize(BEAM_WIDTH);
          threshold = new_leaves.back().cand.score;
        }
        state.rollback(edge.op);
      }
    }

    std::ranges::sort(new_leaves, std::ranges::greater(),
                      [](auto &&v) { return v.cand.score; });
    std::set<hash_type> hash_set;
    size_t count = 0;
    for (const auto &leaf : new_leaves) {
      if (count == BEAM_WIDTH)
        break;
      if (hash_set.contains(leaf.cand.hash))
        continue;

      accept_leaf[leaf.par_idx].push_back(leaf);
      hash_set.insert(leaf.cand.hash);
      count++;
    }

    leaf_idx_type leaf_idx_cnt = 0;
    for (const auto &edge : now_tree) {
      if (edge.leaf_idx == Edge::APPLY) {
        next_tree.emplace_back(edge.op, Edge::APPLY);
      } else if (edge.leaf_idx == Edge::ROLLBACK) {
        if (next_tree.back().leaf_idx == Edge::APPLY) {
          next_tree.pop_back();
        } else {
          next_tree.emplace_back(edge.op, Edge::ROLLBACK);
        }
      } else {
        if (!accept_leaf[edge.leaf_idx].empty()) {
          next_tree.emplace_back(edge.op, Edge::APPLY);
          for (const auto &leaf : accept_leaf[edge.leaf_idx]) {
            next_tree.emplace_back(leaf.cand.op, leaf_idx_cnt);
            leaf_idx_cnt++;
          }
          next_tree.emplace_back(edge.op, Edge::ROLLBACK);
          accept_leaf[edge.leaf_idx].clear();
        }
      }
    }

    std::swap(now_tree, next_tree);
    next_tree.clear();
  }

  std::vector<leaf_type> step_and_get_leaf() {
    std::vector<leaf_type> ret;

    state_type state = init_state;
    if (now_tree.empty()) {
      std::vector<cand_type> cands = state.enumerate_cands();
      std::ranges::sort(cands, std::ranges::greater(), &cand_type::score);
      cands.resize(std::min(cands.size(), BEAM_WIDTH));
      for (size_t i = 0; i < cands.size(); i++) {
        now_tree.emplace_back(cands[i].op, i);
        ret.emplace_back(cands[i], i);
      }
      return ret;
    }

    std::vector<NewLeaf> new_leaves;
    score_type threshold = std::numeric_limits<score_type>::min();

    for (const auto &edge : now_tree) {
      if (edge.leaf_idx == Edge::APPLY) {
        state.apply(edge.op);
      } else if (edge.leaf_idx == Edge::ROLLBACK) {
        state.rollback(edge.op);
      } else {
        state.apply(edge.op);

        std::vector<cand_type> cands = state.enumerate_cands();
        for (const auto &cand : cands) {
          if (cand.score >= threshold) {
            new_leaves.emplace_back(cand, edge.leaf_idx);
          }
        }
        if (new_leaves.size() > BEAM_WIDTH * 2) {
          std::ranges::sort(new_leaves, std::ranges::greater(),
                            [](auto &&v) { return v.cand.score; });
          new_leaves.resize(BEAM_WIDTH);
          threshold = new_leaves.back().cand.score;
        }
        state.rollback(edge.op);
      }
    }

    std::ranges::sort(new_leaves, std::ranges::greater(),
                      [](auto &&v) { return v.cand.score; });
    std::set<hash_type> hash_set;
    size_t count = 0;
    for (const auto &leaf : new_leaves) {
      if (count == BEAM_WIDTH)
        break;
      if (hash_set.contains(leaf.cand.hash))
        continue;

      accept_leaf[leaf.par_idx].push_back(leaf);
      hash_set.insert(leaf.cand.hash);
      count++;
    }

    leaf_idx_type leaf_idx_cnt = 0;
    for (const auto &edge : now_tree) {
      if (edge.leaf_idx == Edge::APPLY) {
        next_tree.emplace_back(edge.op, Edge::APPLY);
      } else if (edge.leaf_idx == Edge::ROLLBACK) {
        if (next_tree.back().leaf_idx == Edge::APPLY) {
          next_tree.pop_back();
        } else {
          next_tree.emplace_back(edge.op, Edge::ROLLBACK);
        }
      } else {
        if (!accept_leaf[edge.leaf_idx].empty()) {
          next_tree.emplace_back(edge.op, Edge::APPLY);
          for (const auto &leaf : accept_leaf[edge.leaf_idx]) {
            next_tree.emplace_back(leaf.cand.op, leaf_idx_cnt);
            ret.emplace_back(leaf.cand, leaf_idx_cnt);
            leaf_idx_cnt++;
          }
          next_tree.emplace_back(edge.op, Edge::ROLLBACK);
          accept_leaf[edge.leaf_idx].clear();
        }
      }
    }

    std::swap(now_tree, next_tree);
    next_tree.clear();

    return ret;
  }

  std::vector<op_type> get_path(const leaf_type &leaf) {
    std::vector<op_type> path;
    for (const auto &edge : now_tree) {
      if (edge.leaf_idx == leaf.par_idx) {
        path.push_back(edge.op);
        break;
      }

      if (edge.leaf_idx == Edge::APPLY) {
        path.emplace_back(edge.op);
      } else if (edge.leaf_idx == Edge::ROLLBACK) {
        path.pop_back();
      }
    }

    return path;
  }
};
