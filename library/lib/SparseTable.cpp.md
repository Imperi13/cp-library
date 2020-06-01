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


# :heavy_check_mark: lib/SparseTable.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/SparseTable.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-02 01:52:30+09:00




## Depends on

* :heavy_check_mark: <a href="utility/Monoid.cpp.html">lib/utility/Monoid.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/SparseTable.test.cpp.html">test/SparseTable.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <vector>
#include <cassert>

#include "./utility/Monoid.cpp"

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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/SparseTable.cpp"

#include <vector>
#include <cassert>

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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

