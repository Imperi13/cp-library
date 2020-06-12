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


# :heavy_check_mark: lib/SegmentTree/DynamicSegmentTree.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8d75131a1ef4f10f86f251b50b9a3462">lib/SegmentTree</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/SegmentTree/DynamicSegmentTree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-12 12:00:09+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/DynamicSegmentTree.test.cpp.html">test/DynamicSegmentTree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <memory>
#include <cassert>

//Monoid
// type value_t
// static var id
// static (value_t,value_t)->value_t op

template<typename Monoid>
class DynamicSegmentTree{
  public:
  using value_t = typename Monoid::value_t;
  using size_t=std::size_t;
  private:

  struct Node{
    value_t val;
    std::shared_ptr<Node> left,right;
    std::weak_ptr<Node> par;
    Node(value_t val_,const std::shared_ptr<Node>& par_=nullptr):val(val_),left(),right(),par(par_){}
  };

  using node_ptr=std::shared_ptr<Node>;
  using weak_ptr=std::weak_ptr<Node>;

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
  DynamicSegmentTree(size_t n_):n(n_),root(new Node(Monoid::id)){
    n0=1;
    while(n0<n)n0<<=1;
  }

  void update(size_t i,value_t val,bool change){
    assert(0<=i&&i<n);
    node_ptr now(root);
    size_t l=0,r=n0;
    while(r-l>1){
      size_t mid=l+(r-l)/2;
      
      if(i<mid){
        if(!now->left)now->left=std::make_shared<Node>(Monoid::id,now);
        now=now->left;
        r=mid;
      }else{
        if(!now->right)now->right=std::make_shared<Node>(Monoid::id,now);
        now=now->right;
        l=mid;
      }
    }

    if(change)now->val=val;
    else now->val=Monoid::op(now->val,val);

    while(now->par.lock()){
      now=now->par.lock();
      now->val=Monoid::op((now->left)?now->left->val:Monoid::id,
                          (now->right)?now->right->val:Monoid::id);
    }
  }

  value_t fold(size_t a,size_t b){
    assert(0<=a&&a<=b&&b<=n);
    return fold(a,b,root,0,n0);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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
  using value_t = typename Monoid::value_t;
  using size_t=std::size_t;
  private:

  struct Node{
    value_t val;
    std::shared_ptr<Node> left,right;
    std::weak_ptr<Node> par;
    Node(value_t val_,const std::shared_ptr<Node>& par_=nullptr):val(val_),left(),right(),par(par_){}
  };

  using node_ptr=std::shared_ptr<Node>;
  using weak_ptr=std::weak_ptr<Node>;

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
  DynamicSegmentTree(size_t n_):n(n_),root(new Node(Monoid::id)){
    n0=1;
    while(n0<n)n0<<=1;
  }

  void update(size_t i,value_t val,bool change){
    assert(0<=i&&i<n);
    node_ptr now(root);
    size_t l=0,r=n0;
    while(r-l>1){
      size_t mid=l+(r-l)/2;
      
      if(i<mid){
        if(!now->left)now->left=std::make_shared<Node>(Monoid::id,now);
        now=now->left;
        r=mid;
      }else{
        if(!now->right)now->right=std::make_shared<Node>(Monoid::id,now);
        now=now->right;
        l=mid;
      }
    }

    if(change)now->val=val;
    else now->val=Monoid::op(now->val,val);

    while(now->par.lock()){
      now=now->par.lock();
      now->val=Monoid::op((now->left)?now->left->val:Monoid::id,
                          (now->right)?now->right->val:Monoid::id);
    }
  }

  value_t fold(size_t a,size_t b){
    assert(0<=a&&a<=b&&b<=n);
    return fold(a,b,root,0,n0);
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

