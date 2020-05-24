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


# :x: lib/SegmentTree/LazySegmentTree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8d75131a1ef4f10f86f251b50b9a3462">lib/SegmentTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/SegmentTree/LazySegmentTree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-24 21:52:44+09:00




## Verified with

* :x: <a href="../../../verify/test/LazySegmentTree.test.cpp.html">test/LazySegmentTree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <vector>
#include <cassert>

//Lazy
// type value_t
// type lazy_t
// static value_t id_val
// static value_t id_lazy
// static (value_t,value_t) -> value_t f
// static (value_t,lazy_t) -> value_t g
// static (lazy_t,lazy_t) -> lazy_t h
// static (lazy_t,size_t) -> lazy_t p


template<typename Lazy>
class LazySegmentTree{
  public:
  using value_t=typename Lazy::value_t;
  using lazy_t=typename Lazy::lazy_t;
  using size_t=std::size_t;
  private:
  size_t n,n0;
  std::vector<value_t> val;
  std::vector<lazy_t> lazy;

  value_t update(size_t a,size_t b,lazy_t laz,size_t l,size_t r,size_t k){
    if(lazy[k]!=Lazy::id_lazy){
      if(k<n0-1){
        lazy[2*k+1]=Lazy::h(lazy[2*k+1],lazy[k]);
        lazy[2*k+2]=Lazy::h(lazy[2*k+2],lazy[k]);
      }
      val[k]=Lazy::g(val[k],Lazy::p(lazy[k],r-l));
      lazy[k]=Lazy::id_lazy;
    }

    if(r<=a||b<=l)return val[k];
    if(a<=l&&r<=b){
      lazy[k]=Lazy::h(lazy[k],laz);
      return Lazy::g(val[k],Lazy::p(lazy[k],r-l));
    }
    return val[k]=Lazy::f(update(a,b,laz,l,l+(r-l)/2,2*k+1),update(a,b,laz,l+(r-l)/2,r,2*k+2));
  }

  value_t fold(size_t a,size_t b,size_t l,size_t r,size_t k){
    if(lazy[k]!=Lazy::id_lazy){
      if(k<n0-1){
        lazy[2*k+1]=Lazy::h(lazy[2*k+1],lazy[k]);
        lazy[2*k+2]=Lazy::h(lazy[2*k+2],lazy[k]);
      }
      val[k]=Lazy::g(val[k],Lazy::p(lazy[k],r-l));
      lazy[k]=Lazy::id_lazy;
    }

    if(r<=a||b<=l)return Lazy::id_val;
    if(a<=l&&r<=b)return val[k];
    return Lazy::f(fold(a,b,l,l+(r-l)/2,2*k+1),
                   fold(a,b,l+(r-l)/2,r,2*k+2));
  }

  inline size_t beki(size_t n_){
    size_t ret=1;
    while(ret<n_)ret<<=1;
    return ret;
  }

  public:
  LazySegmentTree(size_t n_):n(n_),n0(beki(n)),
                             val(2*n0-1,Lazy::id_val),lazy(2*n0-1,Lazy::id_lazy){}
  
  LazySegmentTree(std::vector<value_t> val_):n(val_.size()),n0(beki(n)),
                             val(2*n0-1,Lazy::id_val),lazy(2*n0-1,Lazy::id_lazy){
    for(size_t i=0;i<n;i++)val[i+n0-1]=val_[i];
    for(long long i=n0-2;i>=0;i--)val[i]=Lazy::f(val[2*i+1],val[2*i+2]);
  }

  void update(size_t a,size_t b,lazy_t laz){
    update(a,b,laz,0,n0,0);
  }

  value_t fold(size_t a,size_t b){
    return fold(a,b,0,n0,0);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/SegmentTree/LazySegmentTree.cpp"

#include <vector>
#include <cassert>

//Lazy
// type value_t
// type lazy_t
// static value_t id_val
// static value_t id_lazy
// static (value_t,value_t) -> value_t f
// static (value_t,lazy_t) -> value_t g
// static (lazy_t,lazy_t) -> lazy_t h
// static (lazy_t,size_t) -> lazy_t p


template<typename Lazy>
class LazySegmentTree{
  public:
  using value_t=typename Lazy::value_t;
  using lazy_t=typename Lazy::lazy_t;
  using size_t=std::size_t;
  private:
  size_t n,n0;
  std::vector<value_t> val;
  std::vector<lazy_t> lazy;

  value_t update(size_t a,size_t b,lazy_t laz,size_t l,size_t r,size_t k){
    if(lazy[k]!=Lazy::id_lazy){
      if(k<n0-1){
        lazy[2*k+1]=Lazy::h(lazy[2*k+1],lazy[k]);
        lazy[2*k+2]=Lazy::h(lazy[2*k+2],lazy[k]);
      }
      val[k]=Lazy::g(val[k],Lazy::p(lazy[k],r-l));
      lazy[k]=Lazy::id_lazy;
    }

    if(r<=a||b<=l)return val[k];
    if(a<=l&&r<=b){
      lazy[k]=Lazy::h(lazy[k],laz);
      return Lazy::g(val[k],Lazy::p(lazy[k],r-l));
    }
    return val[k]=Lazy::f(update(a,b,laz,l,l+(r-l)/2,2*k+1),update(a,b,laz,l+(r-l)/2,r,2*k+2));
  }

  value_t fold(size_t a,size_t b,size_t l,size_t r,size_t k){
    if(lazy[k]!=Lazy::id_lazy){
      if(k<n0-1){
        lazy[2*k+1]=Lazy::h(lazy[2*k+1],lazy[k]);
        lazy[2*k+2]=Lazy::h(lazy[2*k+2],lazy[k]);
      }
      val[k]=Lazy::g(val[k],Lazy::p(lazy[k],r-l));
      lazy[k]=Lazy::id_lazy;
    }

    if(r<=a||b<=l)return Lazy::id_val;
    if(a<=l&&r<=b)return val[k];
    return Lazy::f(fold(a,b,l,l+(r-l)/2,2*k+1),
                   fold(a,b,l+(r-l)/2,r,2*k+2));
  }

  inline size_t beki(size_t n_){
    size_t ret=1;
    while(ret<n_)ret<<=1;
    return ret;
  }

  public:
  LazySegmentTree(size_t n_):n(n_),n0(beki(n)),
                             val(2*n0-1,Lazy::id_val),lazy(2*n0-1,Lazy::id_lazy){}
  
  LazySegmentTree(std::vector<value_t> val_):n(val_.size()),n0(beki(n)),
                             val(2*n0-1,Lazy::id_val),lazy(2*n0-1,Lazy::id_lazy){
    for(size_t i=0;i<n;i++)val[i+n0-1]=val_[i];
    for(long long i=n0-2;i>=0;i--)val[i]=Lazy::f(val[2*i+1],val[2*i+2]);
  }

  void update(size_t a,size_t b,lazy_t laz){
    update(a,b,laz,0,n0,0);
  }

  value_t fold(size_t a,size_t b){
    return fold(a,b,0,n0,0);
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

