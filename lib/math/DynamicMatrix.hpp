#pragma once

#include <cassert>
#include <utility>
#include <vector>

template <typename Field>
class DynamicMatrix {
 public:
  using value_t = Field;
  using size_t = std::size_t;

 private:
  size_t row, column;
  std::vector<std::vector<value_t>> a;

 public:
  explicit DynamicMatrix(size_t row_ = 0, size_t column_ = 0,
                         value_t init_ = value_t())
      : row(row_),
        column(column_),
        a(row, std::vector<value_t>(column, init_)) {}

  constexpr value_t& operator()(size_t i, size_t j) {
    assert(0 <= i && i < row && 0 <= j && j < column);
    return a[i][j];
  }
  constexpr bool operator==(const DynamicMatrix& rhs) {
    if (row != rhs.row || column != rhs.column) return false;
    for (size_t i = 0; i < row; i++) {
      for (size_t j = 0; j < column; j++) {
        if (a[i][j] != rhs.a[i][j]) return false;
      }
    }
    return true;
  }
  constexpr bool operator!=(const DynamicMatrix& rhs) {
    return !(*this == rhs);
  }

  constexpr DynamicMatrix operator+(const DynamicMatrix rhs) {
    return DynamicMatrix(*this) += rhs;
  }
  constexpr DynamicMatrix operator-(const DynamicMatrix rhs) {
    return DynamicMatrix(*this) -= rhs;
  }
  constexpr DynamicMatrix operator*(const DynamicMatrix rhs) {
    return DynamicMatrix(*this) *= rhs;
  }

  constexpr DynamicMatrix& operator+=(const DynamicMatrix& rhs) {
    assert(row == rhs.row && column == rhs.column);
    for (size_t i = 0; i < row; i++) {
      for (size_t j = 0; j < column; j++) {
        a[i][j] += rhs.a[i][j];
      }
    }
    return *this;
  }
  constexpr DynamicMatrix& operator-=(const DynamicMatrix& rhs) {
    assert(row == rhs.row && column == rhs.column);
    for (size_t i = 0; i < row; i++) {
      for (size_t j = 0; j < column; j++) {
        a[i][j] -= rhs.a[i][j];
      }
    }
    return *this;
  }
  constexpr DynamicMatrix& operator*=(const DynamicMatrix& rhs) {
    assert(column == rhs.row);
    std::vector<std::vector<value_t>> tmp(row,
                                          std::vector<value_t>(rhs.column, 0));
    for (size_t r = 0; r < row; r++) {
      for (size_t c = 0; c < rhs.column; c++) {
        for (size_t i = 0; i < column; i++) {
          tmp[r][c] += a[r][i] * rhs.a[i][c];
        }
      }
    }
    column = rhs.column;
    a = std::move(tmp);
    return *this;
  }

  constexpr static DynamicMatrix id(size_t size) {
    DynamicMatrix<Field> tmp(size, size);
    for (size_t i = 0; i < size; i++) tmp.a[i][i] = 1;
    return tmp;
  }

  constexpr void LUPdecomposition(DynamicMatrix& P, DynamicMatrix& L,
                                  DynamicMatrix& U) {
    assert(row == column);
    std::vector<std::vector<value_t>> tmp = a;
    P = DynamicMatrix::id(row);
    L = DynamicMatrix(row, column, 0);
    U = DynamicMatrix(row, column, 0);

    for (size_t i = 0; i < row; i++) {
      for (size_t j = 0; j < column; j++) {
        value_t val = 0;
        for (size_t k = 0; k < i; k++) val += L.a[j][k] * U.a[k][i];
        if (val != tmp[j][i]) {
          std::swap(tmp[i], tmp[j]);
          std::swap(P.a[i], P.a[j]);
          std::swap(L.a[i], L.a[j]);
          break;
        }
      }
      L.a[i][i] = 1;
      for (size_t j = i; j < row; j++) {
        U.a[i][j] = tmp[i][j];
        for (size_t k = 0; k < i; k++) U.a[i][j] -= L.a[i][k] * U.a[k][j];
      }
      if (U.a[i][i] != 0) {
        for (size_t j = i + 1; j < row; j++) {
          L.a[j][i] = tmp[j][i];
          for (size_t k = 0; k < i; k++) L.a[j][i] -= L.a[j][k] * U.a[k][i];
          L.a[j][i] /= U.a[i][i];
        }
      }
    }
  }

  constexpr value_t det() {
    DynamicMatrix<Field> p, l, u;
    LUPdecomposition(p, l, u);
    size_t cnt = 0;
    value_t ret = 0;
    for (size_t i = 0; i < row; i++) {
      if (p.a[i][i] == 1) continue;
      for (size_t j = 1; j < row; j++) {
        if (p.a[j][i] == 1) {
          std::swap(p.a[i], p.a[j]);
          cnt++;
          break;
        }
      }
    }
    if (cnt & 1)
      ret -= 1;
    else
      ret += 1;
    for (size_t i = 0; i < row; i++) ret *= u.a[i][i];
    return ret;
  }
};