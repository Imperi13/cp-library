#pragma once

#include <cassert>
#include <cstdint>
#include <vector>

#include "../utility/modint.hpp"

template <std::uint_fast64_t MOD>
class Factorial {
 public:
  using mint = modint<MOD>;
  using size_t = std::size_t;

 private:
  std::size_t n;
  std::vector<mint> factorial, factorial_inv;

 public:
  Factorial(std::size_t n_) :n(n_) factorial(n + 1), factorial_inv(n + 1) {
    factorial[0] = 1;
    for (size_t i = 1; i < n + 1; i++) factorial[i] = factorial[i - 1] * i;
    factorial_inv[n] = mint(1) / factorial[n];
    for (size_t i = n; i > 0; i--) factorial_inv[i - 1] = factorial_inv[i] * i;
  }

  mint fact(size_t pos) const {
    assert(0 <= pos && pos <= n);
    return factorial[pos];
  }
  mint fact_inv(size_t pos) const {
    assert(0 <= pos && pos <= n);
    return factorial_inv[pos];
  }
  mint binom(size_t ns, size_t k) const {
    assert(0 <= ns && ns <= n);
    assert(0 <= k && k <= ns);
    return fact(ns) * fact_inv(k) * fact_inv(ns - k);
  }
};