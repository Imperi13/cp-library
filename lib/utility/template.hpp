#pragma once

#include <functional>

#include "utility/type_alias.hpp"

template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
  return a < b && (a = b, true);
}

template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
  return a > b && (a = b, true);
}

template <typename Num, typename Func = std::multiplies<Num>>
constexpr Num mypow(Num a, u64 b, Num id = 1, Func mul = Func()) {
  if (b == 0) return id;
  Num x = id;
  while (b > 0) {
    if (b & 1) x = mul(x, a);
    a = mul(a, a);
    b >>= 1;
  }
  return x;
}