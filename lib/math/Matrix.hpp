#pragma once

#include <array>
#include <cassert>
#include <utility>

template <typename Field, std::size_t ROW, std::size_t COLUMN>
class Matrix {
 public:
  using value_t = Field;
  using size_t = std::size_t;
  static constexpr size_t row = ROW;
  static constexpr size_t column = COLUMN;

  std::array<std::array<value_t, COLUMN>, ROW> a;

  explicit Matrix(const value_t init = value_t()) {
    std::fill(a[0].begin(), a[ROW - 1].end(), init);
  }

  Matrix(const std::array<std::array<Field, COLUMN>, ROW>& a_) : a(a_) {}

  constexpr value_t& operator()(size_t i, size_t j) { return a[i][j]; }
  constexpr bool operator==(const Matrix& rhs) {
    for (size_t i = 0; i < ROW; i++) {
      for (size_t j = 0; j < COLUMN; j++) {
        if (a[i][j] != rhs.a[i][j]) return false;
      }
    }
    return true;
  }
  constexpr bool operator!=(const Matrix& rhs) { return !(*this == rhs); }

  constexpr Matrix operator+(const Matrix rhs) { return Matrix(*this) += rhs; }
  constexpr Matrix operator-(const Matrix rhs) { return Matrix(*this) -= rhs; }

  template <size_t NEWCOLUMN>
  constexpr Matrix<Field, ROW, NEWCOLUMN> operator*(
      const Matrix<Field, COLUMN, NEWCOLUMN> rhs) {
    Matrix<Field, ROW, NEWCOLUMN> tmp;
    for (size_t r = 0; r < ROW; r++) {
      for (size_t c = 0; c < NEWCOLUMN; c++) {
        for (size_t i = 0; i < COLUMN; i++) {
          tmp.a[r][c] += a[r][i] * rhs.a[i][c];
        }
      }
    }
    return tmp;
  }

  constexpr Matrix& operator+=(const Matrix& rhs) {
    for (size_t i = 0; i < ROW; i++) {
      for (size_t j = 0; j < COLUMN; j++) {
        a[i][j] += rhs.a[i][j];
      }
    }
    return *this;
  }
  constexpr Matrix& operator-=(const Matrix& rhs) {
    for (size_t i = 0; i < ROW; i++) {
      for (size_t j = 0; j < COLUMN; j++) {
        a[i][j] -= rhs.a[i][j];
      }
    }
  }
  constexpr Matrix& operator*=(const Matrix<Field, COLUMN, COLUMN>& rhs) {
    std::array<std::array<value_t, COLUMN>, ROW> tmp;
    std::fill(tmp[0].begin(), tmp[ROW - 1].end(), 0);
    for (size_t r = 0; r < ROW; r++) {
      for (size_t c = 0; c < COLUMN; c++) {
        for (size_t i = 0; i < COLUMN; i++) {
          tmp[r][c] += a[r][i] * rhs.a[i][c];
        }
      }
    }
    a = std::move(tmp);
    return *this;
  }

  constexpr static Matrix id() {
    static_assert(ROW == COLUMN, "ROW must be equal to COLUMN");
    Matrix<Field, ROW, COLUMN> tmp;
    for (size_t i = 0; i < ROW; i++) tmp.a[i][i] = 1;
    return tmp;
  }

  void print(){
    for(size_t r=0;r<ROW;r++){
      for(size_t c=0;c<COLUMN;c++){
        std::cout<<a[r][c]<<" ";
      }
      std::cout<<"\n";
    }
  }
};