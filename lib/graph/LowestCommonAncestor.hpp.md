---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LowestCommonAncestor.test.cpp
    title: test/LowestCommonAncestor.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"lib/graph/LowestCommonAncestor.hpp\"\n\n#include <vector>\n\
    \nclass LowestCommonAncestor {\n public:\n  using size_t = std::size_t;\n\n private:\n\
    \  size_t n, bit;\n  std::vector<size_t> depth;\n  std::vector<std::vector<size_t>>\
    \ par_dbl;\n\n  size_t log(size_t tmp) {\n    size_t ret = 1;\n    while (tmp\
    \ > 0) {\n      ret++;\n      tmp >>= 1;\n    }\n    return ret;\n  }\n\n public:\n\
    \  template <typename Edge>\n  LowestCommonAncestor(size_t root, const std::vector<std::vector<Edge>>&\
    \ graph)\n      : n(graph.size()),\n        bit(log(n)),\n        depth(n),\n\
    \        par_dbl(n, std::vector<size_t>(bit)) {\n    auto dfs = [&](auto f, size_t\
    \ now, size_t par, size_t dep) -> void {\n      depth[now] = dep;\n      if (dep\
    \ != 0)\n        par_dbl[now][0] = par;\n      else\n        par_dbl[now][0] =\
    \ now;\n\n      for (const auto& e : graph[now]) {\n        if (e != par) f(f,\
    \ e, now, dep + 1);\n      }\n    };\n    dfs(dfs, root, -1, 0);\n    for (size_t\
    \ i = 1; i < bit; i++) {\n      for (size_t j = 0; j < n; j++)\n        par_dbl[j][i]\
    \ = par_dbl[par_dbl[j][i - 1]][i - 1];\n    }\n  }\n\n  size_t lca(size_t a, size_t\
    \ b) {\n    if (depth[a] < depth[b]) std::swap(a, b);\n    for (size_t i = 0;\
    \ i < bit; i++) {\n      if (((depth[a] - depth[b]) >> i) & 1) a = par_dbl[a][i];\n\
    \    }\n    if (a == b) return a;\n    for (long long i = bit - 1; i >= 0; i--)\
    \ {\n      if (par_dbl[a][i] != par_dbl[b][i]) {\n        a = par_dbl[a][i];\n\
    \        b = par_dbl[b][i];\n      }\n    }\n    return par_dbl[a][0];\n  }\n\
    };\n"
  code: "#pragma once\n\n#include <vector>\n\nclass LowestCommonAncestor {\n public:\n\
    \  using size_t = std::size_t;\n\n private:\n  size_t n, bit;\n  std::vector<size_t>\
    \ depth;\n  std::vector<std::vector<size_t>> par_dbl;\n\n  size_t log(size_t tmp)\
    \ {\n    size_t ret = 1;\n    while (tmp > 0) {\n      ret++;\n      tmp >>= 1;\n\
    \    }\n    return ret;\n  }\n\n public:\n  template <typename Edge>\n  LowestCommonAncestor(size_t\
    \ root, const std::vector<std::vector<Edge>>& graph)\n      : n(graph.size()),\n\
    \        bit(log(n)),\n        depth(n),\n        par_dbl(n, std::vector<size_t>(bit))\
    \ {\n    auto dfs = [&](auto f, size_t now, size_t par, size_t dep) -> void {\n\
    \      depth[now] = dep;\n      if (dep != 0)\n        par_dbl[now][0] = par;\n\
    \      else\n        par_dbl[now][0] = now;\n\n      for (const auto& e : graph[now])\
    \ {\n        if (e != par) f(f, e, now, dep + 1);\n      }\n    };\n    dfs(dfs,\
    \ root, -1, 0);\n    for (size_t i = 1; i < bit; i++) {\n      for (size_t j =\
    \ 0; j < n; j++)\n        par_dbl[j][i] = par_dbl[par_dbl[j][i - 1]][i - 1];\n\
    \    }\n  }\n\n  size_t lca(size_t a, size_t b) {\n    if (depth[a] < depth[b])\
    \ std::swap(a, b);\n    for (size_t i = 0; i < bit; i++) {\n      if (((depth[a]\
    \ - depth[b]) >> i) & 1) a = par_dbl[a][i];\n    }\n    if (a == b) return a;\n\
    \    for (long long i = bit - 1; i >= 0; i--) {\n      if (par_dbl[a][i] != par_dbl[b][i])\
    \ {\n        a = par_dbl[a][i];\n        b = par_dbl[b][i];\n      }\n    }\n\
    \    return par_dbl[a][0];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/LowestCommonAncestor.hpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LowestCommonAncestor.test.cpp
documentation_of: lib/graph/LowestCommonAncestor.hpp
layout: document
redirect_from:
- /library/lib/graph/LowestCommonAncestor.hpp
- /library/lib/graph/LowestCommonAncestor.hpp.html
title: lib/graph/LowestCommonAncestor.hpp
---
