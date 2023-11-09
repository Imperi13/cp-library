---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/utility/type_alias.hpp
    title: lib/utility/type_alias.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/math/FactorialTable.hpp
    title: lib/math/FactorialTable.hpp
  - icon: ':heavy_check_mark:'
    path: lib/math/FormalPowerSeries.hpp
    title: lib/math/FormalPowerSeries.hpp
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/noshi91/Library/blob/master/other/modint.cpp
    - https://noshi91.hatenablog.com/entry/2019/03/31/174006
  bundledCode: "#line 2 \"lib/utility/modint.hpp\"\n\n/*\n  author:noshi91\n  reference:https://noshi91.hatenablog.com/entry/2019/03/31/174006\n\
    \            https://github.com/noshi91/Library/blob/master/other/modint.cpp\n\
    \n  1\u3064\u3081\u306Emodint\u306Boperator==,!=\u3092\u8FFD\u52A0\u3057\u305F\
    \u3082\u306E\u3067\u3059\n\n  thx @noshi91!!\n*/\n\n#include <cstdint>\n#include\
    \ <iostream>\n#line 2 \"lib/utility/type_alias.hpp\"\n\n#line 4 \"lib/utility/type_alias.hpp\"\
    \n\nusing u64 = std::uint64_t;\nusing u32 = std::uint32_t;\nusing u16 = std::uint16_t;\n\
    using u8 = std::uint8_t;\n\nusing i64 = std::int64_t;\nusing i32 = std::int32_t;\n\
    using i16 = std::int16_t;\nusing i8 = std::int8_t;\n\nusing usize = std::size_t;\n\
    using isize = std::ptrdiff_t;\n\nconstexpr i64 operator\"\" _i64(unsigned long\
    \ long num) { return i64(num); }\n\nconstexpr u64 operator\"\" _u64(unsigned long\
    \ long num) { return u64(num); }\n#line 16 \"lib/utility/modint.hpp\"\n\ntemplate\
    \ <u64 Modulus>\nclass modint {\n\n public:\n  constexpr static u64 mod = Modulus;\n\
    \  u64 a;\n\n  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}\n\
    \  constexpr u64 &value() noexcept { return a; }\n  constexpr const u64 &value()\
    \ const noexcept { return a; }\n  constexpr bool operator==(const modint rhs)\
    \ const noexcept {\n    return a == rhs.a;\n  }\n  constexpr bool operator!=(const\
    \ modint rhs) const noexcept {\n    return !(*this == rhs);\n  }\n  constexpr\
    \ modint operator+(const modint rhs) const noexcept {\n    return modint(*this)\
    \ += rhs;\n  }\n  constexpr modint operator-(const modint rhs) const noexcept\
    \ {\n    return modint(*this) -= rhs;\n  }\n  constexpr modint operator*(const\
    \ modint rhs) const noexcept {\n    return modint(*this) *= rhs;\n  }\n  constexpr\
    \ modint operator/(const modint rhs) const noexcept {\n    return modint(*this)\
    \ /= rhs;\n  }\n  constexpr modint &operator+=(const modint rhs) noexcept {\n\
    \    a += rhs.a;\n    if (a >= Modulus) {\n      a -= Modulus;\n    }\n    return\
    \ *this;\n  }\n  constexpr modint &operator-=(const modint rhs) noexcept {\n \
    \   if (a < rhs.a) {\n      a += Modulus;\n    }\n    a -= rhs.a;\n    return\
    \ *this;\n  }\n  constexpr modint &operator*=(const modint rhs) noexcept {\n \
    \   a = a * rhs.a % Modulus;\n    return *this;\n  }\n  constexpr modint &operator/=(modint\
    \ rhs) noexcept {\n    u64 exp = Modulus - 2;\n    while (exp) {\n      if (exp\
    \ % 2) {\n        *this *= rhs;\n      }\n      rhs *= rhs;\n      exp /= 2;\n\
    \    }\n    return *this;\n  }\n};\n\ntemplate <u64 MOD>\nstd::ostream& operator<<(std::ostream&\
    \ os, modint<MOD> a) {\n  return os << a.value();\n}\n"
  code: "#pragma once\n\n/*\n  author:noshi91\n  reference:https://noshi91.hatenablog.com/entry/2019/03/31/174006\n\
    \            https://github.com/noshi91/Library/blob/master/other/modint.cpp\n\
    \n  1\u3064\u3081\u306Emodint\u306Boperator==,!=\u3092\u8FFD\u52A0\u3057\u305F\
    \u3082\u306E\u3067\u3059\n\n  thx @noshi91!!\n*/\n\n#include <cstdint>\n#include\
    \ <iostream>\n#include \"./type_alias.hpp\"\n\ntemplate <u64 Modulus>\nclass modint\
    \ {\n\n public:\n  constexpr static u64 mod = Modulus;\n  u64 a;\n\n  constexpr\
    \ modint(const u64 x = 0) noexcept : a(x % Modulus) {}\n  constexpr u64 &value()\
    \ noexcept { return a; }\n  constexpr const u64 &value() const noexcept { return\
    \ a; }\n  constexpr bool operator==(const modint rhs) const noexcept {\n    return\
    \ a == rhs.a;\n  }\n  constexpr bool operator!=(const modint rhs) const noexcept\
    \ {\n    return !(*this == rhs);\n  }\n  constexpr modint operator+(const modint\
    \ rhs) const noexcept {\n    return modint(*this) += rhs;\n  }\n  constexpr modint\
    \ operator-(const modint rhs) const noexcept {\n    return modint(*this) -= rhs;\n\
    \  }\n  constexpr modint operator*(const modint rhs) const noexcept {\n    return\
    \ modint(*this) *= rhs;\n  }\n  constexpr modint operator/(const modint rhs) const\
    \ noexcept {\n    return modint(*this) /= rhs;\n  }\n  constexpr modint &operator+=(const\
    \ modint rhs) noexcept {\n    a += rhs.a;\n    if (a >= Modulus) {\n      a -=\
    \ Modulus;\n    }\n    return *this;\n  }\n  constexpr modint &operator-=(const\
    \ modint rhs) noexcept {\n    if (a < rhs.a) {\n      a += Modulus;\n    }\n \
    \   a -= rhs.a;\n    return *this;\n  }\n  constexpr modint &operator*=(const\
    \ modint rhs) noexcept {\n    a = a * rhs.a % Modulus;\n    return *this;\n  }\n\
    \  constexpr modint &operator/=(modint rhs) noexcept {\n    u64 exp = Modulus\
    \ - 2;\n    while (exp) {\n      if (exp % 2) {\n        *this *= rhs;\n     \
    \ }\n      rhs *= rhs;\n      exp /= 2;\n    }\n    return *this;\n  }\n};\n\n\
    template <u64 MOD>\nstd::ostream& operator<<(std::ostream& os, modint<MOD> a)\
    \ {\n  return os << a.value();\n}"
  dependsOn:
  - lib/utility/type_alias.hpp
  isVerificationFile: false
  path: lib/utility/modint.hpp
  requiredBy:
  - lib/math/FormalPowerSeries.hpp
  - lib/math/FactorialTable.hpp
  timestamp: '2021-11-02 10:46:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DynamicMatrix_2.test.cpp
  - test/FactorialTable.test.cpp
  - test/FPSmultiply.test.cpp
  - test/FPSinv.test.cpp
  - test/FPSexp.test.cpp
  - test/FPSlog.test.cpp
documentation_of: lib/utility/modint.hpp
layout: document
redirect_from:
- /library/lib/utility/modint.hpp
- /library/lib/utility/modint.hpp.html
title: lib/utility/modint.hpp
---
