---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/utility/bit.hpp
    title: lib/utility/bit.hpp
  - icon: ':heavy_check_mark:'
    path: lib/utility/type_alias.hpp
    title: lib/utility/type_alias.hpp
  _extendedRequiredBy:
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
  bundledCode: "#line 2 \"lib/data_structure/WaveletMatrix/BitVector.hpp\"\n\n#include\
    \ <cassert>\n#include <limits>\n#include <vector>\n\n#line 2 \"lib/utility/bit.hpp\"\
    \n\n#line 2 \"lib/utility/type_alias.hpp\"\n\n#include <cstdint>\n\nusing i64\
    \ = std::int64_t;\nusing i32 = std::int32_t;\nusing i16 = std::int16_t;\nusing\
    \ i8 = std::int8_t;\n\nusing u64 = std::uint64_t;\nusing u32 = std::uint32_t;\n\
    using u16 = std::uint16_t;\nusing u8 = std::uint8_t;\n\nusing usize = std::size_t;\n\
    using isize = std::ptrdiff_t;\n\nconstexpr i64 operator\"\" _i64(unsigned long\
    \ long num) { return i64(num); }\nconstexpr i32 operator\"\" _i32(unsigned long\
    \ long num) { return i32(num); }\nconstexpr i16 operator\"\" _i16(unsigned long\
    \ long num) { return i16(num); }\nconstexpr i8 operator\"\" _i8(unsigned long\
    \ long num) { return i8(num); }\n\nconstexpr u64 operator\"\" _u64(unsigned long\
    \ long num) { return u64(num); }\nconstexpr u32 operator\"\" _u32(unsigned long\
    \ long num) { return u32(num); }\nconstexpr u16 operator\"\" _u16(unsigned long\
    \ long num) { return u16(num); }\nconstexpr u8 operator\"\" _u8(unsigned long\
    \ long num) { return u8(num); }\n#line 4 \"lib/utility/bit.hpp\"\n\nconstexpr\
    \ u64 next_combination(u64 num) {\n  u64 x = num & (-num);\n  u64 y = x + num;\n\
    \  return y | (((num & ~y) / x) >> 1);\n}\n\nconstexpr u32 popcount32(u32 x) {\n\
    #ifdef __GNUC__\n\n  return __builtin_popcount(x);\n\n#else\n\n  x = (x & 0x55555555)\
    \ + (x >> 1 & 0x55555555);\n  x = (x & 0x33333333) + (x >> 2 & 0x33333333);\n\
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
    \    }\n  }\n  return ret;\n#endif\n}\n#line 9 \"lib/data_structure/WaveletMatrix/BitVector.hpp\"\
    \n\nclass BitVector {\n private:\n  constexpr static usize LBLOCK = 1ul << 16;\n\
    \  constexpr static usize SBLOCK = 64;\n\n  usize n;\n  usize bitcnt;\n\n  std::vector<u64>\
    \ raw_bit;\n\n  std::vector<u32> rank_l;\n  std::vector<u16> rank_s;\n\n  bool\
    \ build_flag;\n\n public:\n  BitVector() = delete;\n  explicit BitVector(usize\
    \ n_)\n      : n(n_),\n        raw_bit(n / SBLOCK + 1),\n        rank_l(n / LBLOCK\
    \ + 1),\n        rank_s(n / SBLOCK + 1),\n        build_flag(false) {\n    assert(n_\
    \ <= std::numeric_limits<u32>::max());\n  }\n\n  void set(usize pos) {\n    assert(!build_flag);\n\
    \    assert(pos < n);\n    raw_bit[pos / SBLOCK] |= 1_u64 << (pos % SBLOCK);\n\
    \  }\n\n  void build() {\n    assert(!build_flag);\n    u32 cnt = 0;\n    for\
    \ (usize i = 0; i <= n; i++) {\n      if (i % LBLOCK == 0) rank_l[i / LBLOCK]\
    \ = cnt;\n      if (i % SBLOCK == 0) rank_s[i / SBLOCK] = cnt - rank_l[i / LBLOCK];\n\
    \      if (i != n && i % SBLOCK == 0) cnt += popcount64(raw_bit[i / SBLOCK]);\n\
    \    }\n    bitcnt = cnt;\n    build_flag = true;\n  }\n\n  bool operator[](usize\
    \ pos) {\n    assert(build_flag);\n    assert(pos < n);\n    return (raw_bit[pos\
    \ / SBLOCK] >> (pos % SBLOCK)) & 1;\n  }\n\n  usize rank(usize pos) {\n    assert(build_flag);\n\
    \    assert(pos <= n);\n    return rank_l[pos / LBLOCK] + rank_s[pos / SBLOCK]\
    \ +\n           popcount64(raw_bit[pos / SBLOCK] & ((1_u64 << (pos % SBLOCK))\
    \ - 1));\n  }\n\n  usize select1(usize i) {\n    assert(build_flag);\n    assert(bitcnt\
    \ > i);\n    usize l = 0, r = n / LBLOCK + 1;\n    while (r - l > 1) {\n     \
    \ usize mid = (l + r) >> 1;\n      if (rank_l[mid] <= i)\n        l = mid;\n \
    \     else\n        r = mid;\n    }\n    i -= rank_l[l];\n    l *= (LBLOCK / SBLOCK);\n\
    \    r = std::min(r * (LBLOCK / SBLOCK), n / SBLOCK + 1);\n    while (r - l >\
    \ 1) {\n      usize mid = (l + r) >> 1;\n      if (rank_s[mid] <= i)\n       \
    \ l = mid;\n      else\n        r = mid;\n    }\n    i -= rank_s[l];\n    return\
    \ l * SBLOCK + select64(raw_bit[l], i);\n  }\n\n  usize select0(usize i) {\n \
    \   assert(build_flag);\n    assert(n - bitcnt > i);\n    usize l = 0, r = n /\
    \ LBLOCK + 1;\n    while (r - l > 1) {\n      usize mid = (l + r) >> 1;\n    \
    \  if (mid * LBLOCK - rank_l[mid] <= i)\n        l = mid;\n      else\n      \
    \  r = mid;\n    }\n    i -= l * LBLOCK - rank_l[l];\n    l *= (LBLOCK / SBLOCK);\n\
    \    r = std::min(r * (LBLOCK / SBLOCK), n / SBLOCK + 1);\n    usize offset =\
    \ l;\n    while (r - l > 1) {\n      usize mid = (l + r) >> 1;\n      if ((mid\
    \ - offset) * SBLOCK - rank_s[mid] <= i)\n        l = mid;\n      else\n     \
    \   r = mid;\n    }\n    i -= (l - offset) * SBLOCK - rank_s[l];\n    return l\
    \ * SBLOCK + select64(~raw_bit[l], i);\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <limits>\n#include <vector>\n\
    \n#include \"../../utility/bit.hpp\"\n#include \"../../utility/type_alias.hpp\"\
    \n\nclass BitVector {\n private:\n  constexpr static usize LBLOCK = 1ul << 16;\n\
    \  constexpr static usize SBLOCK = 64;\n\n  usize n;\n  usize bitcnt;\n\n  std::vector<u64>\
    \ raw_bit;\n\n  std::vector<u32> rank_l;\n  std::vector<u16> rank_s;\n\n  bool\
    \ build_flag;\n\n public:\n  BitVector() = delete;\n  explicit BitVector(usize\
    \ n_)\n      : n(n_),\n        raw_bit(n / SBLOCK + 1),\n        rank_l(n / LBLOCK\
    \ + 1),\n        rank_s(n / SBLOCK + 1),\n        build_flag(false) {\n    assert(n_\
    \ <= std::numeric_limits<u32>::max());\n  }\n\n  void set(usize pos) {\n    assert(!build_flag);\n\
    \    assert(pos < n);\n    raw_bit[pos / SBLOCK] |= 1_u64 << (pos % SBLOCK);\n\
    \  }\n\n  void build() {\n    assert(!build_flag);\n    u32 cnt = 0;\n    for\
    \ (usize i = 0; i <= n; i++) {\n      if (i % LBLOCK == 0) rank_l[i / LBLOCK]\
    \ = cnt;\n      if (i % SBLOCK == 0) rank_s[i / SBLOCK] = cnt - rank_l[i / LBLOCK];\n\
    \      if (i != n && i % SBLOCK == 0) cnt += popcount64(raw_bit[i / SBLOCK]);\n\
    \    }\n    bitcnt = cnt;\n    build_flag = true;\n  }\n\n  bool operator[](usize\
    \ pos) {\n    assert(build_flag);\n    assert(pos < n);\n    return (raw_bit[pos\
    \ / SBLOCK] >> (pos % SBLOCK)) & 1;\n  }\n\n  usize rank(usize pos) {\n    assert(build_flag);\n\
    \    assert(pos <= n);\n    return rank_l[pos / LBLOCK] + rank_s[pos / SBLOCK]\
    \ +\n           popcount64(raw_bit[pos / SBLOCK] & ((1_u64 << (pos % SBLOCK))\
    \ - 1));\n  }\n\n  usize select1(usize i) {\n    assert(build_flag);\n    assert(bitcnt\
    \ > i);\n    usize l = 0, r = n / LBLOCK + 1;\n    while (r - l > 1) {\n     \
    \ usize mid = (l + r) >> 1;\n      if (rank_l[mid] <= i)\n        l = mid;\n \
    \     else\n        r = mid;\n    }\n    i -= rank_l[l];\n    l *= (LBLOCK / SBLOCK);\n\
    \    r = std::min(r * (LBLOCK / SBLOCK), n / SBLOCK + 1);\n    while (r - l >\
    \ 1) {\n      usize mid = (l + r) >> 1;\n      if (rank_s[mid] <= i)\n       \
    \ l = mid;\n      else\n        r = mid;\n    }\n    i -= rank_s[l];\n    return\
    \ l * SBLOCK + select64(raw_bit[l], i);\n  }\n\n  usize select0(usize i) {\n \
    \   assert(build_flag);\n    assert(n - bitcnt > i);\n    usize l = 0, r = n /\
    \ LBLOCK + 1;\n    while (r - l > 1) {\n      usize mid = (l + r) >> 1;\n    \
    \  if (mid * LBLOCK - rank_l[mid] <= i)\n        l = mid;\n      else\n      \
    \  r = mid;\n    }\n    i -= l * LBLOCK - rank_l[l];\n    l *= (LBLOCK / SBLOCK);\n\
    \    r = std::min(r * (LBLOCK / SBLOCK), n / SBLOCK + 1);\n    usize offset =\
    \ l;\n    while (r - l > 1) {\n      usize mid = (l + r) >> 1;\n      if ((mid\
    \ - offset) * SBLOCK - rank_s[mid] <= i)\n        l = mid;\n      else\n     \
    \   r = mid;\n    }\n    i -= (l - offset) * SBLOCK - rank_s[l];\n    return l\
    \ * SBLOCK + select64(~raw_bit[l], i);\n  }\n};"
  dependsOn:
  - lib/utility/bit.hpp
  - lib/utility/type_alias.hpp
  isVerificationFile: false
  path: lib/data_structure/WaveletMatrix/BitVector.hpp
  requiredBy:
  - lib/data_structure/WaveletMatrix/WaveletMatrix.hpp
  timestamp: '2024-07-20 17:36:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/WaveletMatrix.test.cpp
documentation_of: lib/data_structure/WaveletMatrix/BitVector.hpp
layout: document
redirect_from:
- /library/lib/data_structure/WaveletMatrix/BitVector.hpp
- /library/lib/data_structure/WaveletMatrix/BitVector.hpp.html
title: lib/data_structure/WaveletMatrix/BitVector.hpp
---