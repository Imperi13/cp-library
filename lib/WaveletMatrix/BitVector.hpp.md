---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/WaveletMatrix/WaveletMatrix.hpp
    title: lib/WaveletMatrix/WaveletMatrix.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/WaveletMatrix.test.cpp
    title: test/WaveletMatrix.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"lib/WaveletMatrix/BitVector.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <cstdint>\n#include <utility>\n#include <vector>\n\
    \ntemplate <std::size_t LBLOCK = 400, std::size_t SBLOCK = 16>\nclass BitVector\
    \ {\n  static_assert(LBLOCK % SBLOCK == 0, \"\");\n  static_assert(0 < SBLOCK\
    \ && SBLOCK <= 16, \"\");\n\n public:\n  using size_t = std::size_t;\n  using\
    \ u32 = std::uint32_t;\n  using u16 = std::uint16_t;\n\n private:\n  static constexpr\
    \ u16 popcount(u16 x) {\n    x = (x & 0x5555) + (x >> 1 & 0x5555);\n    x = (x\
    \ & 0x3333) + (x >> 2 & 0x3333);\n    x = (x & 0x0f0f) + (x >> 4 & 0x0f0f);\n\
    \    return (x & 0x00ff) + (x >> 8 & 0x00ff);\n  }\n\n  size_t n;\n  size_t bitcnt;\n\
    \n  std::vector<u32> l;\n  std::vector<std::pair<u16, u16>> s;\n\n  bool build_flag;\n\
    \n public:\n  BitVector() = delete;\n  explicit BitVector(size_t n_)\n      :\
    \ n(n_), l(n / LBLOCK + 1), s(n / SBLOCK + 1, {0, 0}),build_flag(false) {}\n\n\
    \  void set(size_t pos) {\n    assert(!build_flag);\n    assert(0 <= pos && pos\
    \ < n);\n    s[pos / SBLOCK].second |= 1llu << (pos % SBLOCK);\n  }\n\n  void\
    \ build() {\n    u32 num = 0;\n    for (size_t i = 0; i <= n; i++) {\n      if\
    \ (i % LBLOCK == 0) l[i / LBLOCK] = num;\n      if (i % SBLOCK == 0) s[i / SBLOCK].first\
    \ = num - l[i / LBLOCK];\n      if (i != n && i % SBLOCK == 0) {\n        num\
    \ += popcount(s[i / SBLOCK].second);\n      }\n    }\n    bitcnt = num;\n    build_flag=true;\n\
    \  }\n\n  bool operator[](size_t pos) {\n    assert(build_flag);\n    assert(0\
    \ <= pos && pos < n);\n    return (s[pos / SBLOCK].second >> (pos % SBLOCK)) &\
    \ 1;\n  }\n\n  size_t rank(size_t pos) {\n    assert(build_flag);\n    assert(0\
    \ <= pos && pos <= n);\n    return l[pos / LBLOCK] + s[pos / SBLOCK].first +\n\
    \           popcount(s[pos / SBLOCK].second & ((1llu << (pos % SBLOCK)) - 1));\n\
    \  }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <cstdint>\n\
    #include <utility>\n#include <vector>\n\ntemplate <std::size_t LBLOCK = 400, std::size_t\
    \ SBLOCK = 16>\nclass BitVector {\n  static_assert(LBLOCK % SBLOCK == 0, \"\"\
    );\n  static_assert(0 < SBLOCK && SBLOCK <= 16, \"\");\n\n public:\n  using size_t\
    \ = std::size_t;\n  using u32 = std::uint32_t;\n  using u16 = std::uint16_t;\n\
    \n private:\n  static constexpr u16 popcount(u16 x) {\n    x = (x & 0x5555) +\
    \ (x >> 1 & 0x5555);\n    x = (x & 0x3333) + (x >> 2 & 0x3333);\n    x = (x &\
    \ 0x0f0f) + (x >> 4 & 0x0f0f);\n    return (x & 0x00ff) + (x >> 8 & 0x00ff);\n\
    \  }\n\n  size_t n;\n  size_t bitcnt;\n\n  std::vector<u32> l;\n  std::vector<std::pair<u16,\
    \ u16>> s;\n\n  bool build_flag;\n\n public:\n  BitVector() = delete;\n  explicit\
    \ BitVector(size_t n_)\n      : n(n_), l(n / LBLOCK + 1), s(n / SBLOCK + 1, {0,\
    \ 0}),build_flag(false) {}\n\n  void set(size_t pos) {\n    assert(!build_flag);\n\
    \    assert(0 <= pos && pos < n);\n    s[pos / SBLOCK].second |= 1llu << (pos\
    \ % SBLOCK);\n  }\n\n  void build() {\n    u32 num = 0;\n    for (size_t i = 0;\
    \ i <= n; i++) {\n      if (i % LBLOCK == 0) l[i / LBLOCK] = num;\n      if (i\
    \ % SBLOCK == 0) s[i / SBLOCK].first = num - l[i / LBLOCK];\n      if (i != n\
    \ && i % SBLOCK == 0) {\n        num += popcount(s[i / SBLOCK].second);\n    \
    \  }\n    }\n    bitcnt = num;\n    build_flag=true;\n  }\n\n  bool operator[](size_t\
    \ pos) {\n    assert(build_flag);\n    assert(0 <= pos && pos < n);\n    return\
    \ (s[pos / SBLOCK].second >> (pos % SBLOCK)) & 1;\n  }\n\n  size_t rank(size_t\
    \ pos) {\n    assert(build_flag);\n    assert(0 <= pos && pos <= n);\n    return\
    \ l[pos / LBLOCK] + s[pos / SBLOCK].first +\n           popcount(s[pos / SBLOCK].second\
    \ & ((1llu << (pos % SBLOCK)) - 1));\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/WaveletMatrix/BitVector.hpp
  requiredBy:
  - lib/WaveletMatrix/WaveletMatrix.hpp
  timestamp: '2020-08-07 13:20:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/WaveletMatrix.test.cpp
documentation_of: lib/WaveletMatrix/BitVector.hpp
layout: document
redirect_from:
- /library/lib/WaveletMatrix/BitVector.hpp
- /library/lib/WaveletMatrix/BitVector.hpp.html
title: lib/WaveletMatrix/BitVector.hpp
---
