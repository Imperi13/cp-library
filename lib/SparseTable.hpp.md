---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/SparseTable.test.cpp
    title: test/SparseTable.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/SparseTable.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \n// Semigroup\n// type value_t\n// static (value_t ,value_t)->value_t op\n\n\
    // a op a == a\n\ntemplate <typename Semigroup>\nclass SparseTable {\n public:\n\
    \  using value_t = typename Semigroup::value_t;\n  using size_t = std::size_t;\n\
    \n private:\n  size_t n;\n  std::vector<size_t> ln;\n  std::vector<std::vector<value_t>>\
    \ table;\n\n public:\n  SparseTable(const std::vector<value_t>& a) : n(a.size()),\
    \ ln(n + 1, 0) {\n    for (size_t i = 1; i < n + 1; i++)\n      ln[i] = ln[i -\
    \ 1] + (i >= (1ull << (ln[i - 1] + 1)));\n    table = std::vector<std::vector<value_t>>(\n\
    \        ln[n] + 1, std::vector<value_t>(n, value_t()));\n    for (size_t i =\
    \ 0; i < n; i++) table[0][i] = a[i];\n    for (size_t j = 1; j < ln[n] + 1; j++)\
    \ {\n      for (size_t i = 0; i < n; i++) {\n        if (i + (1ll << j) > n)\n\
    \          table[j][i] = value_t();\n        else\n          table[j][i] = Semigroup::op(table[j\
    \ - 1][i],\n                                      table[j - 1][i + (1ll << (j\
    \ - 1))]);\n      }\n    }\n  }\n\n  value_t fold(size_t l, size_t r) {\n    assert(0\
    \ <= l && l < r && r <= n);\n    size_t m = r - l;\n    return Semigroup::op(table[ln[m]][l],\
    \ table[ln[m]][r - (1ll << ln[m])]);\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\n// Semigroup\n//\
    \ type value_t\n// static (value_t ,value_t)->value_t op\n\n// a op a == a\n\n\
    template <typename Semigroup>\nclass SparseTable {\n public:\n  using value_t\
    \ = typename Semigroup::value_t;\n  using size_t = std::size_t;\n\n private:\n\
    \  size_t n;\n  std::vector<size_t> ln;\n  std::vector<std::vector<value_t>> table;\n\
    \n public:\n  SparseTable(const std::vector<value_t>& a) : n(a.size()), ln(n +\
    \ 1, 0) {\n    for (size_t i = 1; i < n + 1; i++)\n      ln[i] = ln[i - 1] + (i\
    \ >= (1ull << (ln[i - 1] + 1)));\n    table = std::vector<std::vector<value_t>>(\n\
    \        ln[n] + 1, std::vector<value_t>(n, value_t()));\n    for (size_t i =\
    \ 0; i < n; i++) table[0][i] = a[i];\n    for (size_t j = 1; j < ln[n] + 1; j++)\
    \ {\n      for (size_t i = 0; i < n; i++) {\n        if (i + (1ll << j) > n)\n\
    \          table[j][i] = value_t();\n        else\n          table[j][i] = Semigroup::op(table[j\
    \ - 1][i],\n                                      table[j - 1][i + (1ll << (j\
    \ - 1))]);\n      }\n    }\n  }\n\n  value_t fold(size_t l, size_t r) {\n    assert(0\
    \ <= l && l < r && r <= n);\n    size_t m = r - l;\n    return Semigroup::op(table[ln[m]][l],\
    \ table[ln[m]][r - (1ll << ln[m])]);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/SparseTable.hpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/SparseTable.test.cpp
documentation_of: lib/SparseTable.hpp
layout: document
redirect_from:
- /library/lib/SparseTable.hpp
- /library/lib/SparseTable.hpp.html
title: lib/SparseTable.hpp
---
