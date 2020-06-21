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


# :heavy_check_mark: test/FactorialTable.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/FactorialTable.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-21 13:23:31+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1501">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1501</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/math/FactorialTable.hpp.html">lib/math/FactorialTable.hpp</a>
* :heavy_check_mark: <a href="../../library/lib/utility/modint.hpp.html">lib/utility/modint.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1501"

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
#include <unordered_map>
#include <vector>
#include <random>
#include <utility>
#include <limits>
#include <list>
#include <type_traits>

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
constexpr Num mypow(Num a, long long b) {
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

#include "../lib/math/FactorialTable.hpp"

constexpr ll MOD=1e8+7;

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  Factorial<1010,MOD> table;

  ll r,c,ax,ay,bx,by;
  std::cin>>r>>c>>ax>>ay>>bx>>by;

  ll mul=1;

  ll x=std::abs(ax-bx),y=std::abs(ay-by);

  chmin(x,r-x);
  chmin(y,c-y);

  if(r==2*x)mul*=2;
  if(c==2*y)mul*=2;

  std::cout<<(table.binom(x+y,x)*mul).value()<<"\n";

  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/FactorialTable.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1501"

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
#include <unordered_map>
#include <vector>
#include <random>
#include <utility>
#include <limits>
#include <list>
#include <type_traits>

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
constexpr Num mypow(Num a, long long b) {
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

#line 2 "lib/math/FactorialTable.hpp"

#line 2 "lib/utility/modint.hpp"

/*
  author:noshi91
  reference:https://noshi91.hatenablog.com/entry/2019/03/31/174006
            https://github.com/noshi91/Library/blob/master/other/modint.cpp

  1つめのmodintにoperator==,!=を追加したものです

  thx @noshi91!!
*/

#line 14 "lib/utility/modint.hpp"

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
#line 87 "test/FactorialTable.test.cpp"

constexpr ll MOD=1e8+7;

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  Factorial<1010,MOD> table;

  ll r,c,ax,ay,bx,by;
  std::cin>>r>>c>>ax>>ay>>bx>>by;

  ll mul=1;

  ll x=std::abs(ax-bx),y=std::abs(ay-by);

  chmin(x,r-x);
  chmin(y,c-y);

  if(r==2*x)mul*=2;
  if(c==2*y)mul*=2;

  std::cout<<(table.binom(x+y,x)*mul).value()<<"\n";

  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

