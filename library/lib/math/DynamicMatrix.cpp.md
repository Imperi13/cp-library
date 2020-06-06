---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: lib/math/DynamicMatrix.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#b524a7b47b8ed72180f0e5150ab6d934">lib/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/math/DynamicMatrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-06 17:09:35+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/DynamicMatrix.test.cpp.html">test/DynamicMatrix.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/math/DynamicMatrix.cpp"

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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

