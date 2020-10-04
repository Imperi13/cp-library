---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/RBST_Multiset.hpp\"\n\n#include <memory>\n#include <utility>\n\
    #include <vector>\n\ntemplate <typename T, typename Comp = std::less<T>>\nclass\
    \ RBST_Multiset {\n public:\n  using value_t = T;\n  using size_t = std::size_t;\n\
    \n private:\n  unsigned int rnd() {\n    static unsigned int x(123456789), y(362436069),\
    \ z(521288629), w(88675123);\n    unsigned int t = (x ^ (x << 11));\n    x = y;\n\
    \    y = z;\n    z = w;\n    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  }\n\
    \n  struct Node {\n    value_t val;\n    size_t cnt;\n    std::shared_ptr<Node>\
    \ left, right;\n    Node(value_t val_) : val(val_), cnt(1), left(), right() {}\n\
    \  };\n\n  using node_ptr = std::shared_ptr<Node>;\n\n  Comp comp;\n  bool equal(const\
    \ value_t& a, const value_t& b) {\n    return (!comp(a, b) && !comp(b, a));\n\
    \  }\n\n  node_ptr root;\n\n  size_t count(const node_ptr& t) { return t ? t->cnt\
    \ : 0; }\n\n  node_ptr update(node_ptr t) {\n    if (!t) return t;\n    t->cnt\
    \ = count(t->left) + count(t->right) + 1;\n    return t;\n  }\n\n  node_ptr merge(node_ptr\
    \ l, node_ptr r) {\n    if (!l || !r) return l ? l : r;\n\n    if (rnd() % (count(l)\
    \ + count(r)) < count(l)) {\n      l->right = merge(l->right, r);\n      return\
    \ update(l);\n    } else {\n      r->left = merge(l, r->left);\n      return update(r);\n\
    \    }\n  }\n\n  std::pair<node_ptr, node_ptr> split(node_ptr t, size_t k) {\n\
    \    if (!t) return std::make_pair(t, t);\n\n    if (k <= count(t->left)) {\n\
    \      auto temp = split(t->left, k);\n      t->left = temp.second;\n      return\
    \ std::make_pair(temp.first, update(t));\n    } else {\n      auto temp = split(t->right,\
    \ k - count(t->left) - 1);\n      t->right = temp.first;\n      return std::make_pair(update(t),\
    \ temp.second);\n    }\n  }\n\n  bool find(const node_ptr& t, const value_t& value)\
    \ {\n    if (!t) return false;\n    if (equal(t->val, value)) return true;\n \
    \   if (comp(value, t->val))\n      return find(t->left, value);\n    else\n \
    \     return find(t->right, value);\n  }\n\n  size_t lower_bound(const node_ptr&\
    \ t, const value_t& value) {\n    if (!t) return 0;\n    if (comp(value, t->val)\
    \ || equal(value, t->val))\n      return lower_bound(t->left, value);\n    else\n\
    \      return lower_bound(t->right, value) + count(t->left) + 1;\n  }\n  size_t\
    \ upper_bound(const node_ptr& t, const value_t& value) {\n    if (!t) return 0;\n\
    \    if (comp(value, t->val))\n      return upper_bound(t->left, value);\n   \
    \ else\n      return upper_bound(t->right, value) + count(t->left) + 1;\n  }\n\
    \  void insert(node_ptr& t, node_ptr newnode, size_t k) {\n    auto temp = split(t,\
    \ k);\n    t = merge(merge(temp.first, newnode), temp.second);\n  }\n  void erase(node_ptr&\
    \ t, size_t k) {\n    auto temp = split(t, k + 1);\n    auto temp2 = split(temp.first,\
    \ k);\n    t = merge(temp2.first, temp.second);\n  }\n  value_t topk(const node_ptr&\
    \ t, size_t k) {\n    if (count(t->left) == k) return t->val;\n    if (k < count(t->left))\n\
    \      return topk(t->left, k);\n    else\n      return topk(t->right, k - count(t->left)\
    \ - 1);\n  }\n\n public:\n  RBST_Multiset() : comp(), root() {}\n  RBST_Multiset(Comp\
    \ comp_) : comp(comp_), root() {}\n\n  size_t size() { return count(root); }\n\
    \  bool find(const value_t& value) { return find(root, value); }\n  size_t lower_bound(const\
    \ value_t& value) { return lower_bound(root, value); }\n  size_t upper_bound(const\
    \ value_t& value) { return upper_bound(root, value); }\n  void insert(const value_t&\
    \ value) {\n    insert(root, std::make_shared<Node>(value), lower_bound(value));\n\
    \  }\n\n  void erase(const value_t& value) {\n    if (!find(value)) return;\n\
    \    erase(root, lower_bound(value));\n  }\n\n  value_t topk(size_t l, size_t\
    \ r, size_t k) {\n    assert(0 <= k && k < r - l);\n    auto temp = split(root,\
    \ r);\n    auto temp2 = split(temp.first, l);\n    value_t ret = topk(temp2.second,\
    \ k);\n    root = merge(merge(temp2.first, temp2.second), temp.second);\n    return\n\
    \  }\n\n  value_t topk(size_t k) { return topk(root, k); }\n};\n"
  code: "#pragma once\n\n#include <memory>\n#include <utility>\n#include <vector>\n\
    \ntemplate <typename T, typename Comp = std::less<T>>\nclass RBST_Multiset {\n\
    \ public:\n  using value_t = T;\n  using size_t = std::size_t;\n\n private:\n\
    \  unsigned int rnd() {\n    static unsigned int x(123456789), y(362436069), z(521288629),\
    \ w(88675123);\n    unsigned int t = (x ^ (x << 11));\n    x = y;\n    y = z;\n\
    \    z = w;\n    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  }\n\n  struct\
    \ Node {\n    value_t val;\n    size_t cnt;\n    std::shared_ptr<Node> left, right;\n\
    \    Node(value_t val_) : val(val_), cnt(1), left(), right() {}\n  };\n\n  using\
    \ node_ptr = std::shared_ptr<Node>;\n\n  Comp comp;\n  bool equal(const value_t&\
    \ a, const value_t& b) {\n    return (!comp(a, b) && !comp(b, a));\n  }\n\n  node_ptr\
    \ root;\n\n  size_t count(const node_ptr& t) { return t ? t->cnt : 0; }\n\n  node_ptr\
    \ update(node_ptr t) {\n    if (!t) return t;\n    t->cnt = count(t->left) + count(t->right)\
    \ + 1;\n    return t;\n  }\n\n  node_ptr merge(node_ptr l, node_ptr r) {\n   \
    \ if (!l || !r) return l ? l : r;\n\n    if (rnd() % (count(l) + count(r)) < count(l))\
    \ {\n      l->right = merge(l->right, r);\n      return update(l);\n    } else\
    \ {\n      r->left = merge(l, r->left);\n      return update(r);\n    }\n  }\n\
    \n  std::pair<node_ptr, node_ptr> split(node_ptr t, size_t k) {\n    if (!t) return\
    \ std::make_pair(t, t);\n\n    if (k <= count(t->left)) {\n      auto temp = split(t->left,\
    \ k);\n      t->left = temp.second;\n      return std::make_pair(temp.first, update(t));\n\
    \    } else {\n      auto temp = split(t->right, k - count(t->left) - 1);\n  \
    \    t->right = temp.first;\n      return std::make_pair(update(t), temp.second);\n\
    \    }\n  }\n\n  bool find(const node_ptr& t, const value_t& value) {\n    if\
    \ (!t) return false;\n    if (equal(t->val, value)) return true;\n    if (comp(value,\
    \ t->val))\n      return find(t->left, value);\n    else\n      return find(t->right,\
    \ value);\n  }\n\n  size_t lower_bound(const node_ptr& t, const value_t& value)\
    \ {\n    if (!t) return 0;\n    if (comp(value, t->val) || equal(value, t->val))\n\
    \      return lower_bound(t->left, value);\n    else\n      return lower_bound(t->right,\
    \ value) + count(t->left) + 1;\n  }\n  size_t upper_bound(const node_ptr& t, const\
    \ value_t& value) {\n    if (!t) return 0;\n    if (comp(value, t->val))\n   \
    \   return upper_bound(t->left, value);\n    else\n      return upper_bound(t->right,\
    \ value) + count(t->left) + 1;\n  }\n  void insert(node_ptr& t, node_ptr newnode,\
    \ size_t k) {\n    auto temp = split(t, k);\n    t = merge(merge(temp.first, newnode),\
    \ temp.second);\n  }\n  void erase(node_ptr& t, size_t k) {\n    auto temp = split(t,\
    \ k + 1);\n    auto temp2 = split(temp.first, k);\n    t = merge(temp2.first,\
    \ temp.second);\n  }\n  value_t topk(const node_ptr& t, size_t k) {\n    if (count(t->left)\
    \ == k) return t->val;\n    if (k < count(t->left))\n      return topk(t->left,\
    \ k);\n    else\n      return topk(t->right, k - count(t->left) - 1);\n  }\n\n\
    \ public:\n  RBST_Multiset() : comp(), root() {}\n  RBST_Multiset(Comp comp_)\
    \ : comp(comp_), root() {}\n\n  size_t size() { return count(root); }\n  bool\
    \ find(const value_t& value) { return find(root, value); }\n  size_t lower_bound(const\
    \ value_t& value) { return lower_bound(root, value); }\n  size_t upper_bound(const\
    \ value_t& value) { return upper_bound(root, value); }\n  void insert(const value_t&\
    \ value) {\n    insert(root, std::make_shared<Node>(value), lower_bound(value));\n\
    \  }\n\n  void erase(const value_t& value) {\n    if (!find(value)) return;\n\
    \    erase(root, lower_bound(value));\n  }\n\n  value_t topk(size_t l, size_t\
    \ r, size_t k) {\n    assert(0 <= k && k < r - l);\n    auto temp = split(root,\
    \ r);\n    auto temp2 = split(temp.first, l);\n    value_t ret = topk(temp2.second,\
    \ k);\n    root = merge(merge(temp2.first, temp2.second), temp.second);\n    return\n\
    \  }\n\n  value_t topk(size_t k) { return topk(root, k); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/RBST_Multiset.hpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/RBST_Multiset.hpp
layout: document
redirect_from:
- /library/lib/RBST_Multiset.hpp
- /library/lib/RBST_Multiset.hpp.html
title: lib/RBST_Multiset.hpp
---
