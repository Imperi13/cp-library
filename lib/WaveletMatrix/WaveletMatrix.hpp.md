---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/WaveletMatrix/BitVector.hpp
    title: lib/WaveletMatrix/BitVector.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/WaveletMatrix.test.cpp
    title: test/WaveletMatrix.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/WaveletMatrix/WaveletMatrix.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <cstdint>\n#include <map>\n#include <vector>\n\n\
    #line 2 \"lib/WaveletMatrix/BitVector.hpp\"\n\n#line 6 \"lib/WaveletMatrix/BitVector.hpp\"\
    \n#include <utility>\n#line 8 \"lib/WaveletMatrix/BitVector.hpp\"\n\ntemplate\
    \ <std::size_t LBLOCK = 400, std::size_t SBLOCK = 16>\nclass BitVector {\n  static_assert(LBLOCK\
    \ % SBLOCK == 0, \"\");\n  static_assert(0 < SBLOCK && SBLOCK <= 16, \"\");\n\n\
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
    \ r, lower);\n  }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <cstdint>\n\
    #include <map>\n#include <vector>\n\n#include \"./BitVector.hpp\"\n\ntemplate\
    \ <typename UInt, std::uint64_t BITLEN>\nclass WaveletMatric {\n  static_assert(std::is_integral<UInt>::value,\
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
    \ r, lower);\n  }\n};"
  dependsOn:
  - lib/WaveletMatrix/BitVector.hpp
  isVerificationFile: false
  path: lib/WaveletMatrix/WaveletMatrix.hpp
  requiredBy: []
  timestamp: '2020-08-07 13:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/WaveletMatrix.test.cpp
documentation_of: lib/WaveletMatrix/WaveletMatrix.hpp
layout: document
redirect_from:
- /library/lib/WaveletMatrix/WaveletMatrix.hpp
- /library/lib/WaveletMatrix/WaveletMatrix.hpp.html
title: lib/WaveletMatrix/WaveletMatrix.hpp
---
