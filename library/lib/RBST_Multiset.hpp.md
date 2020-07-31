---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: lib/RBST_Multiset.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/RBST_Multiset.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-31 15:44:20+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <memory>
#include <utility>
#include <vector>

template <typename T, typename Comp = std::less<T>>
class RBST_Multiset {
 public:
  using value_t = T;
  using size_t = std::size_t;

 private:
  unsigned int rnd() {
    static unsigned int x(123456789), y(362436069), z(521288629), w(88675123);
    unsigned int t = (x ^ (x << 11));
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }

  struct Node {
    value_t val;
    size_t cnt;
    std::shared_ptr<Node> left, right;
    Node(value_t val_) : val(val_), cnt(1), left(), right() {}
  };

  using node_ptr = std::shared_ptr<Node>;

  Comp comp;
  bool equal(const value_t& a, const value_t& b) {
    return (!comp(a, b) && !comp(b, a));
  }

  node_ptr root;

  size_t count(const node_ptr& t) { return t ? t->cnt : 0; }

  node_ptr update(node_ptr t) {
    if (!t) return t;
    t->cnt = count(t->left) + count(t->right) + 1;
    return t;
  }

  node_ptr merge(node_ptr l, node_ptr r) {
    if (!l || !r) return l ? l : r;

    if (rnd() % (count(l) + count(r)) < count(l)) {
      l->right = merge(l->right, r);
      return update(l);
    } else {
      r->left = merge(l, r->left);
      return update(r);
    }
  }

  std::pair<node_ptr, node_ptr> split(node_ptr t, size_t k) {
    if (!t) return std::make_pair(t, t);

    if (k <= count(t->left)) {
      auto temp = split(t->left, k);
      t->left = temp.second;
      return std::make_pair(temp.first, update(t));
    } else {
      auto temp = split(t->right, k - count(t->left) - 1);
      t->right = temp.first;
      return std::make_pair(update(t), temp.second);
    }
  }

  bool find(const node_ptr& t, const value_t& value) {
    if (!t) return false;
    if (equal(t->val, value)) return true;
    if (comp(value, t->val))
      return find(t->left, value);
    else
      return find(t->right, value);
  }

  size_t lower_bound(const node_ptr& t, const value_t& value) {
    if (!t) return 0;
    if (comp(value, t->val) || equal(value, t->val))
      return lower_bound(t->left, value);
    else
      return lower_bound(t->right, value) + count(t->left) + 1;
  }
  size_t upper_bound(const node_ptr& t, const value_t& value) {
    if (!t) return 0;
    if (comp(value, t->val))
      return upper_bound(t->left, value);
    else
      return upper_bound(t->right, value) + count(t->left) + 1;
  }
  void insert(node_ptr& t, node_ptr newnode, size_t k) {
    auto temp = split(t, k);
    t = merge(merge(temp.first, newnode), temp.second);
  }
  void erase(node_ptr& t, size_t k) {
    auto temp = split(t, k + 1);
    auto temp2 = split(temp.first, k);
    t = merge(temp2.first, temp.second);
  }
  value_t topk(const node_ptr& t, size_t k) {
    if (count(t->left) == k) return t->val;
    if (k < count(t->left))
      return topk(t->left, k);
    else
      return topk(t->right, k - count(t->left) - 1);
  }

 public:
  RBST_Multiset() : comp(), root() {}
  RBST_Multiset(Comp comp_) : comp(comp_), root() {}

  size_t size() { return count(root); }
  bool find(const value_t& value) { return find(root, value); }
  size_t lower_bound(const value_t& value) { return lower_bound(root, value); }
  size_t upper_bound(const value_t& value) { return upper_bound(root, value); }
  void insert(const value_t& value) {
    insert(root, std::make_shared<Node>(value), lower_bound(value));
  }

  void erase(const value_t& value) {
    if (!find(value)) return;
    erase(root, lower_bound(value));
  }

  value_t topk(size_t l, size_t r, size_t k) {
    assert(0 <= k && k < r - l);
    auto temp = split(root, r);
    auto temp2 = split(temp.first, l);
    value_t ret = topk(temp2.second, k);
    root = merge(merge(temp2.first, temp2.second), temp.second);
    return
  }

  value_t topk(size_t k) { return topk(root, k); }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/RBST_Multiset.hpp"

#include <memory>
#include <utility>
#include <vector>

template <typename T, typename Comp = std::less<T>>
class RBST_Multiset {
 public:
  using value_t = T;
  using size_t = std::size_t;

 private:
  unsigned int rnd() {
    static unsigned int x(123456789), y(362436069), z(521288629), w(88675123);
    unsigned int t = (x ^ (x << 11));
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }

  struct Node {
    value_t val;
    size_t cnt;
    std::shared_ptr<Node> left, right;
    Node(value_t val_) : val(val_), cnt(1), left(), right() {}
  };

  using node_ptr = std::shared_ptr<Node>;

  Comp comp;
  bool equal(const value_t& a, const value_t& b) {
    return (!comp(a, b) && !comp(b, a));
  }

  node_ptr root;

  size_t count(const node_ptr& t) { return t ? t->cnt : 0; }

  node_ptr update(node_ptr t) {
    if (!t) return t;
    t->cnt = count(t->left) + count(t->right) + 1;
    return t;
  }

  node_ptr merge(node_ptr l, node_ptr r) {
    if (!l || !r) return l ? l : r;

    if (rnd() % (count(l) + count(r)) < count(l)) {
      l->right = merge(l->right, r);
      return update(l);
    } else {
      r->left = merge(l, r->left);
      return update(r);
    }
  }

  std::pair<node_ptr, node_ptr> split(node_ptr t, size_t k) {
    if (!t) return std::make_pair(t, t);

    if (k <= count(t->left)) {
      auto temp = split(t->left, k);
      t->left = temp.second;
      return std::make_pair(temp.first, update(t));
    } else {
      auto temp = split(t->right, k - count(t->left) - 1);
      t->right = temp.first;
      return std::make_pair(update(t), temp.second);
    }
  }

  bool find(const node_ptr& t, const value_t& value) {
    if (!t) return false;
    if (equal(t->val, value)) return true;
    if (comp(value, t->val))
      return find(t->left, value);
    else
      return find(t->right, value);
  }

  size_t lower_bound(const node_ptr& t, const value_t& value) {
    if (!t) return 0;
    if (comp(value, t->val) || equal(value, t->val))
      return lower_bound(t->left, value);
    else
      return lower_bound(t->right, value) + count(t->left) + 1;
  }
  size_t upper_bound(const node_ptr& t, const value_t& value) {
    if (!t) return 0;
    if (comp(value, t->val))
      return upper_bound(t->left, value);
    else
      return upper_bound(t->right, value) + count(t->left) + 1;
  }
  void insert(node_ptr& t, node_ptr newnode, size_t k) {
    auto temp = split(t, k);
    t = merge(merge(temp.first, newnode), temp.second);
  }
  void erase(node_ptr& t, size_t k) {
    auto temp = split(t, k + 1);
    auto temp2 = split(temp.first, k);
    t = merge(temp2.first, temp.second);
  }
  value_t topk(const node_ptr& t, size_t k) {
    if (count(t->left) == k) return t->val;
    if (k < count(t->left))
      return topk(t->left, k);
    else
      return topk(t->right, k - count(t->left) - 1);
  }

 public:
  RBST_Multiset() : comp(), root() {}
  RBST_Multiset(Comp comp_) : comp(comp_), root() {}

  size_t size() { return count(root); }
  bool find(const value_t& value) { return find(root, value); }
  size_t lower_bound(const value_t& value) { return lower_bound(root, value); }
  size_t upper_bound(const value_t& value) { return upper_bound(root, value); }
  void insert(const value_t& value) {
    insert(root, std::make_shared<Node>(value), lower_bound(value));
  }

  void erase(const value_t& value) {
    if (!find(value)) return;
    erase(root, lower_bound(value));
  }

  value_t topk(size_t l, size_t r, size_t k) {
    assert(0 <= k && k < r - l);
    auto temp = split(root, r);
    auto temp2 = split(temp.first, l);
    value_t ret = topk(temp2.second, k);
    root = merge(merge(temp2.first, temp2.second), temp.second);
    return
  }

  value_t topk(size_t k) { return topk(root, k); }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

