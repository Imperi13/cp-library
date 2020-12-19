---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LazySegmentTree.test.cpp
    title: test/LazySegmentTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/LazySegmentTree_2.test.cpp
    title: test/LazySegmentTree_2.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/SegmentTree/LazySegmentTree.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n\n// Lazy\n// type value_t\n// type lazy_t\n// static value_t\
    \ id_val\n// static value_t id_lazy\n// static (value_t,value_t) -> value_t f\n\
    // static (value_t,lazy_t) -> value_t g\n// static (lazy_t,lazy_t) -> lazy_t h\n\
    // static (lazy_t,size_t) -> lazy_t p\n\n/* Lazy template\n\nstruct Lazy{\n  using\
    \ value_t= ~~ ;\n  using lazy_t= ~~ ;\n  static constexpr value_t id_val= ~~ ;\n\
    \  static constexpr lazy_t id_lazy= ~~ ;\n  static value_t f(value_t a,value_t\
    \ b){\n    return ~~ ;\n  }\n  static value_t g(value_t a,lazy_t b){\n    return\
    \ ~~ ;\n  }\n  static lazy_t h(lazy_t a,lazy_t b){\n    return ~~ ;\n  }\n  static\
    \ lazy_t p(lazy_t a,std::size_t n){\n    return ~~ ;\n  }\n};\n\n*/\n\ntemplate\
    \ <typename Lazy>\nclass LazySegmentTree {\n public:\n  using value_t = typename\
    \ Lazy::value_t;\n  using lazy_t = typename Lazy::lazy_t;\n  using size_t = std::size_t;\n\
    \n private:\n  size_t n, n0;\n  std::vector<value_t> val;\n  std::vector<lazy_t>\
    \ lazy;\n\n  value_t update(size_t a, size_t b, lazy_t laz, size_t l, size_t r,\
    \ size_t k) {\n    if (lazy[k] != Lazy::id_lazy) {\n      if (k < n0 - 1) {\n\
    \        lazy[2 * k + 1] = Lazy::h(lazy[2 * k + 1], lazy[k]);\n        lazy[2\
    \ * k + 2] = Lazy::h(lazy[2 * k + 2], lazy[k]);\n      }\n      val[k] = Lazy::g(val[k],\
    \ Lazy::p(lazy[k], r - l));\n      lazy[k] = Lazy::id_lazy;\n    }\n\n    if (r\
    \ <= a || b <= l) return val[k];\n    if (a <= l && r <= b) {\n      lazy[k] =\
    \ Lazy::h(lazy[k], laz);\n      return Lazy::g(val[k], Lazy::p(lazy[k], r - l));\n\
    \    }\n    return val[k] = Lazy::f(update(a, b, laz, l, l + (r - l) / 2, 2 *\
    \ k + 1),\n                            update(a, b, laz, l + (r - l) / 2, r, 2\
    \ * k + 2));\n  }\n\n  value_t fold(size_t a, size_t b, size_t l, size_t r, size_t\
    \ k) {\n    if (lazy[k] != Lazy::id_lazy) {\n      if (k < n0 - 1) {\n       \
    \ lazy[2 * k + 1] = Lazy::h(lazy[2 * k + 1], lazy[k]);\n        lazy[2 * k + 2]\
    \ = Lazy::h(lazy[2 * k + 2], lazy[k]);\n      }\n      val[k] = Lazy::g(val[k],\
    \ Lazy::p(lazy[k], r - l));\n      lazy[k] = Lazy::id_lazy;\n    }\n\n    if (r\
    \ <= a || b <= l) return Lazy::id_val;\n    if (a <= l && r <= b) return val[k];\n\
    \    return Lazy::f(fold(a, b, l, l + (r - l) / 2, 2 * k + 1),\n             \
    \      fold(a, b, l + (r - l) / 2, r, 2 * k + 2));\n  }\n\n  inline size_t beki(size_t\
    \ n_) {\n    size_t ret = 1;\n    while (ret < n_) ret <<= 1;\n    return ret;\n\
    \  }\n\n public:\n  LazySegmentTree(size_t n_)\n      : n(n_),\n        n0(beki(n)),\n\
    \        val(2 * n0 - 1, Lazy::id_val),\n        lazy(2 * n0 - 1, Lazy::id_lazy)\
    \ {}\n\n  LazySegmentTree(std::vector<value_t> val_)\n      : n(val_.size()),\n\
    \        n0(beki(n)),\n        val(2 * n0 - 1, Lazy::id_val),\n        lazy(2\
    \ * n0 - 1, Lazy::id_lazy) {\n    for (size_t i = 0; i < n; i++) val[i + n0 -\
    \ 1] = val_[i];\n    for (long long i = n0 - 2; i >= 0; i--)\n      val[i] = Lazy::f(val[2\
    \ * i + 1], val[2 * i + 2]);\n  }\n\n  void update(size_t a, size_t b, lazy_t\
    \ laz) { update(a, b, laz, 0, n0, 0); }\n\n  value_t fold(size_t a, size_t b)\
    \ { return fold(a, b, 0, n0, 0); }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n// Lazy\n// type\
    \ value_t\n// type lazy_t\n// static value_t id_val\n// static value_t id_lazy\n\
    // static (value_t,value_t) -> value_t f\n// static (value_t,lazy_t) -> value_t\
    \ g\n// static (lazy_t,lazy_t) -> lazy_t h\n// static (lazy_t,size_t) -> lazy_t\
    \ p\n\n/* Lazy template\n\nstruct Lazy{\n  using value_t= ~~ ;\n  using lazy_t=\
    \ ~~ ;\n  static constexpr value_t id_val= ~~ ;\n  static constexpr lazy_t id_lazy=\
    \ ~~ ;\n  static value_t f(value_t a,value_t b){\n    return ~~ ;\n  }\n  static\
    \ value_t g(value_t a,lazy_t b){\n    return ~~ ;\n  }\n  static lazy_t h(lazy_t\
    \ a,lazy_t b){\n    return ~~ ;\n  }\n  static lazy_t p(lazy_t a,std::size_t n){\n\
    \    return ~~ ;\n  }\n};\n\n*/\n\ntemplate <typename Lazy>\nclass LazySegmentTree\
    \ {\n public:\n  using value_t = typename Lazy::value_t;\n  using lazy_t = typename\
    \ Lazy::lazy_t;\n  using size_t = std::size_t;\n\n private:\n  size_t n, n0;\n\
    \  std::vector<value_t> val;\n  std::vector<lazy_t> lazy;\n\n  value_t update(size_t\
    \ a, size_t b, lazy_t laz, size_t l, size_t r, size_t k) {\n    if (lazy[k] !=\
    \ Lazy::id_lazy) {\n      if (k < n0 - 1) {\n        lazy[2 * k + 1] = Lazy::h(lazy[2\
    \ * k + 1], lazy[k]);\n        lazy[2 * k + 2] = Lazy::h(lazy[2 * k + 2], lazy[k]);\n\
    \      }\n      val[k] = Lazy::g(val[k], Lazy::p(lazy[k], r - l));\n      lazy[k]\
    \ = Lazy::id_lazy;\n    }\n\n    if (r <= a || b <= l) return val[k];\n    if\
    \ (a <= l && r <= b) {\n      lazy[k] = Lazy::h(lazy[k], laz);\n      return Lazy::g(val[k],\
    \ Lazy::p(lazy[k], r - l));\n    }\n    return val[k] = Lazy::f(update(a, b, laz,\
    \ l, l + (r - l) / 2, 2 * k + 1),\n                            update(a, b, laz,\
    \ l + (r - l) / 2, r, 2 * k + 2));\n  }\n\n  value_t fold(size_t a, size_t b,\
    \ size_t l, size_t r, size_t k) {\n    if (lazy[k] != Lazy::id_lazy) {\n     \
    \ if (k < n0 - 1) {\n        lazy[2 * k + 1] = Lazy::h(lazy[2 * k + 1], lazy[k]);\n\
    \        lazy[2 * k + 2] = Lazy::h(lazy[2 * k + 2], lazy[k]);\n      }\n     \
    \ val[k] = Lazy::g(val[k], Lazy::p(lazy[k], r - l));\n      lazy[k] = Lazy::id_lazy;\n\
    \    }\n\n    if (r <= a || b <= l) return Lazy::id_val;\n    if (a <= l && r\
    \ <= b) return val[k];\n    return Lazy::f(fold(a, b, l, l + (r - l) / 2, 2 *\
    \ k + 1),\n                   fold(a, b, l + (r - l) / 2, r, 2 * k + 2));\n  }\n\
    \n  inline size_t beki(size_t n_) {\n    size_t ret = 1;\n    while (ret < n_)\
    \ ret <<= 1;\n    return ret;\n  }\n\n public:\n  LazySegmentTree(size_t n_)\n\
    \      : n(n_),\n        n0(beki(n)),\n        val(2 * n0 - 1, Lazy::id_val),\n\
    \        lazy(2 * n0 - 1, Lazy::id_lazy) {}\n\n  LazySegmentTree(std::vector<value_t>\
    \ val_)\n      : n(val_.size()),\n        n0(beki(n)),\n        val(2 * n0 - 1,\
    \ Lazy::id_val),\n        lazy(2 * n0 - 1, Lazy::id_lazy) {\n    for (size_t i\
    \ = 0; i < n; i++) val[i + n0 - 1] = val_[i];\n    for (long long i = n0 - 2;\
    \ i >= 0; i--)\n      val[i] = Lazy::f(val[2 * i + 1], val[2 * i + 2]);\n  }\n\
    \n  void update(size_t a, size_t b, lazy_t laz) { update(a, b, laz, 0, n0, 0);\
    \ }\n\n  value_t fold(size_t a, size_t b) { return fold(a, b, 0, n0, 0); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/SegmentTree/LazySegmentTree.hpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LazySegmentTree_2.test.cpp
  - test/LazySegmentTree.test.cpp
documentation_of: lib/SegmentTree/LazySegmentTree.hpp
layout: document
redirect_from:
- /library/lib/SegmentTree/LazySegmentTree.hpp
- /library/lib/SegmentTree/LazySegmentTree.hpp.html
title: lib/SegmentTree/LazySegmentTree.hpp
---
