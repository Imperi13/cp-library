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
    - Last commit date: 2020-06-19 19:03:42+09:00




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
  using value_t=typename Monoid::value_t;
  using size_t=std::size_t;
  private:

  struct Node{
    value_t val;
    Node *left,*right,*par;
    Node(Node *par_=nullptr):val(Monoid::id),left(),right(),par(par_){}
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

  void copy_dfs(node_ptr& node,const node_ptr& from){
    node->val=from->val;
    if(from->left){
      node->left=new Node(node);
      copy_dfs(node->left,from->left);
    }
    if(from->right){
      node->right=new Node(node);
      copy_dfs(node->right,from->right);
    }
  }

  public:
  DynamicSegmentTree(size_t n_=0):n(n_),root(nullptr){
    n0=1;
    while(n0<n)n0<<=1;
  }
  DynamicSegmentTree(const DynamicSegmentTree& from){
    n=from.n;n0=from.n0;root=nullptr;
    if(from.root){
      root=new Node();
      copy_dfs(root,from.root);
    }
  }
  DynamicSegmentTree& operator=(const DynamicSegmentTree& from){
    n=from.n;n0=from.n0;root=nullptr;
    if(from.root){
      root=new Node();
      copy_dfs(root,from.root);
    }
  }
  DynamicSegmentTree(DynamicSegmentTree&&)=default;
  DynamicSegmentTree& operator=(DynamicSegmentTree&&)=default;
  ~DynamicSegmentTree(){
    if(root)delete root;
    root=nullptr;
  }

  void update(size_t i,value_t val,bool change){
    assert(0<=i&&i<n);
    if(!root)root=new Node();
    node_ptr now=root;
    size_t l=0,r=n0;
    while(r-l>1){
      size_t mid=l+(r-l)/2;
      if(i<mid){
        if(!now->left)now->left=new Node(now);
        now=now->left;
        r=mid;
      }else{
        if(!now->right)now->right=new Node(now);
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
  using value_t=typename Monoid::value_t;
  using size_t=std::size_t;
  private:

  struct Node{
    value_t val;
    Node *left,*right,*par;
    Node(Node *par_=nullptr):val(Monoid::id),left(),right(),par(par_){}
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

  void copy_dfs(node_ptr& node,const node_ptr& from){
    node->val=from->val;
    if(from->left){
      node->left=new Node(node);
      copy_dfs(node->left,from->left);
    }
    if(from->right){
      node->right=new Node(node);
      copy_dfs(node->right,from->right);
    }
  }

  public:
  DynamicSegmentTree(size_t n_=0):n(n_),root(nullptr){
    n0=1;
    while(n0<n)n0<<=1;
  }
  DynamicSegmentTree(const DynamicSegmentTree& from){
    n=from.n;n0=from.n0;root=nullptr;
    if(from.root){
      root=new Node();
      copy_dfs(root,from.root);
    }
  }
  DynamicSegmentTree& operator=(const DynamicSegmentTree& from){
    n=from.n;n0=from.n0;root=nullptr;
    if(from.root){
      root=new Node();
      copy_dfs(root,from.root);
    }
  }
  DynamicSegmentTree(DynamicSegmentTree&&)=default;
  DynamicSegmentTree& operator=(DynamicSegmentTree&&)=default;
  ~DynamicSegmentTree(){
    if(root)delete root;
    root=nullptr;
  }

  void update(size_t i,value_t val,bool change){
    assert(0<=i&&i<n);
    if(!root)root=new Node();
    node_ptr now=root;
    size_t l=0,r=n0;
    while(r-l>1){
      size_t mid=l+(r-l)/2;
      if(i<mid){
        if(!now->left)now->left=new Node(now);
        now=now->left;
        r=mid;
      }else{
        if(!now->right)now->right=new Node(now);
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

