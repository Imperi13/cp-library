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
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/FormalPowerSeries.hpp\"\n\n#include <cassert>\n\
    #include <cstdint>\n\n#line 2 \"lib/utility/modint.hpp\"\n\n/*\n  author:noshi91\n\
    \  reference:https://noshi91.hatenablog.com/entry/2019/03/31/174006\n        \
    \    https://github.com/noshi91/Library/blob/master/other/modint.cpp\n\n  1\u3064\
    \u3081\u306Emodint\u306Boperator==,!=\u3092\u8FFD\u52A0\u3057\u305F\u3082\u306E\
    \u3067\u3059\n\n  thx @noshi91!!\n*/\n\n#line 2 \"lib/utility/type_alias.hpp\"\
    \n\n#line 4 \"lib/utility/type_alias.hpp\"\n\nusing u64 = std::uint64_t;\nusing\
    \ u32 = std::uint32_t;\nusing u16 = std::uint16_t;\nusing u8 = std::uint8_t;\n\
    \nusing i64 = std::int64_t;\nusing i32 = std::int32_t;\nusing i16 = std::int16_t;\n\
    using i8 = std::int8_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    \ni64 operator\"\" _i64(unsigned long long num) { return i64(num); }\n\nu64 operator\"\
    \" _u64(unsigned long long num) { return u64(num); }\n#line 15 \"lib/utility/modint.hpp\"\
    \n\ntemplate <u64 Modulus>\nclass modint {\n\n public:\n  constexpr static u64\
    \ mod = Modulus;\n  u64 a;\n\n  constexpr modint(const u64 x = 0) noexcept : a(x\
    \ % Modulus) {}\n  constexpr u64 &value() noexcept { return a; }\n  constexpr\
    \ const u64 &value() const noexcept { return a; }\n  constexpr bool operator==(const\
    \ modint rhs) const noexcept {\n    return a == rhs.a;\n  }\n  constexpr bool\
    \ operator!=(const modint rhs) const noexcept {\n    return !(*this == rhs);\n\
    \  }\n  constexpr modint operator+(const modint rhs) const noexcept {\n    return\
    \ modint(*this) += rhs;\n  }\n  constexpr modint operator-(const modint rhs) const\
    \ noexcept {\n    return modint(*this) -= rhs;\n  }\n  constexpr modint operator*(const\
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
    \    }\n    return *this;\n  }\n};\n#line 7 \"lib/math/FormalPowerSeries.hpp\"\
    \n\nusing u64=std::uint_fast64_t;\n\ntemplate <u64 MOD, u64 PRI_ROOT>\nclass FPSoperator\
    \ {\n public:\n  using mint = modint<MOD>;\n  using FPS = std::vector<mint>;\n\
    \n private:\n  u64 len_real, len;\n\n  std::vector<mint> w;\n  std::vector<mint>\
    \ inv_table;\n\n  FPS fft(FPS a, u64 l, bool inv) {\n    if (l == 1) return a;\n\
    \    u64 h = 0;\n    for (u64 i = 1; i < l; i <<= 1) h++;\n\n    for (u64 i =\
    \ 0; i < l; i++) {\n      u64 bit = 0;\n      for (u64 j = 0; j < h; j++) bit\
    \ |= ((i >> j) & 1) << (h - 1 - j);\n      if (i < bit) std::swap(a[i], a[bit]);\n\
    \    }\n\n    for (u64 i = 1; i < l; i <<= 1) {\n      u64 haba = len / i;\n \
    \     for (u64 j = 0; j < l; j += 2 * i) {\n        for (u64 k = 0; k < i; k++)\
    \ {\n          mint even = a[j + k];\n          mint odd = a[j + i + k];\n   \
    \       a[j + k] =\n              even + w[inv ? (2 * len - haba * k) % (2 * len)\
    \ : haba * k] * odd;\n          a[j + i + k] =\n              even +\n       \
    \       w[inv ? (2 * len - haba * (k + i)) % (2 * len) : haba * (k + i)] *\n \
    \                 odd;\n        }\n      }\n    }\n\n    if (inv) {\n      for\
    \ (auto&& e : a) e *= inv_table[l];\n    }\n    return a;\n  }\n\n  FPS mul(FPS\
    \ a, FPS b, u64 l) {\n    assert(a.size() == l && b.size() == l);\n    a.resize(2\
    \ * l);\n    b.resize(2 * l);\n    a = fft(a, 2 * l, false);\n    b = fft(b, 2\
    \ * l, false);\n    for (std::size_t i = 0; i < 2 * l; i++) a[i] *= b[i];\n  \
    \  a = fft(a, 2 * l, true);\n    a.resize(l);\n    return a;\n  }\n\n  FPS inv(FPS\
    \ a,u64 l) {\n    assert(a.size() == l);\n    assert(a[0] != 0);\n    u64 now\
    \ = 1;\n    FPS ret(1, mint(1) / a[0]);\n    while (now < l) {\n      now <<=\
    \ 1;\n      ret.resize(now);\n      auto tmp = mul(FPS(a.begin(), a.begin() +\
    \ now), mul(ret, ret, now), now);\n      for (std::size_t i = 0; i < now; i++)\
    \ ret[i] = ret[i] * 2 - tmp[i];\n    }\n    return ret;\n  }\n\n  FPS log(FPS\
    \ a,u64 l){\n    assert(!a.empty() && a.size() == l);\n    assert(a[0] == 1);\n\
    \    FPS ret(l,0);\n    for(std::size_t i=1;i<l;i++)ret[i-1] = a[i]*i;\n    ret\
    \ = mul(ret,inv(a,l),l);\n    for(i64 i=l-1;i>0;i--)ret[i] = ret[i-1] * inv_table[i];\n\
    \    ret[0]=0;\n    return ret;\n  }\n\n  FPS exp(FPS a,u64 l){\n    assert(a.size()\
    \ == l);\n    assert(a[0] == 0);\n    u64 now = 1;\n    FPS ret(1,1);\n    while(now\
    \ < l){\n      now <<= 1;\n      ret.resize(now);\n      auto log_tmp = log(ret,now);\n\
    \      for(std::size_t i=0;i<now;i++)log_tmp[i] = a[i] - log_tmp[i] + (i==0?1:0);\n\
    \      ret = mul(ret,log_tmp,now);\n    }\n    return ret;\n  }\n\n public:\n\
    \  FPSoperator(u64 len_) : len_real(len_){\n    len = 1;\n    while (len < len_real)\
    \ len <<= 1;\n    w = FPS(2 * len, 1);\n    inv_table = FPS(2*len+1,0);\n    assert((MOD\
    \ - 1) % (2 * len) == 0);\n    u64 bit = (MOD - 1) / (2 * len);\n    mint a =\
    \ PRI_ROOT;\n    while (bit > 0) {\n      if (bit & 1) w[1] *= a;\n      a *=\
    \ a;\n      bit >>= 1;\n    }\n    for (std::size_t i = 2; i < 2 * len; i++) w[i]\
    \ = w[i - 1] * w[1];\n\n    inv_table[1] = 1;\n    for(std::size_t i=2;i<2*len+1;i++)inv_table[i]\
    \ -= inv_table[MOD%i]*(MOD/i);\n  }\n\n  FPS mul(FPS a, FPS b) {\n    assert(a.size()\
    \ <= len_real && b.size() <= len_real);\n    a.resize(len);\n    b.resize(len);\n\
    \    a = mul(a, b, len);\n    a.resize(len_real);\n    return a;\n  }\n\n  FPS\
    \ inv(FPS a) {\n    assert(a.size() <= len_real);\n    assert(a[0] != 0);\n  \
    \  a.resize(len);\n    a = inv(a,len);\n    a.resize(len_real);\n    return a;\n\
    \  }\n\n  FPS log(FPS a){\n    assert(a.size() <= len_real);\n    assert(a[0]\
    \ == 1);\n    a.resize(len);\n    a = log(a,len);\n    a.resize(len_real);\n \
    \   return a;\n  }\n\n  FPS exp(FPS a){\n    assert(a.size() <= len_real);\n \
    \   assert(a[0] == 0);\n    a.resize(len);\n    a = exp(a,len);\n    a.resize(len_real);\n\
    \    return a;\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <cstdint>\n\n#include \"../utility/modint.hpp\"\
    \n\nusing u64=std::uint_fast64_t;\n\ntemplate <u64 MOD, u64 PRI_ROOT>\nclass FPSoperator\
    \ {\n public:\n  using mint = modint<MOD>;\n  using FPS = std::vector<mint>;\n\
    \n private:\n  u64 len_real, len;\n\n  std::vector<mint> w;\n  std::vector<mint>\
    \ inv_table;\n\n  FPS fft(FPS a, u64 l, bool inv) {\n    if (l == 1) return a;\n\
    \    u64 h = 0;\n    for (u64 i = 1; i < l; i <<= 1) h++;\n\n    for (u64 i =\
    \ 0; i < l; i++) {\n      u64 bit = 0;\n      for (u64 j = 0; j < h; j++) bit\
    \ |= ((i >> j) & 1) << (h - 1 - j);\n      if (i < bit) std::swap(a[i], a[bit]);\n\
    \    }\n\n    for (u64 i = 1; i < l; i <<= 1) {\n      u64 haba = len / i;\n \
    \     for (u64 j = 0; j < l; j += 2 * i) {\n        for (u64 k = 0; k < i; k++)\
    \ {\n          mint even = a[j + k];\n          mint odd = a[j + i + k];\n   \
    \       a[j + k] =\n              even + w[inv ? (2 * len - haba * k) % (2 * len)\
    \ : haba * k] * odd;\n          a[j + i + k] =\n              even +\n       \
    \       w[inv ? (2 * len - haba * (k + i)) % (2 * len) : haba * (k + i)] *\n \
    \                 odd;\n        }\n      }\n    }\n\n    if (inv) {\n      for\
    \ (auto&& e : a) e *= inv_table[l];\n    }\n    return a;\n  }\n\n  FPS mul(FPS\
    \ a, FPS b, u64 l) {\n    assert(a.size() == l && b.size() == l);\n    a.resize(2\
    \ * l);\n    b.resize(2 * l);\n    a = fft(a, 2 * l, false);\n    b = fft(b, 2\
    \ * l, false);\n    for (std::size_t i = 0; i < 2 * l; i++) a[i] *= b[i];\n  \
    \  a = fft(a, 2 * l, true);\n    a.resize(l);\n    return a;\n  }\n\n  FPS inv(FPS\
    \ a,u64 l) {\n    assert(a.size() == l);\n    assert(a[0] != 0);\n    u64 now\
    \ = 1;\n    FPS ret(1, mint(1) / a[0]);\n    while (now < l) {\n      now <<=\
    \ 1;\n      ret.resize(now);\n      auto tmp = mul(FPS(a.begin(), a.begin() +\
    \ now), mul(ret, ret, now), now);\n      for (std::size_t i = 0; i < now; i++)\
    \ ret[i] = ret[i] * 2 - tmp[i];\n    }\n    return ret;\n  }\n\n  FPS log(FPS\
    \ a,u64 l){\n    assert(!a.empty() && a.size() == l);\n    assert(a[0] == 1);\n\
    \    FPS ret(l,0);\n    for(std::size_t i=1;i<l;i++)ret[i-1] = a[i]*i;\n    ret\
    \ = mul(ret,inv(a,l),l);\n    for(i64 i=l-1;i>0;i--)ret[i] = ret[i-1] * inv_table[i];\n\
    \    ret[0]=0;\n    return ret;\n  }\n\n  FPS exp(FPS a,u64 l){\n    assert(a.size()\
    \ == l);\n    assert(a[0] == 0);\n    u64 now = 1;\n    FPS ret(1,1);\n    while(now\
    \ < l){\n      now <<= 1;\n      ret.resize(now);\n      auto log_tmp = log(ret,now);\n\
    \      for(std::size_t i=0;i<now;i++)log_tmp[i] = a[i] - log_tmp[i] + (i==0?1:0);\n\
    \      ret = mul(ret,log_tmp,now);\n    }\n    return ret;\n  }\n\n public:\n\
    \  FPSoperator(u64 len_) : len_real(len_){\n    len = 1;\n    while (len < len_real)\
    \ len <<= 1;\n    w = FPS(2 * len, 1);\n    inv_table = FPS(2*len+1,0);\n    assert((MOD\
    \ - 1) % (2 * len) == 0);\n    u64 bit = (MOD - 1) / (2 * len);\n    mint a =\
    \ PRI_ROOT;\n    while (bit > 0) {\n      if (bit & 1) w[1] *= a;\n      a *=\
    \ a;\n      bit >>= 1;\n    }\n    for (std::size_t i = 2; i < 2 * len; i++) w[i]\
    \ = w[i - 1] * w[1];\n\n    inv_table[1] = 1;\n    for(std::size_t i=2;i<2*len+1;i++)inv_table[i]\
    \ -= inv_table[MOD%i]*(MOD/i);\n  }\n\n  FPS mul(FPS a, FPS b) {\n    assert(a.size()\
    \ <= len_real && b.size() <= len_real);\n    a.resize(len);\n    b.resize(len);\n\
    \    a = mul(a, b, len);\n    a.resize(len_real);\n    return a;\n  }\n\n  FPS\
    \ inv(FPS a) {\n    assert(a.size() <= len_real);\n    assert(a[0] != 0);\n  \
    \  a.resize(len);\n    a = inv(a,len);\n    a.resize(len_real);\n    return a;\n\
    \  }\n\n  FPS log(FPS a){\n    assert(a.size() <= len_real);\n    assert(a[0]\
    \ == 1);\n    a.resize(len);\n    a = log(a,len);\n    a.resize(len_real);\n \
    \   return a;\n  }\n\n  FPS exp(FPS a){\n    assert(a.size() <= len_real);\n \
    \   assert(a[0] == 0);\n    a.resize(len);\n    a = exp(a,len);\n    a.resize(len_real);\n\
    \    return a;\n  }\n};"
  dependsOn:
  - lib/utility/modint.hpp
  - lib/utility/type_alias.hpp
  isVerificationFile: false
  path: lib/math/FormalPowerSeries.hpp
  requiredBy: []
  timestamp: '2021-01-16 18:13:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FPSinv.test.cpp
  - test/FPSmultiply.test.cpp
  - test/FPSlog.test.cpp
  - test/FPSexp.test.cpp
documentation_of: lib/math/FormalPowerSeries.hpp
layout: document
redirect_from:
- /library/lib/math/FormalPowerSeries.hpp
- /library/lib/math/FormalPowerSeries.hpp.html
title: lib/math/FormalPowerSeries.hpp
---
