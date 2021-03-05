---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/SparseTable.hpp
    title: lib/SparseTable.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/SparseTable.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#include <iostream>\n#include <cassert>\n#include <algorithm>\n\n#include\
    \ <vector>\n\n#line 2 \"lib/SparseTable.hpp\"\n\n#line 5 \"lib/SparseTable.hpp\"\
    \n\n// Semigroup\n// type value_t\n// static (value_t ,value_t)->value_t op\n\n\
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
    \ table[ln[m]][r - (1ll << ln[m])]);\n  }\n};\n#line 10 \"test/SparseTable.test.cpp\"\
    \n\nstruct Semigroup{\n  using value_t = long long;\n  static constexpr value_t\
    \ op(const value_t &a, const value_t &b){\n    return std::min(a, b);\n  }\n};\n\
    \nusing ll = long long;\nusing P = std::pair<ll, ll>;\n\nint main()\n{\n  std::cin.tie(nullptr);\n\
    \  std::ios::sync_with_stdio(false);\n\n  ll n, q;\n  std::cin >> n >> q;\n\n\
    \  std::vector<ll> a(n);\n  for (auto &&e : a)\n    std::cin >> e;\n\n  SparseTable<Semigroup>\
    \ sp(a);\n\n  while (q--)\n  {\n    ll l, r;\n    std::cin >> l >> r;\n    std::cout\
    \ << sp.fold(l, r) << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <iostream>\n#include <cassert>\n#include <algorithm>\n\n#include <vector>\n\n\
    #include \"../lib/SparseTable.hpp\"\n\nstruct Semigroup{\n  using value_t = long\
    \ long;\n  static constexpr value_t op(const value_t &a, const value_t &b){\n\
    \    return std::min(a, b);\n  }\n};\n\nusing ll = long long;\nusing P = std::pair<ll,\
    \ ll>;\n\nint main()\n{\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  ll n, q;\n  std::cin >> n >> q;\n\n  std::vector<ll> a(n);\n  for (auto &&e\
    \ : a)\n    std::cin >> e;\n\n  SparseTable<Semigroup> sp(a);\n\n  while (q--)\n\
    \  {\n    ll l, r;\n    std::cin >> l >> r;\n    std::cout << sp.fold(l, r) <<\
    \ \"\\n\";\n  }\n\n  return 0;\n}"
  dependsOn:
  - lib/SparseTable.hpp
  isVerificationFile: true
  path: test/SparseTable.test.cpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/SparseTable.test.cpp
layout: document
redirect_from:
- /verify/test/SparseTable.test.cpp
- /verify/test/SparseTable.test.cpp.html
title: test/SparseTable.test.cpp
---
