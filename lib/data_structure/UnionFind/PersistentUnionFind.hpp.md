---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/PersistentArray.hpp
    title: lib/data_structure/PersistentArray.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/PersistentUnionFind.test.cpp
    title: test/PersistentUnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/UnionFind/PersistentUnionFind.hpp\"\n\
    \n#line 2 \"lib/data_structure/PersistentArray.hpp\"\n\n#include <array>\n#include\
    \ <cassert>\n#include <memory>\n\ntemplate <typename T, std::size_t BITSIZE =\
    \ 4>\nclass PersistentArray {\n public:\n  using value_t = T;\n  using size_t\
    \ = std::size_t;\n\n private:\n  struct Node {\n    value_t val;\n    std::array<std::shared_ptr<Node>,\
    \ 1 << BITSIZE> ch;\n    Node(value_t val_) : val(val_) { ch.fill(nullptr); }\n\
    \  };\n  using node_ptr = std::shared_ptr<Node>;\n\n  value_t init;\n  node_ptr\
    \ root;\n\n  node_ptr update(size_t k, value_t value, node_ptr now) {\n    node_ptr\
    \ ret =\n        (now ? std::make_shared<Node>(*now) : std::make_shared<Node>(init));\n\
    \    if (k == 0)\n      ret->val = value;\n    else {\n      size_t mask = (1\
    \ << BITSIZE) - 1;\n      ret->ch[k & mask] = update(k >> BITSIZE, value, ret->ch[k\
    \ & mask]);\n    }\n    return ret;\n  }\n\n  value_t at(size_t k, node_ptr now)\
    \ {\n    if (!now) return init;\n    if (k == 0) return now->val;\n    return\
    \ at(k >> BITSIZE, now->ch[k & ((1 << BITSIZE) - 1)]);\n  }\n\n  PersistentArray(value_t\
    \ init_, const node_ptr& root_)\n      : init(init_), root(root_) {}\n\n public:\n\
    \  PersistentArray(value_t init_ = value_t()) : init(init_), root(nullptr) {}\n\
    \n  PersistentArray update(size_t k, const value_t& value) {\n    return PersistentArray(init,\
    \ update(k, value, root));\n  }\n\n  value_t operator[](size_t k) { return at(k,\
    \ root); }\n};\n#line 4 \"lib/data_structure/UnionFind/PersistentUnionFind.hpp\"\
    \n\nclass PersistentUnionFind {\n public:\n  using size_t = std::size_t;\n\n private:\n\
    \  PersistentArray<long long> uni;\n  size_t group;\n\n  PersistentUnionFind(PersistentArray<long\
    \ long> uni_, size_t group_)\n      : uni(uni_), group(group_) {}\n\n public:\n\
    \  PersistentUnionFind(size_t n = 0) : uni(-1), group(n) {}\n\n  size_t root(size_t\
    \ a) {\n    if (uni[a] < 0) return a;\n    size_t tmp = root(uni[a]);\n    uni\
    \ = uni.update(a, tmp);\n    return tmp;\n  }\n\n  PersistentUnionFind unite(size_t\
    \ a, size_t b) {\n    a = root(a);\n    b = root(b);\n    if (a == b) return *this;\n\
    \    group--;\n    if (uni[a] > uni[b]) std::swap(a, b);\n\n    PersistentArray<long\
    \ long> newuni = uni;\n    long long va = uni[a], vb = uni[b];\n    newuni = newuni.update(a,\
    \ va + vb);\n    newuni = newuni.update(b, a);\n    return PersistentUnionFind(newuni,\
    \ group);\n  }\n\n  bool isconnect(size_t a, size_t b) { return root(a) == root(b);\
    \ }\n  size_t group_size(size_t a) { return -uni[root(a)]; }\n  size_t groups()\
    \ { return group; }\n};\n"
  code: "#pragma once\n\n#include \"../PersistentArray.hpp\"\n\nclass PersistentUnionFind\
    \ {\n public:\n  using size_t = std::size_t;\n\n private:\n  PersistentArray<long\
    \ long> uni;\n  size_t group;\n\n  PersistentUnionFind(PersistentArray<long long>\
    \ uni_, size_t group_)\n      : uni(uni_), group(group_) {}\n\n public:\n  PersistentUnionFind(size_t\
    \ n = 0) : uni(-1), group(n) {}\n\n  size_t root(size_t a) {\n    if (uni[a] <\
    \ 0) return a;\n    size_t tmp = root(uni[a]);\n    uni = uni.update(a, tmp);\n\
    \    return tmp;\n  }\n\n  PersistentUnionFind unite(size_t a, size_t b) {\n \
    \   a = root(a);\n    b = root(b);\n    if (a == b) return *this;\n    group--;\n\
    \    if (uni[a] > uni[b]) std::swap(a, b);\n\n    PersistentArray<long long> newuni\
    \ = uni;\n    long long va = uni[a], vb = uni[b];\n    newuni = newuni.update(a,\
    \ va + vb);\n    newuni = newuni.update(b, a);\n    return PersistentUnionFind(newuni,\
    \ group);\n  }\n\n  bool isconnect(size_t a, size_t b) { return root(a) == root(b);\
    \ }\n  size_t group_size(size_t a) { return -uni[root(a)]; }\n  size_t groups()\
    \ { return group; }\n};"
  dependsOn:
  - lib/data_structure/PersistentArray.hpp
  isVerificationFile: false
  path: lib/data_structure/UnionFind/PersistentUnionFind.hpp
  requiredBy: []
  timestamp: '2023-11-10 04:55:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/PersistentUnionFind.test.cpp
documentation_of: lib/data_structure/UnionFind/PersistentUnionFind.hpp
layout: document
redirect_from:
- /library/lib/data_structure/UnionFind/PersistentUnionFind.hpp
- /library/lib/data_structure/UnionFind/PersistentUnionFind.hpp.html
title: lib/data_structure/UnionFind/PersistentUnionFind.hpp
---
