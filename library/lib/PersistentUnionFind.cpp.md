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


# :heavy_check_mark: lib/PersistentUnionFind.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/PersistentUnionFind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-23 03:38:17+09:00




## Depends on

* :heavy_check_mark: <a href="PersistentArray.cpp.html">lib/PersistentArray.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/PersistentUnionFind.test.cpp.html">test/PersistentUnionFind.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "./PersistentArray.cpp"

class PersistentUnionFind{
  public:
  using size_t=std::size_t;
  private:
  PersistentArray<long long> uni;
  size_t group;

  PersistentUnionFind(PersistentArray<long long> uni_,size_t group_):uni(uni_),group(group_){}
  public:
  PersistentUnionFind(size_t n=0):uni(n,-1),group(n){}

  size_t root(size_t a){
    if(uni[a]<0)return a;
    size_t tmp=root(uni[a]);
    uni=uni.update(a,tmp);
    return tmp;
  }

  PersistentUnionFind unite(size_t a,size_t b){
    a=root(a);
    b=root(b);
    if(a==b)return *this;
    group--;
    if(uni[a]>uni[b])std::swap(a,b);

    PersistentArray<long long> newuni=uni;
    long long va=uni[a],vb=uni[b];
    newuni=newuni.update(a,va+vb);
    newuni=newuni.update(b,a);
    return PersistentUnionFind(newuni,group);
  }

  bool isconnect(size_t a,size_t b){return root(a)==root(b);}
  size_t group_size(size_t a){return -uni[root(a)];}
  size_t groups(){return group;}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/PersistentUnionFind.cpp"

#line 2 "lib/PersistentArray.cpp"

#include <memory>
#include <cassert>

template<typename T>
class PersistentArray{
  public:
  using value_t=T;
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

  void build(node_ptr now,size_t l,size_t r,value_t value){
    if(r-l>1){
      now->left=std::make_shared<Node>(value);
      now->right=std::make_shared<Node>(value);
      build(now->left,l,l+(r-l)/2,value);
      build(now->right,l+(r-l)/2,r,value);
    }
  }

  PersistentArray(size_t n_,size_t n0_,node_ptr root_):n(n_),n0(n0_),root(root_){}

  public:

  PersistentArray(size_t n_=0,value_t init=value_t()):n(n_),root(new Node(init)){
    n0=1;
    while(n0<n)n0<<=1;
    build(root,0,n0,init);
  }

  size_t size(){return n;}

  value_t operator[](size_t pos){
    assert(0<=pos&&pos<n);
    size_t l=0,r=n0;
    node_ptr now=root;
    while(r-l>1){
      size_t mid=l+(r-l)/2;
      if(pos<mid){
        now=now->left;
        r=mid;
      }else{
        now=now->right;
        l=mid;
      }
    }
    return now->val;
  }

  PersistentArray update(size_t pos,value_t value){
    node_ptr newroot=std::make_shared<Node>(value);
    node_ptr now=root,cur=newroot;
    size_t l=0,r=n0;
    while(r-l>1){
      size_t mid=l+(r-l)/2;
      if(pos<mid){
        cur->right=now->right;
        cur->left=std::make_shared<Node>(value);
        cur=cur->left;
        now=now->left;
        r=mid;
      }else{
        cur->left=now->left;
        cur->right=std::make_shared<Node>(value);
        cur=cur->right;
        now=now->right;
        l=mid;
      }
    }

    return PersistentArray(n,n0,newroot);
  }
};
#line 4 "lib/PersistentUnionFind.cpp"

class PersistentUnionFind{
  public:
  using size_t=std::size_t;
  private:
  PersistentArray<long long> uni;
  size_t group;

  PersistentUnionFind(PersistentArray<long long> uni_,size_t group_):uni(uni_),group(group_){}
  public:
  PersistentUnionFind(size_t n=0):uni(n,-1),group(n){}

  size_t root(size_t a){
    if(uni[a]<0)return a;
    size_t tmp=root(uni[a]);
    uni=uni.update(a,tmp);
    return tmp;
  }

  PersistentUnionFind unite(size_t a,size_t b){
    a=root(a);
    b=root(b);
    if(a==b)return *this;
    group--;
    if(uni[a]>uni[b])std::swap(a,b);

    PersistentArray<long long> newuni=uni;
    long long va=uni[a],vb=uni[b];
    newuni=newuni.update(a,va+vb);
    newuni=newuni.update(b,a);
    return PersistentUnionFind(newuni,group);
  }

  bool isconnect(size_t a,size_t b){return root(a)==root(b);}
  size_t group_size(size_t a){return -uni[root(a)];}
  size_t groups(){return group;}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

