---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/math/DynamicMatrix.hpp
    title: lib/math/DynamicMatrix.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/DynamicMatrix_2.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cstdint>\n#include <cstdlib>\n#include <cmath>\n\
    #include <complex>\n#include <chrono>\n#include <deque>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <map>\n#include <memory>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <type_traits>\n#include <unordered_map>\n#include <vector>\n#include\
    \ <random>\n#include <utility>\n#include <limits>\n#include <list>\n\n/* template\
    \ start */\n \n#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)\n\
    #define all(i) i.begin(), i.end()\n\n#ifdef LOCAL\n#define debug(...) std::cerr\
    \ << \"[\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n\
    #endif\n\nvoid debug_out(){std::cerr<<std::endl;}\n\ntemplate<typename Head,typename...\
    \ Tail>\nvoid debug_out(Head h,Tail... t){\n  std::cerr<<\" \"<<h;\n  if(sizeof...(t)>0)std::cout<<\"\
    \ :\";\n  debug_out(t...);\n}\n \ntemplate <typename T1, typename T2>\nstd::ostream&\
    \ operator<<(std::ostream& os, std::pair<T1, T2> pa) {\n  return os << pa.first\
    \ << \" \" << pa.second;\n}\n \ntemplate <typename T>\nstd::ostream& operator<<(std::ostream&\
    \ os, std::vector<T> vec) {\n  for (std::size_t i = 0; i < vec.size(); i++)os\
    \ << vec[i] << (i + 1 == vec.size() ? \"\" : \" \");\n  return os;\n}\n \ntemplate<typename\
    \ T1,typename T2>\ninline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}\n\
    \ \ntemplate<typename T1,typename T2>\ninline bool chmin(T1& a,T2 b){return a>b\
    \ && (a=b,true);}\n\ntemplate<typename Num>\nconstexpr Num mypow(Num a, unsigned\
    \ long long b) {\n  if(b==0)return 1;\n  if (a==0)return 0;\n  Num x = 1;\n  while\
    \ (b > 0) {\n    if(b & 1)x*=a;\n    a*=a;\n    b >>= 1;\n  }\n  return x;\n}\n\
    \n/* template end */\n\nusing ll = long long;\n\n#line 2 \"lib/math/DynamicMatrix.hpp\"\
    \n\n#line 6 \"lib/math/DynamicMatrix.hpp\"\n\ntemplate <typename Field>\nclass\
    \ DynamicMatrix {\n public:\n  using value_t = Field;\n  using size_t = std::size_t;\n\
    \  size_t row, column;\n\n private:\n  std::vector<std::vector<value_t>> a;\n\n\
    \ public:\n  explicit DynamicMatrix(size_t row_ = 0, size_t column_ = 0,\n   \
    \                      value_t init_ = value_t())\n      : row(row_),\n      \
    \  column(column_),\n        a(row, std::vector<value_t>(column, init_)) {}\n\n\
    \  constexpr value_t& operator()(size_t i, size_t j) {\n    assert(0 <= i && i\
    \ < row && 0 <= j && j < column);\n    return a[i][j];\n  }\n  constexpr bool\
    \ operator==(const DynamicMatrix& rhs) {\n    if (row != rhs.row || column !=\
    \ rhs.column) return false;\n    for (size_t i = 0; i < row; i++) {\n      for\
    \ (size_t j = 0; j < column; j++) {\n        if (a[i][j] != rhs.a[i][j]) return\
    \ false;\n      }\n    }\n    return true;\n  }\n  constexpr bool operator!=(const\
    \ DynamicMatrix& rhs) {\n    return !(*this == rhs);\n  }\n\n  constexpr DynamicMatrix\
    \ operator+(const DynamicMatrix rhs) {\n    return DynamicMatrix(*this) += rhs;\n\
    \  }\n  constexpr DynamicMatrix operator-(const DynamicMatrix rhs) {\n    return\
    \ DynamicMatrix(*this) -= rhs;\n  }\n  constexpr DynamicMatrix operator*(const\
    \ DynamicMatrix rhs) {\n    return DynamicMatrix(*this) *= rhs;\n  }\n\n  constexpr\
    \ DynamicMatrix& operator+=(const DynamicMatrix& rhs) {\n    assert(row == rhs.row\
    \ && column == rhs.column);\n    for (size_t i = 0; i < row; i++) {\n      for\
    \ (size_t j = 0; j < column; j++) {\n        a[i][j] += rhs.a[i][j];\n      }\n\
    \    }\n    return *this;\n  }\n  constexpr DynamicMatrix& operator-=(const DynamicMatrix&\
    \ rhs) {\n    assert(row == rhs.row && column == rhs.column);\n    for (size_t\
    \ i = 0; i < row; i++) {\n      for (size_t j = 0; j < column; j++) {\n      \
    \  a[i][j] -= rhs.a[i][j];\n      }\n    }\n    return *this;\n  }\n  constexpr\
    \ DynamicMatrix& operator*=(const DynamicMatrix& rhs) {\n    assert(column ==\
    \ rhs.row);\n    std::vector<std::vector<value_t>> tmp(row,\n                \
    \                          std::vector<value_t>(rhs.column, 0));\n    for (size_t\
    \ r = 0; r < row; r++) {\n      for (size_t c = 0; c < rhs.column; c++) {\n  \
    \      for (size_t i = 0; i < column; i++) {\n          tmp[r][c] += a[r][i] *\
    \ rhs.a[i][c];\n        }\n      }\n    }\n    column = rhs.column;\n    a = std::move(tmp);\n\
    \    return *this;\n  }\n\n  constexpr static DynamicMatrix id(size_t size) {\n\
    \    DynamicMatrix<Field> tmp(size, size);\n    for (size_t i = 0; i < size; i++)\
    \ tmp.a[i][i] = 1;\n    return tmp;\n  }\n\n  constexpr void LUPdecomposition(DynamicMatrix&\
    \ P, DynamicMatrix& L,\n                                  DynamicMatrix& U) {\n\
    \    assert(row == column);\n    std::vector<std::vector<value_t>> tmp = a;\n\
    \    P = DynamicMatrix::id(row);\n    L = DynamicMatrix(row, column, 0);\n   \
    \ U = DynamicMatrix(row, column, 0);\n\n    for (size_t i = 0; i < row; i++) {\n\
    \      for (size_t j = 0; j < column; j++) {\n        value_t val = 0;\n     \
    \   for (size_t k = 0; k < i; k++) val += L.a[j][k] * U.a[k][i];\n        if (val\
    \ != tmp[j][i]) {\n          std::swap(tmp[i], tmp[j]);\n          std::swap(P.a[i],\
    \ P.a[j]);\n          std::swap(L.a[i], L.a[j]);\n          break;\n        }\n\
    \      }\n      L.a[i][i] = 1;\n      for (size_t j = i; j < row; j++) {\n   \
    \     U.a[i][j] = tmp[i][j];\n        for (size_t k = 0; k < i; k++) U.a[i][j]\
    \ -= L.a[i][k] * U.a[k][j];\n      }\n      if (U.a[i][i] != 0) {\n        for\
    \ (size_t j = i + 1; j < row; j++) {\n          L.a[j][i] = tmp[j][i];\n     \
    \     for (size_t k = 0; k < i; k++) L.a[j][i] -= L.a[j][k] * U.a[k][i];\n   \
    \       L.a[j][i] /= U.a[i][i];\n        }\n      }\n    }\n  }\n\n  constexpr\
    \ value_t det() {\n    DynamicMatrix<Field> p, l, u;\n    LUPdecomposition(p,\
    \ l, u);\n    size_t cnt = 0;\n    value_t ret = 0;\n    for (size_t i = 0; i\
    \ < row; i++) {\n      if (p.a[i][i] == 1) continue;\n      for (size_t j = 1;\
    \ j < row; j++) {\n        if (p.a[j][i] == 1) {\n          std::swap(p.a[i],\
    \ p.a[j]);\n          cnt++;\n          break;\n        }\n      }\n    }\n  \
    \  if (cnt & 1)\n      ret -= 1;\n    else\n      ret += 1;\n    for (size_t i\
    \ = 0; i < row; i++) ret *= u.a[i][i];\n    return ret;\n  }\n};\n#line 87 \"\
    test/DynamicMatrix_2.test.cpp\"\n\n#line 2 \"lib/utility/modint.hpp\"\n\n/*\n\
    \  author:noshi91\n  reference:https://noshi91.hatenablog.com/entry/2019/03/31/174006\n\
    \            https://github.com/noshi91/Library/blob/master/other/modint.cpp\n\
    \n  1\u3064\u3081\u306Emodint\u306Boperator==,!=\u3092\u8FFD\u52A0\u3057\u305F\
    \u3082\u306E\u3067\u3059\n\n  thx @noshi91!!\n*/\n\n#line 2 \"lib/utility/type_alias.hpp\"\
    \n\n#line 4 \"lib/utility/type_alias.hpp\"\n\nusing i64 = std::int64_t;\nusing\
    \ i32 = std::int32_t;\nusing i16 = std::int16_t;\nusing i8 = std::int8_t;\n\n\
    using u64 = std::uint64_t;\nusing u32 = std::uint32_t;\nusing u16 = std::uint16_t;\n\
    using u8 = std::uint8_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    \nconstexpr i64 operator\"\" _i64(unsigned long long num) { return i64(num); }\n\
    constexpr i32 operator\"\" _i32(unsigned long long num) { return i32(num); }\n\
    constexpr i16 operator\"\" _i16(unsigned long long num) { return i16(num); }\n\
    constexpr i8 operator\"\" _i8(unsigned long long num) { return i8(num); }\n\n\
    constexpr u64 operator\"\" _u64(unsigned long long num) { return u64(num); }\n\
    constexpr u32 operator\"\" _u32(unsigned long long num) { return u32(num); }\n\
    constexpr u16 operator\"\" _u16(unsigned long long num) { return u16(num); }\n\
    constexpr u8 operator\"\" _u8(unsigned long long num) { return u8(num); }\n#line\
    \ 16 \"lib/utility/modint.hpp\"\n\ntemplate <u64 Modulus>\nclass modint {\n\n\
    \ public:\n  constexpr static u64 mod = Modulus;\n  u64 a;\n\n  constexpr modint(const\
    \ u64 x = 0) noexcept : a(x % Modulus) {}\n  constexpr u64 &value() noexcept {\
    \ return a; }\n  constexpr const u64 &value() const noexcept { return a; }\n \
    \ constexpr bool operator==(const modint rhs) const noexcept {\n    return a ==\
    \ rhs.a;\n  }\n  constexpr bool operator!=(const modint rhs) const noexcept {\n\
    \    return !(*this == rhs);\n  }\n  constexpr modint operator+(const modint rhs)\
    \ const noexcept {\n    return modint(*this) += rhs;\n  }\n  constexpr modint\
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
    \ {\n  return os << a.value();\n}\n#line 89 \"test/DynamicMatrix_2.test.cpp\"\n\
    \nconstexpr ll MOD=998244353;\n\nusing mint=modint<MOD>;\n\nusing mat=DynamicMatrix<mint>;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  ll n;\n  std::cin>>n;\n\n  mat tmp(n,n);\n\n  rep(i,0,n){\n    rep(j,0,n){\n\
    \      ll e;\n      std::cin>>e;\n      tmp(i,j)=e;\n    }\n  }\n\n  std::cout<<tmp.det().value()<<\"\
    \\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cctype>\n#include <cstdint>\n#include <cstdlib>\n#include <cmath>\n#include\
    \ <complex>\n#include <chrono>\n#include <deque>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <map>\n#include <memory>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <type_traits>\n#include <unordered_map>\n#include <vector>\n#include\
    \ <random>\n#include <utility>\n#include <limits>\n#include <list>\n\n/* template\
    \ start */\n \n#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)\n\
    #define all(i) i.begin(), i.end()\n\n#ifdef LOCAL\n#define debug(...) std::cerr\
    \ << \"[\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n\
    #endif\n\nvoid debug_out(){std::cerr<<std::endl;}\n\ntemplate<typename Head,typename...\
    \ Tail>\nvoid debug_out(Head h,Tail... t){\n  std::cerr<<\" \"<<h;\n  if(sizeof...(t)>0)std::cout<<\"\
    \ :\";\n  debug_out(t...);\n}\n \ntemplate <typename T1, typename T2>\nstd::ostream&\
    \ operator<<(std::ostream& os, std::pair<T1, T2> pa) {\n  return os << pa.first\
    \ << \" \" << pa.second;\n}\n \ntemplate <typename T>\nstd::ostream& operator<<(std::ostream&\
    \ os, std::vector<T> vec) {\n  for (std::size_t i = 0; i < vec.size(); i++)os\
    \ << vec[i] << (i + 1 == vec.size() ? \"\" : \" \");\n  return os;\n}\n \ntemplate<typename\
    \ T1,typename T2>\ninline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}\n\
    \ \ntemplate<typename T1,typename T2>\ninline bool chmin(T1& a,T2 b){return a>b\
    \ && (a=b,true);}\n\ntemplate<typename Num>\nconstexpr Num mypow(Num a, unsigned\
    \ long long b) {\n  if(b==0)return 1;\n  if (a==0)return 0;\n  Num x = 1;\n  while\
    \ (b > 0) {\n    if(b & 1)x*=a;\n    a*=a;\n    b >>= 1;\n  }\n  return x;\n}\n\
    \n/* template end */\n\nusing ll = long long;\n\n#include \"../lib/math/DynamicMatrix.hpp\"\
    \n\n#include \"../lib/utility/modint.hpp\"\n\nconstexpr ll MOD=998244353;\n\n\
    using mint=modint<MOD>;\n\nusing mat=DynamicMatrix<mint>;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios::sync_with_stdio(false);\n\n  ll n;\n  std::cin>>n;\n\n  mat tmp(n,n);\n\
    \n  rep(i,0,n){\n    rep(j,0,n){\n      ll e;\n      std::cin>>e;\n      tmp(i,j)=e;\n\
    \    }\n  }\n\n  std::cout<<tmp.det().value()<<\"\\n\";\n\n  return 0;\n}"
  dependsOn:
  - lib/math/DynamicMatrix.hpp
  - lib/utility/modint.hpp
  - lib/utility/type_alias.hpp
  isVerificationFile: true
  path: test/DynamicMatrix_2.test.cpp
  requiredBy: []
  timestamp: '2024-07-20 17:36:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DynamicMatrix_2.test.cpp
layout: document
redirect_from:
- /verify/test/DynamicMatrix_2.test.cpp
- /verify/test/DynamicMatrix_2.test.cpp.html
title: test/DynamicMatrix_2.test.cpp
---