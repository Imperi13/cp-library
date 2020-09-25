---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/PotentialUnionFind.test.cpp
    title: test/PotentialUnionFind.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"lib/UnionFind/PotentialUnionFind.hpp\"\n\n#include <cassert>\n\
    #include <numeric>\n#include <vector>\n\ntemplate <typename Group>\nclass PotentialUnionFind\
    \ {\n public:\n  using value_t = typename Group::value_t;\n  using size_t = std::size_t;\n\
    \n private:\n  size_t group;\n  std::vector<size_t> par, sz;\n  std::vector<value_t>\
    \ df;  // val[par]=val[x]+df[x]\n\n  value_t fold_to_root(size_t x) {\n    value_t\
    \ ret = Group::id;\n    while (par[x] != x) {\n      df[x] = Group::op(df[x],\
    \ df[par[x]]);\n      par[x] = par[par[x]];\n      ret = Group::op(ret, df[x]);\n\
    \      x = par[x];\n    }\n    return ret;\n  }\n\n public:\n  PotentialUnionFind(size_t\
    \ n = 0)\n      : group(n), par(n), sz(n, 1), df(n, Group::id) {\n    std::iota(par.begin(),\
    \ par.end(), 0);\n  }\n\n  size_t root(size_t x) {\n    while (par[x] != x) {\n\
    \      df[x] = Group::op(df[x], df[par[x]]);\n      par[x] = par[par[x]];\n  \
    \    x = par[x];\n    }\n    return x;\n  }\n\n  bool same(size_t a, size_t b)\
    \ { return root(a) == root(b); }\n  size_t size() { return par.size(); }\n  size_t\
    \ groups() { return group; }\n  size_t group_size(size_t x) { return sz[root(x)];\
    \ }\n\n  // unite A=B+value\n  bool unite(size_t a, size_t b, value_t value) {\n\
    \    size_t aroot = root(a), broot = root(b);\n    if (aroot == broot) return\
    \ false;\n    group--;\n    if (sz[aroot] < sz[broot]) {\n      std::swap(aroot,\
    \ broot);\n      std::swap(a, b);\n      value = Group::inv(value);\n    }\n \
    \   sz[aroot] += sz[broot];\n    value = Group::op(value, fold_to_root(a));\n\
    \    value = Group::op(Group::inv(fold_to_root(b)), value);\n    df[broot] = value;\n\
    \    par[broot] = aroot;\n    return true;\n  }\n\n  // return diff  such as A=B+diff\n\
    \  value_t diff(size_t a, size_t b) {\n    assert(same(a, b));\n    return Group::op(fold_to_root(b),\
    \ Group::inv(fold_to_root(a)));\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <numeric>\n#include <vector>\n\
    \ntemplate <typename Group>\nclass PotentialUnionFind {\n public:\n  using value_t\
    \ = typename Group::value_t;\n  using size_t = std::size_t;\n\n private:\n  size_t\
    \ group;\n  std::vector<size_t> par, sz;\n  std::vector<value_t> df;  // val[par]=val[x]+df[x]\n\
    \n  value_t fold_to_root(size_t x) {\n    value_t ret = Group::id;\n    while\
    \ (par[x] != x) {\n      df[x] = Group::op(df[x], df[par[x]]);\n      par[x] =\
    \ par[par[x]];\n      ret = Group::op(ret, df[x]);\n      x = par[x];\n    }\n\
    \    return ret;\n  }\n\n public:\n  PotentialUnionFind(size_t n = 0)\n      :\
    \ group(n), par(n), sz(n, 1), df(n, Group::id) {\n    std::iota(par.begin(), par.end(),\
    \ 0);\n  }\n\n  size_t root(size_t x) {\n    while (par[x] != x) {\n      df[x]\
    \ = Group::op(df[x], df[par[x]]);\n      par[x] = par[par[x]];\n      x = par[x];\n\
    \    }\n    return x;\n  }\n\n  bool same(size_t a, size_t b) { return root(a)\
    \ == root(b); }\n  size_t size() { return par.size(); }\n  size_t groups() { return\
    \ group; }\n  size_t group_size(size_t x) { return sz[root(x)]; }\n\n  // unite\
    \ A=B+value\n  bool unite(size_t a, size_t b, value_t value) {\n    size_t aroot\
    \ = root(a), broot = root(b);\n    if (aroot == broot) return false;\n    group--;\n\
    \    if (sz[aroot] < sz[broot]) {\n      std::swap(aroot, broot);\n      std::swap(a,\
    \ b);\n      value = Group::inv(value);\n    }\n    sz[aroot] += sz[broot];\n\
    \    value = Group::op(value, fold_to_root(a));\n    value = Group::op(Group::inv(fold_to_root(b)),\
    \ value);\n    df[broot] = value;\n    par[broot] = aroot;\n    return true;\n\
    \  }\n\n  // return diff  such as A=B+diff\n  value_t diff(size_t a, size_t b)\
    \ {\n    assert(same(a, b));\n    return Group::op(fold_to_root(b), Group::inv(fold_to_root(a)));\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/UnionFind/PotentialUnionFind.hpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/PotentialUnionFind.test.cpp
documentation_of: lib/UnionFind/PotentialUnionFind.hpp
layout: document
redirect_from:
- /library/lib/UnionFind/PotentialUnionFind.hpp
- /library/lib/UnionFind/PotentialUnionFind.hpp.html
title: lib/UnionFind/PotentialUnionFind.hpp
---
