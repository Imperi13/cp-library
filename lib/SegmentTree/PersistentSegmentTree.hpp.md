---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/PersistentSegmentTree.test.cpp
    title: test/PersistentSegmentTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/SegmentTree/PersistentSegmentTree.hpp\"\n\n#include\
    \ <cassert>\n#include <memory>\n\ntemplate <typename Monoid>\nclass PersistentSegmentTree\
    \ {\n public:\n  using value_t = typename Monoid::value_t;\n  using size_t = std::size_t;\n\
    \n private:\n  struct Node {\n    value_t val;\n    std::shared_ptr<Node> left,\
    \ right;\n    std::weak_ptr<Node> par;\n    Node(value_t val_, std::shared_ptr<Node>\
    \ par_ = nullptr)\n        : val(val_), left(), right(), par(par_) {}\n  };\n\n\
    \  using node_ptr = std::shared_ptr<Node>;\n  size_t n, n0;\n  node_ptr root;\n\
    \n  value_t fold(size_t a, size_t b, const node_ptr& now, size_t l, size_t r)\
    \ {\n    if (a <= l && r <= b) return now->val;\n    if (b <= l || r <= a) return\
    \ Monoid::id;\n    value_t lval =\n        (now->left) ? fold(a, b, now->left,\
    \ l, l + (r - l) / 2) : Monoid::id;\n    value_t rval =\n        (now->right)\
    \ ? fold(a, b, now->right, l + (r - l) / 2, r) : Monoid::id;\n    return Monoid::op(lval,\
    \ rval);\n  }\n\n  PersistentSegmentTree(size_t n_, size_t n0_, const node_ptr&\
    \ root_)\n      : n(n_), n0(n0_), root(root_) {}\n\n public:\n  PersistentSegmentTree(size_t\
    \ n_ = 0) : n(n_), root(new Node(Monoid::id)) {\n    n0 = 1;\n    while (n0 <\
    \ n) n0 <<= 1;\n  }\n\n  PersistentSegmentTree update(size_t i, value_t value,\
    \ bool change) {\n    assert(0 <= i && i < n);\n    node_ptr now(root);\n    node_ptr\
    \ newroot = std::make_shared<Node>(Monoid::id), cur(newroot);\n\n    size_t l\
    \ = 0, r = n0;\n    bool isok = true;\n    while (r - l > 1) {\n      size_t mid\
    \ = l + (r - l) / 2;\n      if (i < mid) {\n        if (isok && now->right) cur->right\
    \ = now->right;\n        cur->left = std::make_shared<Node>(Monoid::id, cur);\n\
    \        if (isok) {\n          if (!now->left)\n            isok = false;\n \
    \         else\n            now = now->left;\n        }\n        cur = cur->left;\n\
    \        r = mid;\n      } else {\n        if (isok && now->left) cur->left =\
    \ now->left;\n        cur->right = std::make_shared<Node>(Monoid::id, cur);\n\n\
    \        if (isok) {\n          if (!now->right)\n            isok = false;\n\
    \          else\n            now = now->right;\n        }\n        cur = cur->right;\n\
    \        l = mid;\n      }\n    }\n\n    if (change)\n      cur->val = value;\n\
    \    else\n      cur->val = Monoid::op((isok) ? now->val : Monoid::id, value);\n\
    \n    while (cur->par.lock()) {\n      cur = cur->par.lock();\n      cur->val\
    \ = Monoid::op((cur->left) ? cur->left->val : Monoid::id,\n                  \
    \          (cur->right) ? cur->right->val : Monoid::id);\n    }\n\n    return\
    \ PersistentSegmentTree(n, n0, newroot);\n  }\n\n  value_t fold(size_t l, size_t\
    \ r) {\n    assert(0 <= l && l <= r && r <= n);\n    return fold(l, r, root, 0,\
    \ n0);\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <memory>\n\ntemplate <typename\
    \ Monoid>\nclass PersistentSegmentTree {\n public:\n  using value_t = typename\
    \ Monoid::value_t;\n  using size_t = std::size_t;\n\n private:\n  struct Node\
    \ {\n    value_t val;\n    std::shared_ptr<Node> left, right;\n    std::weak_ptr<Node>\
    \ par;\n    Node(value_t val_, std::shared_ptr<Node> par_ = nullptr)\n       \
    \ : val(val_), left(), right(), par(par_) {}\n  };\n\n  using node_ptr = std::shared_ptr<Node>;\n\
    \  size_t n, n0;\n  node_ptr root;\n\n  value_t fold(size_t a, size_t b, const\
    \ node_ptr& now, size_t l, size_t r) {\n    if (a <= l && r <= b) return now->val;\n\
    \    if (b <= l || r <= a) return Monoid::id;\n    value_t lval =\n        (now->left)\
    \ ? fold(a, b, now->left, l, l + (r - l) / 2) : Monoid::id;\n    value_t rval\
    \ =\n        (now->right) ? fold(a, b, now->right, l + (r - l) / 2, r) : Monoid::id;\n\
    \    return Monoid::op(lval, rval);\n  }\n\n  PersistentSegmentTree(size_t n_,\
    \ size_t n0_, const node_ptr& root_)\n      : n(n_), n0(n0_), root(root_) {}\n\
    \n public:\n  PersistentSegmentTree(size_t n_ = 0) : n(n_), root(new Node(Monoid::id))\
    \ {\n    n0 = 1;\n    while (n0 < n) n0 <<= 1;\n  }\n\n  PersistentSegmentTree\
    \ update(size_t i, value_t value, bool change) {\n    assert(0 <= i && i < n);\n\
    \    node_ptr now(root);\n    node_ptr newroot = std::make_shared<Node>(Monoid::id),\
    \ cur(newroot);\n\n    size_t l = 0, r = n0;\n    bool isok = true;\n    while\
    \ (r - l > 1) {\n      size_t mid = l + (r - l) / 2;\n      if (i < mid) {\n \
    \       if (isok && now->right) cur->right = now->right;\n        cur->left =\
    \ std::make_shared<Node>(Monoid::id, cur);\n        if (isok) {\n          if\
    \ (!now->left)\n            isok = false;\n          else\n            now = now->left;\n\
    \        }\n        cur = cur->left;\n        r = mid;\n      } else {\n     \
    \   if (isok && now->left) cur->left = now->left;\n        cur->right = std::make_shared<Node>(Monoid::id,\
    \ cur);\n\n        if (isok) {\n          if (!now->right)\n            isok =\
    \ false;\n          else\n            now = now->right;\n        }\n        cur\
    \ = cur->right;\n        l = mid;\n      }\n    }\n\n    if (change)\n      cur->val\
    \ = value;\n    else\n      cur->val = Monoid::op((isok) ? now->val : Monoid::id,\
    \ value);\n\n    while (cur->par.lock()) {\n      cur = cur->par.lock();\n   \
    \   cur->val = Monoid::op((cur->left) ? cur->left->val : Monoid::id,\n       \
    \                     (cur->right) ? cur->right->val : Monoid::id);\n    }\n\n\
    \    return PersistentSegmentTree(n, n0, newroot);\n  }\n\n  value_t fold(size_t\
    \ l, size_t r) {\n    assert(0 <= l && l <= r && r <= n);\n    return fold(l,\
    \ r, root, 0, n0);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/SegmentTree/PersistentSegmentTree.hpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/PersistentSegmentTree.test.cpp
documentation_of: lib/SegmentTree/PersistentSegmentTree.hpp
layout: document
redirect_from:
- /library/lib/SegmentTree/PersistentSegmentTree.hpp
- /library/lib/SegmentTree/PersistentSegmentTree.hpp.html
title: lib/SegmentTree/PersistentSegmentTree.hpp
---
