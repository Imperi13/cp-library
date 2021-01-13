#pragma once

#include "./type_alias.hpp"

constexpr u32 popcount32(u32 x) {
#ifdef __GNUC__

  return __builtin_popcount(x);

#else

  x = (x & 0x55555555) + (x >> 1 & 0x55555555);
  x = (x & 0x33333333) + (x >> 2 & 0x33333333);
  x = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);
  x = (x & 0x00ff00ff) + (x >> 8 & 0x00ff00ff);
  return (x & 0x0000ffff) + (x >> 16 & 0x0000ffff);

#endif
}

constexpr u64 popcount64(u64 x) {
#ifdef __GNUC__

  return __builtin_popcountll(x);

#else

  x = (x & 0x5555555555555555) + (x >> 1 & 0x5555555555555555);
  x = (x & 0x3333333333333333) + (x >> 2 & 0x3333333333333333);
  x = (x & 0x0f0f0f0f0f0f0f0f) + (x >> 4 & 0x0f0f0f0f0f0f0f0f);
  x = (x & 0x00ff00ff00ff00ff) + (x >> 8 & 0x00ff00ff00ff00ff);
  x = (x & 0x0000ffff0000ffff) + (x >> 16 & 0x0000ffff0000ffff);
  return (x & 0x00000000ffffffff) + (x >> 32 & 0x00000000ffffffff);

#endif
}

#ifdef __GNUC__
#include <x86intrin.h>
#endif

u64 select64(u64 num, u64 i) {
#ifdef __AVX2__
  u64 z = 1_u64 << i;
  u64 y = _pdep_u64(z, num);
  return _tzcnt_u64(y);
#else
  u64 ret = 0;
  for (u64 bitlen = 32; bitlen > 0; bitlen >>= 1) {
    u64 popcnt = popcount64(num & ((1_u64 << bitlen) - 1) << ret);
    if (popcnt <= i) {
      i -= popcnt;
      ret += bitlen;
    }
  }
  return ret;
#endif
}