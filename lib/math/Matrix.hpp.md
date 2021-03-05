---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/math/Matrix.hpp\"\n\n#include <array>\n#include <cassert>\n\
    #include <utility>\n\ntemplate <typename Field, std::size_t ROW, std::size_t COLUMN>\n\
    class Matrix {\n public:\n  using value_t = Field;\n  using size_t = std::size_t;\n\
    \  static constexpr size_t row = ROW;\n  static constexpr size_t column = COLUMN;\n\
    \n  std::array<std::array<value_t, COLUMN>, ROW> a;\n\n  explicit Matrix(const\
    \ value_t init = value_t()) {\n    std::fill(a[0].begin(), a[ROW - 1].end(), init);\n\
    \  }\n\n  Matrix(const std::array<std::array<Field, COLUMN>, ROW>& a_) : a(a_)\
    \ {}\n\n  constexpr value_t& operator()(size_t i, size_t j) { return a[i][j];\
    \ }\n  constexpr bool operator==(const Matrix& rhs) {\n    for (size_t i = 0;\
    \ i < ROW; i++) {\n      for (size_t j = 0; j < COLUMN; j++) {\n        if (a[i][j]\
    \ != rhs.a[i][j]) return false;\n      }\n    }\n    return true;\n  }\n  constexpr\
    \ bool operator!=(const Matrix& rhs) { return !(*this == rhs); }\n\n  constexpr\
    \ Matrix operator+(const Matrix rhs) { return Matrix(*this) += rhs; }\n  constexpr\
    \ Matrix operator-(const Matrix rhs) { return Matrix(*this) -= rhs; }\n\n  template\
    \ <size_t NEWCOLUMN>\n  constexpr Matrix<Field, ROW, NEWCOLUMN> operator*(\n \
    \     const Matrix<Field, COLUMN, NEWCOLUMN> rhs) {\n    Matrix<Field, ROW, NEWCOLUMN>\
    \ tmp;\n    for (size_t r = 0; r < ROW; r++) {\n      for (size_t c = 0; c < NEWCOLUMN;\
    \ c++) {\n        for (size_t i = 0; i < COLUMN; i++) {\n          tmp.a[r][c]\
    \ += a[r][i] * rhs.a[i][c];\n        }\n      }\n    }\n    return tmp;\n  }\n\
    \n  constexpr Matrix& operator+=(const Matrix& rhs) {\n    for (size_t i = 0;\
    \ i < ROW; i++) {\n      for (size_t j = 0; j < COLUMN; j++) {\n        a[i][j]\
    \ += rhs.a[i][j];\n      }\n    }\n    return *this;\n  }\n  constexpr Matrix&\
    \ operator-=(const Matrix& rhs) {\n    for (size_t i = 0; i < ROW; i++) {\n  \
    \    for (size_t j = 0; j < COLUMN; j++) {\n        a[i][j] -= rhs.a[i][j];\n\
    \      }\n    }\n  }\n  constexpr Matrix& operator*=(const Matrix<Field, COLUMN,\
    \ COLUMN>& rhs) {\n    std::array<std::array<value_t, COLUMN>, ROW> tmp;\n   \
    \ std::fill(tmp[0].begin(), tmp[ROW - 1].end(), 0);\n    for (size_t r = 0; r\
    \ < ROW; r++) {\n      for (size_t c = 0; c < COLUMN; c++) {\n        for (size_t\
    \ i = 0; i < COLUMN; i++) {\n          tmp[r][c] += a[r][i] * rhs.a[i][c];\n \
    \       }\n      }\n    }\n    a = std::move(tmp);\n    return *this;\n  }\n\n\
    \  constexpr static Matrix id() {\n    static_assert(ROW == COLUMN, \"ROW must\
    \ be equal to COLUMN\");\n    Matrix<Field, ROW, COLUMN> tmp;\n    for (size_t\
    \ i = 0; i < ROW; i++) tmp.a[i][i] = 1;\n    return tmp;\n  }\n\n  void print(){\n\
    \    for(size_t r=0;r<ROW;r++){\n      for(size_t c=0;c<COLUMN;c++){\n       \
    \ std::cout<<a[r][c]<<\" \";\n      }\n      std::cout<<\"\\n\";\n    }\n  }\n\
    };\n"
  code: "#pragma once\n\n#include <array>\n#include <cassert>\n#include <utility>\n\
    \ntemplate <typename Field, std::size_t ROW, std::size_t COLUMN>\nclass Matrix\
    \ {\n public:\n  using value_t = Field;\n  using size_t = std::size_t;\n  static\
    \ constexpr size_t row = ROW;\n  static constexpr size_t column = COLUMN;\n\n\
    \  std::array<std::array<value_t, COLUMN>, ROW> a;\n\n  explicit Matrix(const\
    \ value_t init = value_t()) {\n    std::fill(a[0].begin(), a[ROW - 1].end(), init);\n\
    \  }\n\n  Matrix(const std::array<std::array<Field, COLUMN>, ROW>& a_) : a(a_)\
    \ {}\n\n  constexpr value_t& operator()(size_t i, size_t j) { return a[i][j];\
    \ }\n  constexpr bool operator==(const Matrix& rhs) {\n    for (size_t i = 0;\
    \ i < ROW; i++) {\n      for (size_t j = 0; j < COLUMN; j++) {\n        if (a[i][j]\
    \ != rhs.a[i][j]) return false;\n      }\n    }\n    return true;\n  }\n  constexpr\
    \ bool operator!=(const Matrix& rhs) { return !(*this == rhs); }\n\n  constexpr\
    \ Matrix operator+(const Matrix rhs) { return Matrix(*this) += rhs; }\n  constexpr\
    \ Matrix operator-(const Matrix rhs) { return Matrix(*this) -= rhs; }\n\n  template\
    \ <size_t NEWCOLUMN>\n  constexpr Matrix<Field, ROW, NEWCOLUMN> operator*(\n \
    \     const Matrix<Field, COLUMN, NEWCOLUMN> rhs) {\n    Matrix<Field, ROW, NEWCOLUMN>\
    \ tmp;\n    for (size_t r = 0; r < ROW; r++) {\n      for (size_t c = 0; c < NEWCOLUMN;\
    \ c++) {\n        for (size_t i = 0; i < COLUMN; i++) {\n          tmp.a[r][c]\
    \ += a[r][i] * rhs.a[i][c];\n        }\n      }\n    }\n    return tmp;\n  }\n\
    \n  constexpr Matrix& operator+=(const Matrix& rhs) {\n    for (size_t i = 0;\
    \ i < ROW; i++) {\n      for (size_t j = 0; j < COLUMN; j++) {\n        a[i][j]\
    \ += rhs.a[i][j];\n      }\n    }\n    return *this;\n  }\n  constexpr Matrix&\
    \ operator-=(const Matrix& rhs) {\n    for (size_t i = 0; i < ROW; i++) {\n  \
    \    for (size_t j = 0; j < COLUMN; j++) {\n        a[i][j] -= rhs.a[i][j];\n\
    \      }\n    }\n  }\n  constexpr Matrix& operator*=(const Matrix<Field, COLUMN,\
    \ COLUMN>& rhs) {\n    std::array<std::array<value_t, COLUMN>, ROW> tmp;\n   \
    \ std::fill(tmp[0].begin(), tmp[ROW - 1].end(), 0);\n    for (size_t r = 0; r\
    \ < ROW; r++) {\n      for (size_t c = 0; c < COLUMN; c++) {\n        for (size_t\
    \ i = 0; i < COLUMN; i++) {\n          tmp[r][c] += a[r][i] * rhs.a[i][c];\n \
    \       }\n      }\n    }\n    a = std::move(tmp);\n    return *this;\n  }\n\n\
    \  constexpr static Matrix id() {\n    static_assert(ROW == COLUMN, \"ROW must\
    \ be equal to COLUMN\");\n    Matrix<Field, ROW, COLUMN> tmp;\n    for (size_t\
    \ i = 0; i < ROW; i++) tmp.a[i][i] = 1;\n    return tmp;\n  }\n\n  void print(){\n\
    \    for(size_t r=0;r<ROW;r++){\n      for(size_t c=0;c<COLUMN;c++){\n       \
    \ std::cout<<a[r][c]<<\" \";\n      }\n      std::cout<<\"\\n\";\n    }\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/Matrix.hpp
  requiredBy: []
  timestamp: '2020-08-07 11:08:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/Matrix.hpp
layout: document
redirect_from:
- /library/lib/math/Matrix.hpp
- /library/lib/math/Matrix.hpp.html
title: lib/math/Matrix.hpp
---
