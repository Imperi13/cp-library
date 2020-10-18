---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/utility/modint.hpp
    title: lib/utility/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FPSinv.test.cpp
    title: test/FPSinv.test.cpp
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
    \u3067\u3059\n\n  thx @noshi91!!\n*/\n\n#line 14 \"lib/utility/modint.hpp\"\n\n\
    template <std::uint_fast64_t Modulus>\nclass modint {\n  using u64 = std::uint_fast64_t;\n\
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
    \    }\n    return *this;\n  }\n};\n#line 7 \"lib/math/FormalPowerSeries.hpp\"\
    \n\nusing u64=std::uint_fast64_t;\n\ntemplate <u64 MOD, u64 PRI_ROOT>\nclass FPSoperator\
    \ {\n public:\n  using mint = modint<MOD>;\n  using FPS = std::vector<mint>;\n\
    \n private:\n  u64 len_real, len;\n\n  std::vector<mint> w;\n\n  FPS fft(const\
    \ FPS& a,u64 l,bool inv){\n    if(l==1)return a;\n    u64 half = l/2,haba = 2*len/l;\n\
    \    FPS even(half),odd(half);\n    for(std::size_t i=0;i<l;i++){\n      if(i%2==0)even[i/2]=a[i];\n\
    \      else odd[i/2]=a[i];\n    }\n    even = fft(even,half,inv);\n    odd = fft(odd,half,inv);\n\
    \    FPS ret(l);\n    for(std::size_t i=0;i<l;i++){\n      ret[i] = even[i%half]\
    \ + w[inv ? (2*len-haba * i)%(2*len) : haba*i] * odd[i%half];\n    }\n    return\
    \ ret;\n  }\n\n  FPS div(FPS a,u64 x){\n    mint inv =mint(1)/x;\n    for(auto&&\
    \ e:a)e*=inv;\n    return a;\n  }\n\n  FPS mul(FPS a,FPS b,u64 l){\n    assert(a.size()\
    \ == l && b.size() == l);\n    a.resize(2*l);b.resize(2*l);\n    a = fft(a,2*l,false);b\
    \ = fft(b,2*l,false);\n    for(std::size_t i=0;i<2*l;i++)a[i] *= b[i];\n    a\
    \ = fft(a,2*l,true);\n    a = div(a,2*l);\n    a.resize(l);\n    return a;\n \
    \ }\n\n public:\n  FPSoperator(u64 len_) : len_real(len_){\n    len = 1;\n   \
    \ while (len < len_real) len <<= 1;\n    w = FPS(2*len,1);\n    assert((MOD -\
    \ 1) % (2*len) == 0);\n    u64 bit = (MOD - 1) / (2*len);\n    mint a = PRI_ROOT;\n\
    \    while (bit > 0) {\n      if (bit & 1) w[1] *= a;\n      a *= a;\n      bit\
    \ >>= 1;\n    }\n    for (std::size_t i = 2; i < 2*len; i++) w[i] = w[i - 1] *\
    \ w[1];\n  }\n\n  FPS mul(FPS a,FPS b){\n    assert(a.size() <= len_real && b.size()\
    \ <= len_real);\n    a.resize(len);b.resize(len);\n    a = mul(a,b,len);\n   \
    \ a.resize(len_real);\n    return a;\n  }\n\n  FPS inv(FPS a){\n    assert(a.size()\
    \ <= len_real);\n    assert(a[0]!=0);\n    a.resize(len);\n    u64 now = 1;\n\
    \    FPS ret(1,mint(1)/a[0]);\n    while(now < len){\n      now<<=1;\n      ret.resize(now);\n\
    \      auto tmp = mul(FPS(a.begin(),a.begin()+now) , mul(ret,ret,now) ,now);\n\
    \      for(std::size_t i=0;i<now;i++)ret[i] = ret[i] * 2 - tmp[i];\n    }\n  \
    \  ret.resize(len_real);\n    return ret;\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <cstdint>\n\n#include \"../utility/modint.hpp\"\
    \n\nusing u64=std::uint_fast64_t;\n\ntemplate <u64 MOD, u64 PRI_ROOT>\nclass FPSoperator\
    \ {\n public:\n  using mint = modint<MOD>;\n  using FPS = std::vector<mint>;\n\
    \n private:\n  u64 len_real, len;\n\n  std::vector<mint> w;\n\n  FPS fft(const\
    \ FPS& a,u64 l,bool inv){\n    if(l==1)return a;\n    u64 half = l/2,haba = 2*len/l;\n\
    \    FPS even(half),odd(half);\n    for(std::size_t i=0;i<l;i++){\n      if(i%2==0)even[i/2]=a[i];\n\
    \      else odd[i/2]=a[i];\n    }\n    even = fft(even,half,inv);\n    odd = fft(odd,half,inv);\n\
    \    FPS ret(l);\n    for(std::size_t i=0;i<l;i++){\n      ret[i] = even[i%half]\
    \ + w[inv ? (2*len-haba * i)%(2*len) : haba*i] * odd[i%half];\n    }\n    return\
    \ ret;\n  }\n\n  FPS div(FPS a,u64 x){\n    mint inv =mint(1)/x;\n    for(auto&&\
    \ e:a)e*=inv;\n    return a;\n  }\n\n  FPS mul(FPS a,FPS b,u64 l){\n    assert(a.size()\
    \ == l && b.size() == l);\n    a.resize(2*l);b.resize(2*l);\n    a = fft(a,2*l,false);b\
    \ = fft(b,2*l,false);\n    for(std::size_t i=0;i<2*l;i++)a[i] *= b[i];\n    a\
    \ = fft(a,2*l,true);\n    a = div(a,2*l);\n    a.resize(l);\n    return a;\n \
    \ }\n\n public:\n  FPSoperator(u64 len_) : len_real(len_){\n    len = 1;\n   \
    \ while (len < len_real) len <<= 1;\n    w = FPS(2*len,1);\n    assert((MOD -\
    \ 1) % (2*len) == 0);\n    u64 bit = (MOD - 1) / (2*len);\n    mint a = PRI_ROOT;\n\
    \    while (bit > 0) {\n      if (bit & 1) w[1] *= a;\n      a *= a;\n      bit\
    \ >>= 1;\n    }\n    for (std::size_t i = 2; i < 2*len; i++) w[i] = w[i - 1] *\
    \ w[1];\n  }\n\n  FPS mul(FPS a,FPS b){\n    assert(a.size() <= len_real && b.size()\
    \ <= len_real);\n    a.resize(len);b.resize(len);\n    a = mul(a,b,len);\n   \
    \ a.resize(len_real);\n    return a;\n  }\n\n  FPS inv(FPS a){\n    assert(a.size()\
    \ <= len_real);\n    assert(a[0]!=0);\n    a.resize(len);\n    u64 now = 1;\n\
    \    FPS ret(1,mint(1)/a[0]);\n    while(now < len){\n      now<<=1;\n      ret.resize(now);\n\
    \      auto tmp = mul(FPS(a.begin(),a.begin()+now) , mul(ret,ret,now) ,now);\n\
    \      for(std::size_t i=0;i<now;i++)ret[i] = ret[i] * 2 - tmp[i];\n    }\n  \
    \  ret.resize(len_real);\n    return ret;\n  }\n};"
  dependsOn:
  - lib/utility/modint.hpp
  isVerificationFile: false
  path: lib/math/FormalPowerSeries.hpp
  requiredBy: []
  timestamp: '2020-10-19 00:53:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FPSmultiply.test.cpp
  - test/FPSinv.test.cpp
documentation_of: lib/math/FormalPowerSeries.hpp
layout: document
redirect_from:
- /library/lib/math/FormalPowerSeries.hpp
- /library/lib/math/FormalPowerSeries.hpp.html
title: lib/math/FormalPowerSeries.hpp
---
