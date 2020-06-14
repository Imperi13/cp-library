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


# :heavy_check_mark: lib/DisjointSparseTable.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/DisjointSparseTable.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-14 19:45:00+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/DisjointSparseTable.test.cpp.html">test/DisjointSparseTable.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <vector>
#include <cassert>

template<typename Semigroup>
class DisjointSparseTable{
  public:
  using value_t=typename Semigroup::value_t;
  using size_t=std::size_t;
  private:

  size_t n,n0;
  std::vector<size_t> ln;
  std::vector<std::vector<value_t>> table;

  public:
  DisjointSparseTable(const std::vector<value_t>& a):n(a.size()){
    n0=1;
    while(n0<n)n0<<=1;
    ln=std::vector<size_t>(n0+1,0);
    for(size_t i=1;i<n0+1;i++)ln[i]=ln[i-1]+(i>=(1ull<<(ln[i-1]+1)));
    table=std::vector<std::vector<value_t>>(ln[n0]+1,a);
    for(size_t i=1;i<ln[n0]+1;i++){
      for(long long j=1ll<<(i-1);j<n;j+=1ll<<i){
        for(long long k=j-2;k>=j-(1ll<<(i-1));k--)
          table[i][k]=Semigroup::op(a[k],table[i][k+1]);
        for(long long k=j+1;k<std::min(j+(1ll<<(i-1)),(long long)n);k++)
          table[i][k]=Semigroup::op(table[i][k-1],a[k]);
      }
    }
  }

  value_t fold(size_t l,size_t r){
    assert(0<=l&&l<r&&r<=n);
    if(r==l+1)return table[0][l];
    size_t m=ln[l^(r-1)];
    return Semigroup::op(table[m+1][l],table[m+1][r-1]);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/DisjointSparseTable.hpp"

#include <vector>
#include <cassert>

template<typename Semigroup>
class DisjointSparseTable{
  public:
  using value_t=typename Semigroup::value_t;
  using size_t=std::size_t;
  private:

  size_t n,n0;
  std::vector<size_t> ln;
  std::vector<std::vector<value_t>> table;

  public:
  DisjointSparseTable(const std::vector<value_t>& a):n(a.size()){
    n0=1;
    while(n0<n)n0<<=1;
    ln=std::vector<size_t>(n0+1,0);
    for(size_t i=1;i<n0+1;i++)ln[i]=ln[i-1]+(i>=(1ull<<(ln[i-1]+1)));
    table=std::vector<std::vector<value_t>>(ln[n0]+1,a);
    for(size_t i=1;i<ln[n0]+1;i++){
      for(long long j=1ll<<(i-1);j<n;j+=1ll<<i){
        for(long long k=j-2;k>=j-(1ll<<(i-1));k--)
          table[i][k]=Semigroup::op(a[k],table[i][k+1]);
        for(long long k=j+1;k<std::min(j+(1ll<<(i-1)),(long long)n);k++)
          table[i][k]=Semigroup::op(table[i][k-1],a[k]);
      }
    }
  }

  value_t fold(size_t l,size_t r){
    assert(0<=l&&l<r&&r<=n);
    if(r==l+1)return table[0][l];
    size_t m=ln[l^(r-1)];
    return Semigroup::op(table[m+1][l],table[m+1][r-1]);
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

