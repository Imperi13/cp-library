---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/heuristic/BeamSearch.hpp\"\n\n#include <algorithm>\n\
    #include <cstddef>\n#include <memory>\n#include <set>\n#include <vector>\n\n/*\n\
    struct Ops {};\nstruct State {\n  using op_type = Ops;\n  using cost_type = u64;\n\
    \  using hash_type = u64;\n  std::vector<op_type> enumerate_ops() {}\n  void apply(Ops\
    \ op) {}\n  void rollback(Ops op) {}\n  cost_type calc_cost() const {  }\n  hash_type\
    \ calc_hash() const { }\n  bool is_finished() const {  }\n};\n\nstruct BMTask\
    \ {\n  using state_type = State;\n\n  static state_type init_state;\n};\n*/\n\n\
    template <typename BeamSearchTask, size_t BEAMSEARCH_WIDTH> class BeamSearch {\n\
    private:\n  using state_type = typename BeamSearchTask::state_type;\n  using op_type\
    \ = typename state_type::op_type;\n  using cost_type = typename state_type::cost_type;\n\
    \  using hash_type = typename state_type::hash_type;\n\n  struct Node;\n  using\
    \ node_ptr = Node *;\n  struct Node {\n    op_type op;\n    node_ptr par;\n  \
    \  node_ptr child;\n    node_ptr right;\n    node_ptr left;\n\n    Node() : par(nullptr),\
    \ child(nullptr), right(nullptr), left(nullptr) {}\n    Node(op_type op_, node_ptr\
    \ par_, node_ptr child_, node_ptr right_,\n         node_ptr left_)\n        :\
    \ op(op_), par(par_), child(child_), right(right_), left(left_) {}\n\n    node_ptr\
    \ push_child(op_type op_) {\n      node_ptr newnode = new Node(op_, this, nullptr,\
    \ child, nullptr);\n      if (child)\n        child->left = newnode;\n      child\
    \ = newnode;\n\n      return newnode;\n    }\n\n    bool is_root() const { return\
    \ !par; }\n    bool is_single_child() const { return !right && !left; }\n    bool\
    \ is_leftest_child() const { return !left; }\n    bool has_child() { return child;\
    \ }\n\n    ~Node() {\n      if (is_root()) {\n        return;\n      }\n\n   \
    \   if (is_single_child()) {\n        delete par;\n        return;\n      }\n\n\
    \      if (is_leftest_child()) {\n        // replace par->child\n        par->child\
    \ = right;\n        right->left = nullptr;\n        return;\n      }\n\n     \
    \ // middle child\n      left->right = right;\n      if (right)\n        right->left\
    \ = left;\n    }\n  };\n\n  struct Cand {\n    node_ptr leaf;\n    op_type op;\n\
    \    cost_type cost;\n    hash_type hash;\n    Cand(node_ptr leaf_, op_type op_,\
    \ cost_type cost_, hash_type hash_)\n        : leaf(leaf_), op(op_), cost(cost_),\
    \ hash(hash_) {}\n\n    bool operator<(const Cand &rhs) const { return cost <\
    \ rhs.cost; }\n  };\n\n  std::vector<op_type> get_op_seq(node_ptr now) {\n   \
    \ std::vector<op_type> ops;\n    while (!now->is_root()) {\n      ops.emplace_back(now->op);\n\
    \      now = now->par;\n    }\n    std::reverse(ops.begin(), ops.end());\n   \
    \ return ops;\n  }\n\npublic:\n  BeamSearch() {}\n\n  std::vector<op_type> run()\
    \ {\n    node_ptr root = new Node();\n    std::vector<node_ptr> leafs;\n\n   \
    \ while (true) {\n      state_type state = BeamSearchTask::init_state;\n     \
    \ std::vector<Cand> cands;\n      std::vector<Cand> finished_cands;\n\n      node_ptr\
    \ now = root;\n      size_t has_right_cnt = 0;\n      while (true) {\n       \
    \ // go down to leaf\n        while (now->child) {\n          now = now->child;\n\
    \          if (now->right)\n            has_right_cnt++;\n          state.apply(now->op);\n\
    \        }\n\n        // gen cands\n        for (op_type op : state.enumerate_ops())\
    \ {\n          state.apply(op);\n\n          cost_type cost = state.calc_cost();\n\
    \          hash_type hash = state.calc_hash();\n\n          if (state.is_finished())\
    \ {\n            finished_cands.emplace_back(now, op, cost, hash);\n         \
    \ } else {\n            cands.emplace_back(now, op, cost, hash);\n          }\n\
    \n          state.rollback(op);\n        }\n\n        // go upward\n        while\
    \ (has_right_cnt != 0 && !now->right) {\n          state.rollback(now->op);\n\
    \          now = now->par;\n        }\n\n        if (has_right_cnt == 0)\n   \
    \       break;\n\n        // move right\n        state.rollback(now->op);\n  \
    \      now = now->right;\n        if (!now->right)\n          has_right_cnt--;\n\
    \        state.apply(now->op);\n      }\n\n      if (!finished_cands.empty())\
    \ {\n        std::sort(finished_cands.begin(), finished_cands.end());\n\n    \
    \    const auto &[leaf, op, cost, hash] = finished_cands[0];\n        auto ops\
    \ = get_op_seq(leaf);\n        ops.emplace_back(op);\n\n        for (node_ptr\
    \ e : leafs) {\n          delete e;\n        }\n        return ops;\n      }\n\
    \n      std::sort(cands.begin(), cands.end());\n\n      std::vector<node_ptr>\
    \ next_leafs;\n      std::set<hash_type> hash_set;\n      size_t count = 0;\n\
    \      for (const auto &[leaf, op, cost, hash] : cands) {\n        if (count ==\
    \ BEAMSEARCH_WIDTH)\n          break;\n        if (hash_set.contains(hash))\n\
    \          continue;\n\n        node_ptr newleaf = leaf->push_child(op);\n   \
    \     next_leafs.emplace_back(newleaf);\n        count++;\n      }\n\n      for\
    \ (node_ptr e : leafs) {\n        if (!e->has_child())\n          delete e;\n\
    \      }\n\n      leafs = next_leafs;\n    }\n  }\n};\n"
  code: "\n#include <algorithm>\n#include <cstddef>\n#include <memory>\n#include <set>\n\
    #include <vector>\n\n/*\nstruct Ops {};\nstruct State {\n  using op_type = Ops;\n\
    \  using cost_type = u64;\n  using hash_type = u64;\n  std::vector<op_type> enumerate_ops()\
    \ {}\n  void apply(Ops op) {}\n  void rollback(Ops op) {}\n  cost_type calc_cost()\
    \ const {  }\n  hash_type calc_hash() const { }\n  bool is_finished() const {\
    \  }\n};\n\nstruct BMTask {\n  using state_type = State;\n\n  static state_type\
    \ init_state;\n};\n*/\n\ntemplate <typename BeamSearchTask, size_t BEAMSEARCH_WIDTH>\
    \ class BeamSearch {\nprivate:\n  using state_type = typename BeamSearchTask::state_type;\n\
    \  using op_type = typename state_type::op_type;\n  using cost_type = typename\
    \ state_type::cost_type;\n  using hash_type = typename state_type::hash_type;\n\
    \n  struct Node;\n  using node_ptr = Node *;\n  struct Node {\n    op_type op;\n\
    \    node_ptr par;\n    node_ptr child;\n    node_ptr right;\n    node_ptr left;\n\
    \n    Node() : par(nullptr), child(nullptr), right(nullptr), left(nullptr) {}\n\
    \    Node(op_type op_, node_ptr par_, node_ptr child_, node_ptr right_,\n    \
    \     node_ptr left_)\n        : op(op_), par(par_), child(child_), right(right_),\
    \ left(left_) {}\n\n    node_ptr push_child(op_type op_) {\n      node_ptr newnode\
    \ = new Node(op_, this, nullptr, child, nullptr);\n      if (child)\n        child->left\
    \ = newnode;\n      child = newnode;\n\n      return newnode;\n    }\n\n    bool\
    \ is_root() const { return !par; }\n    bool is_single_child() const { return\
    \ !right && !left; }\n    bool is_leftest_child() const { return !left; }\n  \
    \  bool has_child() { return child; }\n\n    ~Node() {\n      if (is_root()) {\n\
    \        return;\n      }\n\n      if (is_single_child()) {\n        delete par;\n\
    \        return;\n      }\n\n      if (is_leftest_child()) {\n        // replace\
    \ par->child\n        par->child = right;\n        right->left = nullptr;\n  \
    \      return;\n      }\n\n      // middle child\n      left->right = right;\n\
    \      if (right)\n        right->left = left;\n    }\n  };\n\n  struct Cand {\n\
    \    node_ptr leaf;\n    op_type op;\n    cost_type cost;\n    hash_type hash;\n\
    \    Cand(node_ptr leaf_, op_type op_, cost_type cost_, hash_type hash_)\n   \
    \     : leaf(leaf_), op(op_), cost(cost_), hash(hash_) {}\n\n    bool operator<(const\
    \ Cand &rhs) const { return cost < rhs.cost; }\n  };\n\n  std::vector<op_type>\
    \ get_op_seq(node_ptr now) {\n    std::vector<op_type> ops;\n    while (!now->is_root())\
    \ {\n      ops.emplace_back(now->op);\n      now = now->par;\n    }\n    std::reverse(ops.begin(),\
    \ ops.end());\n    return ops;\n  }\n\npublic:\n  BeamSearch() {}\n\n  std::vector<op_type>\
    \ run() {\n    node_ptr root = new Node();\n    std::vector<node_ptr> leafs;\n\
    \n    while (true) {\n      state_type state = BeamSearchTask::init_state;\n \
    \     std::vector<Cand> cands;\n      std::vector<Cand> finished_cands;\n\n  \
    \    node_ptr now = root;\n      size_t has_right_cnt = 0;\n      while (true)\
    \ {\n        // go down to leaf\n        while (now->child) {\n          now =\
    \ now->child;\n          if (now->right)\n            has_right_cnt++;\n     \
    \     state.apply(now->op);\n        }\n\n        // gen cands\n        for (op_type\
    \ op : state.enumerate_ops()) {\n          state.apply(op);\n\n          cost_type\
    \ cost = state.calc_cost();\n          hash_type hash = state.calc_hash();\n\n\
    \          if (state.is_finished()) {\n            finished_cands.emplace_back(now,\
    \ op, cost, hash);\n          } else {\n            cands.emplace_back(now, op,\
    \ cost, hash);\n          }\n\n          state.rollback(op);\n        }\n\n  \
    \      // go upward\n        while (has_right_cnt != 0 && !now->right) {\n   \
    \       state.rollback(now->op);\n          now = now->par;\n        }\n\n   \
    \     if (has_right_cnt == 0)\n          break;\n\n        // move right\n   \
    \     state.rollback(now->op);\n        now = now->right;\n        if (!now->right)\n\
    \          has_right_cnt--;\n        state.apply(now->op);\n      }\n\n      if\
    \ (!finished_cands.empty()) {\n        std::sort(finished_cands.begin(), finished_cands.end());\n\
    \n        const auto &[leaf, op, cost, hash] = finished_cands[0];\n        auto\
    \ ops = get_op_seq(leaf);\n        ops.emplace_back(op);\n\n        for (node_ptr\
    \ e : leafs) {\n          delete e;\n        }\n        return ops;\n      }\n\
    \n      std::sort(cands.begin(), cands.end());\n\n      std::vector<node_ptr>\
    \ next_leafs;\n      std::set<hash_type> hash_set;\n      size_t count = 0;\n\
    \      for (const auto &[leaf, op, cost, hash] : cands) {\n        if (count ==\
    \ BEAMSEARCH_WIDTH)\n          break;\n        if (hash_set.contains(hash))\n\
    \          continue;\n\n        node_ptr newleaf = leaf->push_child(op);\n   \
    \     next_leafs.emplace_back(newleaf);\n        count++;\n      }\n\n      for\
    \ (node_ptr e : leafs) {\n        if (!e->has_child())\n          delete e;\n\
    \      }\n\n      leafs = next_leafs;\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/heuristic/BeamSearch.hpp
  requiredBy: []
  timestamp: '2024-07-23 23:21:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/heuristic/BeamSearch.hpp
layout: document
redirect_from:
- /library/lib/heuristic/BeamSearch.hpp
- /library/lib/heuristic/BeamSearch.hpp.html
title: lib/heuristic/BeamSearch.hpp
---
