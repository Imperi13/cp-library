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
    path: lib/WaveletMatrix/WaveletMatrix.hpp
    title: lib/WaveletMatrix/WaveletMatrix.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/WaveletMatrix.test.cpp
    title: test/WaveletMatrix.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/WaveletMatrix/BitVector.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n#line 2 \"lib/utility/type_alias.hpp\"\n\n#include <cstdint>\n\
    \nusing u64 = std::uint64_t;\nusing u32 = std::uint32_t;\nusing u16 = std::uint16_t;\n\
    using u8 = std::uint8_t;\n\nusing i64 = std::int64_t;\nusing i32 = std::int32_t;\n\
    using i16 = std::int16_t;\nusing i8 = std::int8_t;\n\nusing usize = std::size_t;\n\
    using isize = std::ptrdiff_t;\n\ni64 operator\"\" _i64(unsigned long long num){\n\
    \  return i64(num);\n}\n \nu64 operator\"\" _u64(unsigned long long num){\n  return\
    \ u64(num);\n}\n#line 2 \"lib/utility/bit.hpp\"\n\n#line 4 \"lib/utility/bit.hpp\"\
    \n\nconstexpr u32 popcount32(u32 x){\n  #ifdef __GNUC__\n\n  return __builtin_popcount(x);\n\
    \n  #else\n\n  x = (x & 0x55555555) + (x >> 1 & 0x55555555);\n  x = (x & 0x33333333)\
    \ + (x >> 2 & 0x33333333);\n  x = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);\n\
    \  x = (x & 0x00ff00ff) + (x >> 8 & 0x00ff00ff);\n  return (x & 0x0000ffff) +\
    \ (x >> 16 & 0x0000ffff);\n\n  #endif\n}\n\nconstexpr u64 popcount64(u64 x){\n\
    \  #ifdef __GNUC__\n\n  return __builtin_popcountll(x);\n\n  #else\n\n  x = (x\
    \ & 0x5555555555555555) + (x >> 1 & 0x5555555555555555);\n  x = (x & 0x3333333333333333)\
    \ + (x >> 2 & 0x3333333333333333);\n  x = (x & 0x0f0f0f0f0f0f0f0f) + (x >> 4 &\
    \ 0x0f0f0f0f0f0f0f0f);\n  x = (x & 0x00ff00ff00ff00ff) + (x >> 8 & 0x00ff00ff00ff00ff);\n\
    \  x = (x & 0x0000ffff0000ffff) + (x >> 16 & 0x0000ffff0000ffff);\n  return (x\
    \ & 0x00000000ffffffff) + (x >> 32 & 0x00000000ffffffff);\n\n  #endif\n}\n#line\
    \ 8 \"lib/WaveletMatrix/BitVector.hpp\"\n\nclass BitVector {\n private:\n  constexpr\
    \ static std::size_t LBLOCK = 1ul << 16;\n  constexpr static std::size_t SBLOCK\
    \ = 64;\n\n  usize n;\n  usize bitcnt;\n\n  std::vector<u64> raw_bit;\n\n  std::vector<u32>\
    \ rank_l;\n  std::vector<u16> rank_s;\n\n  bool build_flag;\n\n public:\n  BitVector()\
    \ = delete;\n  explicit BitVector(usize n_)\n      : n(n_),\n        raw_bit(n\
    \ / SBLOCK + 1),\n        rank_l(n / LBLOCK + 1),\n        rank_s(n / SBLOCK +\
    \ 1),\n        build_flag(false) {\n    assert(n_ <= std::numeric_limits<u32>::max());\n\
    \  }\n\n  void set(usize pos) {\n    assert(!build_flag);\n    assert(pos < n);\n\
    \    raw_bit[pos / SBLOCK] |= 1_u64 << (pos % SBLOCK);\n  }\n\n  void build()\
    \ {\n    assert(!build_flag);\n    u32 cnt = 0;\n    for (usize i = 0; i <= n;\
    \ i++) {\n      if (i % LBLOCK == 0) rank_l[i / LBLOCK] = cnt;\n      if (i %\
    \ SBLOCK == 0) rank_s[i / SBLOCK] = cnt - rank_l[i / LBLOCK];\n      if (i !=\
    \ n && i % SBLOCK == 0) cnt += popcount64(raw_bit[i / SBLOCK]);\n    }\n    bitcnt\
    \ = cnt;\n    build_flag = true;\n  }\n\n  bool operator[](usize pos){\n    assert(build_flag);\n\
    \    assert(pos < n);\n    return (raw_bit[pos/SBLOCK] >> (pos % SBLOCK)) & 1;\n\
    \  }\n\n  usize rank(usize pos){\n    assert(build_flag);\n    assert(pos <= n);\n\
    \    return rank_l[pos/LBLOCK] + rank_s[pos / SBLOCK] + popcount64(raw_bit[pos/SBLOCK]\
    \ & ((1_u64 << (pos % SBLOCK))-1) );\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n#include \"../utility/type_alias.hpp\"\
    \n#include \"../utility/bit.hpp\"\n\nclass BitVector {\n private:\n  constexpr\
    \ static std::size_t LBLOCK = 1ul << 16;\n  constexpr static std::size_t SBLOCK\
    \ = 64;\n\n  usize n;\n  usize bitcnt;\n\n  std::vector<u64> raw_bit;\n\n  std::vector<u32>\
    \ rank_l;\n  std::vector<u16> rank_s;\n\n  bool build_flag;\n\n public:\n  BitVector()\
    \ = delete;\n  explicit BitVector(usize n_)\n      : n(n_),\n        raw_bit(n\
    \ / SBLOCK + 1),\n        rank_l(n / LBLOCK + 1),\n        rank_s(n / SBLOCK +\
    \ 1),\n        build_flag(false) {\n    assert(n_ <= std::numeric_limits<u32>::max());\n\
    \  }\n\n  void set(usize pos) {\n    assert(!build_flag);\n    assert(pos < n);\n\
    \    raw_bit[pos / SBLOCK] |= 1_u64 << (pos % SBLOCK);\n  }\n\n  void build()\
    \ {\n    assert(!build_flag);\n    u32 cnt = 0;\n    for (usize i = 0; i <= n;\
    \ i++) {\n      if (i % LBLOCK == 0) rank_l[i / LBLOCK] = cnt;\n      if (i %\
    \ SBLOCK == 0) rank_s[i / SBLOCK] = cnt - rank_l[i / LBLOCK];\n      if (i !=\
    \ n && i % SBLOCK == 0) cnt += popcount64(raw_bit[i / SBLOCK]);\n    }\n    bitcnt\
    \ = cnt;\n    build_flag = true;\n  }\n\n  bool operator[](usize pos){\n    assert(build_flag);\n\
    \    assert(pos < n);\n    return (raw_bit[pos/SBLOCK] >> (pos % SBLOCK)) & 1;\n\
    \  }\n\n  usize rank(usize pos){\n    assert(build_flag);\n    assert(pos <= n);\n\
    \    return rank_l[pos/LBLOCK] + rank_s[pos / SBLOCK] + popcount64(raw_bit[pos/SBLOCK]\
    \ & ((1_u64 << (pos % SBLOCK))-1) );\n  }\n};"
  dependsOn:
  - lib/utility/type_alias.hpp
  - lib/utility/bit.hpp
  isVerificationFile: false
  path: lib/WaveletMatrix/BitVector.hpp
  requiredBy:
  - lib/WaveletMatrix/WaveletMatrix.hpp
  timestamp: '2020-12-19 20:24:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/WaveletMatrix.test.cpp
documentation_of: lib/WaveletMatrix/BitVector.hpp
layout: document
redirect_from:
- /library/lib/WaveletMatrix/BitVector.hpp
- /library/lib/WaveletMatrix/BitVector.hpp.html
title: lib/WaveletMatrix/BitVector.hpp
---
