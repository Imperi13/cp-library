---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/WaveletMatrix/BitVector.hpp
    title: lib/WaveletMatrix/BitVector.hpp
  - icon: ':heavy_check_mark:'
    path: lib/WaveletMatrix/WaveletMatrix.hpp
    title: lib/WaveletMatrix/WaveletMatrix.hpp
  - icon: ':heavy_check_mark:'
    path: lib/utility/bit.hpp
    title: lib/utility/bit.hpp
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
    \n\n#line 5 \"lib/WaveletMatrix/BitVector.hpp\"\n\n#line 2 \"lib/utility/bit.hpp\"\
    \n\n#line 2 \"lib/utility/type_alias.hpp\"\n\n#line 4 \"lib/utility/type_alias.hpp\"\
    \n\nusing u64 = std::uint64_t;\nusing u32 = std::uint32_t;\nusing u16 = std::uint16_t;\n\
    using u8 = std::uint8_t;\n\nusing i64 = std::int64_t;\nusing i32 = std::int32_t;\n\
    using i16 = std::int16_t;\nusing i8 = std::int8_t;\n\nusing usize = std::size_t;\n\
    using isize = std::ptrdiff_t;\n\nconstexpr i64 operator\"\" _i64(unsigned long\
    \ long num) { return i64(num); }\n\nconstexpr u64 operator\"\" _u64(unsigned long\
    \ long num) { return u64(num); }\n#line 4 \"lib/utility/bit.hpp\"\n\nconstexpr\
    \ u64 next_combination(u64 num) {\n  u64 x = num & (-num);\n  u64 y = x + num;\n\
    \  return y | (((num & ~y) / x) >> 1);\n}\n\nconstexpr u32 popcount32(u32 x) {\n\
    #ifdef __GNUC__\n\n  return __builtin_popcount(x);\n\n#else\n\n  x = (x & 0x55555555)\
    \ + (x >> 1 & 0x55555555);\n  x = (x & 0x33333333) + (x >> 2 & 0x33333333);\n\
    \  x = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);\n  x = (x & 0x00ff00ff) + (x\
    \ >> 8 & 0x00ff00ff);\n  return (x & 0x0000ffff) + (x >> 16 & 0x0000ffff);\n\n\
    #endif\n}\n\nconstexpr u64 popcount64(u64 x) {\n#ifdef __GNUC__\n\n  return __builtin_popcountll(x);\n\
    \n#else\n\n  x = (x & 0x5555555555555555) + (x >> 1 & 0x5555555555555555);\n \
    \ x = (x & 0x3333333333333333) + (x >> 2 & 0x3333333333333333);\n  x = (x & 0x0f0f0f0f0f0f0f0f)\
    \ + (x >> 4 & 0x0f0f0f0f0f0f0f0f);\n  x = (x & 0x00ff00ff00ff00ff) + (x >> 8 &\
    \ 0x00ff00ff00ff00ff);\n  x = (x & 0x0000ffff0000ffff) + (x >> 16 & 0x0000ffff0000ffff);\n\
    \  return (x & 0x00000000ffffffff) + (x >> 32 & 0x00000000ffffffff);\n\n#endif\n\
    }\n\n#ifdef __GNUC__\n#include <x86intrin.h>\n#endif\n\nu64 select64(u64 num,\
    \ u64 i) {\n#ifdef __AVX2__\n  u64 z = 1_u64 << i;\n  u64 y = _pdep_u64(z, num);\n\
    \  return _tzcnt_u64(y);\n#else\n  u64 ret = 0;\n  for (u64 bitlen = 32; bitlen\
    \ > 0; bitlen >>= 1) {\n    u64 popcnt = popcount64(num & ((1_u64 << bitlen) -\
    \ 1) << ret);\n    if (popcnt <= i) {\n      i -= popcnt;\n      ret += bitlen;\n\
    \    }\n  }\n  return ret;\n#endif\n}\n#line 8 \"lib/WaveletMatrix/BitVector.hpp\"\
    \n\nclass BitVector {\n private:\n  constexpr static usize LBLOCK = 1ul << 16;\n\
    \  constexpr static usize SBLOCK = 64;\n\n  usize n;\n  usize bitcnt;\n\n  std::vector<u64>\
    \ raw_bit;\n\n  std::vector<u32> rank_l;\n  std::vector<u16> rank_s;\n\n  bool\
    \ build_flag;\n\n public:\n  BitVector() = delete;\n  explicit BitVector(usize\
    \ n_)\n      : n(n_),\n        raw_bit(n / SBLOCK + 1),\n        rank_l(n / LBLOCK\
    \ + 1),\n        rank_s(n / SBLOCK + 1),\n        build_flag(false) {\n    assert(n_\
    \ <= std::numeric_limits<u32>::max());\n  }\n\n  void set(usize pos) {\n    assert(!build_flag);\n\
    \    assert(pos < n);\n    raw_bit[pos / SBLOCK] |= 1_u64 << (pos % SBLOCK);\n\
    \  }\n\n  void build() {\n    assert(!build_flag);\n    u32 cnt = 0;\n    for\
    \ (usize i = 0; i <= n; i++) {\n      if (i % LBLOCK == 0) rank_l[i / LBLOCK]\
    \ = cnt;\n      if (i % SBLOCK == 0) rank_s[i / SBLOCK] = cnt - rank_l[i / LBLOCK];\n\
    \      if (i != n && i % SBLOCK == 0) cnt += popcount64(raw_bit[i / SBLOCK]);\n\
    \    }\n    bitcnt = cnt;\n    build_flag = true;\n  }\n\n  bool operator[](usize\
    \ pos) {\n    assert(build_flag);\n    assert(pos < n);\n    return (raw_bit[pos\
    \ / SBLOCK] >> (pos % SBLOCK)) & 1;\n  }\n\n  usize rank(usize pos) {\n    assert(build_flag);\n\
    \    assert(pos <= n);\n    return rank_l[pos / LBLOCK] + rank_s[pos / SBLOCK]\
    \ +\n           popcount64(raw_bit[pos / SBLOCK] & ((1_u64 << (pos % SBLOCK))\
    \ - 1));\n  }\n\n  usize select1(usize i) {\n    assert(build_flag);\n    assert(bitcnt\
    \ > i);\n    usize l = 0, r = n / LBLOCK + 1;\n    while (r - l > 1) {\n     \
    \ usize mid = (l + r) >> 1;\n      if (rank_l[mid] <= i)\n        l = mid;\n \
    \     else\n        r = mid;\n    }\n    i -= rank_l[l];\n    l *= (LBLOCK / SBLOCK);\n\
    \    r = std::min(r * (LBLOCK / SBLOCK), n / SBLOCK + 1);\n    while (r - l >\
    \ 1) {\n      usize mid = (l + r) >> 1;\n      if (rank_s[mid] <= i)\n       \
    \ l = mid;\n      else\n        r = mid;\n    }\n    i -= rank_s[l];\n    return\
    \ l * SBLOCK + select64(raw_bit[l], i);\n  }\n\n  usize select0(usize i) {\n \
    \   assert(build_flag);\n    assert(n - bitcnt > i);\n    usize l = 0, r = n /\
    \ LBLOCK + 1;\n    while (r - l > 1) {\n      usize mid = (l + r) >> 1;\n    \
    \  if (mid * LBLOCK - rank_l[mid] <= i)\n        l = mid;\n      else\n      \
    \  r = mid;\n    }\n    i -= l * LBLOCK - rank_l[l];\n    l *= (LBLOCK / SBLOCK);\n\
    \    r = std::min(r * (LBLOCK / SBLOCK), n / SBLOCK + 1);\n    usize offset =\
    \ l;\n    while (r - l > 1) {\n      usize mid = (l + r) >> 1;\n      if ((mid\
    \ - offset) * SBLOCK - rank_s[mid] <= i)\n        l = mid;\n      else\n     \
    \   r = mid;\n    }\n    i -= (l - offset) * SBLOCK - rank_s[l];\n    return l\
    \ * SBLOCK + select64(~raw_bit[l], i);\n  }\n};\n#line 10 \"lib/WaveletMatrix/WaveletMatrix.hpp\"\
    \n\ntemplate <typename UInt, std::uint64_t BITLEN>\nclass WaveletMatric {\n  static_assert(std::is_integral<UInt>::value,\
    \ \"UInt must be integer\");\n  static_assert(std::is_unsigned<UInt>::value, \"\
    UInt must be unsigned\");\n  static_assert(0 < BITLEN && BITLEN <= std::numeric_limits<UInt>::digits,\
    \ \"\");\n\n public:\n  using value_t = UInt;\n  using size_t = std::size_t;\n\
    \n private:\n  using u32 = std::uint32_t;\n  using BitVec = BitVector;\n\n  size_t\
    \ n;\n  std::vector<BitVec> bitvec;\n  std::vector<u32> zerocnt;\n  std::map<value_t,\
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
  - lib/utility/bit.hpp
  - lib/utility/type_alias.hpp
  isVerificationFile: true
  path: test/WaveletMatrix.test.cpp
  requiredBy: []
  timestamp: '2021-11-02 10:46:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/WaveletMatrix.test.cpp
layout: document
redirect_from:
- /verify/test/WaveletMatrix.test.cpp
- /verify/test/WaveletMatrix.test.cpp.html
title: test/WaveletMatrix.test.cpp
---
