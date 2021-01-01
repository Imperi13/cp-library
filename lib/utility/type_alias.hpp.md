---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lib/SkewBinaryList.hpp
    title: lib/SkewBinaryList.hpp
  - icon: ':x:'
    path: lib/WaveletMatrix/BitVector.hpp
    title: lib/WaveletMatrix/BitVector.hpp
  - icon: ':x:'
    path: lib/WaveletMatrix/WaveletMatrix.hpp
    title: lib/WaveletMatrix/WaveletMatrix.hpp
  - icon: ':x:'
    path: lib/utility/bit.hpp
    title: lib/utility/bit.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/WaveletMatrix.test.cpp
    title: test/WaveletMatrix.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: '#line 2 "lib/utility/type_alias.hpp"


    #include <cstdint>


    using u64 = std::uint64_t;

    using u32 = std::uint32_t;

    using u16 = std::uint16_t;

    using u8 = std::uint8_t;


    using i64 = std::int64_t;

    using i32 = std::int32_t;

    using i16 = std::int16_t;

    using i8 = std::int8_t;


    using usize = std::size_t;

    using isize = std::ptrdiff_t;

    '
  code: '#pragma once


    #include <cstdint>


    using u64 = std::uint64_t;

    using u32 = std::uint32_t;

    using u16 = std::uint16_t;

    using u8 = std::uint8_t;


    using i64 = std::int64_t;

    using i32 = std::int32_t;

    using i16 = std::int16_t;

    using i8 = std::int8_t;


    using usize = std::size_t;

    using isize = std::ptrdiff_t;'
  dependsOn: []
  isVerificationFile: false
  path: lib/utility/type_alias.hpp
  requiredBy:
  - lib/SkewBinaryList.hpp
  - lib/utility/bit.hpp
  - lib/WaveletMatrix/BitVector.hpp
  - lib/WaveletMatrix/WaveletMatrix.hpp
  timestamp: '2021-01-01 14:18:17+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/WaveletMatrix.test.cpp
documentation_of: lib/utility/type_alias.hpp
layout: document
redirect_from:
- /library/lib/utility/type_alias.hpp
- /library/lib/utility/type_alias.hpp.html
title: lib/utility/type_alias.hpp
---
