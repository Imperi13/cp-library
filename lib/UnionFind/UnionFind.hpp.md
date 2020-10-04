---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/UnionFind.test.cpp
    title: test/UnionFind.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/UnionFind/UnionFind.hpp\"\n\n#include <cstddef>\n#include\
    \ <numeric>\n#include <vector>\n\nclass UnionFind {\n public:\n  using size_t\
    \ = std::size_t;\n\n private:\n  std::vector<size_t> par, sz;\n  size_t group;\n\
    \n public:\n  UnionFind(size_t n = 0) : par(n, 0), sz(n, 1), group(n) {\n    std::iota(par.begin(),\
    \ par.end(), 0);\n  }\n\n  size_t root(size_t n) {\n    if (par[n] == n) return\
    \ n;\n    return par[n] = root(par[n]);\n  }\n\n  bool unite(size_t a, size_t\
    \ b) {\n    a = root(a);\n    b = root(b);\n    if (a == b) return false;\n  \
    \  group--;\n    if (sz[a] < sz[b]) std::swap(a, b);\n    sz[a] += sz[b];\n  \
    \  par[b] = a;\n    return true;\n  }\n\n  size_t size() { return par.size();\
    \ }\n  size_t groups() { return group; }\n  size_t group_size(size_t n) { return\
    \ sz[root(n)]; }\n\n  bool same(size_t a, size_t b) { return root(a) == root(b);\
    \ }\n};\n"
  code: "#pragma once\n\n#include <cstddef>\n#include <numeric>\n#include <vector>\n\
    \nclass UnionFind {\n public:\n  using size_t = std::size_t;\n\n private:\n  std::vector<size_t>\
    \ par, sz;\n  size_t group;\n\n public:\n  UnionFind(size_t n = 0) : par(n, 0),\
    \ sz(n, 1), group(n) {\n    std::iota(par.begin(), par.end(), 0);\n  }\n\n  size_t\
    \ root(size_t n) {\n    if (par[n] == n) return n;\n    return par[n] = root(par[n]);\n\
    \  }\n\n  bool unite(size_t a, size_t b) {\n    a = root(a);\n    b = root(b);\n\
    \    if (a == b) return false;\n    group--;\n    if (sz[a] < sz[b]) std::swap(a,\
    \ b);\n    sz[a] += sz[b];\n    par[b] = a;\n    return true;\n  }\n\n  size_t\
    \ size() { return par.size(); }\n  size_t groups() { return group; }\n  size_t\
    \ group_size(size_t n) { return sz[root(n)]; }\n\n  bool same(size_t a, size_t\
    \ b) { return root(a) == root(b); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/UnionFind/UnionFind.hpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/UnionFind.test.cpp
documentation_of: lib/UnionFind/UnionFind.hpp
layout: document
redirect_from:
- /library/lib/UnionFind/UnionFind.hpp
- /library/lib/UnionFind/UnionFind.hpp.html
title: lib/UnionFind/UnionFind.hpp
---
