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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: test/DynamicMatrix_2.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/DynamicMatrix_2.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-31 15:44:20+09:00


* see: <a href="https://judge.yosupo.jp/problem/matrix_det">https://judge.yosupo.jp/problem/matrix_det</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/math/DynamicMatrix.hpp.html">lib/math/DynamicMatrix.hpp</a>
* :heavy_check_mark: <a href="../../library/lib/utility/modint.hpp.html">lib/utility/modint.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <chrono>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <vector>
#include <random>
#include <utility>
#include <limits>
#include <list>

/* template start */
 
#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(i) i.begin(), i.end()

#ifdef LOCAL
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out(){std::cerr<<std::endl;}

template<typename Head,typename... Tail>
void debug_out(Head h,Tail... t){
  std::cerr<<" "<<h;
  if(sizeof...(t)>0)std::cout<<" :";
  debug_out(t...);
}
 
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << pa.first << " " << pa.second;
}
 
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (std::size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}
 
template<typename T1,typename T2>
inline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}
 
template<typename T1,typename T2>
inline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}

template<typename Num>
constexpr Num mypow(Num a, unsigned long long b) {
  if(b==0)return 1;
  if (a==0)return 0;
  Num x = 1;
  while (b > 0) {
    if(b & 1)x*=a;
    a*=a;
    b >>= 1;
  }
  return x;
}

/* template end */

using ll = long long;

#include "../lib/math/DynamicMatrix.hpp"

#include "../lib/utility/modint.hpp"

constexpr ll MOD=998244353;

using mint=modint<MOD>;

using mat=DynamicMatrix<mint>;

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n;
  std::cin>>n;

  mat tmp(n,n);

  rep(i,0,n){
    rep(j,0,n){
      ll e;
      std::cin>>e;
      tmp(i,j)=e;
    }
  }

  std::cout<<tmp.det().value()<<"\n";

  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/DynamicMatrix_2.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <chrono>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <vector>
#include <random>
#include <utility>
#include <limits>
#include <list>

/* template start */
 
#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(i) i.begin(), i.end()

#ifdef LOCAL
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out(){std::cerr<<std::endl;}

template<typename Head,typename... Tail>
void debug_out(Head h,Tail... t){
  std::cerr<<" "<<h;
  if(sizeof...(t)>0)std::cout<<" :";
  debug_out(t...);
}
 
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << pa.first << " " << pa.second;
}
 
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (std::size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}
 
template<typename T1,typename T2>
inline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}
 
template<typename T1,typename T2>
inline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}

template<typename Num>
constexpr Num mypow(Num a, unsigned long long b) {
  if(b==0)return 1;
  if (a==0)return 0;
  Num x = 1;
  while (b > 0) {
    if(b & 1)x*=a;
    a*=a;
    b >>= 1;
  }
  return x;
}

/* template end */

using ll = long long;

#line 2 "lib/math/DynamicMatrix.hpp"

#line 6 "lib/math/DynamicMatrix.hpp"

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
#line 87 "test/DynamicMatrix_2.test.cpp"

#line 2 "lib/utility/modint.hpp"

/*
  author:noshi91
  reference:https://noshi91.hatenablog.com/entry/2019/03/31/174006
            https://github.com/noshi91/Library/blob/master/other/modint.cpp

  1つめのmodintにoperator==,!=を追加したものです

  thx @noshi91!!
*/

#line 14 "lib/utility/modint.hpp"

template <std::uint_fast64_t Modulus>
class modint {
  using u64 = std::uint_fast64_t;

 public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr bool operator==(const modint rhs) const noexcept {
    return a == rhs.a;
  }
  constexpr bool operator!=(const modint rhs) const noexcept {
    return !(*this == rhs);
  }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};
#line 89 "test/DynamicMatrix_2.test.cpp"

constexpr ll MOD=998244353;

using mint=modint<MOD>;

using mat=DynamicMatrix<mint>;

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n;
  std::cin>>n;

  mat tmp(n,n);

  rep(i,0,n){
    rep(j,0,n){
      ll e;
      std::cin>>e;
      tmp(i,j)=e;
    }
  }

  std::cout<<tmp.det().value()<<"\n";

  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

