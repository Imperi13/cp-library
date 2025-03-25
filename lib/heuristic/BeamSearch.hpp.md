---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/utility/type_alias.hpp
    title: lib/utility/type_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://eijirou-kyopro.hatenablog.com/entry/2024/02/01/115639
  bundledCode: "#line 1 \"lib/heuristic/BeamSearch.hpp\"\n\n#include <algorithm>\n\
    #include <cstddef>\n#include <memory>\n#include <numeric>\n#include <set>\n#include\
    \ <vector>\n\n#line 2 \"lib/utility/type_alias.hpp\"\n\n#include <cstdint>\n\n\
    using i64 = std::int64_t;\nusing i32 = std::int32_t;\nusing i16 = std::int16_t;\n\
    using i8 = std::int8_t;\n\nusing u64 = std::uint64_t;\nusing u32 = std::uint32_t;\n\
    using u16 = std::uint16_t;\nusing u8 = std::uint8_t;\n\nusing usize = std::size_t;\n\
    using isize = std::ptrdiff_t;\n\nconstexpr i64 operator\"\" _i64(unsigned long\
    \ long num) { return i64(num); }\nconstexpr i32 operator\"\" _i32(unsigned long\
    \ long num) { return i32(num); }\nconstexpr i16 operator\"\" _i16(unsigned long\
    \ long num) { return i16(num); }\nconstexpr i8 operator\"\" _i8(unsigned long\
    \ long num) { return i8(num); }\n\nconstexpr u64 operator\"\" _u64(unsigned long\
    \ long num) { return u64(num); }\nconstexpr u32 operator\"\" _u32(unsigned long\
    \ long num) { return u32(num); }\nconstexpr u16 operator\"\" _u16(unsigned long\
    \ long num) { return u16(num); }\nconstexpr u8 operator\"\" _u8(unsigned long\
    \ long num) { return u8(num); }\n#line 10 \"lib/heuristic/BeamSearch.hpp\"\n\n\
    // ref: https://eijirou-kyopro.hatenablog.com/entry/2024/02/01/115639\n\ntemplate\
    \ <class T>\nconcept BeamSearchStateConcept = requires(T &x, T::op_type op,\n\
    \                                          T::cand_type cand) {\n  typename T::op_type;\n\
    \  typename T::cand_type;\n  typename T::cand_type::score_type;\n  typename T::cand_type::hash_type;\n\
    \  x.apply(op);\n  x.rollback(op);\n  { x.enumerate_cands() } -> std::same_as<std::vector<typename\
    \ T::cand_type>>;\n  requires std::same_as<decltype(T::cand_type::op), typename\
    \ T::op_type>;\n  requires std::same_as<decltype(T::cand_type::score), typename\
    \ T::score_type>;\n  requires std::same_as<decltype(T::cand_type::hash), typename\
    \ T::hash_type>;\n};\n\ntemplate <BeamSearchStateConcept State, size_t BEAM_WIDTH>\
    \ class BeamSearch {\nprivate:\n  using leaf_idx_type = i32;\n  static_assert(BEAM_WIDTH\
    \ <= std::numeric_limits<leaf_idx_type>::max());\n\n  using state_type = State;\n\
    \  using op_type = state_type::op_type;\n  using cand_type = state_type::cand_type;\n\
    \  using score_type = cand_type::score_type;\n  using hash_type = cand_type::hash_type;\n\
    \n  class NewLeaf {\n    friend BeamSearch;\n\n  private:\n    leaf_idx_type par_idx;\n\
    \n  public:\n    cand_type cand;\n    NewLeaf(cand_type cand_, leaf_idx_type par_idx_)\n\
    \        : par_idx(par_idx_), cand(cand_) {}\n    NewLeaf() : par_idx(-1) {}\n\
    \  };\n\n  struct Edge {\n    op_type op;\n    leaf_idx_type leaf_idx; // -1:\
    \ apply , -2: rollback ,  positive: leaf\n    static constexpr leaf_idx_type APPLY\
    \ = -1;\n    static constexpr leaf_idx_type ROLLBACK = -2;\n    Edge(op_type op_,\
    \ leaf_idx_type leaf_idx_) : op(op_), leaf_idx(leaf_idx_) {}\n  };\n\n  const\
    \ state_type init_state;\n  std::vector<Edge> now_tree, next_tree;\n  std::vector<NewLeaf>\
    \ accept_leaf[BEAM_WIDTH];\n\npublic:\n  using leaf_type = NewLeaf;\n  BeamSearch(state_type\
    \ init_state_) : init_state(init_state_) {}\n\n  void step() {\n    state_type\
    \ state = init_state;\n    if (now_tree.empty()) {\n      std::vector<cand_type>\
    \ cands = state.enumerate_cands();\n      std::ranges::sort(cands, std::ranges::greater(),\
    \ &cand_type::score);\n      cands.resize(std::min(cands.size(), BEAM_WIDTH));\n\
    \      for (size_t i = 0; i < cands.size(); i++) {\n        now_tree.emplace_back(cands[i].op,\
    \ i);\n      }\n      return;\n    }\n\n    std::vector<NewLeaf> new_leaves;\n\
    \    score_type threshold = std::numeric_limits<score_type>::min();\n\n    for\
    \ (const auto &edge : now_tree) {\n      if (edge.leaf_idx == Edge::APPLY) {\n\
    \        state.apply(edge.op);\n      } else if (edge.leaf_idx == Edge::ROLLBACK)\
    \ {\n        state.rollback(edge.op);\n      } else {\n        state.apply(edge.op);\n\
    \n        std::vector<cand_type> cands = state.enumerate_cands();\n        for\
    \ (const auto &cand : cands) {\n          if (cand.score >= threshold) {\n   \
    \         new_leaves.emplace_back(cand, edge.leaf_idx);\n          }\n       \
    \ }\n        if (new_leaves.size() > BEAM_WIDTH * 2) {\n          std::ranges::sort(new_leaves,\
    \ std::ranges::greater(),\n                            [](auto &&v) { return v.cand.score;\
    \ });\n          new_leaves.resize(BEAM_WIDTH);\n          threshold = new_leaves.back().cand.score;\n\
    \        }\n        state.rollback(edge.op);\n      }\n    }\n\n    std::ranges::sort(new_leaves,\
    \ std::ranges::greater(),\n                      [](auto &&v) { return v.cand.score;\
    \ });\n    std::set<hash_type> hash_set;\n    size_t count = 0;\n    for (const\
    \ auto &leaf : new_leaves) {\n      if (count == BEAM_WIDTH)\n        break;\n\
    \      if (hash_set.contains(leaf.cand.hash))\n        continue;\n\n      accept_leaf[leaf.par_idx].push_back(leaf);\n\
    \      hash_set.insert(leaf.cand.hash);\n      count++;\n    }\n\n    leaf_idx_type\
    \ leaf_idx_cnt = 0;\n    for (const auto &edge : now_tree) {\n      if (edge.leaf_idx\
    \ == Edge::APPLY) {\n        next_tree.emplace_back(edge.op, Edge::APPLY);\n \
    \     } else if (edge.leaf_idx == Edge::ROLLBACK) {\n        if (next_tree.back().leaf_idx\
    \ == Edge::APPLY) {\n          next_tree.pop_back();\n        } else {\n     \
    \     next_tree.emplace_back(edge.op, Edge::ROLLBACK);\n        }\n      } else\
    \ {\n        if (!accept_leaf[edge.leaf_idx].empty()) {\n          next_tree.emplace_back(edge.op,\
    \ Edge::APPLY);\n          for (const auto &leaf : accept_leaf[edge.leaf_idx])\
    \ {\n            next_tree.emplace_back(leaf.cand.op, leaf_idx_cnt);\n       \
    \     leaf_idx_cnt++;\n          }\n          next_tree.emplace_back(edge.op,\
    \ Edge::ROLLBACK);\n          accept_leaf[edge.leaf_idx].clear();\n        }\n\
    \      }\n    }\n\n    std::swap(now_tree, next_tree);\n    next_tree.clear();\n\
    \  }\n\n  std::vector<leaf_type> step_and_get_leaf() {\n    std::vector<leaf_type>\
    \ ret;\n\n    state_type state = init_state;\n    if (now_tree.empty()) {\n  \
    \    std::vector<cand_type> cands = state.enumerate_cands();\n      std::ranges::sort(cands,\
    \ std::ranges::greater(), &cand_type::score);\n      cands.resize(std::min(cands.size(),\
    \ BEAM_WIDTH));\n      for (size_t i = 0; i < cands.size(); i++) {\n        now_tree.emplace_back(cands[i].op,\
    \ i);\n        ret.emplace_back(cands[i], i);\n      }\n      return ret;\n  \
    \  }\n\n    std::vector<NewLeaf> new_leaves;\n    score_type threshold = std::numeric_limits<score_type>::min();\n\
    \n    for (const auto &edge : now_tree) {\n      if (edge.leaf_idx == Edge::APPLY)\
    \ {\n        state.apply(edge.op);\n      } else if (edge.leaf_idx == Edge::ROLLBACK)\
    \ {\n        state.rollback(edge.op);\n      } else {\n        state.apply(edge.op);\n\
    \n        std::vector<cand_type> cands = state.enumerate_cands();\n        for\
    \ (const auto &cand : cands) {\n          if (cand.score >= threshold) {\n   \
    \         new_leaves.emplace_back(cand, edge.leaf_idx);\n          }\n       \
    \ }\n        if (new_leaves.size() > BEAM_WIDTH * 2) {\n          std::ranges::sort(new_leaves,\
    \ std::ranges::greater(),\n                            [](auto &&v) { return v.cand.score;\
    \ });\n          new_leaves.resize(BEAM_WIDTH);\n          threshold = new_leaves.back().cand.score;\n\
    \        }\n        state.rollback(edge.op);\n      }\n    }\n\n    std::ranges::sort(new_leaves,\
    \ std::ranges::greater(),\n                      [](auto &&v) { return v.cand.score;\
    \ });\n    std::set<hash_type> hash_set;\n    size_t count = 0;\n    for (const\
    \ auto &leaf : new_leaves) {\n      if (count == BEAM_WIDTH)\n        break;\n\
    \      if (hash_set.contains(leaf.cand.hash))\n        continue;\n\n      accept_leaf[leaf.par_idx].push_back(leaf);\n\
    \      hash_set.insert(leaf.cand.hash);\n      count++;\n    }\n\n    leaf_idx_type\
    \ leaf_idx_cnt = 0;\n    for (const auto &edge : now_tree) {\n      if (edge.leaf_idx\
    \ == Edge::APPLY) {\n        next_tree.emplace_back(edge.op, Edge::APPLY);\n \
    \     } else if (edge.leaf_idx == Edge::ROLLBACK) {\n        if (next_tree.back().leaf_idx\
    \ == Edge::APPLY) {\n          next_tree.pop_back();\n        } else {\n     \
    \     next_tree.emplace_back(edge.op, Edge::ROLLBACK);\n        }\n      } else\
    \ {\n        if (!accept_leaf[edge.leaf_idx].empty()) {\n          next_tree.emplace_back(edge.op,\
    \ Edge::APPLY);\n          for (const auto &leaf : accept_leaf[edge.leaf_idx])\
    \ {\n            next_tree.emplace_back(leaf.cand.op, leaf_idx_cnt);\n       \
    \     ret.emplace_back(leaf.cand, leaf_idx_cnt);\n            leaf_idx_cnt++;\n\
    \          }\n          next_tree.emplace_back(edge.op, Edge::ROLLBACK);\n   \
    \       accept_leaf[edge.leaf_idx].clear();\n        }\n      }\n    }\n\n   \
    \ std::swap(now_tree, next_tree);\n    next_tree.clear();\n\n    return ret;\n\
    \  }\n\n  std::vector<op_type> get_path(const leaf_type &leaf) {\n    std::vector<op_type>\
    \ path;\n    for (const auto &edge : now_tree) {\n      if (edge.leaf_idx == leaf.par_idx)\
    \ {\n        path.push_back(edge.op);\n        break;\n      }\n\n      if (edge.leaf_idx\
    \ == Edge::APPLY) {\n        path.emplace_back(edge.op);\n      } else if (edge.leaf_idx\
    \ == Edge::ROLLBACK) {\n        path.pop_back();\n      }\n    }\n\n    return\
    \ path;\n  }\n};\n"
  code: "\n#include <algorithm>\n#include <cstddef>\n#include <memory>\n#include <numeric>\n\
    #include <set>\n#include <vector>\n\n#include \"../utility/type_alias.hpp\"\n\n\
    // ref: https://eijirou-kyopro.hatenablog.com/entry/2024/02/01/115639\n\ntemplate\
    \ <class T>\nconcept BeamSearchStateConcept = requires(T &x, T::op_type op,\n\
    \                                          T::cand_type cand) {\n  typename T::op_type;\n\
    \  typename T::cand_type;\n  typename T::cand_type::score_type;\n  typename T::cand_type::hash_type;\n\
    \  x.apply(op);\n  x.rollback(op);\n  { x.enumerate_cands() } -> std::same_as<std::vector<typename\
    \ T::cand_type>>;\n  requires std::same_as<decltype(T::cand_type::op), typename\
    \ T::op_type>;\n  requires std::same_as<decltype(T::cand_type::score), typename\
    \ T::score_type>;\n  requires std::same_as<decltype(T::cand_type::hash), typename\
    \ T::hash_type>;\n};\n\ntemplate <BeamSearchStateConcept State, size_t BEAM_WIDTH>\
    \ class BeamSearch {\nprivate:\n  using leaf_idx_type = i32;\n  static_assert(BEAM_WIDTH\
    \ <= std::numeric_limits<leaf_idx_type>::max());\n\n  using state_type = State;\n\
    \  using op_type = state_type::op_type;\n  using cand_type = state_type::cand_type;\n\
    \  using score_type = cand_type::score_type;\n  using hash_type = cand_type::hash_type;\n\
    \n  class NewLeaf {\n    friend BeamSearch;\n\n  private:\n    leaf_idx_type par_idx;\n\
    \n  public:\n    cand_type cand;\n    NewLeaf(cand_type cand_, leaf_idx_type par_idx_)\n\
    \        : par_idx(par_idx_), cand(cand_) {}\n    NewLeaf() : par_idx(-1) {}\n\
    \  };\n\n  struct Edge {\n    op_type op;\n    leaf_idx_type leaf_idx; // -1:\
    \ apply , -2: rollback ,  positive: leaf\n    static constexpr leaf_idx_type APPLY\
    \ = -1;\n    static constexpr leaf_idx_type ROLLBACK = -2;\n    Edge(op_type op_,\
    \ leaf_idx_type leaf_idx_) : op(op_), leaf_idx(leaf_idx_) {}\n  };\n\n  const\
    \ state_type init_state;\n  std::vector<Edge> now_tree, next_tree;\n  std::vector<NewLeaf>\
    \ accept_leaf[BEAM_WIDTH];\n\npublic:\n  using leaf_type = NewLeaf;\n  BeamSearch(state_type\
    \ init_state_) : init_state(init_state_) {}\n\n  void step() {\n    state_type\
    \ state = init_state;\n    if (now_tree.empty()) {\n      std::vector<cand_type>\
    \ cands = state.enumerate_cands();\n      std::ranges::sort(cands, std::ranges::greater(),\
    \ &cand_type::score);\n      cands.resize(std::min(cands.size(), BEAM_WIDTH));\n\
    \      for (size_t i = 0; i < cands.size(); i++) {\n        now_tree.emplace_back(cands[i].op,\
    \ i);\n      }\n      return;\n    }\n\n    std::vector<NewLeaf> new_leaves;\n\
    \    score_type threshold = std::numeric_limits<score_type>::min();\n\n    for\
    \ (const auto &edge : now_tree) {\n      if (edge.leaf_idx == Edge::APPLY) {\n\
    \        state.apply(edge.op);\n      } else if (edge.leaf_idx == Edge::ROLLBACK)\
    \ {\n        state.rollback(edge.op);\n      } else {\n        state.apply(edge.op);\n\
    \n        std::vector<cand_type> cands = state.enumerate_cands();\n        for\
    \ (const auto &cand : cands) {\n          if (cand.score >= threshold) {\n   \
    \         new_leaves.emplace_back(cand, edge.leaf_idx);\n          }\n       \
    \ }\n        if (new_leaves.size() > BEAM_WIDTH * 2) {\n          std::ranges::sort(new_leaves,\
    \ std::ranges::greater(),\n                            [](auto &&v) { return v.cand.score;\
    \ });\n          new_leaves.resize(BEAM_WIDTH);\n          threshold = new_leaves.back().cand.score;\n\
    \        }\n        state.rollback(edge.op);\n      }\n    }\n\n    std::ranges::sort(new_leaves,\
    \ std::ranges::greater(),\n                      [](auto &&v) { return v.cand.score;\
    \ });\n    std::set<hash_type> hash_set;\n    size_t count = 0;\n    for (const\
    \ auto &leaf : new_leaves) {\n      if (count == BEAM_WIDTH)\n        break;\n\
    \      if (hash_set.contains(leaf.cand.hash))\n        continue;\n\n      accept_leaf[leaf.par_idx].push_back(leaf);\n\
    \      hash_set.insert(leaf.cand.hash);\n      count++;\n    }\n\n    leaf_idx_type\
    \ leaf_idx_cnt = 0;\n    for (const auto &edge : now_tree) {\n      if (edge.leaf_idx\
    \ == Edge::APPLY) {\n        next_tree.emplace_back(edge.op, Edge::APPLY);\n \
    \     } else if (edge.leaf_idx == Edge::ROLLBACK) {\n        if (next_tree.back().leaf_idx\
    \ == Edge::APPLY) {\n          next_tree.pop_back();\n        } else {\n     \
    \     next_tree.emplace_back(edge.op, Edge::ROLLBACK);\n        }\n      } else\
    \ {\n        if (!accept_leaf[edge.leaf_idx].empty()) {\n          next_tree.emplace_back(edge.op,\
    \ Edge::APPLY);\n          for (const auto &leaf : accept_leaf[edge.leaf_idx])\
    \ {\n            next_tree.emplace_back(leaf.cand.op, leaf_idx_cnt);\n       \
    \     leaf_idx_cnt++;\n          }\n          next_tree.emplace_back(edge.op,\
    \ Edge::ROLLBACK);\n          accept_leaf[edge.leaf_idx].clear();\n        }\n\
    \      }\n    }\n\n    std::swap(now_tree, next_tree);\n    next_tree.clear();\n\
    \  }\n\n  std::vector<leaf_type> step_and_get_leaf() {\n    std::vector<leaf_type>\
    \ ret;\n\n    state_type state = init_state;\n    if (now_tree.empty()) {\n  \
    \    std::vector<cand_type> cands = state.enumerate_cands();\n      std::ranges::sort(cands,\
    \ std::ranges::greater(), &cand_type::score);\n      cands.resize(std::min(cands.size(),\
    \ BEAM_WIDTH));\n      for (size_t i = 0; i < cands.size(); i++) {\n        now_tree.emplace_back(cands[i].op,\
    \ i);\n        ret.emplace_back(cands[i], i);\n      }\n      return ret;\n  \
    \  }\n\n    std::vector<NewLeaf> new_leaves;\n    score_type threshold = std::numeric_limits<score_type>::min();\n\
    \n    for (const auto &edge : now_tree) {\n      if (edge.leaf_idx == Edge::APPLY)\
    \ {\n        state.apply(edge.op);\n      } else if (edge.leaf_idx == Edge::ROLLBACK)\
    \ {\n        state.rollback(edge.op);\n      } else {\n        state.apply(edge.op);\n\
    \n        std::vector<cand_type> cands = state.enumerate_cands();\n        for\
    \ (const auto &cand : cands) {\n          if (cand.score >= threshold) {\n   \
    \         new_leaves.emplace_back(cand, edge.leaf_idx);\n          }\n       \
    \ }\n        if (new_leaves.size() > BEAM_WIDTH * 2) {\n          std::ranges::sort(new_leaves,\
    \ std::ranges::greater(),\n                            [](auto &&v) { return v.cand.score;\
    \ });\n          new_leaves.resize(BEAM_WIDTH);\n          threshold = new_leaves.back().cand.score;\n\
    \        }\n        state.rollback(edge.op);\n      }\n    }\n\n    std::ranges::sort(new_leaves,\
    \ std::ranges::greater(),\n                      [](auto &&v) { return v.cand.score;\
    \ });\n    std::set<hash_type> hash_set;\n    size_t count = 0;\n    for (const\
    \ auto &leaf : new_leaves) {\n      if (count == BEAM_WIDTH)\n        break;\n\
    \      if (hash_set.contains(leaf.cand.hash))\n        continue;\n\n      accept_leaf[leaf.par_idx].push_back(leaf);\n\
    \      hash_set.insert(leaf.cand.hash);\n      count++;\n    }\n\n    leaf_idx_type\
    \ leaf_idx_cnt = 0;\n    for (const auto &edge : now_tree) {\n      if (edge.leaf_idx\
    \ == Edge::APPLY) {\n        next_tree.emplace_back(edge.op, Edge::APPLY);\n \
    \     } else if (edge.leaf_idx == Edge::ROLLBACK) {\n        if (next_tree.back().leaf_idx\
    \ == Edge::APPLY) {\n          next_tree.pop_back();\n        } else {\n     \
    \     next_tree.emplace_back(edge.op, Edge::ROLLBACK);\n        }\n      } else\
    \ {\n        if (!accept_leaf[edge.leaf_idx].empty()) {\n          next_tree.emplace_back(edge.op,\
    \ Edge::APPLY);\n          for (const auto &leaf : accept_leaf[edge.leaf_idx])\
    \ {\n            next_tree.emplace_back(leaf.cand.op, leaf_idx_cnt);\n       \
    \     ret.emplace_back(leaf.cand, leaf_idx_cnt);\n            leaf_idx_cnt++;\n\
    \          }\n          next_tree.emplace_back(edge.op, Edge::ROLLBACK);\n   \
    \       accept_leaf[edge.leaf_idx].clear();\n        }\n      }\n    }\n\n   \
    \ std::swap(now_tree, next_tree);\n    next_tree.clear();\n\n    return ret;\n\
    \  }\n\n  std::vector<op_type> get_path(const leaf_type &leaf) {\n    std::vector<op_type>\
    \ path;\n    for (const auto &edge : now_tree) {\n      if (edge.leaf_idx == leaf.par_idx)\
    \ {\n        path.push_back(edge.op);\n        break;\n      }\n\n      if (edge.leaf_idx\
    \ == Edge::APPLY) {\n        path.emplace_back(edge.op);\n      } else if (edge.leaf_idx\
    \ == Edge::ROLLBACK) {\n        path.pop_back();\n      }\n    }\n\n    return\
    \ path;\n  }\n};\n"
  dependsOn:
  - lib/utility/type_alias.hpp
  isVerificationFile: false
  path: lib/heuristic/BeamSearch.hpp
  requiredBy: []
  timestamp: '2025-03-25 17:30:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/heuristic/BeamSearch.hpp
layout: document
redirect_from:
- /library/lib/heuristic/BeamSearch.hpp
- /library/lib/heuristic/BeamSearch.hpp.html
title: lib/heuristic/BeamSearch.hpp
---
