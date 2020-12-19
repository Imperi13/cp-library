---
data:
  _extendedDependsOn: []
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
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/noshi91/Library/blob/master/other/modint.cpp
    - https://noshi91.hatenablog.com/entry/2019/03/31/174006
  bundledCode: "#line 2 \"lib/utility/modint.hpp\"\n\n/*\n  author:noshi91\n  reference:https://noshi91.hatenablog.com/entry/2019/03/31/174006\n\
    \            https://github.com/noshi91/Library/blob/master/other/modint.cpp\n\
    \n  1\u3064\u3081\u306Emodint\u306Boperator==,!=\u3092\u8FFD\u52A0\u3057\u305F\
    \u3082\u306E\u3067\u3059\n\n  thx @noshi91!!\n*/\n\n#include <cstdint>\n\ntemplate\
    \ <std::uint_fast64_t Modulus>\nclass modint {\n  using u64 = std::uint_fast64_t;\n\
    \n public:\n  u64 a;\n\n  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus)\
    \ {}\n  constexpr u64 &value() noexcept { return a; }\n  constexpr const u64 &value()\
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
    \    }\n    return *this;\n  }\n};\n"
  code: "#pragma once\n\n/*\n  author:noshi91\n  reference:https://noshi91.hatenablog.com/entry/2019/03/31/174006\n\
    \            https://github.com/noshi91/Library/blob/master/other/modint.cpp\n\
    \n  1\u3064\u3081\u306Emodint\u306Boperator==,!=\u3092\u8FFD\u52A0\u3057\u305F\
    \u3082\u306E\u3067\u3059\n\n  thx @noshi91!!\n*/\n\n#include <cstdint>\n\ntemplate\
    \ <std::uint_fast64_t Modulus>\nclass modint {\n  using u64 = std::uint_fast64_t;\n\
    \n public:\n  u64 a;\n\n  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus)\
    \ {}\n  constexpr u64 &value() noexcept { return a; }\n  constexpr const u64 &value()\
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
    \    }\n    return *this;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/utility/modint.hpp
  requiredBy:
  - lib/math/FormalPowerSeries.hpp
  - lib/math/FactorialTable.hpp
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FPSmultiply.test.cpp
  - test/FPSexp.test.cpp
  - test/FactorialTable.test.cpp
  - test/FPSlog.test.cpp
  - test/DynamicMatrix_2.test.cpp
  - test/FPSinv.test.cpp
documentation_of: lib/utility/modint.hpp
layout: document
redirect_from:
- /library/lib/utility/modint.hpp
- /library/lib/utility/modint.hpp.html
title: lib/utility/modint.hpp
---
