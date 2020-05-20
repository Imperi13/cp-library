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


# :heavy_check_mark: lib/UnionFind.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/UnionFind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-19 15:28:29+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/UnionFind.test.cpp.html">test/UnionFind.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <cstddef>
#include <vector>
#include <numeric>

class UnionFind{
  private:
  using size_type=std::size_t;

  std::vector<size_type> par,sz;
  size_type group;

  public:

  UnionFind(size_type n):par(n,0),sz(n,1),group(n){
    std::iota(par.begin(),par.end(),0);
  }

  size_type root(size_type n){
    if(par[n]==n)return n;
    return par[n]=root(par[n]);
  }

  bool unite(size_type a,size_type b){
    a=root(a);b=root(b);
    if(a==b)return false;
    if(sz[a]<sz[b])std::swap(a,b);
    sz[a]+=sz[b];
    par[b]=a;
    return true;
  }

  size_type size(){return par.size();}
  size_type groups(){return group;}
  size_type group_size(size_type n){return sz[root(n)];}

  bool same(size_type a,size_type b){return root(a)==root(b);}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/UnionFind.cpp"

#include <cstddef>
#include <vector>
#include <numeric>

class UnionFind{
  private:
  using size_type=std::size_t;

  std::vector<size_type> par,sz;
  size_type group;

  public:

  UnionFind(size_type n):par(n,0),sz(n,1),group(n){
    std::iota(par.begin(),par.end(),0);
  }

  size_type root(size_type n){
    if(par[n]==n)return n;
    return par[n]=root(par[n]);
  }

  bool unite(size_type a,size_type b){
    a=root(a);b=root(b);
    if(a==b)return false;
    if(sz[a]<sz[b])std::swap(a,b);
    sz[a]+=sz[b];
    par[b]=a;
    return true;
  }

  size_type size(){return par.size();}
  size_type groups(){return group;}
  size_type group_size(size_type n){return sz[root(n)];}

  bool same(size_type a,size_type b){return root(a)==root(b);}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

