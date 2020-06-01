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


# :heavy_check_mark: test/SparseTable.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/SparseTable.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 01:52:30+09:00


* see: <a href="https://judge.yosupo.jp/problem/staticrmq">https://judge.yosupo.jp/problem/staticrmq</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/SparseTable.cpp.html">lib/SparseTable.cpp</a>
* :heavy_check_mark: <a href="../../library/lib/utility/Monoid.cpp.html">lib/utility/Monoid.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <cassert>
#include <algorithm>

#include <vector>

#include "../lib/SparseTable.cpp"

struct Semigroup{
  using value_t = long long;
  static constexpr value_t op(const value_t &a, const value_t &b){
    return std::min(a, b);
  }
};

using ll = long long;
using P = std::pair<ll, ll>;

int main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n, q;
  std::cin >> n >> q;

  std::vector<ll> a(n);
  for (auto &&e : a)
    std::cin >> e;

  SparseTable<Semigroup> sp(a);

  while (q--)
  {
    ll l, r;
    std::cin >> l >> r;
    std::cout << sp.fold(l, r) << "\n";
  }

  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/SparseTable.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <cassert>
#include <algorithm>

#include <vector>

#line 2 "lib/SparseTable.cpp"

#line 5 "lib/SparseTable.cpp"

#line 2 "lib/utility/Monoid.cpp"

#line 4 "lib/utility/Monoid.cpp"

template<typename Semigroup>
class OptionalMonoid{
  private:
  using base_t=typename Semigroup::value_t;
  public:
  using value_t=std::pair<base_t,bool>;
  constexpr static value_t id={base_t(),false};
  constexpr static value_t op(value_t a,value_t b){
    if(a.second&&b.second)return {Semigroup::op(a.first,b.first),true};
    if(a.second||b.second) return a.second?a:b;
    return id;
  }
};

template<typename Monoid>
class ReverseMonoid{
  private:
  using base_t=typename Monoid::value_t;
  public:
  using value_t=std::pair<base_t,base_t>;
  constexpr static value_t id={Monoid::id,Monoid::id};
  constexpr static value_t op(value_t a,value_t b){
    return {Monoid::op(a.first,b.first),Monoid::op(b.second,a.second)};
  }
};
#line 7 "lib/SparseTable.cpp"

//Semigroup
// type value_t 
// static (value_t ,value_t)->value_t op

// a op a == a

template<typename Semigroup>
class SparseTable{
  public:
  using value_t=typename Semigroup::value_t;
  using size_t=std::size_t;
  private:
  using Opt=OptionalMonoid<Semigroup>;
  using opt_t=typename Opt::value_t;

  size_t n;
  std::vector<size_t> ln;
  std::vector<std::vector<opt_t>> table;

  public:
  SparseTable(const std::vector<value_t>& a):n(a.size()),ln(n+1,0){
    for(size_t i=1;i<n+1;i++)ln[i]=ln[i-1]+(i>=(1ull<<(ln[i-1]+1)));
    table=std::vector<std::vector<opt_t>>(ln[n]+1,std::vector<opt_t>(n,Opt::id));
    for(size_t i=0;i<n;i++)table[0][i]={a[i],true};
    for(size_t j=1;j<ln[n]+1;j++){
      for(size_t i=0;i<n;i++){
        if(i+(1ll<<j) > n)table[j][i]=Opt::id;
        else table[j][i]=Opt::op(table[j-1][i],table[j-1][i+(1ll<<(j-1))]);
      }
    }
  }

  value_t fold(size_t l,size_t r){
    assert(0<=l&&l<r&&r<=n);
    size_t m=r-l;
    return Opt::op(table[ln[m]][l],table[ln[m]][r-(1ll<<ln[m])]).first;
  }
};
#line 10 "test/SparseTable.test.cpp"

struct Semigroup{
  using value_t = long long;
  static constexpr value_t op(const value_t &a, const value_t &b){
    return std::min(a, b);
  }
};

using ll = long long;
using P = std::pair<ll, ll>;

int main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n, q;
  std::cin >> n >> q;

  std::vector<ll> a(n);
  for (auto &&e : a)
    std::cin >> e;

  SparseTable<Semigroup> sp(a);

  while (q--)
  {
    ll l, r;
    std::cin >> l >> r;
    std::cout << sp.fold(l, r) << "\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

