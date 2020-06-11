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


# :heavy_check_mark: lib/SegmentTree/SegmentTree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8d75131a1ef4f10f86f251b50b9a3462">lib/SegmentTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/SegmentTree/SegmentTree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-11 12:26:31+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/SegmentTree.test.cpp.html">test/SegmentTree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <vector>
#include <cassert>

//Monoid
// type value_t
// static var id
// static (value_t,value_t)->value_t op

template<typename Monoid>
class SegmentTree{
  public:
  using value_t=typename Monoid::value_t;
  using size_t=std::size_t;

  private:
  size_t n,n0;
  std::vector<value_t> dat;

  public:
  SegmentTree(size_t n_):n(n_){
    assert(n_>0);
    n0=1;
    while(n0<n)n0<<=1;
    dat=std::vector<value_t>(2*n0-1,Monoid::id);
  }

  SegmentTree(const std::vector<value_t>& tmp):n(tmp.size()){
    assert(n>0);
    n0=1;
    while(n0<n)n0<<=1;
    dat=std::vector<value_t>(2*n0-1,Monoid::id);
    for(size_t i=0;i<n;i++)dat[i+n0-1]=tmp[i];
    for(long long i=n0-2;i>=0;i--)dat[i]=Monoid::op(dat[2*i+1],dat[2*i+2]);
  }

  void update(size_t i,value_t val,bool change){
    assert(0<=i&&i<n);
    std::size_t now=i+n0-1;
    if(change)dat[now]=val;
    else dat[now]=Monoid::op(dat[now],val);

    while(now>0){
      now=(now-1)>>1;
      dat[now]=Monoid::op(dat[2*now+1],dat[2*now+2]);
    }
  }

  value_t fold(size_t a,size_t b){
    assert(0<=a&&a<=b&&b<=n);
    value_t rval=Monoid::id,lval=Monoid::id;
    size_t l=a+n0-1,r=b+n0-1;
    for(;l<r;l>>=1,r>>=1){
      if(!(r&1)){
        r--;
        rval=Monoid::op(dat[r],rval);
      }
      if(!(l&1)){
        lval=Monoid::op(lval,dat[l]);
        l++;
      }
    }

    return Monoid::op(lval,rval);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/SegmentTree/SegmentTree.cpp"

#include <vector>
#include <cassert>

//Monoid
// type value_t
// static var id
// static (value_t,value_t)->value_t op

template<typename Monoid>
class SegmentTree{
  public:
  using value_t=typename Monoid::value_t;
  using size_t=std::size_t;

  private:
  size_t n,n0;
  std::vector<value_t> dat;

  public:
  SegmentTree(size_t n_):n(n_){
    assert(n_>0);
    n0=1;
    while(n0<n)n0<<=1;
    dat=std::vector<value_t>(2*n0-1,Monoid::id);
  }

  SegmentTree(const std::vector<value_t>& tmp):n(tmp.size()){
    assert(n>0);
    n0=1;
    while(n0<n)n0<<=1;
    dat=std::vector<value_t>(2*n0-1,Monoid::id);
    for(size_t i=0;i<n;i++)dat[i+n0-1]=tmp[i];
    for(long long i=n0-2;i>=0;i--)dat[i]=Monoid::op(dat[2*i+1],dat[2*i+2]);
  }

  void update(size_t i,value_t val,bool change){
    assert(0<=i&&i<n);
    std::size_t now=i+n0-1;
    if(change)dat[now]=val;
    else dat[now]=Monoid::op(dat[now],val);

    while(now>0){
      now=(now-1)>>1;
      dat[now]=Monoid::op(dat[2*now+1],dat[2*now+2]);
    }
  }

  value_t fold(size_t a,size_t b){
    assert(0<=a&&a<=b&&b<=n);
    value_t rval=Monoid::id,lval=Monoid::id;
    size_t l=a+n0-1,r=b+n0-1;
    for(;l<r;l>>=1,r>>=1){
      if(!(r&1)){
        r--;
        rval=Monoid::op(dat[r],rval);
      }
      if(!(l&1)){
        lval=Monoid::op(lval,dat[l]);
        l++;
      }
    }

    return Monoid::op(lval,rval);
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

