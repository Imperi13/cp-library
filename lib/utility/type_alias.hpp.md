---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/WaveletMatrix/BitVector.hpp
    title: lib/WaveletMatrix/BitVector.hpp
  - icon: ':heavy_check_mark:'
    path: lib/WaveletMatrix/WaveletMatrix.hpp
    title: lib/WaveletMatrix/WaveletMatrix.hpp
  - icon: ':heavy_check_mark:'
    path: lib/utility/bit.hpp
    title: lib/utility/bit.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/WaveletMatrix.test.cpp
    title: test/WaveletMatrix.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/utility/type_alias.hpp\"\n\n#include <cstdint>\n\nusing\
    \ u64 = std::uint64_t;\nusing u32 = std::uint32_t;\nusing u16 = std::uint16_t;\n\
    using u8 = std::uint8_t;\n\nusing i64 = std::int64_t;\nusing i32 = std::int32_t;\n\
    using i16 = std::int16_t;\nusing i8 = std::int8_t;\n\nusing usize = std::size_t;\n\
    using isize = std::ptrdiff_t;\n\ni64 operator\"\" _i64(unsigned long long num){\n\
    \  return i64(num);\n}\n \nu64 operator\"\" _u64(unsigned long long num){\n  return\
    \ u64(num);\n}\n"
  code: "#pragma once\n\n#include <cstdint>\n\nusing u64 = std::uint64_t;\nusing u32\
    \ = std::uint32_t;\nusing u16 = std::uint16_t;\nusing u8 = std::uint8_t;\n\nusing\
    \ i64 = std::int64_t;\nusing i32 = std::int32_t;\nusing i16 = std::int16_t;\n\
    using i8 = std::int8_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    \ni64 operator\"\" _i64(unsigned long long num){\n  return i64(num);\n}\n \nu64\
    \ operator\"\" _u64(unsigned long long num){\n  return u64(num);\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/utility/type_alias.hpp
  requiredBy:
  - lib/utility/bit.hpp
  - lib/WaveletMatrix/BitVector.hpp
  - lib/WaveletMatrix/WaveletMatrix.hpp
  timestamp: '2020-12-19 20:24:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/WaveletMatrix.test.cpp
documentation_of: lib/utility/type_alias.hpp
layout: document
redirect_from:
- /library/lib/utility/type_alias.hpp
- /library/lib/utility/type_alias.hpp.html
title: lib/utility/type_alias.hpp
---
