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


# :warning: lib/math/Matrix.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#b524a7b47b8ed72180f0e5150ab6d934">lib/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/math/Matrix.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-12 12:00:09+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <cassert>
#include <array>
#include <utility>

template<typename Field,std::size_t ROW,std::size_t COLUMN>
class Matrix{
  public:
  using value_t=Field;
  using size_t=std::size_t;
  static constexpr size_t row=ROW;
  static constexpr size_t column=COLUMN;

  std::array<std::array<value_t,COLUMN>,ROW> a;

  explicit Matrix(const value_t init=value_t()){
    std::fill(a[0].begin(),a[ROW-1].end(),init);
  }

  Matrix(const std::array<std::array<Field,COLUMN>,ROW>& a_):a(a_){}

  constexpr value_t& operator()(size_t i,size_t j){return a[i][j];}
  constexpr   bool operator==(const Matrix& rhs){
    for(size_t i=0;i<ROW;i++){
      for(size_t j=0;j<COLUMN;j++){
        if(a[i][j]!=rhs.a[i][j])return false;
      }
    }
    return true;
  }
  constexpr bool operator!=(const Matrix& rhs){return !(*this==rhs);}

  constexpr Matrix operator+(const Matrix rhs){
    return Matrix(*this)+=rhs;
  }
  constexpr Matrix operator-(const Matrix rhs){
    return Matrix(*this)-=rhs;
  }
  
  template<size_t NEWCOLUMN>
  constexpr Matrix<Field,ROW,NEWCOLUMN> operator*(const Matrix<Field,COLUMN,NEWCOLUMN> rhs){
    Matrix<Field,ROW,NEWCOLUMN> tmp;
    for(size_t r=0;r<ROW;r++){
      for(size_t c=0;c<NEWCOLUMN;c++){
        for(size_t i=0;i<COLUMN;i++){
          tmp.a[r][c]+=a[r][i]*rhs.a[i][c];
        }
      }
    }
    return tmp;
  }

  constexpr Matrix& operator+=(const Matrix& rhs){
    for(size_t i=0;i<ROW;i++){
      for(size_t j=0;j<COLUMN;j++){
        a[i][j]+=rhs.a[i][j];
      }
    }
    return *this;
  }
  constexpr Matrix& operator-=(const Matrix& rhs){
    for(size_t i=0;i<ROW;i++){
      for(size_t j=0;j<COLUMN;j++){
        a[i][j]-=rhs.a[i][j];
      }
    }
  }
  constexpr Matrix& operator*=(const Matrix<Field,COLUMN,COLUMN>& rhs){
    std::array<std::array<value_t,COLUMN>,ROW> tmp;
    for(size_t r=0;r<ROW;r++){
      for(size_t c=0;c<COLUMN;c++){
        for(size_t i=0;i<COLUMN;i++){
          tmp[r][c]+=a[r][i]*rhs.a[i][c];
        }
      }
    }
    a=std::move(tmp);
    return *this;
  }

  constexpr static Matrix id(){
    static_assert(ROW==COLUMN,"ROW must be equal to COLUMN");
    Matrix<Field,ROW,COLUMN> tmp;
    for(size_t i=0;i<ROW;i++)tmp.a[i][i]=1;
    return tmp;
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/math/Matrix.hpp"

#include <cassert>
#include <array>
#include <utility>

template<typename Field,std::size_t ROW,std::size_t COLUMN>
class Matrix{
  public:
  using value_t=Field;
  using size_t=std::size_t;
  static constexpr size_t row=ROW;
  static constexpr size_t column=COLUMN;

  std::array<std::array<value_t,COLUMN>,ROW> a;

  explicit Matrix(const value_t init=value_t()){
    std::fill(a[0].begin(),a[ROW-1].end(),init);
  }

  Matrix(const std::array<std::array<Field,COLUMN>,ROW>& a_):a(a_){}

  constexpr value_t& operator()(size_t i,size_t j){return a[i][j];}
  constexpr   bool operator==(const Matrix& rhs){
    for(size_t i=0;i<ROW;i++){
      for(size_t j=0;j<COLUMN;j++){
        if(a[i][j]!=rhs.a[i][j])return false;
      }
    }
    return true;
  }
  constexpr bool operator!=(const Matrix& rhs){return !(*this==rhs);}

  constexpr Matrix operator+(const Matrix rhs){
    return Matrix(*this)+=rhs;
  }
  constexpr Matrix operator-(const Matrix rhs){
    return Matrix(*this)-=rhs;
  }
  
  template<size_t NEWCOLUMN>
  constexpr Matrix<Field,ROW,NEWCOLUMN> operator*(const Matrix<Field,COLUMN,NEWCOLUMN> rhs){
    Matrix<Field,ROW,NEWCOLUMN> tmp;
    for(size_t r=0;r<ROW;r++){
      for(size_t c=0;c<NEWCOLUMN;c++){
        for(size_t i=0;i<COLUMN;i++){
          tmp.a[r][c]+=a[r][i]*rhs.a[i][c];
        }
      }
    }
    return tmp;
  }

  constexpr Matrix& operator+=(const Matrix& rhs){
    for(size_t i=0;i<ROW;i++){
      for(size_t j=0;j<COLUMN;j++){
        a[i][j]+=rhs.a[i][j];
      }
    }
    return *this;
  }
  constexpr Matrix& operator-=(const Matrix& rhs){
    for(size_t i=0;i<ROW;i++){
      for(size_t j=0;j<COLUMN;j++){
        a[i][j]-=rhs.a[i][j];
      }
    }
  }
  constexpr Matrix& operator*=(const Matrix<Field,COLUMN,COLUMN>& rhs){
    std::array<std::array<value_t,COLUMN>,ROW> tmp;
    for(size_t r=0;r<ROW;r++){
      for(size_t c=0;c<COLUMN;c++){
        for(size_t i=0;i<COLUMN;i++){
          tmp[r][c]+=a[r][i]*rhs.a[i][c];
        }
      }
    }
    a=std::move(tmp);
    return *this;
  }

  constexpr static Matrix id(){
    static_assert(ROW==COLUMN,"ROW must be equal to COLUMN");
    Matrix<Field,ROW,COLUMN> tmp;
    for(size_t i=0;i<ROW;i++)tmp.a[i][i]=1;
    return tmp;
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

