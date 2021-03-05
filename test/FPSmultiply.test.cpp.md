---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/FormalPowerSeries.hpp
    title: lib/math/FormalPowerSeries.hpp
  - icon: ':heavy_check_mark:'
    path: lib/utility/modint.hpp
    title: lib/utility/modint.hpp
  - icon: ':heavy_check_mark:'
    path: lib/utility/type_alias.hpp
    title: lib/utility/type_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/FPSmultiply.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <chrono>\n#include <cmath>\n#include <complex>\n#include\
    \ <cstdint>\n#include <cstdlib>\n#include <deque>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <limits>\n#include <list>\n#include\
    \ <map>\n#include <memory>\n#include <numeric>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <utility>\n#include <vector>\n\n/* template\
    \ start */\n\nusing i64 = std::int_fast64_t;\nusing u64 = std::uint_fast64_t;\n\
    \n#define rep(i, a, b) for (i64 i = (a); (i) < (b); (i)++)\n#define all(i) i.begin(),\
    \ i.end()\n\n#ifdef LOCAL\n#define debug(...)                                \
    \                    \\\n  std::cerr << \"LINE: \" << __LINE__ << \"  [\" << #__VA_ARGS__\
    \ << \"]:\", \\\n      debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\
    \nvoid debug_out() { std::cerr << std::endl; }\n\ntemplate <typename Head, typename...\
    \ Tail>\nvoid debug_out(Head h, Tail... t) {\n  std::cerr << \" \" << h;\n  if\
    \ (sizeof...(t) > 0) std::cout << \" :\";\n  debug_out(t...);\n}\n\ntemplate <typename\
    \ T1, typename T2>\nstd::ostream& operator<<(std::ostream& os, std::pair<T1, T2>\
    \ pa) {\n  return os << pa.first << \" \" << pa.second;\n}\n\ntemplate <typename\
    \ T>\nstd::ostream& operator<<(std::ostream& os, std::vector<T> vec) {\n  for\
    \ (std::size_t i = 0; i < vec.size(); i++)\n    os << vec[i] << (i + 1 == vec.size()\
    \ ? \"\" : \" \");\n  return os;\n}\n\ntemplate <typename T1, typename T2>\ninline\
    \ bool chmax(T1& a, T2 b) {\n  return a < b && (a = b, true);\n}\n\ntemplate <typename\
    \ T1, typename T2>\ninline bool chmin(T1& a, T2 b) {\n  return a > b && (a = b,\
    \ true);\n}\n\ntemplate <typename Num>\nconstexpr Num mypow(Num a, u64 b, Num\
    \ id = 1) {\n  if (b == 0) return id;\n  Num x = id;\n  while (b > 0) {\n    if\
    \ (b & 1) x *= a;\n    a *= a;\n    b >>= 1;\n  }\n  return x;\n}\n\ntemplate\
    \ <typename T>\nstd::vector<std::pair<std::size_t, T>> enumerate(const std::vector<T>&\
    \ data) {\n  std::vector<std::pair<std::size_t, T>> ret;\n  for (std::size_t index\
    \ = 0; index < data.size(); index++)\n    ret.emplace_back(index, data[index]);\n\
    \  return ret;\n}\n\n/* template end */\n\n#line 2 \"lib/math/FormalPowerSeries.hpp\"\
    \n\n#line 5 \"lib/math/FormalPowerSeries.hpp\"\n\n#line 2 \"lib/utility/modint.hpp\"\
    \n\n/*\n  author:noshi91\n  reference:https://noshi91.hatenablog.com/entry/2019/03/31/174006\n\
    \            https://github.com/noshi91/Library/blob/master/other/modint.cpp\n\
    \n  1\u3064\u3081\u306Emodint\u306Boperator==,!=\u3092\u8FFD\u52A0\u3057\u305F\
    \u3082\u306E\u3067\u3059\n\n  thx @noshi91!!\n*/\n\n#line 2 \"lib/utility/type_alias.hpp\"\
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
    \    return a;\n  }\n};\n#line 102 \"test/FPSmultiply.test.cpp\"\n\nusing FPS\
    \ = FPSoperator<998244353, 3>;\nusing mint = FPS::mint;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios::sync_with_stdio(false);\n\n  i64 n, m;\n  std::cin >> n >> m;\n\n\
    \  FPS fps(n+m-1);\n\n  std::vector<mint> a(n), b(m);\n  for (auto&& e : a) {\n\
    \    i64 tmp;\n    std::cin >> tmp;\n    e = tmp;\n  }\n\n  for (auto&& e : b)\
    \ {\n    i64 tmp;\n    std::cin >> tmp;\n    e = tmp;\n  }\n\n  auto c =fps.mul(a,b);\n\
    \n  for(const auto& e:c)std::cout<<e.value()<<\" \";\n  std::cout<<\"\\n\";\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cctype>\n#include <chrono>\n#include <cmath>\n#include <complex>\n#include\
    \ <cstdint>\n#include <cstdlib>\n#include <deque>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <limits>\n#include <list>\n#include\
    \ <map>\n#include <memory>\n#include <numeric>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <utility>\n#include <vector>\n\n/* template\
    \ start */\n\nusing i64 = std::int_fast64_t;\nusing u64 = std::uint_fast64_t;\n\
    \n#define rep(i, a, b) for (i64 i = (a); (i) < (b); (i)++)\n#define all(i) i.begin(),\
    \ i.end()\n\n#ifdef LOCAL\n#define debug(...)                                \
    \                    \\\n  std::cerr << \"LINE: \" << __LINE__ << \"  [\" << #__VA_ARGS__\
    \ << \"]:\", \\\n      debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\
    \nvoid debug_out() { std::cerr << std::endl; }\n\ntemplate <typename Head, typename...\
    \ Tail>\nvoid debug_out(Head h, Tail... t) {\n  std::cerr << \" \" << h;\n  if\
    \ (sizeof...(t) > 0) std::cout << \" :\";\n  debug_out(t...);\n}\n\ntemplate <typename\
    \ T1, typename T2>\nstd::ostream& operator<<(std::ostream& os, std::pair<T1, T2>\
    \ pa) {\n  return os << pa.first << \" \" << pa.second;\n}\n\ntemplate <typename\
    \ T>\nstd::ostream& operator<<(std::ostream& os, std::vector<T> vec) {\n  for\
    \ (std::size_t i = 0; i < vec.size(); i++)\n    os << vec[i] << (i + 1 == vec.size()\
    \ ? \"\" : \" \");\n  return os;\n}\n\ntemplate <typename T1, typename T2>\ninline\
    \ bool chmax(T1& a, T2 b) {\n  return a < b && (a = b, true);\n}\n\ntemplate <typename\
    \ T1, typename T2>\ninline bool chmin(T1& a, T2 b) {\n  return a > b && (a = b,\
    \ true);\n}\n\ntemplate <typename Num>\nconstexpr Num mypow(Num a, u64 b, Num\
    \ id = 1) {\n  if (b == 0) return id;\n  Num x = id;\n  while (b > 0) {\n    if\
    \ (b & 1) x *= a;\n    a *= a;\n    b >>= 1;\n  }\n  return x;\n}\n\ntemplate\
    \ <typename T>\nstd::vector<std::pair<std::size_t, T>> enumerate(const std::vector<T>&\
    \ data) {\n  std::vector<std::pair<std::size_t, T>> ret;\n  for (std::size_t index\
    \ = 0; index < data.size(); index++)\n    ret.emplace_back(index, data[index]);\n\
    \  return ret;\n}\n\n/* template end */\n\n#include \"../lib/math/FormalPowerSeries.hpp\"\
    \n\nusing FPS = FPSoperator<998244353, 3>;\nusing mint = FPS::mint;\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\n  i64 n,\
    \ m;\n  std::cin >> n >> m;\n\n  FPS fps(n+m-1);\n\n  std::vector<mint> a(n),\
    \ b(m);\n  for (auto&& e : a) {\n    i64 tmp;\n    std::cin >> tmp;\n    e = tmp;\n\
    \  }\n\n  for (auto&& e : b) {\n    i64 tmp;\n    std::cin >> tmp;\n    e = tmp;\n\
    \  }\n\n  auto c =fps.mul(a,b);\n\n  for(const auto& e:c)std::cout<<e.value()<<\"\
    \ \";\n  std::cout<<\"\\n\";\n\n  return 0;\n}"
  dependsOn:
  - lib/math/FormalPowerSeries.hpp
  - lib/utility/modint.hpp
  - lib/utility/type_alias.hpp
  isVerificationFile: true
  path: test/FPSmultiply.test.cpp
  requiredBy: []
  timestamp: '2021-01-16 18:13:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/FPSmultiply.test.cpp
layout: document
redirect_from:
- /verify/test/FPSmultiply.test.cpp
- /verify/test/FPSmultiply.test.cpp.html
title: test/FPSmultiply.test.cpp
---
