#pragma once

#include "./type_alias.hpp"

constexpr u32 popcount32(u32 x){
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

constexpr u64 popcount64(u64 x){
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