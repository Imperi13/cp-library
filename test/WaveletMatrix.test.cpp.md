---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/WaveletMatrix/BitVector.hpp
    title: lib/WaveletMatrix/BitVector.hpp
  - icon: ':heavy_check_mark:'
    path: lib/WaveletMatrix/WaveletMatrix.hpp
    title: lib/WaveletMatrix/WaveletMatrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/WaveletMatrix.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\
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
    \ template end */\n\nusing ll = long long;\n\n#line 2 \"lib/WaveletMatrix/WaveletMatrix.hpp\"\
    \n\n#line 8 \"lib/WaveletMatrix/WaveletMatrix.hpp\"\n\n#line 2 \"lib/WaveletMatrix/BitVector.hpp\"\
    \n\n#line 8 \"lib/WaveletMatrix/BitVector.hpp\"\n\ntemplate <std::size_t LBLOCK\
    \ = 400, std::size_t SBLOCK = 16>\nclass BitVector {\n  static_assert(LBLOCK %\
    \ SBLOCK == 0, \"\");\n  static_assert(0 < SBLOCK && SBLOCK <= 16, \"\");\n\n\
    \ public:\n  using size_t = std::size_t;\n  using u32 = std::uint32_t;\n  using\
    \ u16 = std::uint16_t;\n\n private:\n  static constexpr u16 popcount(u16 x) {\n\
    \    x = (x & 0x5555) + (x >> 1 & 0x5555);\n    x = (x & 0x3333) + (x >> 2 & 0x3333);\n\
    \    x = (x & 0x0f0f) + (x >> 4 & 0x0f0f);\n    return (x & 0x00ff) + (x >> 8\
    \ & 0x00ff);\n  }\n\n  size_t n;\n  size_t bitcnt;\n\n  std::vector<u32> l;\n\
    \  std::vector<std::pair<u16, u16>> s;\n\n  bool build_flag;\n\n public:\n  BitVector()\
    \ = delete;\n  explicit BitVector(size_t n_)\n      : n(n_), l(n / LBLOCK + 1),\
    \ s(n / SBLOCK + 1, {0, 0}),build_flag(false) {}\n\n  void set(size_t pos) {\n\
    \    assert(!build_flag);\n    assert(0 <= pos && pos < n);\n    s[pos / SBLOCK].second\
    \ |= 1llu << (pos % SBLOCK);\n  }\n\n  void build() {\n    u32 num = 0;\n    for\
    \ (size_t i = 0; i <= n; i++) {\n      if (i % LBLOCK == 0) l[i / LBLOCK] = num;\n\
    \      if (i % SBLOCK == 0) s[i / SBLOCK].first = num - l[i / LBLOCK];\n     \
    \ if (i != n && i % SBLOCK == 0) {\n        num += popcount(s[i / SBLOCK].second);\n\
    \      }\n    }\n    bitcnt = num;\n    build_flag=true;\n  }\n\n  bool operator[](size_t\
    \ pos) {\n    assert(build_flag);\n    assert(0 <= pos && pos < n);\n    return\
    \ (s[pos / SBLOCK].second >> (pos % SBLOCK)) & 1;\n  }\n\n  size_t rank(size_t\
    \ pos) {\n    assert(build_flag);\n    assert(0 <= pos && pos <= n);\n    return\
    \ l[pos / LBLOCK] + s[pos / SBLOCK].first +\n           popcount(s[pos / SBLOCK].second\
    \ & ((1llu << (pos % SBLOCK)) - 1));\n  }\n};\n#line 10 \"lib/WaveletMatrix/WaveletMatrix.hpp\"\
    \n\ntemplate <typename UInt, std::uint64_t BITLEN>\nclass WaveletMatric {\n  static_assert(std::is_integral<UInt>::value,\
    \ \"UInt must be integer\");\n  static_assert(std::is_unsigned<UInt>::value, \"\
    UInt must be unsigned\");\n  static_assert(0 < BITLEN && BITLEN <= std::numeric_limits<UInt>::digits,\
    \ \"\");\n\n public:\n  using value_t = UInt;\n  using size_t = std::size_t;\n\
    \n private:\n  using u32 = std::uint32_t;\n  using BitVec = BitVector<>;\n\n \
    \ size_t n;\n  std::vector<BitVec> bitvec;\n  std::vector<u32> zerocnt;\n  std::map<value_t,\
    \ std::pair<u32, u32>> index;\n\n  size_t less(size_t l, size_t r, value_t num)\
    \ {\n    u32 ret = 0;\n    for (int bit = BITLEN - 1; bit >= 0; bit--) {\n   \
    \   if ((num >> bit) & 1) {\n        ret += (r - bitvec[bit].rank(r)) - (l - bitvec[bit].rank(l));\n\
    \        l = zerocnt[bit] + bitvec[bit].rank(l);\n        r = zerocnt[bit] + bitvec[bit].rank(r);\n\
    \      } else {\n        l -= bitvec[bit].rank(l);\n        r -= bitvec[bit].rank(r);\n\
    \      }\n    }\n    return ret;\n  }\n\n public:\n  explicit WaveletMatric(std::vector<value_t>\
    \ seq)\n      : n(seq.size()), bitvec(BITLEN, BitVec(n)), zerocnt(BITLEN) {\n\
    \    for (int bit = BITLEN - 1; bit >= 0; bit--) {\n      std::vector<value_t>\
    \ zero, one;\n      zero.reserve(n);\n      for (size_t j = 0; j < n; j++) {\n\
    \        if ((seq[j] >> bit) & 1) {\n          bitvec[bit].set(j);\n         \
    \ one.emplace_back(seq[j]);\n        } else {\n          zero.emplace_back(seq[j]);\n\
    \        }\n      }\n      bitvec[bit].build();\n      std::copy(one.begin(),\
    \ one.end(), std::back_inserter(zero));\n      seq = zero;\n      zerocnt[bit]\
    \ = n - bitvec[bit].rank(n);\n    }\n    index[seq[0]] = {0, 0};\n    value_t\
    \ num = seq[0];\n    for (size_t i = 0; i < n; i++) {\n      if (seq[i] != num)\
    \ {\n        index[seq[i]] = {i, 1};\n        num = seq[i];\n      } else {\n\
    \        index[num].second++;\n      }\n    }\n  }\n\n  value_t quantile(size_t\
    \ l, size_t r, size_t pos) {\n    assert(0 <= l && l < r && r <= n);\n    assert(0\
    \ <= pos && pos < r - l);\n    value_t ret = 0;\n    for (int bit = BITLEN - 1;\
    \ bit >= 0; bit--) {\n      size_t zero = (r - bitvec[bit].rank(r)) - (l - bitvec[bit].rank(l));\n\
    \      if (pos < zero) {\n        l -= bitvec[bit].rank(l);\n        r = l + zero;\n\
    \      } else {\n        ret += (1llu << bit);\n        pos -= zero;\n       \
    \ size_t one = r - l - zero;\n        l = zerocnt[bit] + bitvec[bit].rank(l);\n\
    \        r = l + one;\n      }\n    }\n    return ret;\n  }\n\n  size_t rangefreq(size_t\
    \ l, size_t r, value_t lower, value_t upper) {\n    assert(0 <= l && l <= r &&\
    \ r <= n);\n    assert(lower <= upper);\n    return less(l, r, upper) - less(l,\
    \ r, lower);\n  }\n};\n#line 87 \"test/WaveletMatrix.test.cpp\"\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\n  ll n,q;\n\
    \  std::cin>>n>>q;\n\n  using u32=uint32_t;\n\n  std::vector<u32> a(n);\n  for(auto&&\
    \ e:a)std::cin>>e;\n\n  WaveletMatric<u32,30> seq(a);\n\n  while(q--){\n    ll\
    \ l,r,k;\n    std::cin>>l>>r>>k;\n    std::cout<<seq.quantile(l,r,k)<<\"\\n\"\
    ;\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
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
    \ template end */\n\nusing ll = long long;\n\n#include \"../lib/WaveletMatrix/WaveletMatrix.hpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  ll n,q;\n  std::cin>>n>>q;\n\n  using u32=uint32_t;\n\n  std::vector<u32>\
    \ a(n);\n  for(auto&& e:a)std::cin>>e;\n\n  WaveletMatric<u32,30> seq(a);\n\n\
    \  while(q--){\n    ll l,r,k;\n    std::cin>>l>>r>>k;\n    std::cout<<seq.quantile(l,r,k)<<\"\
    \\n\";\n  }\n\n  return 0;\n}"
  dependsOn:
  - lib/WaveletMatrix/WaveletMatrix.hpp
  - lib/WaveletMatrix/BitVector.hpp
  isVerificationFile: true
  path: test/WaveletMatrix.test.cpp
  requiredBy: []
  timestamp: '2020-08-07 13:20:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/WaveletMatrix.test.cpp
layout: document
redirect_from:
- /verify/test/WaveletMatrix.test.cpp
- /verify/test/WaveletMatrix.test.cpp.html
title: test/WaveletMatrix.test.cpp
---
