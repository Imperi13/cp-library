---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DynamicMatrix.test.cpp
    title: test/DynamicMatrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/DynamicMatrix_2.test.cpp
    title: test/DynamicMatrix_2.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/DynamicMatrix.hpp\"\n\n#include <cassert>\n#include\
    \ <utility>\n#include <vector>\n\ntemplate <typename Field>\nclass DynamicMatrix\
    \ {\n public:\n  using value_t = Field;\n  using size_t = std::size_t;\n\n private:\n\
    \  size_t row, column;\n  std::vector<std::vector<value_t>> a;\n\n public:\n \
    \ explicit DynamicMatrix(size_t row_ = 0, size_t column_ = 0,\n              \
    \           value_t init_ = value_t())\n      : row(row_),\n        column(column_),\n\
    \        a(row, std::vector<value_t>(column, init_)) {}\n\n  constexpr value_t&\
    \ operator()(size_t i, size_t j) {\n    assert(0 <= i && i < row && 0 <= j &&\
    \ j < column);\n    return a[i][j];\n  }\n  constexpr bool operator==(const DynamicMatrix&\
    \ rhs) {\n    if (row != rhs.row || column != rhs.column) return false;\n    for\
    \ (size_t i = 0; i < row; i++) {\n      for (size_t j = 0; j < column; j++) {\n\
    \        if (a[i][j] != rhs.a[i][j]) return false;\n      }\n    }\n    return\
    \ true;\n  }\n  constexpr bool operator!=(const DynamicMatrix& rhs) {\n    return\
    \ !(*this == rhs);\n  }\n\n  constexpr DynamicMatrix operator+(const DynamicMatrix\
    \ rhs) {\n    return DynamicMatrix(*this) += rhs;\n  }\n  constexpr DynamicMatrix\
    \ operator-(const DynamicMatrix rhs) {\n    return DynamicMatrix(*this) -= rhs;\n\
    \  }\n  constexpr DynamicMatrix operator*(const DynamicMatrix rhs) {\n    return\
    \ DynamicMatrix(*this) *= rhs;\n  }\n\n  constexpr DynamicMatrix& operator+=(const\
    \ DynamicMatrix& rhs) {\n    assert(row == rhs.row && column == rhs.column);\n\
    \    for (size_t i = 0; i < row; i++) {\n      for (size_t j = 0; j < column;\
    \ j++) {\n        a[i][j] += rhs.a[i][j];\n      }\n    }\n    return *this;\n\
    \  }\n  constexpr DynamicMatrix& operator-=(const DynamicMatrix& rhs) {\n    assert(row\
    \ == rhs.row && column == rhs.column);\n    for (size_t i = 0; i < row; i++) {\n\
    \      for (size_t j = 0; j < column; j++) {\n        a[i][j] -= rhs.a[i][j];\n\
    \      }\n    }\n    return *this;\n  }\n  constexpr DynamicMatrix& operator*=(const\
    \ DynamicMatrix& rhs) {\n    assert(column == rhs.row);\n    std::vector<std::vector<value_t>>\
    \ tmp(row,\n                                          std::vector<value_t>(rhs.column,\
    \ 0));\n    for (size_t r = 0; r < row; r++) {\n      for (size_t c = 0; c < rhs.column;\
    \ c++) {\n        for (size_t i = 0; i < column; i++) {\n          tmp[r][c] +=\
    \ a[r][i] * rhs.a[i][c];\n        }\n      }\n    }\n    column = rhs.column;\n\
    \    a = std::move(tmp);\n    return *this;\n  }\n\n  constexpr static DynamicMatrix\
    \ id(size_t size) {\n    DynamicMatrix<Field> tmp(size, size);\n    for (size_t\
    \ i = 0; i < size; i++) tmp.a[i][i] = 1;\n    return tmp;\n  }\n\n  constexpr\
    \ void LUPdecomposition(DynamicMatrix& P, DynamicMatrix& L,\n                \
    \                  DynamicMatrix& U) {\n    assert(row == column);\n    std::vector<std::vector<value_t>>\
    \ tmp = a;\n    P = DynamicMatrix::id(row);\n    L = DynamicMatrix(row, column,\
    \ 0);\n    U = DynamicMatrix(row, column, 0);\n\n    for (size_t i = 0; i < row;\
    \ i++) {\n      for (size_t j = 0; j < column; j++) {\n        value_t val = 0;\n\
    \        for (size_t k = 0; k < i; k++) val += L.a[j][k] * U.a[k][i];\n      \
    \  if (val != tmp[j][i]) {\n          std::swap(tmp[i], tmp[j]);\n          std::swap(P.a[i],\
    \ P.a[j]);\n          std::swap(L.a[i], L.a[j]);\n          break;\n        }\n\
    \      }\n      L.a[i][i] = 1;\n      for (size_t j = i; j < row; j++) {\n   \
    \     U.a[i][j] = tmp[i][j];\n        for (size_t k = 0; k < i; k++) U.a[i][j]\
    \ -= L.a[i][k] * U.a[k][j];\n      }\n      if (U.a[i][i] != 0) {\n        for\
    \ (size_t j = i + 1; j < row; j++) {\n          L.a[j][i] = tmp[j][i];\n     \
    \     for (size_t k = 0; k < i; k++) L.a[j][i] -= L.a[j][k] * U.a[k][i];\n   \
    \       L.a[j][i] /= U.a[i][i];\n        }\n      }\n    }\n  }\n\n  constexpr\
    \ value_t det() {\n    DynamicMatrix<Field> p, l, u;\n    LUPdecomposition(p,\
    \ l, u);\n    size_t cnt = 0;\n    value_t ret = 0;\n    for (size_t i = 0; i\
    \ < row; i++) {\n      if (p.a[i][i] == 1) continue;\n      for (size_t j = 1;\
    \ j < row; j++) {\n        if (p.a[j][i] == 1) {\n          std::swap(p.a[i],\
    \ p.a[j]);\n          cnt++;\n          break;\n        }\n      }\n    }\n  \
    \  if (cnt & 1)\n      ret -= 1;\n    else\n      ret += 1;\n    for (size_t i\
    \ = 0; i < row; i++) ret *= u.a[i][i];\n    return ret;\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \ntemplate <typename Field>\nclass DynamicMatrix {\n public:\n  using value_t\
    \ = Field;\n  using size_t = std::size_t;\n\n private:\n  size_t row, column;\n\
    \  std::vector<std::vector<value_t>> a;\n\n public:\n  explicit DynamicMatrix(size_t\
    \ row_ = 0, size_t column_ = 0,\n                         value_t init_ = value_t())\n\
    \      : row(row_),\n        column(column_),\n        a(row, std::vector<value_t>(column,\
    \ init_)) {}\n\n  constexpr value_t& operator()(size_t i, size_t j) {\n    assert(0\
    \ <= i && i < row && 0 <= j && j < column);\n    return a[i][j];\n  }\n  constexpr\
    \ bool operator==(const DynamicMatrix& rhs) {\n    if (row != rhs.row || column\
    \ != rhs.column) return false;\n    for (size_t i = 0; i < row; i++) {\n     \
    \ for (size_t j = 0; j < column; j++) {\n        if (a[i][j] != rhs.a[i][j]) return\
    \ false;\n      }\n    }\n    return true;\n  }\n  constexpr bool operator!=(const\
    \ DynamicMatrix& rhs) {\n    return !(*this == rhs);\n  }\n\n  constexpr DynamicMatrix\
    \ operator+(const DynamicMatrix rhs) {\n    return DynamicMatrix(*this) += rhs;\n\
    \  }\n  constexpr DynamicMatrix operator-(const DynamicMatrix rhs) {\n    return\
    \ DynamicMatrix(*this) -= rhs;\n  }\n  constexpr DynamicMatrix operator*(const\
    \ DynamicMatrix rhs) {\n    return DynamicMatrix(*this) *= rhs;\n  }\n\n  constexpr\
    \ DynamicMatrix& operator+=(const DynamicMatrix& rhs) {\n    assert(row == rhs.row\
    \ && column == rhs.column);\n    for (size_t i = 0; i < row; i++) {\n      for\
    \ (size_t j = 0; j < column; j++) {\n        a[i][j] += rhs.a[i][j];\n      }\n\
    \    }\n    return *this;\n  }\n  constexpr DynamicMatrix& operator-=(const DynamicMatrix&\
    \ rhs) {\n    assert(row == rhs.row && column == rhs.column);\n    for (size_t\
    \ i = 0; i < row; i++) {\n      for (size_t j = 0; j < column; j++) {\n      \
    \  a[i][j] -= rhs.a[i][j];\n      }\n    }\n    return *this;\n  }\n  constexpr\
    \ DynamicMatrix& operator*=(const DynamicMatrix& rhs) {\n    assert(column ==\
    \ rhs.row);\n    std::vector<std::vector<value_t>> tmp(row,\n                \
    \                          std::vector<value_t>(rhs.column, 0));\n    for (size_t\
    \ r = 0; r < row; r++) {\n      for (size_t c = 0; c < rhs.column; c++) {\n  \
    \      for (size_t i = 0; i < column; i++) {\n          tmp[r][c] += a[r][i] *\
    \ rhs.a[i][c];\n        }\n      }\n    }\n    column = rhs.column;\n    a = std::move(tmp);\n\
    \    return *this;\n  }\n\n  constexpr static DynamicMatrix id(size_t size) {\n\
    \    DynamicMatrix<Field> tmp(size, size);\n    for (size_t i = 0; i < size; i++)\
    \ tmp.a[i][i] = 1;\n    return tmp;\n  }\n\n  constexpr void LUPdecomposition(DynamicMatrix&\
    \ P, DynamicMatrix& L,\n                                  DynamicMatrix& U) {\n\
    \    assert(row == column);\n    std::vector<std::vector<value_t>> tmp = a;\n\
    \    P = DynamicMatrix::id(row);\n    L = DynamicMatrix(row, column, 0);\n   \
    \ U = DynamicMatrix(row, column, 0);\n\n    for (size_t i = 0; i < row; i++) {\n\
    \      for (size_t j = 0; j < column; j++) {\n        value_t val = 0;\n     \
    \   for (size_t k = 0; k < i; k++) val += L.a[j][k] * U.a[k][i];\n        if (val\
    \ != tmp[j][i]) {\n          std::swap(tmp[i], tmp[j]);\n          std::swap(P.a[i],\
    \ P.a[j]);\n          std::swap(L.a[i], L.a[j]);\n          break;\n        }\n\
    \      }\n      L.a[i][i] = 1;\n      for (size_t j = i; j < row; j++) {\n   \
    \     U.a[i][j] = tmp[i][j];\n        for (size_t k = 0; k < i; k++) U.a[i][j]\
    \ -= L.a[i][k] * U.a[k][j];\n      }\n      if (U.a[i][i] != 0) {\n        for\
    \ (size_t j = i + 1; j < row; j++) {\n          L.a[j][i] = tmp[j][i];\n     \
    \     for (size_t k = 0; k < i; k++) L.a[j][i] -= L.a[j][k] * U.a[k][i];\n   \
    \       L.a[j][i] /= U.a[i][i];\n        }\n      }\n    }\n  }\n\n  constexpr\
    \ value_t det() {\n    DynamicMatrix<Field> p, l, u;\n    LUPdecomposition(p,\
    \ l, u);\n    size_t cnt = 0;\n    value_t ret = 0;\n    for (size_t i = 0; i\
    \ < row; i++) {\n      if (p.a[i][i] == 1) continue;\n      for (size_t j = 1;\
    \ j < row; j++) {\n        if (p.a[j][i] == 1) {\n          std::swap(p.a[i],\
    \ p.a[j]);\n          cnt++;\n          break;\n        }\n      }\n    }\n  \
    \  if (cnt & 1)\n      ret -= 1;\n    else\n      ret += 1;\n    for (size_t i\
    \ = 0; i < row; i++) ret *= u.a[i][i];\n    return ret;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/DynamicMatrix.hpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DynamicMatrix_2.test.cpp
  - test/DynamicMatrix.test.cpp
documentation_of: lib/math/DynamicMatrix.hpp
layout: document
redirect_from:
- /library/lib/math/DynamicMatrix.hpp
- /library/lib/math/DynamicMatrix.hpp.html
title: lib/math/DynamicMatrix.hpp
---
