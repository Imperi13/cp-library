---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/RBST_Seq.test.cpp
    title: test/RBST_Seq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/RBST_Seq.hpp\"\n\n#include <memory>\n#include <utility>\n\
    #include <vector>\n\ntemplate <typename Monoid>\nclass RBST_Seq {\n public:\n\
    \  using value_t = typename Monoid::value_t;\n  using size_t = std::size_t;\n\n\
    \ private:\n  unsigned int rnd() {\n    static unsigned int x(123456789), y(362436069),\
    \ z(521288629), w(88675123);\n    unsigned int t = (x ^ (x << 11));\n    x = y;\n\
    \    y = z;\n    z = w;\n    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  }\n\
    \n  struct Node {\n    value_t val, sum;\n    size_t cnt;\n    std::shared_ptr<Node>\
    \ left, right;\n    Node(value_t val_) : val(val_), sum(val_), cnt(1), left(),\
    \ right() {}\n  };\n\n  using node_ptr = std::shared_ptr<Node>;\n  node_ptr root;\n\
    \n  value_t calc(const node_ptr& t) { return t ? t->sum : Monoid::id; }\n  size_t\
    \ count(const node_ptr& t) { return t ? t->cnt : 0; }\n\n  node_ptr update(node_ptr\
    \ t) {\n    if (!t) return t;\n    t->sum = Monoid::op(Monoid::op(calc(t->left),\
    \ t->val), calc(t->right));\n    t->cnt = count(t->left) + count(t->right) + 1;\n\
    \    return t;\n  }\n\n  node_ptr merge(node_ptr l, node_ptr r) {\n    if (!l\
    \ || !r) return l ? l : r;\n\n    if (rnd() % (count(l) + count(r)) < count(l))\
    \ {\n      l->right = merge(l->right, r);\n      return update(l);\n    } else\
    \ {\n      r->left = merge(l, r->left);\n      return update(r);\n    }\n  }\n\
    \n  std::pair<node_ptr, node_ptr> split(node_ptr t, size_t k) {\n    if (!t) return\
    \ std::make_pair(t, t);\n\n    if (k <= count(t->left)) {\n      auto temp = split(t->left,\
    \ k);\n      t->left = temp.second;\n      return std::make_pair(temp.first, update(t));\n\
    \    } else {\n      auto temp = split(t->right, k - count(t->left) - 1);\n  \
    \    t->right = temp.first;\n      return std::make_pair(update(t), temp.second);\n\
    \    }\n  }\n\n  void insert(node_ptr& t, node_ptr newnode, size_t k) {\n    auto\
    \ temp = split(t, k);\n    t = merge(merge(temp.first, newnode), temp.second);\n\
    \  }\n\n  void erase(node_ptr& t, size_t k) {\n    auto temp = split(t, k + 1);\n\
    \    auto temp2 = split(temp.first, k);\n    t = merge(temp2.first, temp.second);\n\
    \  }\n\n  void build(node_ptr& t, const std::vector<value_t>& val_, size_t l,\n\
    \             size_t r) {\n    if (l == r) {\n      t = nullptr;\n      return;\n\
    \    }\n    if (r == l + 1) {\n      t = std::make_shared<Node>(val_[l]);\n  \
    \    return;\n    }\n\n    size_t mid = l + (r - l) / 2;\n    t = std::make_shared<Node>(val_[mid]);\n\
    \    build(t->left, val_, l, mid);\n    build(t->right, val_, mid + 1, r);\n \
    \   update(t);\n  }\n\n  void copy_dfs(node_ptr& now, const node_ptr& copy_from)\
    \ {\n    now->val = copy_from->val;\n    now->sum = copy_from->sum;\n    now->cnt\
    \ = copy_from->cnt;\n    if (copy_from->left) {\n      now->left = std::make_shared<Node>(Monoid::id);\n\
    \      copy_dfs(now->left, copy_from->left);\n    }\n    if (copy_from->right)\
    \ {\n      now->right = std::make_shared<Node>(Monoid::id);\n      copy_dfs(now->right,\
    \ copy_from->right);\n    }\n  }\n\n  RBST_Seq(const node_ptr& t) : root(t) {}\n\
    \n public:\n  RBST_Seq() : root() {}\n  RBST_Seq(const std::vector<value_t>& seq_)\
    \ : root() {\n    build(root, seq_, 0, seq_.size());\n  }\n  RBST_Seq(const RBST_Seq&\
    \ from) {\n    root = nullptr;\n    if (from.root) {\n      root = std::make_shared<Node>(Monoid::id);\n\
    \      copy_dfs(root, from.root);\n    }\n  }\n  RBST_Seq& operator=(const RBST_Seq&\
    \ from) {\n    root = nullptr;\n    if (from.root) {\n      root = std::make_shared<Node>(Monoid::id);\n\
    \      copy_dfs(root, from.root);\n    }\n  }\n  RBST_Seq(RBST_Seq&&) = default;\n\
    \  RBST_Seq& operator=(RBST_Seq&&) = default;\n\n  size_t size() { return count(root);\
    \ }\n  void insert(size_t k, const value_t& value) {\n    insert(root, std::make_shared<Node>(value),\
    \ k);\n  }\n  void erase(size_t k) { erase(root, k); }\n\n  RBST_Seq split(size_t\
    \ l, size_t r) {\n    assert(0 <= l && l <= r && r <= size());\n    auto tmp =\
    \ split(root, r);\n    auto tmp2 = split(tmp.first, l);\n    root = merge(tmp2.first,\
    \ tmp.second);\n    return RBST_Seq(tmp2.second);\n  }\n\n  void insert(size_t\
    \ pos, RBST_Seq seq) {\n    assert(0 <= pos && pos <= size());\n    auto tmp =\
    \ split(root, pos);\n    tmp.first = merge(tmp.first, seq.root);\n    root = merge(tmp.first,\
    \ tmp.second);\n    seq.root = nullptr;\n  }\n\n  value_t fold_all() { return\
    \ calc(root); }\n  value_t fold(size_t l, size_t r) {\n    auto temp = split(root,\
    \ r);\n    auto temp2 = split(temp.first, l);\n    value_t ret = calc(temp2.second);\n\
    \    root = merge(merge(temp2.first, temp2.second), temp.second);\n\n    return\
    \ ret;\n  }\n};\n"
  code: "#pragma once\n\n#include <memory>\n#include <utility>\n#include <vector>\n\
    \ntemplate <typename Monoid>\nclass RBST_Seq {\n public:\n  using value_t = typename\
    \ Monoid::value_t;\n  using size_t = std::size_t;\n\n private:\n  unsigned int\
    \ rnd() {\n    static unsigned int x(123456789), y(362436069), z(521288629), w(88675123);\n\
    \    unsigned int t = (x ^ (x << 11));\n    x = y;\n    y = z;\n    z = w;\n \
    \   return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  }\n\n  struct Node {\n   \
    \ value_t val, sum;\n    size_t cnt;\n    std::shared_ptr<Node> left, right;\n\
    \    Node(value_t val_) : val(val_), sum(val_), cnt(1), left(), right() {}\n \
    \ };\n\n  using node_ptr = std::shared_ptr<Node>;\n  node_ptr root;\n\n  value_t\
    \ calc(const node_ptr& t) { return t ? t->sum : Monoid::id; }\n  size_t count(const\
    \ node_ptr& t) { return t ? t->cnt : 0; }\n\n  node_ptr update(node_ptr t) {\n\
    \    if (!t) return t;\n    t->sum = Monoid::op(Monoid::op(calc(t->left), t->val),\
    \ calc(t->right));\n    t->cnt = count(t->left) + count(t->right) + 1;\n    return\
    \ t;\n  }\n\n  node_ptr merge(node_ptr l, node_ptr r) {\n    if (!l || !r) return\
    \ l ? l : r;\n\n    if (rnd() % (count(l) + count(r)) < count(l)) {\n      l->right\
    \ = merge(l->right, r);\n      return update(l);\n    } else {\n      r->left\
    \ = merge(l, r->left);\n      return update(r);\n    }\n  }\n\n  std::pair<node_ptr,\
    \ node_ptr> split(node_ptr t, size_t k) {\n    if (!t) return std::make_pair(t,\
    \ t);\n\n    if (k <= count(t->left)) {\n      auto temp = split(t->left, k);\n\
    \      t->left = temp.second;\n      return std::make_pair(temp.first, update(t));\n\
    \    } else {\n      auto temp = split(t->right, k - count(t->left) - 1);\n  \
    \    t->right = temp.first;\n      return std::make_pair(update(t), temp.second);\n\
    \    }\n  }\n\n  void insert(node_ptr& t, node_ptr newnode, size_t k) {\n    auto\
    \ temp = split(t, k);\n    t = merge(merge(temp.first, newnode), temp.second);\n\
    \  }\n\n  void erase(node_ptr& t, size_t k) {\n    auto temp = split(t, k + 1);\n\
    \    auto temp2 = split(temp.first, k);\n    t = merge(temp2.first, temp.second);\n\
    \  }\n\n  void build(node_ptr& t, const std::vector<value_t>& val_, size_t l,\n\
    \             size_t r) {\n    if (l == r) {\n      t = nullptr;\n      return;\n\
    \    }\n    if (r == l + 1) {\n      t = std::make_shared<Node>(val_[l]);\n  \
    \    return;\n    }\n\n    size_t mid = l + (r - l) / 2;\n    t = std::make_shared<Node>(val_[mid]);\n\
    \    build(t->left, val_, l, mid);\n    build(t->right, val_, mid + 1, r);\n \
    \   update(t);\n  }\n\n  void copy_dfs(node_ptr& now, const node_ptr& copy_from)\
    \ {\n    now->val = copy_from->val;\n    now->sum = copy_from->sum;\n    now->cnt\
    \ = copy_from->cnt;\n    if (copy_from->left) {\n      now->left = std::make_shared<Node>(Monoid::id);\n\
    \      copy_dfs(now->left, copy_from->left);\n    }\n    if (copy_from->right)\
    \ {\n      now->right = std::make_shared<Node>(Monoid::id);\n      copy_dfs(now->right,\
    \ copy_from->right);\n    }\n  }\n\n  RBST_Seq(const node_ptr& t) : root(t) {}\n\
    \n public:\n  RBST_Seq() : root() {}\n  RBST_Seq(const std::vector<value_t>& seq_)\
    \ : root() {\n    build(root, seq_, 0, seq_.size());\n  }\n  RBST_Seq(const RBST_Seq&\
    \ from) {\n    root = nullptr;\n    if (from.root) {\n      root = std::make_shared<Node>(Monoid::id);\n\
    \      copy_dfs(root, from.root);\n    }\n  }\n  RBST_Seq& operator=(const RBST_Seq&\
    \ from) {\n    root = nullptr;\n    if (from.root) {\n      root = std::make_shared<Node>(Monoid::id);\n\
    \      copy_dfs(root, from.root);\n    }\n  }\n  RBST_Seq(RBST_Seq&&) = default;\n\
    \  RBST_Seq& operator=(RBST_Seq&&) = default;\n\n  size_t size() { return count(root);\
    \ }\n  void insert(size_t k, const value_t& value) {\n    insert(root, std::make_shared<Node>(value),\
    \ k);\n  }\n  void erase(size_t k) { erase(root, k); }\n\n  RBST_Seq split(size_t\
    \ l, size_t r) {\n    assert(0 <= l && l <= r && r <= size());\n    auto tmp =\
    \ split(root, r);\n    auto tmp2 = split(tmp.first, l);\n    root = merge(tmp2.first,\
    \ tmp.second);\n    return RBST_Seq(tmp2.second);\n  }\n\n  void insert(size_t\
    \ pos, RBST_Seq seq) {\n    assert(0 <= pos && pos <= size());\n    auto tmp =\
    \ split(root, pos);\n    tmp.first = merge(tmp.first, seq.root);\n    root = merge(tmp.first,\
    \ tmp.second);\n    seq.root = nullptr;\n  }\n\n  value_t fold_all() { return\
    \ calc(root); }\n  value_t fold(size_t l, size_t r) {\n    auto temp = split(root,\
    \ r);\n    auto temp2 = split(temp.first, l);\n    value_t ret = calc(temp2.second);\n\
    \    root = merge(merge(temp2.first, temp2.second), temp.second);\n\n    return\
    \ ret;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/RBST_Seq.hpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/RBST_Seq.test.cpp
documentation_of: lib/RBST_Seq.hpp
layout: document
redirect_from:
- /library/lib/RBST_Seq.hpp
- /library/lib/RBST_Seq.hpp.html
title: lib/RBST_Seq.hpp
---
