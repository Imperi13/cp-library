---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DualSegmentTree.test.cpp
    title: test/DualSegmentTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/SegmentTree/DualSegmentTree.hpp\"\n\n\
    #include <cassert>\n#include <memory>\n\n// commutative Monoid\n// type value_t\n\
    // static value_t id\n// static (value_t,value_t)->value_t op\n\ntemplate <typename\
    \ Monoid>\nclass DualSegmentTree {\n public:\n  using value_t = typename Monoid::value_t;\n\
    \  using size_t = std::size_t;\n\n private:\n  struct Node {\n    value_t val;\n\
    \    std::shared_ptr<Node> left, right;\n    Node(value_t val_) : val(val_), left(),\
    \ right() {}\n  };\n\n  using node_ptr = std::shared_ptr<Node>;\n\n  size_t n,\
    \ n0;\n  node_ptr root;\n\n  void update(size_t a, size_t b, value_t value, const\
    \ node_ptr& now, size_t l,\n              size_t r) {\n    if (a <= l && r <=\
    \ b) {\n      now->val = Monoid::op(now->val, value);\n      return;\n    }\n\
    \    if (b <= l || r <= a) return;\n\n    if (!now->left) now->left = std::make_shared<Node>(Monoid::id);\n\
    \    if (!now->right) now->right = std::make_shared<Node>(Monoid::id);\n    update(a,\
    \ b, value, now->left, l, l + (r - l) / 2);\n    update(a, b, value, now->right,\
    \ l + (r - l) / 2, r);\n  }\n\n public:\n  DualSegmentTree(size_t n_) : n(n_),\
    \ root(new Node(Monoid::id)) {\n    n0 = 1;\n    while (n0 < n) n0 <<= 1;\n  }\n\
    \n  void update(size_t l, size_t r, value_t value) {\n    assert(0 <= l && l <=\
    \ r && r <= n);\n    update(l, r, value, root, 0, n0);\n  }\n\n  value_t at(size_t\
    \ i) {\n    assert(0 <= i && i < n);\n    node_ptr now(root);\n    value_t ret\
    \ = now->val;\n\n    size_t l = 0, r = n0;\n    while (r - l > 1) {\n      size_t\
    \ mid = l + (r - l) / 2;\n      if (i < mid) {\n        if (!now->left) break;\n\
    \        now = now->left;\n        r = mid;\n      } else {\n        if (!now->right)\
    \ break;\n        now = now->right;\n        l = mid;\n      }\n      ret = Monoid::op(ret,\
    \ now->val);\n    }\n    return ret;\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <memory>\n\n// commutative Monoid\n\
    // type value_t\n// static value_t id\n// static (value_t,value_t)->value_t op\n\
    \ntemplate <typename Monoid>\nclass DualSegmentTree {\n public:\n  using value_t\
    \ = typename Monoid::value_t;\n  using size_t = std::size_t;\n\n private:\n  struct\
    \ Node {\n    value_t val;\n    std::shared_ptr<Node> left, right;\n    Node(value_t\
    \ val_) : val(val_), left(), right() {}\n  };\n\n  using node_ptr = std::shared_ptr<Node>;\n\
    \n  size_t n, n0;\n  node_ptr root;\n\n  void update(size_t a, size_t b, value_t\
    \ value, const node_ptr& now, size_t l,\n              size_t r) {\n    if (a\
    \ <= l && r <= b) {\n      now->val = Monoid::op(now->val, value);\n      return;\n\
    \    }\n    if (b <= l || r <= a) return;\n\n    if (!now->left) now->left = std::make_shared<Node>(Monoid::id);\n\
    \    if (!now->right) now->right = std::make_shared<Node>(Monoid::id);\n    update(a,\
    \ b, value, now->left, l, l + (r - l) / 2);\n    update(a, b, value, now->right,\
    \ l + (r - l) / 2, r);\n  }\n\n public:\n  DualSegmentTree(size_t n_) : n(n_),\
    \ root(new Node(Monoid::id)) {\n    n0 = 1;\n    while (n0 < n) n0 <<= 1;\n  }\n\
    \n  void update(size_t l, size_t r, value_t value) {\n    assert(0 <= l && l <=\
    \ r && r <= n);\n    update(l, r, value, root, 0, n0);\n  }\n\n  value_t at(size_t\
    \ i) {\n    assert(0 <= i && i < n);\n    node_ptr now(root);\n    value_t ret\
    \ = now->val;\n\n    size_t l = 0, r = n0;\n    while (r - l > 1) {\n      size_t\
    \ mid = l + (r - l) / 2;\n      if (i < mid) {\n        if (!now->left) break;\n\
    \        now = now->left;\n        r = mid;\n      } else {\n        if (!now->right)\
    \ break;\n        now = now->right;\n        l = mid;\n      }\n      ret = Monoid::op(ret,\
    \ now->val);\n    }\n    return ret;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/SegmentTree/DualSegmentTree.hpp
  requiredBy: []
  timestamp: '2023-11-10 03:27:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DualSegmentTree.test.cpp
documentation_of: lib/data_structure/SegmentTree/DualSegmentTree.hpp
layout: document
redirect_from:
- /library/lib/data_structure/SegmentTree/DualSegmentTree.hpp
- /library/lib/data_structure/SegmentTree/DualSegmentTree.hpp.html
title: lib/data_structure/SegmentTree/DualSegmentTree.hpp
---
