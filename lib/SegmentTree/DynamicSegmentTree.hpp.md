---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DynamicSegmentTree.test.cpp
    title: test/DynamicSegmentTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/SegmentTree/DynamicSegmentTree.hpp\"\n\n#include <cassert>\n\
    #include <memory>\n\n// Monoid\n// type value_t\n// static var id\n// static (value_t,value_t)->value_t\
    \ op\n\ntemplate <typename Monoid>\nclass DynamicSegmentTree {\n public:\n  using\
    \ value_t = typename Monoid::value_t;\n  using size_t = std::size_t;\n\n private:\n\
    \  struct Node {\n    value_t val;\n    Node *left, *right, *par;\n    Node(Node*\
    \ par_ = nullptr) : val(Monoid::id), left(), right(), par(par_) {}\n    ~Node()\
    \ {\n      if (left) delete left;\n      if (right) delete right;\n      left\
    \ = nullptr;\n      right = nullptr;\n      par = nullptr;\n    }\n  };\n\n  using\
    \ node_ptr = Node*;\n\n  size_t n, n0;\n  node_ptr root;\n\n  value_t fold(size_t\
    \ a, size_t b, const node_ptr& now, size_t l, size_t r) {\n    if (a <= l && r\
    \ <= b) return now->val;\n    if (b <= l || r <= a) return Monoid::id;\n    value_t\
    \ lval =\n        (now->left) ? fold(a, b, now->left, l, l + (r - l) / 2) : Monoid::id;\n\
    \    value_t rval =\n        (now->right) ? fold(a, b, now->right, l + (r - l)\
    \ / 2, r) : Monoid::id;\n    return Monoid::op(lval, rval);\n  }\n\n  void copy_dfs(node_ptr&\
    \ node, const node_ptr& from) {\n    node->val = from->val;\n    if (from->left)\
    \ {\n      node->left = new Node(node);\n      copy_dfs(node->left, from->left);\n\
    \    }\n    if (from->right) {\n      node->right = new Node(node);\n      copy_dfs(node->right,\
    \ from->right);\n    }\n  }\n\n public:\n  DynamicSegmentTree(size_t n_ = 0) :\
    \ n(n_), root(nullptr) {\n    n0 = 1;\n    while (n0 < n) n0 <<= 1;\n  }\n  DynamicSegmentTree(const\
    \ DynamicSegmentTree& from) {\n    n = from.n;\n    n0 = from.n0;\n    root =\
    \ nullptr;\n    if (from.root) {\n      root = new Node();\n      copy_dfs(root,\
    \ from.root);\n    }\n  }\n  DynamicSegmentTree& operator=(const DynamicSegmentTree&\
    \ from) {\n    n = from.n;\n    n0 = from.n0;\n    root = nullptr;\n    if (from.root)\
    \ {\n      root = new Node();\n      copy_dfs(root, from.root);\n    }\n  }\n\
    \  DynamicSegmentTree(DynamicSegmentTree&&) = default;\n  DynamicSegmentTree&\
    \ operator=(DynamicSegmentTree&&) = default;\n  ~DynamicSegmentTree() {\n    if\
    \ (root) delete root;\n    root = nullptr;\n  }\n\n  void update(size_t i, value_t\
    \ val, bool change) {\n    assert(0 <= i && i < n);\n    if (!root) root = new\
    \ Node();\n    node_ptr now = root;\n    size_t l = 0, r = n0;\n    while (r -\
    \ l > 1) {\n      size_t mid = l + (r - l) / 2;\n      if (i < mid) {\n      \
    \  if (!now->left) now->left = new Node(now);\n        now = now->left;\n    \
    \    r = mid;\n      } else {\n        if (!now->right) now->right = new Node(now);\n\
    \        now = now->right;\n        l = mid;\n      }\n    }\n    if (change)\n\
    \      now->val = val;\n    else\n      now->val = Monoid::op(now->val, val);\n\
    \n    while (now->par) {\n      now = now->par;\n      now->val = Monoid::op((now->left)\
    \ ? now->left->val : Monoid::id,\n                            (now->right) ? now->right->val\
    \ : Monoid::id);\n    }\n  }\n\n  value_t fold(size_t a, size_t b) {\n    assert(0\
    \ <= a && a <= b && b <= n);\n    if (!root) return Monoid::id;\n    return fold(a,\
    \ b, root, 0, n0);\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <memory>\n\n// Monoid\n// type\
    \ value_t\n// static var id\n// static (value_t,value_t)->value_t op\n\ntemplate\
    \ <typename Monoid>\nclass DynamicSegmentTree {\n public:\n  using value_t = typename\
    \ Monoid::value_t;\n  using size_t = std::size_t;\n\n private:\n  struct Node\
    \ {\n    value_t val;\n    Node *left, *right, *par;\n    Node(Node* par_ = nullptr)\
    \ : val(Monoid::id), left(), right(), par(par_) {}\n    ~Node() {\n      if (left)\
    \ delete left;\n      if (right) delete right;\n      left = nullptr;\n      right\
    \ = nullptr;\n      par = nullptr;\n    }\n  };\n\n  using node_ptr = Node*;\n\
    \n  size_t n, n0;\n  node_ptr root;\n\n  value_t fold(size_t a, size_t b, const\
    \ node_ptr& now, size_t l, size_t r) {\n    if (a <= l && r <= b) return now->val;\n\
    \    if (b <= l || r <= a) return Monoid::id;\n    value_t lval =\n        (now->left)\
    \ ? fold(a, b, now->left, l, l + (r - l) / 2) : Monoid::id;\n    value_t rval\
    \ =\n        (now->right) ? fold(a, b, now->right, l + (r - l) / 2, r) : Monoid::id;\n\
    \    return Monoid::op(lval, rval);\n  }\n\n  void copy_dfs(node_ptr& node, const\
    \ node_ptr& from) {\n    node->val = from->val;\n    if (from->left) {\n     \
    \ node->left = new Node(node);\n      copy_dfs(node->left, from->left);\n    }\n\
    \    if (from->right) {\n      node->right = new Node(node);\n      copy_dfs(node->right,\
    \ from->right);\n    }\n  }\n\n public:\n  DynamicSegmentTree(size_t n_ = 0) :\
    \ n(n_), root(nullptr) {\n    n0 = 1;\n    while (n0 < n) n0 <<= 1;\n  }\n  DynamicSegmentTree(const\
    \ DynamicSegmentTree& from) {\n    n = from.n;\n    n0 = from.n0;\n    root =\
    \ nullptr;\n    if (from.root) {\n      root = new Node();\n      copy_dfs(root,\
    \ from.root);\n    }\n  }\n  DynamicSegmentTree& operator=(const DynamicSegmentTree&\
    \ from) {\n    n = from.n;\n    n0 = from.n0;\n    root = nullptr;\n    if (from.root)\
    \ {\n      root = new Node();\n      copy_dfs(root, from.root);\n    }\n  }\n\
    \  DynamicSegmentTree(DynamicSegmentTree&&) = default;\n  DynamicSegmentTree&\
    \ operator=(DynamicSegmentTree&&) = default;\n  ~DynamicSegmentTree() {\n    if\
    \ (root) delete root;\n    root = nullptr;\n  }\n\n  void update(size_t i, value_t\
    \ val, bool change) {\n    assert(0 <= i && i < n);\n    if (!root) root = new\
    \ Node();\n    node_ptr now = root;\n    size_t l = 0, r = n0;\n    while (r -\
    \ l > 1) {\n      size_t mid = l + (r - l) / 2;\n      if (i < mid) {\n      \
    \  if (!now->left) now->left = new Node(now);\n        now = now->left;\n    \
    \    r = mid;\n      } else {\n        if (!now->right) now->right = new Node(now);\n\
    \        now = now->right;\n        l = mid;\n      }\n    }\n    if (change)\n\
    \      now->val = val;\n    else\n      now->val = Monoid::op(now->val, val);\n\
    \n    while (now->par) {\n      now = now->par;\n      now->val = Monoid::op((now->left)\
    \ ? now->left->val : Monoid::id,\n                            (now->right) ? now->right->val\
    \ : Monoid::id);\n    }\n  }\n\n  value_t fold(size_t a, size_t b) {\n    assert(0\
    \ <= a && a <= b && b <= n);\n    if (!root) return Monoid::id;\n    return fold(a,\
    \ b, root, 0, n0);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/SegmentTree/DynamicSegmentTree.hpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DynamicSegmentTree.test.cpp
documentation_of: lib/SegmentTree/DynamicSegmentTree.hpp
layout: document
redirect_from:
- /library/lib/SegmentTree/DynamicSegmentTree.hpp
- /library/lib/SegmentTree/DynamicSegmentTree.hpp.html
title: lib/SegmentTree/DynamicSegmentTree.hpp
---
