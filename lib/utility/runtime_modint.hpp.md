---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DynamicMatrix.test.cpp
    title: test/DynamicMatrix.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"lib/utility/runtime_modint.hpp\"\n#include <cstdint>\n\n\
    class modint {\n  using u64 = std::uint_fast64_t;\n\n public:\n  u64 a;\n  static\
    \ u64 Modulus;\n\n  modint(const u64 x = 0) noexcept : a(x % Modulus) {}\n  u64\
    \ &value() noexcept { return a; }\n  const u64 &value() const noexcept { return\
    \ a; }\n  bool operator==(const modint rhs) const noexcept { return a == rhs.a;\
    \ }\n  bool operator!=(const modint rhs) const noexcept { return !(*this == rhs);\
    \ }\n  modint operator+(const modint rhs) const noexcept {\n    return modint(*this)\
    \ += rhs;\n  }\n  modint operator-(const modint rhs) const noexcept {\n    return\
    \ modint(*this) -= rhs;\n  }\n  modint operator*(const modint rhs) const noexcept\
    \ {\n    return modint(*this) *= rhs;\n  }\n  modint operator/(const modint rhs)\
    \ const noexcept {\n    return modint(*this) /= rhs;\n  }\n  modint &operator+=(const\
    \ modint rhs) noexcept {\n    a += rhs.a;\n    if (a >= Modulus) {\n      a -=\
    \ Modulus;\n    }\n    return *this;\n  }\n  modint &operator-=(const modint rhs)\
    \ noexcept {\n    if (a < rhs.a) {\n      a += Modulus;\n    }\n    a -= rhs.a;\n\
    \    return *this;\n  }\n  modint &operator*=(const modint rhs) noexcept {\n \
    \   a = a * rhs.a % Modulus;\n    return *this;\n  }\n  modint &operator/=(modint\
    \ rhs) noexcept {\n    u64 exp = Modulus - 2;\n    while (exp) {\n      if (exp\
    \ % 2) {\n        *this *= rhs;\n      }\n      rhs *= rhs;\n      exp /= 2;\n\
    \    }\n    return *this;\n  }\n};\n"
  code: "#include <cstdint>\n\nclass modint {\n  using u64 = std::uint_fast64_t;\n\
    \n public:\n  u64 a;\n  static u64 Modulus;\n\n  modint(const u64 x = 0) noexcept\
    \ : a(x % Modulus) {}\n  u64 &value() noexcept { return a; }\n  const u64 &value()\
    \ const noexcept { return a; }\n  bool operator==(const modint rhs) const noexcept\
    \ { return a == rhs.a; }\n  bool operator!=(const modint rhs) const noexcept {\
    \ return !(*this == rhs); }\n  modint operator+(const modint rhs) const noexcept\
    \ {\n    return modint(*this) += rhs;\n  }\n  modint operator-(const modint rhs)\
    \ const noexcept {\n    return modint(*this) -= rhs;\n  }\n  modint operator*(const\
    \ modint rhs) const noexcept {\n    return modint(*this) *= rhs;\n  }\n  modint\
    \ operator/(const modint rhs) const noexcept {\n    return modint(*this) /= rhs;\n\
    \  }\n  modint &operator+=(const modint rhs) noexcept {\n    a += rhs.a;\n   \
    \ if (a >= Modulus) {\n      a -= Modulus;\n    }\n    return *this;\n  }\n  modint\
    \ &operator-=(const modint rhs) noexcept {\n    if (a < rhs.a) {\n      a += Modulus;\n\
    \    }\n    a -= rhs.a;\n    return *this;\n  }\n  modint &operator*=(const modint\
    \ rhs) noexcept {\n    a = a * rhs.a % Modulus;\n    return *this;\n  }\n  modint\
    \ &operator/=(modint rhs) noexcept {\n    u64 exp = Modulus - 2;\n    while (exp)\
    \ {\n      if (exp % 2) {\n        *this *= rhs;\n      }\n      rhs *= rhs;\n\
    \      exp /= 2;\n    }\n    return *this;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/utility/runtime_modint.hpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DynamicMatrix.test.cpp
documentation_of: lib/utility/runtime_modint.hpp
layout: document
redirect_from:
- /library/lib/utility/runtime_modint.hpp
- /library/lib/utility/runtime_modint.hpp.html
title: lib/utility/runtime_modint.hpp
---
