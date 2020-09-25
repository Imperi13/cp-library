---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/DisjointSparseTable.hpp
    title: lib/DisjointSparseTable.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/DisjointSparseTable.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include <algorithm>\n#include\
    \ <array>\n#include <bitset>\n#include <cassert>\n#include <cctype>\n#include\
    \ <cstdint>\n#include <cstdlib>\n#include <cmath>\n#include <complex>\n#include\
    \ <chrono>\n#include <deque>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <map>\n#include <memory>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n\
    #include <vector>\n#include <random>\n#include <utility>\n#include <limits>\n\
    #include <list>\n#include <type_traits>\n\n/* template start */\n \n#define rep(i,\
    \ a, b) for (long long i = (a); (i) < (b); (i)++)\n#define all(i) i.begin(), i.end()\n\
    \n#ifdef LOCAL\n#define debug(...) std::cerr << \"[\" << #__VA_ARGS__ << \"]:\"\
    , debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\nvoid debug_out(){std::cerr<<std::endl;}\n\
    \ntemplate<typename Head,typename... Tail>\nvoid debug_out(Head h,Tail... t){\n\
    \  std::cerr<<\" \"<<h;\n  if(sizeof...(t)>0)std::cout<<\" :\";\n  debug_out(t...);\n\
    }\n \ntemplate <typename T1, typename T2>\nstd::ostream& operator<<(std::ostream&\
    \ os, std::pair<T1, T2> pa) {\n  return os << pa.first << \" \" << pa.second;\n\
    }\n \ntemplate <typename T>\nstd::ostream& operator<<(std::ostream& os, std::vector<T>\
    \ vec) {\n  for (std::size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1\
    \ == vec.size() ? \"\" : \" \");\n  return os;\n}\n \ntemplate<typename T1,typename\
    \ T2>\ninline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}\n \ntemplate<typename\
    \ T1,typename T2>\ninline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}\n\n\
    template<typename Num>\nconstexpr Num mypow(Num a, long long b) {\n  if(b==0)return\
    \ 1;\n  if (a==0)return 0;\n  Num x = 1;\n  while (b > 0) {\n    if(b & 1)x*=a;\n\
    \    a*=a;\n    b >>= 1;\n  }\n  return x;\n}\n\n/* template end */\n\nusing ll\
    \ = long long;\n\n#line 2 \"lib/DisjointSparseTable.hpp\"\n\n#line 5 \"lib/DisjointSparseTable.hpp\"\
    \n\ntemplate <typename Semigroup>\nclass DisjointSparseTable {\n public:\n  using\
    \ value_t = typename Semigroup::value_t;\n  using size_t = std::size_t;\n\n private:\n\
    \  size_t n, n0;\n  std::vector<size_t> ln;\n  std::vector<std::vector<value_t>>\
    \ table;\n\n public:\n  DisjointSparseTable(const std::vector<value_t>& a) : n(a.size())\
    \ {\n    n0 = 1;\n    while (n0 < n) n0 <<= 1;\n    ln = std::vector<size_t>(n0\
    \ + 1, 0);\n    for (size_t i = 1; i < n0 + 1; i++)\n      ln[i] = ln[i - 1] +\
    \ (i >= (1ull << (ln[i - 1] + 1)));\n    table = std::vector<std::vector<value_t>>(ln[n0]\
    \ + 1, a);\n    for (size_t i = 1; i < ln[n0] + 1; i++) {\n      for (long long\
    \ j = 1ll << (i - 1); j < n; j += 1ll << i) {\n        for (long long k = j -\
    \ 2; k >= j - (1ll << (i - 1)); k--)\n          table[i][k] = Semigroup::op(a[k],\
    \ table[i][k + 1]);\n        for (long long k = j + 1;\n             k < std::min(j\
    \ + (1ll << (i - 1)), (long long)n); k++)\n          table[i][k] = Semigroup::op(table[i][k\
    \ - 1], a[k]);\n      }\n    }\n  }\n\n  value_t fold(size_t l, size_t r) {\n\
    \    assert(0 <= l && l < r && r <= n);\n    if (r == l + 1) return table[0][l];\n\
    \    size_t m = ln[l ^ (r - 1)];\n    return Semigroup::op(table[m + 1][l], table[m\
    \ + 1][r - 1]);\n  }\n};\n#line 87 \"test/DisjointSparseTable.test.cpp\"\n\nstruct\
    \ Semigroup{\n  using value_t=ll;\n  static constexpr value_t op(value_t a,value_t\
    \ b){\n    return a+b;\n  }\n};\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  ll n,q;\n  std::cin>>n>>q;\n\n  std::vector<ll> a(n);\n  for(auto&& e:a)std::cin>>e;\n\
    \n  DisjointSparseTable<Semigroup> seq(a);\n\n  while(q--){\n    ll l,r;\n   \
    \ std::cin>>l>>r;\n    std::cout<<seq.fold(l,r)<<\"\\n\";\n  }\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
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
    \ template end */\n\nusing ll = long long;\n\n#include \"../lib/DisjointSparseTable.hpp\"\
    \n\nstruct Semigroup{\n  using value_t=ll;\n  static constexpr value_t op(value_t\
    \ a,value_t b){\n    return a+b;\n  }\n};\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios::sync_with_stdio(false);\n\n  ll n,q;\n  std::cin>>n>>q;\n\n  std::vector<ll>\
    \ a(n);\n  for(auto&& e:a)std::cin>>e;\n\n  DisjointSparseTable<Semigroup> seq(a);\n\
    \n  while(q--){\n    ll l,r;\n    std::cin>>l>>r;\n    std::cout<<seq.fold(l,r)<<\"\
    \\n\";\n  }\n\n  return 0;\n}"
  dependsOn:
  - lib/DisjointSparseTable.hpp
  isVerificationFile: true
  path: test/DisjointSparseTable.test.cpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DisjointSparseTable.test.cpp
layout: document
redirect_from:
- /verify/test/DisjointSparseTable.test.cpp
- /verify/test/DisjointSparseTable.test.cpp.html
title: test/DisjointSparseTable.test.cpp
---
