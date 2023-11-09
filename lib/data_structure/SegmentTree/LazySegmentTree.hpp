#pragma once

#include <cassert>
#include <vector>

// Lazy
// type value_t
// type lazy_t
// static value_t id_val
// static value_t id_lazy
// static (value_t,value_t) -> value_t f
// static (value_t,lazy_t) -> value_t g
// static (lazy_t,lazy_t) -> lazy_t h
// static (lazy_t,size_t) -> lazy_t p

/* Lazy template

struct Lazy{
  using value_t= ~~ ;
  using lazy_t= ~~ ;
  static constexpr value_t id_val= ~~ ;
  static constexpr lazy_t id_lazy= ~~ ;
  static value_t f(value_t a,value_t b){
    return ~~ ;
  }
  static value_t g(value_t a,lazy_t b){
    return ~~ ;
  }
  static lazy_t h(lazy_t a,lazy_t b){
    return ~~ ;
  }
  static lazy_t p(lazy_t a,std::size_t n){
    return ~~ ;
  }
};

*/

template <typename Lazy>
class LazySegmentTree {
 public:
  using value_t = typename Lazy::value_t;
  using lazy_t = typename Lazy::lazy_t;
  using size_t = std::size_t;

 private:
  size_t n, n0;
  std::vector<value_t> val;
  std::vector<lazy_t> lazy;

  value_t update(size_t a, size_t b, lazy_t laz, size_t l, size_t r, size_t k) {
    if (lazy[k] != Lazy::id_lazy) {
      if (k < n0 - 1) {
        lazy[2 * k + 1] = Lazy::h(lazy[2 * k + 1], lazy[k]);
        lazy[2 * k + 2] = Lazy::h(lazy[2 * k + 2], lazy[k]);
      }
      val[k] = Lazy::g(val[k], Lazy::p(lazy[k], r - l));
      lazy[k] = Lazy::id_lazy;
    }

    if (r <= a || b <= l) return val[k];
    if (a <= l && r <= b) {
      lazy[k] = Lazy::h(lazy[k], laz);
      return Lazy::g(val[k], Lazy::p(lazy[k], r - l));
    }
    return val[k] = Lazy::f(update(a, b, laz, l, l + (r - l) / 2, 2 * k + 1),
                            update(a, b, laz, l + (r - l) / 2, r, 2 * k + 2));
  }

  value_t fold(size_t a, size_t b, size_t l, size_t r, size_t k) {
    if (lazy[k] != Lazy::id_lazy) {
      if (k < n0 - 1) {
        lazy[2 * k + 1] = Lazy::h(lazy[2 * k + 1], lazy[k]);
        lazy[2 * k + 2] = Lazy::h(lazy[2 * k + 2], lazy[k]);
      }
      val[k] = Lazy::g(val[k], Lazy::p(lazy[k], r - l));
      lazy[k] = Lazy::id_lazy;
    }

    if (r <= a || b <= l) return Lazy::id_val;
    if (a <= l && r <= b) return val[k];
    return Lazy::f(fold(a, b, l, l + (r - l) / 2, 2 * k + 1),
                   fold(a, b, l + (r - l) / 2, r, 2 * k + 2));
  }

  inline size_t beki(size_t n_) {
    size_t ret = 1;
    while (ret < n_) ret <<= 1;
    return ret;
  }

 public:
  LazySegmentTree(size_t n_)
      : n(n_),
        n0(beki(n)),
        val(2 * n0 - 1, Lazy::id_val),
        lazy(2 * n0 - 1, Lazy::id_lazy) {}

  LazySegmentTree(std::vector<value_t> val_)
      : n(val_.size()),
        n0(beki(n)),
        val(2 * n0 - 1, Lazy::id_val),
        lazy(2 * n0 - 1, Lazy::id_lazy) {
    for (size_t i = 0; i < n; i++) val[i + n0 - 1] = val_[i];
    for (long long i = n0 - 2; i >= 0; i--)
      val[i] = Lazy::f(val[2 * i + 1], val[2 * i + 2]);
  }

  void update(size_t a, size_t b, lazy_t laz) { update(a, b, laz, 0, n0, 0); }

  value_t fold(size_t a, size_t b) { return fold(a, b, 0, n0, 0); }
};