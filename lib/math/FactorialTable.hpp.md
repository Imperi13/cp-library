---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/utility/modint.hpp
    title: lib/utility/modint.hpp
  - icon: ':heavy_check_mark:'
    path: lib/utility/type_alias.hpp
    title: lib/utility/type_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FactorialTable.test.cpp
    title: test/FactorialTable.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/FactorialTable.hpp\"\n\n#include <cassert>\n#include\
    \ <cstdint>\n#include <vector>\n\n#line 2 \"lib/utility/modint.hpp\"\n\n/*\n \
    \ author:noshi91\n  reference:https://noshi91.hatenablog.com/entry/2019/03/31/174006\n\
    \            https://github.com/noshi91/Library/blob/master/other/modint.cpp\n\
    \n  1\u3064\u3081\u306Emodint\u306Boperator==,!=\u3092\u8FFD\u52A0\u3057\u305F\
    \u3082\u306E\u3067\u3059\n\n  thx @noshi91!!\n*/\n\n#line 14 \"lib/utility/modint.hpp\"\
    \n#include <iostream>\n#line 2 \"lib/utility/type_alias.hpp\"\n\n#line 4 \"lib/utility/type_alias.hpp\"\
    \n\nusing i64 = std::int64_t;\nusing i32 = std::int32_t;\nusing i16 = std::int16_t;\n\
    using i8 = std::int8_t;\n\nusing u64 = std::uint64_t;\nusing u32 = std::uint32_t;\n\
    using u16 = std::uint16_t;\nusing u8 = std::uint8_t;\n\nusing usize = std::size_t;\n\
    using isize = std::ptrdiff_t;\n\nconstexpr i64 operator\"\" _i64(unsigned long\
    \ long num) { return i64(num); }\nconstexpr i32 operator\"\" _i32(unsigned long\
    \ long num) { return i32(num); }\nconstexpr i16 operator\"\" _i16(unsigned long\
    \ long num) { return i16(num); }\nconstexpr i8 operator\"\" _i8(unsigned long\
    \ long num) { return i8(num); }\n\nconstexpr u64 operator\"\" _u64(unsigned long\
    \ long num) { return u64(num); }\nconstexpr u32 operator\"\" _u32(unsigned long\
    \ long num) { return u32(num); }\nconstexpr u16 operator\"\" _u16(unsigned long\
    \ long num) { return u16(num); }\nconstexpr u8 operator\"\" _u8(unsigned long\
    \ long num) { return u8(num); }\n#line 16 \"lib/utility/modint.hpp\"\n\ntemplate\
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
    \ os, modint<MOD> a) {\n  return os << a.value();\n}\n#line 8 \"lib/math/FactorialTable.hpp\"\
    \n\ntemplate <std::uint_fast64_t MOD>\nclass Factorial {\n public:\n  using mint\
    \ = modint<MOD>;\n  using size_t = std::size_t;\n\n private:\n  std::size_t n;\n\
    \  std::vector<mint> factorial, factorial_inv;\n\n public:\n  Factorial(std::size_t\
    \ n_) :n(n_), factorial(n + 1), factorial_inv(n + 1) {\n    factorial[0] = 1;\n\
    \    for (size_t i = 1; i < n + 1; i++) factorial[i] = factorial[i - 1] * i;\n\
    \    factorial_inv[n] = mint(1) / factorial[n];\n    for (size_t i = n; i > 0;\
    \ i--) factorial_inv[i - 1] = factorial_inv[i] * i;\n  }\n\n  mint fact(size_t\
    \ pos) const {\n    assert(0 <= pos && pos <= n);\n    return factorial[pos];\n\
    \  }\n  mint fact_inv(size_t pos) const {\n    assert(0 <= pos && pos <= n);\n\
    \    return factorial_inv[pos];\n  }\n  mint inv(size_t pos)const{\n    assert(0\
    \ < pos && pos <= n);\n    return factorial_inv[pos] * factorial[pos-1];\n  }\n\
    \  mint binom(size_t ns, size_t k) const {\n    assert(0 <= ns && ns <= n);\n\
    \    assert(0 <= k && k <= ns);\n    return fact(ns) * fact_inv(k) * fact_inv(ns\
    \ - k);\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <cstdint>\n#include <vector>\n\
    \n#include \"../utility/modint.hpp\"\n\ntemplate <std::uint_fast64_t MOD>\nclass\
    \ Factorial {\n public:\n  using mint = modint<MOD>;\n  using size_t = std::size_t;\n\
    \n private:\n  std::size_t n;\n  std::vector<mint> factorial, factorial_inv;\n\
    \n public:\n  Factorial(std::size_t n_) :n(n_), factorial(n + 1), factorial_inv(n\
    \ + 1) {\n    factorial[0] = 1;\n    for (size_t i = 1; i < n + 1; i++) factorial[i]\
    \ = factorial[i - 1] * i;\n    factorial_inv[n] = mint(1) / factorial[n];\n  \
    \  for (size_t i = n; i > 0; i--) factorial_inv[i - 1] = factorial_inv[i] * i;\n\
    \  }\n\n  mint fact(size_t pos) const {\n    assert(0 <= pos && pos <= n);\n \
    \   return factorial[pos];\n  }\n  mint fact_inv(size_t pos) const {\n    assert(0\
    \ <= pos && pos <= n);\n    return factorial_inv[pos];\n  }\n  mint inv(size_t\
    \ pos)const{\n    assert(0 < pos && pos <= n);\n    return factorial_inv[pos]\
    \ * factorial[pos-1];\n  }\n  mint binom(size_t ns, size_t k) const {\n    assert(0\
    \ <= ns && ns <= n);\n    assert(0 <= k && k <= ns);\n    return fact(ns) * fact_inv(k)\
    \ * fact_inv(ns - k);\n  }\n};"
  dependsOn:
  - lib/utility/modint.hpp
  - lib/utility/type_alias.hpp
  isVerificationFile: false
  path: lib/math/FactorialTable.hpp
  requiredBy: []
  timestamp: '2024-07-20 17:36:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FactorialTable.test.cpp
documentation_of: lib/math/FactorialTable.hpp
layout: document
redirect_from:
- /library/lib/math/FactorialTable.hpp
- /library/lib/math/FactorialTable.hpp.html
title: lib/math/FactorialTable.hpp
---
