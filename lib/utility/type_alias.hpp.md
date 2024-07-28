---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lib/data_structure/SkewBinaryList.hpp
    title: lib/data_structure/SkewBinaryList.hpp
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/WaveletMatrix/BitVector.hpp
    title: lib/data_structure/WaveletMatrix/BitVector.hpp
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/WaveletMatrix/WaveletMatrix.hpp
    title: lib/data_structure/WaveletMatrix/WaveletMatrix.hpp
  - icon: ':heavy_check_mark:'
    path: lib/math/FactorialTable.hpp
    title: lib/math/FactorialTable.hpp
  - icon: ':heavy_check_mark:'
    path: lib/math/FormalPowerSeries.hpp
    title: lib/math/FormalPowerSeries.hpp
  - icon: ':heavy_check_mark:'
    path: lib/utility/bit.hpp
    title: lib/utility/bit.hpp
  - icon: ':heavy_check_mark:'
    path: lib/utility/modint.hpp
    title: lib/utility/modint.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DynamicMatrix_2.test.cpp
    title: test/DynamicMatrix_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/FPSexp.test.cpp
    title: test/FPSexp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/FPSinv.test.cpp
    title: test/FPSinv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/FPSlog.test.cpp
    title: test/FPSlog.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/FPSmultiply.test.cpp
    title: test/FPSmultiply.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/FactorialTable.test.cpp
    title: test/FactorialTable.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/WaveletMatrix.test.cpp
    title: test/WaveletMatrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "lib/utility/type_alias.hpp"


    #include <cstdint>


    using i64 = std::int64_t;

    using i32 = std::int32_t;

    using i16 = std::int16_t;

    using i8 = std::int8_t;


    using u64 = std::uint64_t;

    using u32 = std::uint32_t;

    using u16 = std::uint16_t;

    using u8 = std::uint8_t;


    using usize = std::size_t;

    using isize = std::ptrdiff_t;


    constexpr i64 operator"" _i64(unsigned long long num) { return i64(num); }

    constexpr i32 operator"" _i32(unsigned long long num) { return i32(num); }

    constexpr i16 operator"" _i16(unsigned long long num) { return i16(num); }

    constexpr i8 operator"" _i8(unsigned long long num) { return i8(num); }


    constexpr u64 operator"" _u64(unsigned long long num) { return u64(num); }

    constexpr u32 operator"" _u32(unsigned long long num) { return u32(num); }

    constexpr u16 operator"" _u16(unsigned long long num) { return u16(num); }

    constexpr u8 operator"" _u8(unsigned long long num) { return u8(num); }

    '
  code: '#pragma once


    #include <cstdint>


    using i64 = std::int64_t;

    using i32 = std::int32_t;

    using i16 = std::int16_t;

    using i8 = std::int8_t;


    using u64 = std::uint64_t;

    using u32 = std::uint32_t;

    using u16 = std::uint16_t;

    using u8 = std::uint8_t;


    using usize = std::size_t;

    using isize = std::ptrdiff_t;


    constexpr i64 operator"" _i64(unsigned long long num) { return i64(num); }

    constexpr i32 operator"" _i32(unsigned long long num) { return i32(num); }

    constexpr i16 operator"" _i16(unsigned long long num) { return i16(num); }

    constexpr i8 operator"" _i8(unsigned long long num) { return i8(num); }


    constexpr u64 operator"" _u64(unsigned long long num) { return u64(num); }

    constexpr u32 operator"" _u32(unsigned long long num) { return u32(num); }

    constexpr u16 operator"" _u16(unsigned long long num) { return u16(num); }

    constexpr u8 operator"" _u8(unsigned long long num) { return u8(num); }

    '
  dependsOn: []
  isVerificationFile: false
  path: lib/utility/type_alias.hpp
  requiredBy:
  - lib/data_structure/SkewBinaryList.hpp
  - lib/data_structure/WaveletMatrix/BitVector.hpp
  - lib/data_structure/WaveletMatrix/WaveletMatrix.hpp
  - lib/utility/modint.hpp
  - lib/utility/bit.hpp
  - lib/math/FactorialTable.hpp
  - lib/math/FormalPowerSeries.hpp
  timestamp: '2024-07-20 17:36:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FPSinv.test.cpp
  - test/FPSmultiply.test.cpp
  - test/FPSexp.test.cpp
  - test/FPSlog.test.cpp
  - test/DynamicMatrix_2.test.cpp
  - test/WaveletMatrix.test.cpp
  - test/FactorialTable.test.cpp
documentation_of: lib/utility/type_alias.hpp
layout: document
redirect_from:
- /library/lib/utility/type_alias.hpp
- /library/lib/utility/type_alias.hpp.html
title: lib/utility/type_alias.hpp
---
