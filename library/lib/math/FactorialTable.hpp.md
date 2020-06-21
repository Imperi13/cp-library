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


# :heavy_check_mark: lib/math/FactorialTable.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#b524a7b47b8ed72180f0e5150ab6d934">lib/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/math/FactorialTable.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-21 13:23:31+09:00




## Depends on

* :heavy_check_mark: <a href="../utility/modint.hpp.html">lib/utility/modint.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/FactorialTable.test.cpp.html">test/FactorialTable.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "../utility/modint.hpp"

#include <vector>
#include <cassert>
#include <cstdint>

template<std::size_t N,std::uint_fast64_t MOD>
class Factorial{
  public:
  using mint=modint<MOD>;
  using size_t=std::size_t;
  private:
  std::vector<mint> factorial,factorial_inv;
  public:
  Factorial():factorial(N+1),factorial_inv(N+1){
    factorial[0]=1;
    for(size_t i=1;i<N+1;i++)factorial[i]=factorial[i-1]*i;
    factorial_inv[N]=mint(1)/factorial[N];
    for(size_t i=N;i>0;i--)factorial_inv[i-1]=factorial_inv[i]*i;
  }

  mint fact(size_t pos)const{
    assert(0<=pos&&pos<=N);
    return factorial[pos];
  }
  mint fact_inv(size_t pos)const{
    assert(0<=pos&&pos<=N);
    return factorial_inv[pos];
  }
  mint binom(size_t n,size_t k)const{
    assert(0<=n&&n<=N);
    assert(0<=k&&k<=n);
    return fact(n)*fact_inv(k)*fact_inv(n-k);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/math/FactorialTable.hpp"

#line 2 "lib/utility/modint.hpp"

/*
  author:noshi91
  reference:https://noshi91.hatenablog.com/entry/2019/03/31/174006
            https://github.com/noshi91/Library/blob/master/other/modint.cpp

  1つめのmodintにoperator==,!=を追加したものです

  thx @noshi91!!
*/

#include <cstdint>

template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;

public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr bool operator==(const modint rhs) const noexcept {return a==rhs.a;}
  constexpr bool operator!=(const modint rhs) const noexcept {return !(*this==rhs);}
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
#line 4 "lib/math/FactorialTable.hpp"

#include <vector>
#include <cassert>
#line 8 "lib/math/FactorialTable.hpp"

template<std::size_t N,std::uint_fast64_t MOD>
class Factorial{
  public:
  using mint=modint<MOD>;
  using size_t=std::size_t;
  private:
  std::vector<mint> factorial,factorial_inv;
  public:
  Factorial():factorial(N+1),factorial_inv(N+1){
    factorial[0]=1;
    for(size_t i=1;i<N+1;i++)factorial[i]=factorial[i-1]*i;
    factorial_inv[N]=mint(1)/factorial[N];
    for(size_t i=N;i>0;i--)factorial_inv[i-1]=factorial_inv[i]*i;
  }

  mint fact(size_t pos)const{
    assert(0<=pos&&pos<=N);
    return factorial[pos];
  }
  mint fact_inv(size_t pos)const{
    assert(0<=pos&&pos<=N);
    return factorial_inv[pos];
  }
  mint binom(size_t n,size_t k)const{
    assert(0<=n&&n<=N);
    assert(0<=k&&k<=n);
    return fact(n)*fact_inv(k)*fact_inv(n-k);
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

