#pragma once

#include <limits>
#include <type_traits>

template <typename Int, Int MAX = std::numeric_limits<Int>::max()>
class LiChaoSegmentTree {
  static_assert(std::is_integral_v<Int>, "Int must be integer");

 public:
  using value_t = Int;
  using size_t = std::size_t;

 private:
  struct Line {
    value_t ax, b;
    value_t value(value_t x) { return ax * x + b; }
    Line() : ax(0), b(MAX) {}
    Line(value_t ax_, value_t b_) : ax(ax_), b(b_) {}
  };

  struct Node;
  using node_ptr = Node*;

  struct Node {
    node_ptr left, right;
    Line line;
    Node() : left(), right(), line() {}
    ~Node() {
      if (left) delete left;
      if (right) delete right;
      left = nullptr;
      right = nullptr;
    }
  };

  value_t l0, r0, lx, rx;
  node_ptr root;

  void eval(Line f, value_t a, value_t b, node_ptr now, value_t l, value_t r) {
    if (a == b) return;
    if (r <= a || b <= l) return;
    if (f.value(l) >= now->line.value(l) &&
        f.value(r - 1) >= now->line.value(r - 1))
      return;
    if (r - l == 1 && f.value(l) > now->line.value(l)) {
      std::swap(f, now->line);
      return;
    }

    value_t mid = l + (r - l) /2;
    if (a <= l && r <= b) {
      if (f.value(l) < now->line.value(l) &&
          f.value(r - 1) < now->line.value(r - 1)) {
        std::swap(f, now->line);
        return;
      }
      if (f.value(mid - 1) < now->line.value(mid - 1)) std::swap(f, now->line);
      if (f.value(l) < now->line.value(l)) {
        if (!now->left) now->left = new Node();
        eval(f, a, b, now->left, l, mid);
      } else {
        if (!now->right) now->right = new Node();
        eval(f, a, b, now->right, mid, r);
      }
    } else {
      if (mid > a && b > l) {
        if (!now->left) now->left = new Node();
        eval(f, a, b, now->left, l, mid);
      }
      if (r > a && b > mid) {
        if (!now->right) now->right = new Node();
        eval(f, a, b, now->right, mid, r);
      }
    }
  }

 public:
  LiChaoSegmentTree(value_t l, value_t r)
      : l0(l), r0(r), lx(l), root(new Node()) {
    value_t n0 = 1;
    while (n0 < (r - l)) n0 <<= 1;
    rx = lx + n0;
  }

  ~LiChaoSegmentTree() {
    if (root) delete root;
    root = nullptr;
  }

  void add_line(value_t ax, value_t b) {
    eval(Line(ax, b), lx, rx, root, lx, rx);
  }

  void add_segment(value_t ax, value_t b, value_t l, value_t r) {
    eval(Line(ax, b), l, r, root, lx, rx);
  }

  value_t query(value_t x) {
    value_t ans = MAX;
    node_ptr now(root);
    value_t l = lx, r = rx;
    while (r - l > 1) {
      if (ans > now->line.value(x)) ans = now->line.value(x);
      value_t mid = l + (r - l) /2;
      if (x < mid) {
        if (!now->left) return ans;
        now = now->left;
        r = mid;
      } else {
        if (!now->right) return ans;
        now = now->right;
        l = mid;
      }
    }
    if (ans > now->line.value(x)) ans = now->line.value(x);
    return ans;
  }
};