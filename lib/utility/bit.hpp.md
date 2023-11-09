---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/utility/type_alias.hpp
    title: lib/utility/type_alias.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/WaveletMatrix/BitVector.hpp
    title: lib/data_structure/WaveletMatrix/BitVector.hpp
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/WaveletMatrix/WaveletMatrix.hpp
    title: lib/data_structure/WaveletMatrix/WaveletMatrix.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/WaveletMatrix.test.cpp
    title: test/WaveletMatrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/utility/bit.hpp\"\n\n#line 2 \"lib/utility/type_alias.hpp\"\
    \n\n#include <cstdint>\n\nusing u64 = std::uint64_t;\nusing u32 = std::uint32_t;\n\
    using u16 = std::uint16_t;\nusing u8 = std::uint8_t;\n\nusing i64 = std::int64_t;\n\
    using i32 = std::int32_t;\nusing i16 = std::int16_t;\nusing i8 = std::int8_t;\n\
    \nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\nconstexpr i64 operator\"\
    \" _i64(unsigned long long num) { return i64(num); }\n\nconstexpr u64 operator\"\
    \" _u64(unsigned long long num) { return u64(num); }\n#line 4 \"lib/utility/bit.hpp\"\
    \n\nconstexpr u64 next_combination(u64 num) {\n  u64 x = num & (-num);\n  u64\
    \ y = x + num;\n  return y | (((num & ~y) / x) >> 1);\n}\n\nconstexpr u32 popcount32(u32\
    \ x) {\n#ifdef __GNUC__\n\n  return __builtin_popcount(x);\n\n#else\n\n  x = (x\
    \ & 0x55555555) + (x >> 1 & 0x55555555);\n  x = (x & 0x33333333) + (x >> 2 & 0x33333333);\n\
    \  x = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);\n  x = (x & 0x00ff00ff) + (x\
    \ >> 8 & 0x00ff00ff);\n  return (x & 0x0000ffff) + (x >> 16 & 0x0000ffff);\n\n\
    #endif\n}\n\nconstexpr u64 popcount64(u64 x) {\n#ifdef __GNUC__\n\n  return __builtin_popcountll(x);\n\
    \n#else\n\n  x = (x & 0x5555555555555555) + (x >> 1 & 0x5555555555555555);\n \
    \ x = (x & 0x3333333333333333) + (x >> 2 & 0x3333333333333333);\n  x = (x & 0x0f0f0f0f0f0f0f0f)\
    \ + (x >> 4 & 0x0f0f0f0f0f0f0f0f);\n  x = (x & 0x00ff00ff00ff00ff) + (x >> 8 &\
    \ 0x00ff00ff00ff00ff);\n  x = (x & 0x0000ffff0000ffff) + (x >> 16 & 0x0000ffff0000ffff);\n\
    \  return (x & 0x00000000ffffffff) + (x >> 32 & 0x00000000ffffffff);\n\n#endif\n\
    }\n\n#ifdef __GNUC__\n#include <x86intrin.h>\n#endif\n\nu64 select64(u64 num,\
    \ u64 i) {\n#ifdef __AVX2__\n  u64 z = 1_u64 << i;\n  u64 y = _pdep_u64(z, num);\n\
    \  return _tzcnt_u64(y);\n#else\n  u64 ret = 0;\n  for (u64 bitlen = 32; bitlen\
    \ > 0; bitlen >>= 1) {\n    u64 popcnt = popcount64(num & ((1_u64 << bitlen) -\
    \ 1) << ret);\n    if (popcnt <= i) {\n      i -= popcnt;\n      ret += bitlen;\n\
    \    }\n  }\n  return ret;\n#endif\n}\n"
  code: "#pragma once\n\n#include \"./type_alias.hpp\"\n\nconstexpr u64 next_combination(u64\
    \ num) {\n  u64 x = num & (-num);\n  u64 y = x + num;\n  return y | (((num & ~y)\
    \ / x) >> 1);\n}\n\nconstexpr u32 popcount32(u32 x) {\n#ifdef __GNUC__\n\n  return\
    \ __builtin_popcount(x);\n\n#else\n\n  x = (x & 0x55555555) + (x >> 1 & 0x55555555);\n\
    \  x = (x & 0x33333333) + (x >> 2 & 0x33333333);\n  x = (x & 0x0f0f0f0f) + (x\
    \ >> 4 & 0x0f0f0f0f);\n  x = (x & 0x00ff00ff) + (x >> 8 & 0x00ff00ff);\n  return\
    \ (x & 0x0000ffff) + (x >> 16 & 0x0000ffff);\n\n#endif\n}\n\nconstexpr u64 popcount64(u64\
    \ x) {\n#ifdef __GNUC__\n\n  return __builtin_popcountll(x);\n\n#else\n\n  x =\
    \ (x & 0x5555555555555555) + (x >> 1 & 0x5555555555555555);\n  x = (x & 0x3333333333333333)\
    \ + (x >> 2 & 0x3333333333333333);\n  x = (x & 0x0f0f0f0f0f0f0f0f) + (x >> 4 &\
    \ 0x0f0f0f0f0f0f0f0f);\n  x = (x & 0x00ff00ff00ff00ff) + (x >> 8 & 0x00ff00ff00ff00ff);\n\
    \  x = (x & 0x0000ffff0000ffff) + (x >> 16 & 0x0000ffff0000ffff);\n  return (x\
    \ & 0x00000000ffffffff) + (x >> 32 & 0x00000000ffffffff);\n\n#endif\n}\n\n#ifdef\
    \ __GNUC__\n#include <x86intrin.h>\n#endif\n\nu64 select64(u64 num, u64 i) {\n\
    #ifdef __AVX2__\n  u64 z = 1_u64 << i;\n  u64 y = _pdep_u64(z, num);\n  return\
    \ _tzcnt_u64(y);\n#else\n  u64 ret = 0;\n  for (u64 bitlen = 32; bitlen > 0; bitlen\
    \ >>= 1) {\n    u64 popcnt = popcount64(num & ((1_u64 << bitlen) - 1) << ret);\n\
    \    if (popcnt <= i) {\n      i -= popcnt;\n      ret += bitlen;\n    }\n  }\n\
    \  return ret;\n#endif\n}"
  dependsOn:
  - lib/utility/type_alias.hpp
  isVerificationFile: false
  path: lib/utility/bit.hpp
  requiredBy:
  - lib/data_structure/WaveletMatrix/WaveletMatrix.hpp
  - lib/data_structure/WaveletMatrix/BitVector.hpp
  timestamp: '2021-11-02 10:46:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/WaveletMatrix.test.cpp
documentation_of: lib/utility/bit.hpp
layout: document
redirect_from:
- /library/lib/utility/bit.hpp
- /library/lib/utility/bit.hpp.html
title: lib/utility/bit.hpp
---
