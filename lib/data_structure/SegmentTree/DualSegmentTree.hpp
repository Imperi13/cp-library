#pragma once

#include <cassert>
#include <memory>

// commutative Monoid
// type value_t
// static value_t id
// static (value_t,value_t)->value_t op

template <typename Monoid>
class DualSegmentTree {
 public:
  using value_t = typename Monoid::value_t;
  using size_t = std::size_t;

 private:
  struct Node {
    value_t val;
    std::shared_ptr<Node> left, right;
    Node(value_t val_) : val(val_), left(), right() {}
  };

  using node_ptr = std::shared_ptr<Node>;

  size_t n, n0;
  node_ptr root;

  void update(size_t a, size_t b, value_t value, const node_ptr& now, size_t l,
              size_t r) {
    if (a <= l && r <= b) {
      now->val = Monoid::op(now->val, value);
      return;
    }
    if (b <= l || r <= a) return;

    if (!now->left) now->left = std::make_shared<Node>(Monoid::id);
    if (!now->right) now->right = std::make_shared<Node>(Monoid::id);
    update(a, b, value, now->left, l, l + (r - l) / 2);
    update(a, b, value, now->right, l + (r - l) / 2, r);
  }

 public:
  DualSegmentTree(size_t n_) : n(n_), root(new Node(Monoid::id)) {
    n0 = 1;
    while (n0 < n) n0 <<= 1;
  }

  void update(size_t l, size_t r, value_t value) {
    assert(0 <= l && l <= r && r <= n);
    update(l, r, value, root, 0, n0);
  }

  value_t at(size_t i) {
    assert(0 <= i && i < n);
    node_ptr now(root);
    value_t ret = now->val;

    size_t l = 0, r = n0;
    while (r - l > 1) {
      size_t mid = l + (r - l) / 2;
      if (i < mid) {
        if (!now->left) break;
        now = now->left;
        r = mid;
      } else {
        if (!now->right) break;
        now = now->right;
        l = mid;
      }
      ret = Monoid::op(ret, now->val);
    }
    return ret;
  }
};