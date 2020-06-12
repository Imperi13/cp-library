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


# :heavy_check_mark: test/DualSegmentTree.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/DualSegmentTree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-12 12:00:09+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/SegmentTree/DualSegmentTree.hpp.html">lib/SegmentTree/DualSegmentTree.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include <iostream>
#include <algorithm>
#include <vector>

#include "../lib/SegmentTree/DualSegmentTree.hpp"

#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(a) a.begin(),a.end()

struct Monoid{
  using value_t=long long;
  static constexpr value_t id=0;
  static constexpr value_t op(value_t a,value_t b){
    return a+b;
  }
};

using ll=long long;

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n,q;
  std::cin>>n>>q;

  DualSegmentTree<Monoid> seg(n);

  while(q--){
    ll mode;
    std::cin>>mode;
    if(mode==0){
      ll s,t,x;
      std::cin>>s>>t>>x;
      seg.update(s-1,t,x);
    }else{
      ll t;
      std::cin>>t;
      std::cout<<seg.at(t-1)<<"\n";
    }
  }

  return 0; 
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/DualSegmentTree.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include <iostream>
#include <algorithm>
#include <vector>

#line 2 "lib/SegmentTree/DualSegmentTree.hpp"

#include <memory>
#include <cassert>

//commutative Monoid
// type value_t
// static value_t id
// static (value_t,value_t)->value_t op

template<typename Monoid>
class DualSegmentTree{
  public:
  using value_t=typename Monoid::value_t;
  using size_t=std::size_t;
  private:
  struct Node{
    value_t val;
    std::shared_ptr<Node> left,right;
    Node(value_t val_):val(val_),left(),right(){}
  };

  using node_ptr=std::shared_ptr<Node>;

  size_t n,n0;
  node_ptr root;

  void update(size_t a,size_t b,value_t value,const node_ptr& now,size_t l,size_t r){
    if(a<=l&&r<=b){
      now->val=Monoid::op(now->val,value);
      return;
    }
    if(b<=l||r<=a)return;

    if(!now->left)now->left=std::make_shared<Node>(Monoid::id);
    if(!now->right)now->right=std::make_shared<Node>(Monoid::id);
    update(a,b,value,now->left,l,l+(r-l)/2);
    update(a,b,value,now->right,l+(r-l)/2,r);
  }

  public:
  DualSegmentTree(size_t n_):n(n_),root(new Node(Monoid::id)){
    n0=1;
    while(n0<n)n0<<=1;
  }

  void update(size_t l,size_t r,value_t value){
    assert(0<=l&&l<=r&&r<=n);
    update(l,r,value,root,0,n0);
  }

  value_t at(size_t i){
    assert(0<=i&&i<n);
    node_ptr now(root);
    value_t ret=now->val;

    size_t l=0,r=n0;
    while(r-l>1){
      size_t mid=l+(r-l)/2;
      if(i<mid){
        if(!now->left)break;
        now=now->left;
        r=mid;
      }else{
        if(!now->right)break;
        now=now->right;
        l=mid;
      }
      ret=Monoid::op(ret,now->val);
    }
    return ret;
  }
};
#line 8 "test/DualSegmentTree.test.cpp"

#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(a) a.begin(),a.end()

struct Monoid{
  using value_t=long long;
  static constexpr value_t id=0;
  static constexpr value_t op(value_t a,value_t b){
    return a+b;
  }
};

using ll=long long;

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n,q;
  std::cin>>n>>q;

  DualSegmentTree<Monoid> seg(n);

  while(q--){
    ll mode;
    std::cin>>mode;
    if(mode==0){
      ll s,t,x;
      std::cin>>s>>t>>x;
      seg.update(s-1,t,x);
    }else{
      ll t;
      std::cin>>t;
      std::cout<<seg.at(t-1)<<"\n";
    }
  }

  return 0; 
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

