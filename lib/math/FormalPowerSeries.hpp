#pragma once

#include <cassert>
#include <cstdint>

#include "../utility/modint.hpp"

using u64=std::uint_fast64_t;

template <u64 MOD, u64 PRI_ROOT>
class FPSoperator {
 public:
  using mint = modint<MOD>;
  using FPS = std::vector<mint>;

 private:
  u64 len_real, len;

  std::vector<mint> w;

  FPS fft(const FPS& a, bool inv) {
    assert(a.size() == len);
    auto dfs = [&](auto f, const FPS& coef, u64 l) {
      assert(coef.size() == l);
      if (l == 1) return coef;
      FPS odd(l / 2), even(l / 2);
      for (std::size_t i = 0; i < l; i++) {
        if (i % 2 == 0)
          even[i / 2] = coef[i];
        else
          odd[i / 2] = coef[i];
      }
      u64 half = l / 2, haba = len / l;
      even = f(f, even, half);
      odd = f(f, odd, half);

      FPS ret(l);
      for (std::size_t i = 0; i < l; i++) {
        ret[i] = even[i % half] +
                 w[inv ? (len - haba * i) : haba * i] * odd[i % half];
      }
      return ret;
    };

    FPS ret = dfs(dfs, a, len);
    mint len_inv = mint(1) / len;
    if (inv)
      for (std::size_t i = 0; i < len; i++) ret[i] *= len_inv;
    return ret;
  }

 public:
  FPSoperator(u64 len_) : len_real(len_), w(len_real * 2, 1) {
    len = 1;
    while (len < len_real) len <<= 1;
    assert((MOD - 1) % len == 0);
    u64 bit = (MOD - 1) / len;
    mint a = PRI_ROOT;
    while (bit > 0) {
      if (bit & 1) w[1] *= a;
      a *= a;
      bit >>= 1;
    }
    for (std::size_t i = 2; i < len; i++) w[i] = w[i - 1] * w[1];
  }

  FPS mul(FPS a, FPS b) {
    assert(a.size() <= len_real && b.size() <= len_real);
    a.resize(len);
    b.resize(len);
    a = fft(a, false);
    b = fft(b, false);
    for (std::size_t i = 0; i < len; i++) a[i] *= b[i];
    a = fft(a, true);
    a.resize(len_real);
    return a;
  }
};