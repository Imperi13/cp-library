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


# :heavy_check_mark: test/SegmentTree.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/SegmentTree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-20 12:57:51+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_set_range_composite">https://judge.yosupo.jp/problem/point_set_range_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/SegmentTree.cpp.html">lib/SegmentTree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <iostream>

#include "../lib/SegmentTree.cpp"

constexpr long long MOD=998244353;

struct Monoid{
  using value_t=std::pair<long long,long long>;
  static constexpr value_t id={1,0};
  static constexpr value_t op(value_t a,value_t b){
    return {a.first*b.first%MOD,(a.second*b.first%MOD + b.second)%MOD};
  }
};

using ll=long long;
using P=std::pair<ll,ll>;

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  ll n,q;
  std::cin>>n>>q;

  std::vector<P> tmp(n);
  for(auto&& e:tmp)std::cin>>e.first>>e.second;

  SegmentTree<Monoid> seg(tmp);

  for(ll i=0;i<q;i++){
    ll mode;
    std::cin>>mode;
    if(mode==0){
      ll p,c,d;
      std::cin>>p>>c>>d;
      seg.update(p,{c,d},true);
    }else{
      ll l,r,x;
      std::cin>>l>>r>>x;
      P fold=seg.fold(l,r);
      std::cout<<(fold.first*x%MOD+fold.second)%MOD<<"\n";
    }
  }

  return 0; 
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/SegmentTree.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <iostream>

#line 2 "lib/SegmentTree.cpp"

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
    for(long long i=0;i<n;i++)dat[i+n0-1]=tmp[i];
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
#line 6 "test/SegmentTree.test.cpp"

constexpr long long MOD=998244353;

struct Monoid{
  using value_t=std::pair<long long,long long>;
  static constexpr value_t id={1,0};
  static constexpr value_t op(value_t a,value_t b){
    return {a.first*b.first%MOD,(a.second*b.first%MOD + b.second)%MOD};
  }
};

using ll=long long;
using P=std::pair<ll,ll>;

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  ll n,q;
  std::cin>>n>>q;

  std::vector<P> tmp(n);
  for(auto&& e:tmp)std::cin>>e.first>>e.second;

  SegmentTree<Monoid> seg(tmp);

  for(ll i=0;i<q;i++){
    ll mode;
    std::cin>>mode;
    if(mode==0){
      ll p,c,d;
      std::cin>>p>>c>>d;
      seg.update(p,{c,d},true);
    }else{
      ll l,r,x;
      std::cin>>l>>r>>x;
      P fold=seg.fold(l,r);
      std::cout<<(fold.first*x%MOD+fold.second)%MOD<<"\n";
    }
  }

  return 0; 
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

