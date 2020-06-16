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


# :heavy_check_mark: test/DynamicSegmentTree.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/DynamicSegmentTree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-17 01:18:15+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_set_range_composite">https://judge.yosupo.jp/problem/point_set_range_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/SegmentTree/DynamicSegmentTree.hpp.html">lib/SegmentTree/DynamicSegmentTree.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <iostream>
#include <vector>

#include "../lib/SegmentTree/DynamicSegmentTree.hpp"

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

  DynamicSegmentTree<Monoid> seg(n);

  for(ll i=0;i<n;i++){
    ll a,b;
    std::cin>>a>>b;
    seg.update(i,{a,b},true);
  }

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
#line 1 "test/DynamicSegmentTree.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <iostream>
#include <vector>

#line 2 "lib/SegmentTree/DynamicSegmentTree.hpp"

#include <memory>
#include <cassert>

//Monoid
// type value_t
// static var id
// static (value_t,value_t)->value_t op

template<typename Monoid>
class DynamicSegmentTree{
  public:
  using value_t=typename Monoid::value_t;
  using size_t=std::size_t;
  private:

  struct Node{
    value_t val;
    Node *left,*right,*par;
    Node(value_t val_,Node *par_=nullptr):val(val_),left(),right(),par(par_){}
    ~Node(){
      if(left)delete left;
      if(right)delete right;
      left=nullptr;right=nullptr;
      par=nullptr;
    }
  };

  using node_ptr=Node *;
  
  size_t n,n0;
  node_ptr root;

  value_t fold(size_t a,size_t b,const node_ptr& now,size_t l,size_t r){
    if(a<=l&&r<=b)return now->val;
    if(b<=l||r<=a)return Monoid::id;
    value_t lval=(now->left)?fold(a,b,now->left,l,l+(r-l)/2):Monoid::id;
    value_t rval=(now->right)?fold(a,b,now->right,l+(r-l)/2,r):Monoid::id;
    return Monoid::op(lval,rval);
  }

  public:
  DynamicSegmentTree(size_t n_):n(n_),root(nullptr){
    n0=1;
    while(n0<n)n0<<=1;
  }
  ~DynamicSegmentTree(){
    if(root)delete root;
    root=nullptr;
  }

  void update(size_t i,value_t val,bool change){
    assert(0<=i&&i<n);
    if(!root)root=new Node(Monoid::id);
    node_ptr now=root;
    size_t l=0,r=n0;
    while(r-l>1){
      size_t mid=l+(r-l)/2;
      if(i<mid){
        if(!now->left)now->left=new Node(Monoid::id,now);
        now=now->left;
        r=mid;
      }else{
        if(!now->right)now->right=new Node(Monoid::id,now);
        now=now->right;
        l=mid;
      }
    }
    if(change)now->val=val;
    else now->val=Monoid::op(now->val,val);

    while(now->par){
      now=now->par;
      now->val=Monoid::op((now->left)?now->left->val:Monoid::id,
                          (now->right)?now->right->val:Monoid::id);
    }
  }

  value_t fold(size_t a,size_t b){
    assert(0<=a&&a<=b&&b<=n);
    if(!root)return Monoid::id;
    return fold(a,b,root,0,n0);
  }
};
#line 7 "test/DynamicSegmentTree.test.cpp"

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

  DynamicSegmentTree<Monoid> seg(n);

  for(ll i=0;i<n;i++){
    ll a,b;
    std::cin>>a>>b;
    seg.update(i,{a,b},true);
  }

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

