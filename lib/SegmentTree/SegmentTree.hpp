#pragma once

#include <cassert>
#include <vector>

// Monoid
// type value_t
// static value_t id
// static (value_t,value_t)->value_t op

template <typename Monoid>
class SegmentTree {
 public:
  using value_t = typename Monoid::value_t;
  using size_t = std::size_t;

 private:
  size_t n, n0;
  std::vector<value_t> dat;

 public:
  SegmentTree(size_t n_) : n(n_) {
    assert(n_ > 0);
    n0 = 1;
    while (n0 < n) n0 <<= 1;
    dat = std::vector<value_t>(2 * n0 - 1, Monoid::id);
  }

  SegmentTree(const std::vector<value_t>& tmp) : n(tmp.size()) {
    assert(n > 0);
    n0 = 1;
    while (n0 < n) n0 <<= 1;
    dat = std::vector<value_t>(2 * n0 - 1, Monoid::id);
    for (size_t i = 0; i < n; i++) dat[i + n0 - 1] = tmp[i];
    for (long long i = n0 - 2; i >= 0; i--)
      dat[i] = Monoid::op(dat[2 * i + 1], dat[2 * i + 2]);
  }

  void update(size_t i, value_t val, bool change) {
    assert(0 <= i && i < n);
    std::size_t now = i + n0 - 1;
    if (change)
      dat[now] = val;
    else
      dat[now] = Monoid::op(dat[now], val);

    while (now > 0) {
      now = (now - 1) >> 1;
      dat[now] = Monoid::op(dat[2 * now + 1], dat[2 * now + 2]);
    }
  }

  value_t fold(size_t a, size_t b) {
    assert(0 <= a && a <= b && b <= n);
    value_t rval = Monoid::id, lval = Monoid::id;
    size_t l = a + n0 - 1, r = b + n0 - 1;
    for (; l < r; l >>= 1, r >>= 1) {
      if (!(r & 1)) {
        r--;
        rval = Monoid::op(dat[r], rval);
      }
      if (!(l & 1)) {
        lval = Monoid::op(lval, dat[l]);
        l++;
      }
    }

    return Monoid::op(lval, rval);
  }
};