---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DisjointSparseTable.test.cpp
    title: test/DisjointSparseTable.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/DisjointSparseTable.hpp\"\n\n#include\
    \ <cassert>\n#include <vector>\n\ntemplate <typename Semigroup>\nclass DisjointSparseTable\
    \ {\n public:\n  using value_t = typename Semigroup::value_t;\n  using size_t\
    \ = std::size_t;\n\n private:\n  size_t n, n0;\n  std::vector<size_t> ln;\n  std::vector<std::vector<value_t>>\
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
    \ + 1][r - 1]);\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ Semigroup>\nclass DisjointSparseTable {\n public:\n  using value_t = typename\
    \ Semigroup::value_t;\n  using size_t = std::size_t;\n\n private:\n  size_t n,\
    \ n0;\n  std::vector<size_t> ln;\n  std::vector<std::vector<value_t>> table;\n\
    \n public:\n  DisjointSparseTable(const std::vector<value_t>& a) : n(a.size())\
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
    \ + 1][r - 1]);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/DisjointSparseTable.hpp
  requiredBy: []
  timestamp: '2023-11-10 03:27:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DisjointSparseTable.test.cpp
documentation_of: lib/data_structure/DisjointSparseTable.hpp
layout: document
redirect_from:
- /library/lib/data_structure/DisjointSparseTable.hpp
- /library/lib/data_structure/DisjointSparseTable.hpp.html
title: lib/data_structure/DisjointSparseTable.hpp
---
