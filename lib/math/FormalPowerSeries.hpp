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
  std::vector<mint> inv_table;

  FPS fft(FPS a, u64 l, bool inv) {
    if (l == 1) return a;
    u64 h = 0;
    for (u64 i = 1; i < l; i <<= 1) h++;

    for (u64 i = 0; i < l; i++) {
      u64 bit = 0;
      for (u64 j = 0; j < h; j++) bit |= ((i >> j) & 1) << (h - 1 - j);
      if (i < bit) std::swap(a[i], a[bit]);
    }

    for (u64 i = 1; i < l; i <<= 1) {
      u64 haba = len / i;
      for (u64 j = 0; j < l; j += 2 * i) {
        for (u64 k = 0; k < i; k++) {
          mint even = a[j + k];
          mint odd = a[j + i + k];
          a[j + k] =
              even + w[inv ? (2 * len - haba * k) % (2 * len) : haba * k] * odd;
          a[j + i + k] =
              even +
              w[inv ? (2 * len - haba * (k + i)) % (2 * len) : haba * (k + i)] *
                  odd;
        }
      }
    }

    if (inv) {
      for (auto&& e : a) e *= inv_table[l];
    }
    return a;
  }

  FPS mul(FPS a, FPS b, u64 l) {
    assert(a.size() == l && b.size() == l);
    a.resize(2 * l);
    b.resize(2 * l);
    a = fft(a, 2 * l, false);
    b = fft(b, 2 * l, false);
    for (std::size_t i = 0; i < 2 * l; i++) a[i] *= b[i];
    a = fft(a, 2 * l, true);
    a.resize(l);
    return a;
  }

  FPS inv(FPS a,u64 l) {
    assert(a.size() == l);
    assert(a[0] != 0);
    u64 now = 1;
    FPS ret(1, mint(1) / a[0]);
    while (now < l) {
      now <<= 1;
      ret.resize(now);
      auto tmp = mul(FPS(a.begin(), a.begin() + now), mul(ret, ret, now), now);
      for (std::size_t i = 0; i < now; i++) ret[i] = ret[i] * 2 - tmp[i];
    }
    return ret;
  }

  FPS log(FPS a,u64 l){
    assert(!a.empty() && a.size() == l);
    assert(a[0] == 1);
    FPS ret(l,0);
    for(std::size_t i=1;i<l;i++)ret[i-1] = a[i]*i;
    ret = mul(ret,inv(a,l),l);
    for(i64 i=l-1;i>0;i--)ret[i] = ret[i-1] * inv_table[i];
    ret[0]=0;
    return ret;
  }

  FPS exp(FPS a,u64 l){
    assert(a.size() == l);
    assert(a[0] == 0);
    u64 now = 1;
    FPS ret(1,1);
    while(now < l){
      now <<= 1;
      ret.resize(now);
      auto log_tmp = log(ret,now);
      for(std::size_t i=0;i<now;i++)log_tmp[i] = a[i] - log_tmp[i] + (i==0?1:0);
      ret = mul(ret,log_tmp,now);
    }
    return ret;
  }

 public:
  FPSoperator(u64 len_) : len_real(len_){
    len = 1;
    while (len < len_real) len <<= 1;
    w = FPS(2 * len, 1);
    inv_table = FPS(2*len+1,0);
    assert((MOD - 1) % (2 * len) == 0);
    u64 bit = (MOD - 1) / (2 * len);
    mint a = PRI_ROOT;
    while (bit > 0) {
      if (bit & 1) w[1] *= a;
      a *= a;
      bit >>= 1;
    }
    for (std::size_t i = 2; i < 2 * len; i++) w[i] = w[i - 1] * w[1];

    inv_table[1] = 1;
    for(std::size_t i=2;i<2*len+1;i++)inv_table[i] -= inv_table[MOD%i]*(MOD/i);
  }

  FPS mul(FPS a, FPS b) {
    assert(a.size() <= len_real && b.size() <= len_real);
    a.resize(len);
    b.resize(len);
    a = mul(a, b, len);
    a.resize(len_real);
    return a;
  }

  FPS inv(FPS a) {
    assert(a.size() <= len_real);
    assert(a[0] != 0);
    a.resize(len);
    a = inv(a,len);
    a.resize(len_real);
    return a;
  }

  FPS log(FPS a){
    assert(a.size() <= len_real);
    assert(a[0] == 1);
    a.resize(len);
    a = log(a,len);
    a.resize(len_real);
    return a;
  }

  FPS exp(FPS a){
    assert(a.size() <= len_real);
    assert(a[0] == 0);
    a.resize(len);
    a = exp(a,len);
    a.resize(len_real);
    return a;
  }
};