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


# :heavy_check_mark: test/DisjointSparseTable.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/DisjointSparseTable.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-31 15:44:20+09:00


* see: <a href="https://judge.yosupo.jp/problem/static_range_sum">https://judge.yosupo.jp/problem/static_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/DisjointSparseTable.hpp.html">lib/DisjointSparseTable.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

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

#include "../lib/DisjointSparseTable.hpp"

struct Semigroup{
  using value_t=ll;
  static constexpr value_t op(value_t a,value_t b){
    return a+b;
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n,q;
  std::cin>>n>>q;

  std::vector<ll> a(n);
  for(auto&& e:a)std::cin>>e;

  DisjointSparseTable<Semigroup> seq(a);

  while(q--){
    ll l,r;
    std::cin>>l>>r;
    std::cout<<seq.fold(l,r)<<"\n";
  }

  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/DisjointSparseTable.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

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

#line 2 "lib/DisjointSparseTable.hpp"

#line 5 "lib/DisjointSparseTable.hpp"

template <typename Semigroup>
class DisjointSparseTable {
 public:
  using value_t = typename Semigroup::value_t;
  using size_t = std::size_t;

 private:
  size_t n, n0;
  std::vector<size_t> ln;
  std::vector<std::vector<value_t>> table;

 public:
  DisjointSparseTable(const std::vector<value_t>& a) : n(a.size()) {
    n0 = 1;
    while (n0 < n) n0 <<= 1;
    ln = std::vector<size_t>(n0 + 1, 0);
    for (size_t i = 1; i < n0 + 1; i++)
      ln[i] = ln[i - 1] + (i >= (1ull << (ln[i - 1] + 1)));
    table = std::vector<std::vector<value_t>>(ln[n0] + 1, a);
    for (size_t i = 1; i < ln[n0] + 1; i++) {
      for (long long j = 1ll << (i - 1); j < n; j += 1ll << i) {
        for (long long k = j - 2; k >= j - (1ll << (i - 1)); k--)
          table[i][k] = Semigroup::op(a[k], table[i][k + 1]);
        for (long long k = j + 1;
             k < std::min(j + (1ll << (i - 1)), (long long)n); k++)
          table[i][k] = Semigroup::op(table[i][k - 1], a[k]);
      }
    }
  }

  value_t fold(size_t l, size_t r) {
    assert(0 <= l && l < r && r <= n);
    if (r == l + 1) return table[0][l];
    size_t m = ln[l ^ (r - 1)];
    return Semigroup::op(table[m + 1][l], table[m + 1][r - 1]);
  }
};
#line 87 "test/DisjointSparseTable.test.cpp"

struct Semigroup{
  using value_t=ll;
  static constexpr value_t op(value_t a,value_t b){
    return a+b;
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n,q;
  std::cin>>n>>q;

  std::vector<ll> a(n);
  for(auto&& e:a)std::cin>>e;

  DisjointSparseTable<Semigroup> seq(a);

  while(q--){
    ll l,r;
    std::cin>>l>>r;
    std::cout<<seq.fold(l,r)<<"\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

