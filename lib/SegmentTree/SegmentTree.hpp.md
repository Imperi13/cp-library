---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/SegmentTree.test.cpp
    title: test/SegmentTree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"lib/SegmentTree/SegmentTree.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n// Monoid\n// type value_t\n// static var id\n// static (value_t,value_t)->value_t\
    \ op\n\ntemplate <typename Monoid>\nclass SegmentTree {\n public:\n  using value_t\
    \ = typename Monoid::value_t;\n  using size_t = std::size_t;\n\n private:\n  size_t\
    \ n, n0;\n  std::vector<value_t> dat;\n\n public:\n  SegmentTree(size_t n_) :\
    \ n(n_) {\n    assert(n_ > 0);\n    n0 = 1;\n    while (n0 < n) n0 <<= 1;\n  \
    \  dat = std::vector<value_t>(2 * n0 - 1, Monoid::id);\n  }\n\n  SegmentTree(const\
    \ std::vector<value_t>& tmp) : n(tmp.size()) {\n    assert(n > 0);\n    n0 = 1;\n\
    \    while (n0 < n) n0 <<= 1;\n    dat = std::vector<value_t>(2 * n0 - 1, Monoid::id);\n\
    \    for (size_t i = 0; i < n; i++) dat[i + n0 - 1] = tmp[i];\n    for (long long\
    \ i = n0 - 2; i >= 0; i--)\n      dat[i] = Monoid::op(dat[2 * i + 1], dat[2 *\
    \ i + 2]);\n  }\n\n  void update(size_t i, value_t val, bool change) {\n    assert(0\
    \ <= i && i < n);\n    std::size_t now = i + n0 - 1;\n    if (change)\n      dat[now]\
    \ = val;\n    else\n      dat[now] = Monoid::op(dat[now], val);\n\n    while (now\
    \ > 0) {\n      now = (now - 1) >> 1;\n      dat[now] = Monoid::op(dat[2 * now\
    \ + 1], dat[2 * now + 2]);\n    }\n  }\n\n  value_t fold(size_t a, size_t b) {\n\
    \    assert(0 <= a && a <= b && b <= n);\n    value_t rval = Monoid::id, lval\
    \ = Monoid::id;\n    size_t l = a + n0 - 1, r = b + n0 - 1;\n    for (; l < r;\
    \ l >>= 1, r >>= 1) {\n      if (!(r & 1)) {\n        r--;\n        rval = Monoid::op(dat[r],\
    \ rval);\n      }\n      if (!(l & 1)) {\n        lval = Monoid::op(lval, dat[l]);\n\
    \        l++;\n      }\n    }\n\n    return Monoid::op(lval, rval);\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n// Monoid\n// type\
    \ value_t\n// static var id\n// static (value_t,value_t)->value_t op\n\ntemplate\
    \ <typename Monoid>\nclass SegmentTree {\n public:\n  using value_t = typename\
    \ Monoid::value_t;\n  using size_t = std::size_t;\n\n private:\n  size_t n, n0;\n\
    \  std::vector<value_t> dat;\n\n public:\n  SegmentTree(size_t n_) : n(n_) {\n\
    \    assert(n_ > 0);\n    n0 = 1;\n    while (n0 < n) n0 <<= 1;\n    dat = std::vector<value_t>(2\
    \ * n0 - 1, Monoid::id);\n  }\n\n  SegmentTree(const std::vector<value_t>& tmp)\
    \ : n(tmp.size()) {\n    assert(n > 0);\n    n0 = 1;\n    while (n0 < n) n0 <<=\
    \ 1;\n    dat = std::vector<value_t>(2 * n0 - 1, Monoid::id);\n    for (size_t\
    \ i = 0; i < n; i++) dat[i + n0 - 1] = tmp[i];\n    for (long long i = n0 - 2;\
    \ i >= 0; i--)\n      dat[i] = Monoid::op(dat[2 * i + 1], dat[2 * i + 2]);\n \
    \ }\n\n  void update(size_t i, value_t val, bool change) {\n    assert(0 <= i\
    \ && i < n);\n    std::size_t now = i + n0 - 1;\n    if (change)\n      dat[now]\
    \ = val;\n    else\n      dat[now] = Monoid::op(dat[now], val);\n\n    while (now\
    \ > 0) {\n      now = (now - 1) >> 1;\n      dat[now] = Monoid::op(dat[2 * now\
    \ + 1], dat[2 * now + 2]);\n    }\n  }\n\n  value_t fold(size_t a, size_t b) {\n\
    \    assert(0 <= a && a <= b && b <= n);\n    value_t rval = Monoid::id, lval\
    \ = Monoid::id;\n    size_t l = a + n0 - 1, r = b + n0 - 1;\n    for (; l < r;\
    \ l >>= 1, r >>= 1) {\n      if (!(r & 1)) {\n        r--;\n        rval = Monoid::op(dat[r],\
    \ rval);\n      }\n      if (!(l & 1)) {\n        lval = Monoid::op(lval, dat[l]);\n\
    \        l++;\n      }\n    }\n\n    return Monoid::op(lval, rval);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/SegmentTree/SegmentTree.hpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/SegmentTree.test.cpp
documentation_of: lib/SegmentTree/SegmentTree.hpp
layout: document
redirect_from:
- /library/lib/SegmentTree/SegmentTree.hpp
- /library/lib/SegmentTree/SegmentTree.hpp.html
title: lib/SegmentTree/SegmentTree.hpp
---
