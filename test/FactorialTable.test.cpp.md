---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/FactorialTable.hpp
    title: lib/math/FactorialTable.hpp
  - icon: ':heavy_check_mark:'
    path: lib/utility/modint.hpp
    title: lib/utility/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1501
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1501
  bundledCode: "#line 1 \"test/FactorialTable.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1501\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cstdint>\n#include <cstdlib>\n#include <cmath>\n\
    #include <complex>\n#include <chrono>\n#include <deque>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <map>\n#include <memory>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <vector>\n#include <random>\n#include <utility>\n\
    #include <limits>\n#include <list>\n#include <type_traits>\n\n/* template start\
    \ */\n \n#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)\n#define\
    \ all(i) i.begin(), i.end()\n\n#ifdef LOCAL\n#define debug(...) std::cerr << \"\
    [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n\
    #endif\n\nvoid debug_out(){std::cerr<<std::endl;}\n\ntemplate<typename Head,typename...\
    \ Tail>\nvoid debug_out(Head h,Tail... t){\n  std::cerr<<\" \"<<h;\n  if(sizeof...(t)>0)std::cout<<\"\
    \ :\";\n  debug_out(t...);\n}\n \ntemplate <typename T1, typename T2>\nstd::ostream&\
    \ operator<<(std::ostream& os, std::pair<T1, T2> pa) {\n  return os << pa.first\
    \ << \" \" << pa.second;\n}\n \ntemplate <typename T>\nstd::ostream& operator<<(std::ostream&\
    \ os, std::vector<T> vec) {\n  for (std::size_t i = 0; i < vec.size(); i++)os\
    \ << vec[i] << (i + 1 == vec.size() ? \"\" : \" \");\n  return os;\n}\n \ntemplate<typename\
    \ T1,typename T2>\ninline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}\n\
    \ \ntemplate<typename T1,typename T2>\ninline bool chmin(T1& a,T2 b){return a>b\
    \ && (a=b,true);}\n\ntemplate<typename Num>\nconstexpr Num mypow(Num a, long long\
    \ b) {\n  if(b==0)return 1;\n  if (a==0)return 0;\n  Num x = 1;\n  while (b >\
    \ 0) {\n    if(b & 1)x*=a;\n    a*=a;\n    b >>= 1;\n  }\n  return x;\n}\n\n/*\
    \ template end */\n\nusing ll = long long;\n\n#line 2 \"lib/math/FactorialTable.hpp\"\
    \n\n#line 6 \"lib/math/FactorialTable.hpp\"\n\n#line 2 \"lib/utility/modint.hpp\"\
    \n\n/*\n  author:noshi91\n  reference:https://noshi91.hatenablog.com/entry/2019/03/31/174006\n\
    \            https://github.com/noshi91/Library/blob/master/other/modint.cpp\n\
    \n  1\u3064\u3081\u306Emodint\u306Boperator==,!=\u3092\u8FFD\u52A0\u3057\u305F\
    \u3082\u306E\u3067\u3059\n\n  thx @noshi91!!\n*/\n\n#line 14 \"lib/utility/modint.hpp\"\
    \n\ntemplate <std::uint_fast64_t Modulus>\nclass modint {\n  using u64 = std::uint_fast64_t;\n\
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
    \    }\n    return *this;\n  }\n};\n#line 8 \"lib/math/FactorialTable.hpp\"\n\n\
    template <std::size_t N, std::uint_fast64_t MOD>\nclass Factorial {\n public:\n\
    \  using mint = modint<MOD>;\n  using size_t = std::size_t;\n\n private:\n  std::vector<mint>\
    \ factorial, factorial_inv;\n\n public:\n  Factorial() : factorial(N + 1), factorial_inv(N\
    \ + 1) {\n    factorial[0] = 1;\n    for (size_t i = 1; i < N + 1; i++) factorial[i]\
    \ = factorial[i - 1] * i;\n    factorial_inv[N] = mint(1) / factorial[N];\n  \
    \  for (size_t i = N; i > 0; i--) factorial_inv[i - 1] = factorial_inv[i] * i;\n\
    \  }\n\n  mint fact(size_t pos) const {\n    assert(0 <= pos && pos <= N);\n \
    \   return factorial[pos];\n  }\n  mint fact_inv(size_t pos) const {\n    assert(0\
    \ <= pos && pos <= N);\n    return factorial_inv[pos];\n  }\n  mint binom(size_t\
    \ n, size_t k) const {\n    assert(0 <= n && n <= N);\n    assert(0 <= k && k\
    \ <= n);\n    return fact(n) * fact_inv(k) * fact_inv(n - k);\n  }\n};\n#line\
    \ 87 \"test/FactorialTable.test.cpp\"\n\nconstexpr ll MOD=1e8+7;\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\n  Factorial<1010,MOD>\
    \ table;\n\n  ll r,c,ax,ay,bx,by;\n  std::cin>>r>>c>>ax>>ay>>bx>>by;\n\n  ll mul=1;\n\
    \n  ll x=std::abs(ax-bx),y=std::abs(ay-by);\n\n  chmin(x,r-x);\n  chmin(y,c-y);\n\
    \n  if(r==2*x)mul*=2;\n  if(c==2*y)mul*=2;\n\n  std::cout<<(table.binom(x+y,x)*mul).value()<<\"\
    \\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1501\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cstdint>\n#include <cstdlib>\n#include <cmath>\n\
    #include <complex>\n#include <chrono>\n#include <deque>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <map>\n#include <memory>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <vector>\n#include <random>\n#include <utility>\n\
    #include <limits>\n#include <list>\n#include <type_traits>\n\n/* template start\
    \ */\n \n#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)\n#define\
    \ all(i) i.begin(), i.end()\n\n#ifdef LOCAL\n#define debug(...) std::cerr << \"\
    [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n\
    #endif\n\nvoid debug_out(){std::cerr<<std::endl;}\n\ntemplate<typename Head,typename...\
    \ Tail>\nvoid debug_out(Head h,Tail... t){\n  std::cerr<<\" \"<<h;\n  if(sizeof...(t)>0)std::cout<<\"\
    \ :\";\n  debug_out(t...);\n}\n \ntemplate <typename T1, typename T2>\nstd::ostream&\
    \ operator<<(std::ostream& os, std::pair<T1, T2> pa) {\n  return os << pa.first\
    \ << \" \" << pa.second;\n}\n \ntemplate <typename T>\nstd::ostream& operator<<(std::ostream&\
    \ os, std::vector<T> vec) {\n  for (std::size_t i = 0; i < vec.size(); i++)os\
    \ << vec[i] << (i + 1 == vec.size() ? \"\" : \" \");\n  return os;\n}\n \ntemplate<typename\
    \ T1,typename T2>\ninline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}\n\
    \ \ntemplate<typename T1,typename T2>\ninline bool chmin(T1& a,T2 b){return a>b\
    \ && (a=b,true);}\n\ntemplate<typename Num>\nconstexpr Num mypow(Num a, long long\
    \ b) {\n  if(b==0)return 1;\n  if (a==0)return 0;\n  Num x = 1;\n  while (b >\
    \ 0) {\n    if(b & 1)x*=a;\n    a*=a;\n    b >>= 1;\n  }\n  return x;\n}\n\n/*\
    \ template end */\n\nusing ll = long long;\n\n#include \"../lib/math/FactorialTable.hpp\"\
    \n\nconstexpr ll MOD=1e8+7;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  Factorial<1010,MOD> table;\n\n  ll r,c,ax,ay,bx,by;\n  std::cin>>r>>c>>ax>>ay>>bx>>by;\n\
    \n  ll mul=1;\n\n  ll x=std::abs(ax-bx),y=std::abs(ay-by);\n\n  chmin(x,r-x);\n\
    \  chmin(y,c-y);\n\n  if(r==2*x)mul*=2;\n  if(c==2*y)mul*=2;\n\n  std::cout<<(table.binom(x+y,x)*mul).value()<<\"\
    \\n\";\n\n  return 0;\n}"
  dependsOn:
  - lib/math/FactorialTable.hpp
  - lib/utility/modint.hpp
  isVerificationFile: true
  path: test/FactorialTable.test.cpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/FactorialTable.test.cpp
layout: document
redirect_from:
- /verify/test/FactorialTable.test.cpp
- /verify/test/FactorialTable.test.cpp.html
title: test/FactorialTable.test.cpp
---
