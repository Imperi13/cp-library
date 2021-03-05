---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/UnionFind/PersistentUnionFind.hpp
    title: lib/UnionFind/PersistentUnionFind.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/PersistentArray.test.cpp
    title: test/PersistentArray.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/PersistentArray_2.test.cpp
    title: test/PersistentArray_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/PersistentUnionFind.test.cpp
    title: test/PersistentUnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/PersistentArray.hpp\"\n\n#include <cassert>\n#include\
    \ <memory>\n\ntemplate <typename T, std::size_t BITSIZE = 4>\nclass PersistentArray\
    \ {\n public:\n  using value_t = T;\n  using size_t = std::size_t;\n\n private:\n\
    \  struct Node {\n    value_t val;\n    std::array<std::shared_ptr<Node>, 1 <<\
    \ BITSIZE> ch;\n    Node(value_t val_) : val(val_) { ch.fill(nullptr); }\n  };\n\
    \  using node_ptr = std::shared_ptr<Node>;\n\n  value_t init;\n  node_ptr root;\n\
    \n  node_ptr update(size_t k, value_t value, node_ptr now) {\n    node_ptr ret\
    \ =\n        (now ? std::make_shared<Node>(*now) : std::make_shared<Node>(init));\n\
    \    if (k == 0)\n      ret->val = value;\n    else {\n      size_t mask = (1\
    \ << BITSIZE) - 1;\n      ret->ch[k & mask] = update(k >> BITSIZE, value, ret->ch[k\
    \ & mask]);\n    }\n    return ret;\n  }\n\n  value_t at(size_t k, node_ptr now)\
    \ {\n    if (!now) return init;\n    if (k == 0) return now->val;\n    return\
    \ at(k >> BITSIZE, now->ch[k & ((1 << BITSIZE) - 1)]);\n  }\n\n  PersistentArray(value_t\
    \ init_, const node_ptr& root_)\n      : init(init_), root(root_) {}\n\n public:\n\
    \  PersistentArray(value_t init_ = value_t()) : init(init_), root(nullptr) {}\n\
    \n  PersistentArray update(size_t k, const value_t& value) {\n    return PersistentArray(init,\
    \ update(k, value, root));\n  }\n\n  value_t operator[](size_t k) { return at(k,\
    \ root); }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <memory>\n\ntemplate <typename\
    \ T, std::size_t BITSIZE = 4>\nclass PersistentArray {\n public:\n  using value_t\
    \ = T;\n  using size_t = std::size_t;\n\n private:\n  struct Node {\n    value_t\
    \ val;\n    std::array<std::shared_ptr<Node>, 1 << BITSIZE> ch;\n    Node(value_t\
    \ val_) : val(val_) { ch.fill(nullptr); }\n  };\n  using node_ptr = std::shared_ptr<Node>;\n\
    \n  value_t init;\n  node_ptr root;\n\n  node_ptr update(size_t k, value_t value,\
    \ node_ptr now) {\n    node_ptr ret =\n        (now ? std::make_shared<Node>(*now)\
    \ : std::make_shared<Node>(init));\n    if (k == 0)\n      ret->val = value;\n\
    \    else {\n      size_t mask = (1 << BITSIZE) - 1;\n      ret->ch[k & mask]\
    \ = update(k >> BITSIZE, value, ret->ch[k & mask]);\n    }\n    return ret;\n\
    \  }\n\n  value_t at(size_t k, node_ptr now) {\n    if (!now) return init;\n \
    \   if (k == 0) return now->val;\n    return at(k >> BITSIZE, now->ch[k & ((1\
    \ << BITSIZE) - 1)]);\n  }\n\n  PersistentArray(value_t init_, const node_ptr&\
    \ root_)\n      : init(init_), root(root_) {}\n\n public:\n  PersistentArray(value_t\
    \ init_ = value_t()) : init(init_), root(nullptr) {}\n\n  PersistentArray update(size_t\
    \ k, const value_t& value) {\n    return PersistentArray(init, update(k, value,\
    \ root));\n  }\n\n  value_t operator[](size_t k) { return at(k, root); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/PersistentArray.hpp
  requiredBy:
  - lib/UnionFind/PersistentUnionFind.hpp
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/PersistentArray_2.test.cpp
  - test/PersistentArray.test.cpp
  - test/PersistentUnionFind.test.cpp
documentation_of: lib/PersistentArray.hpp
layout: document
redirect_from:
- /library/lib/PersistentArray.hpp
- /library/lib/PersistentArray.hpp.html
title: lib/PersistentArray.hpp
---
