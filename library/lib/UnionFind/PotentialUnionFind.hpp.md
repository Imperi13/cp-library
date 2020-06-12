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


# :heavy_check_mark: lib/UnionFind/PotentialUnionFind.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d8ce77e7929e89891ebe5f859497af18">lib/UnionFind</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/UnionFind/PotentialUnionFind.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-12 12:00:09+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/PotentialUnionFind.test.cpp.html">test/PotentialUnionFind.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <vector>
#include <cassert>
#include <numeric>

template<typename Group>
class PotentialUnionFind{
  public:
  using value_t=typename Group::value_t;
  using size_t=std::size_t;
  private:
  size_t group;
  std::vector<size_t> par,sz;
  std::vector<value_t> df; //val[par]=val[x]+df[x]

  value_t fold_to_root(size_t x){
    value_t ret=Group::id;
    while(par[x]!=x){
      df[x]=Group::op(df[x],df[par[x]]);
      par[x]=par[par[x]];
      ret=Group::op(ret,df[x]);
      x=par[x];
    }
    return ret;
  }

  public:
  PotentialUnionFind(size_t n=0):group(n),par(n),sz(n,1),df(n,Group::id){
    std::iota(par.begin(),par.end(),0);
  }

  size_t root(size_t x){
    while(par[x]!=x){
      df[x]=Group::op(df[x],df[par[x]]);
      par[x]=par[par[x]];
      x=par[x];
    }
    return x;
  }

  bool same(size_t a,size_t b){return root(a)==root(b);}
  size_t size(){return par.size();}
  size_t groups(){return group;}
  size_t group_size(size_t x){return sz[root(x)];}

  // unite A=B+value
  bool unite(size_t a,size_t b,value_t value){
    size_t aroot=root(a),broot=root(b);
    if(aroot==broot)return false;
    group--;
    if(sz[aroot]<sz[broot]){
      std::swap(aroot,broot);
      std::swap(a,b);
      value=Group::inv(value);
    }
    sz[aroot]+=sz[broot];
    value=Group::op(value,fold_to_root(a));
    value=Group::op(Group::inv(fold_to_root(b)),value);
    df[broot]=value;
    par[broot]=aroot;
    return true;
  }

  // return diff  such as A=B+diff
  value_t diff(size_t a,size_t b){
    assert(same(a,b));
    return Group::op(fold_to_root(b),Group::inv(fold_to_root(a)));
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/UnionFind/PotentialUnionFind.hpp"

#include <vector>
#include <cassert>
#include <numeric>

template<typename Group>
class PotentialUnionFind{
  public:
  using value_t=typename Group::value_t;
  using size_t=std::size_t;
  private:
  size_t group;
  std::vector<size_t> par,sz;
  std::vector<value_t> df; //val[par]=val[x]+df[x]

  value_t fold_to_root(size_t x){
    value_t ret=Group::id;
    while(par[x]!=x){
      df[x]=Group::op(df[x],df[par[x]]);
      par[x]=par[par[x]];
      ret=Group::op(ret,df[x]);
      x=par[x];
    }
    return ret;
  }

  public:
  PotentialUnionFind(size_t n=0):group(n),par(n),sz(n,1),df(n,Group::id){
    std::iota(par.begin(),par.end(),0);
  }

  size_t root(size_t x){
    while(par[x]!=x){
      df[x]=Group::op(df[x],df[par[x]]);
      par[x]=par[par[x]];
      x=par[x];
    }
    return x;
  }

  bool same(size_t a,size_t b){return root(a)==root(b);}
  size_t size(){return par.size();}
  size_t groups(){return group;}
  size_t group_size(size_t x){return sz[root(x)];}

  // unite A=B+value
  bool unite(size_t a,size_t b,value_t value){
    size_t aroot=root(a),broot=root(b);
    if(aroot==broot)return false;
    group--;
    if(sz[aroot]<sz[broot]){
      std::swap(aroot,broot);
      std::swap(a,b);
      value=Group::inv(value);
    }
    sz[aroot]+=sz[broot];
    value=Group::op(value,fold_to_root(a));
    value=Group::op(Group::inv(fold_to_root(b)),value);
    df[broot]=value;
    par[broot]=aroot;
    return true;
  }

  // return diff  such as A=B+diff
  value_t diff(size_t a,size_t b){
    assert(same(a,b));
    return Group::op(fold_to_root(b),Group::inv(fold_to_root(a)));
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

