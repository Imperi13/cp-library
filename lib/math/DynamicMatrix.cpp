#pragma once

#include <vector>
#include <cassert>
#include <utility>

template <typename Field>
class DynamicMatrix{
  public:
  using value_t = Field;
  using size_t = std::size_t;

  private:
  size_t row, column;
  std::vector<std::vector<value_t>> a;

  public:
  explicit DynamicMatrix(size_t row_, size_t column_, value_t init_ = value_t())
      : row(row_), column(column_), a(row, std::vector<value_t>(column, init_)) {}

  constexpr value_t& operator()(size_t i, size_t j) { return a[i][j]; }
  constexpr bool operator==(const DynamicMatrix& rhs){
    if (row != rhs.row || column != rhs.column)return false;
    for (size_t i = 0; i < row; i++){
      for (size_t j = 0; j < column; j++){
        if (a[i][j] != rhs.a[i][j])return false;
      }
    }
    return true;
  }
  constexpr bool operator!=(const DynamicMatrix& rhs) { return !(*this == rhs); }

  constexpr DynamicMatrix operator+(const DynamicMatrix rhs){
    return DynamicMatrix(*this) += rhs;
  }
  constexpr DynamicMatrix operator-(const DynamicMatrix rhs){
    return DynamicMatrix(*this) -= rhs;
  }
  constexpr DynamicMatrix operator*(const DynamicMatrix rhs){
    return DynamicMatrix(*this) *= rhs;
  }

  constexpr DynamicMatrix& operator+=(const DynamicMatrix& rhs){
    assert(row == rhs.row && column == rhs.column);
    for (size_t i = 0; i < row; i++){
      for (size_t j = 0; j < column; j++){
        a[i][j] += rhs.a[i][j];
      }
    }
    return *this;
  }
  constexpr DynamicMatrix& operator-=(const DynamicMatrix& rhs){
    assert(row == rhs.row && column == rhs.column);
    for (size_t i = 0; i < row; i++){
      for (size_t j = 0; j < column; j++){
        a[i][j] -= rhs.a[i][j];
      }
    }
    return *this;
  }
  constexpr DynamicMatrix& operator*=(const DynamicMatrix& rhs){
    assert(column == rhs.row);
    std::vector<std::vector<value_t>> tmp(row, std::vector<value_t>(rhs.column, 0));
    for (size_t r = 0; r < row; r++){
      for (size_t c = 0; c < rhs.column; c++){
        for (size_t i = 0; i < column; i++){
          tmp[r][c] += a[r][i] * rhs.a[i][c];
        }
      }
    }
    column = rhs.column;
    a = std::move(tmp);
    return *this;
  }

  constexpr static DynamicMatrix id(size_t size){
    DynamicMatrix<Field> tmp(size, size);
    for (size_t i = 0; i < size; i++)tmp.a[i][i] = 1;
    return tmp;
  }
};