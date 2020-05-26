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


# :heavy_check_mark: test/PersistentUnionFind.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/PersistentUnionFind.test.cpp">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00


* see: <a href="https://judge.yosupo.jp/problem/persistent_unionfind">https://judge.yosupo.jp/problem/persistent_unionfind</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/PersistentArray.cpp.html">lib/PersistentArray.cpp</a>
* :heavy_check_mark: <a href="../../library/lib/UnionFind/PersistentUnionFind.cpp.html">lib/UnionFind/PersistentUnionFind.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include <iostream>
#include <algorithm>
#include <vector>

#include "../lib/UnionFind/PersistentUnionFind.cpp"

#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(a) a.begin(),a.end()

using ll=long long;

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n,q;
  std::cin>>n>>q;

  PersistentUnionFind base(n);
  std::vector<PersistentUnionFind> G(q);

  rep(i,0,q){
    ll t,k,u,v;
    std::cin>>t>>k>>u>>v;
    if(t==0){
      if(k==-1)G[i]=base.unite(u,v);
      else G[i]=G[k].unite(u,v);
    }else{
      if(k==-1)std::cout<<base.isconnect(u,v)<<"\n";
      else std::cout<<G[k].isconnect(u,v)<<"\n";
    }
  }

  return 0; 
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/PersistentUnionFind.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include <iostream>
#include <algorithm>
#include <vector>

#line 2 "lib/UnionFind/PersistentUnionFind.cpp"

#line 2 "lib/PersistentArray.cpp"

#include <memory>
#include <cassert>

template<typename T,std::size_t BITSIZE=4>
class PersistentArray{
  public:
  using value_t=T;
  using size_t=std::size_t;
  private:
  struct Node{
    value_t val;
    std::array<std::shared_ptr<Node>,1<<BITSIZE> ch;
    Node(value_t val_):val(val_){ch.fill(nullptr);}
  };
  using node_ptr=std::shared_ptr<Node>;

  value_t init;
  node_ptr root;

  node_ptr update(size_t k,value_t value,node_ptr now){
    node_ptr ret=(now?std::make_shared<Node>(*now):std::make_shared<Node>(init));
    if(k==0)ret->val=value;
    else{
      size_t mask=(1<<BITSIZE)-1;
      ret->ch[k&mask]=update(k>>BITSIZE,value,ret->ch[k&mask]);
    }
    return ret;
  }

  value_t at(size_t k,node_ptr now){
    if(!now)return init;
    if(k==0)return now->val;
    return at(k>>BITSIZE,now->ch[k&((1<<BITSIZE)-1)]);
  }

  PersistentArray(value_t init_,const node_ptr& root_):init(init_),root(root_){}
  public:
  PersistentArray(value_t init_=value_t()):init(init_),root(nullptr){}

  PersistentArray update(size_t k,const value_t& value){
    return PersistentArray(init,update(k,value,root));
  }

  value_t operator[](size_t k){
    return at(k,root);
  }
};
#line 4 "lib/UnionFind/PersistentUnionFind.cpp"

class PersistentUnionFind{
  public:
  using size_t=std::size_t;
  private:
  PersistentArray<long long> uni;
  size_t group;

  PersistentUnionFind(PersistentArray<long long> uni_,size_t group_):uni(uni_),group(group_){}
  public:
  PersistentUnionFind(size_t n=0):uni(-1),group(n){}

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
#line 8 "test/PersistentUnionFind.test.cpp"

#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(a) a.begin(),a.end()

using ll=long long;

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n,q;
  std::cin>>n>>q;

  PersistentUnionFind base(n);
  std::vector<PersistentUnionFind> G(q);

  rep(i,0,q){
    ll t,k,u,v;
    std::cin>>t>>k>>u>>v;
    if(t==0){
      if(k==-1)G[i]=base.unite(u,v);
      else G[i]=G[k].unite(u,v);
    }else{
      if(k==-1)std::cout<<base.isconnect(u,v)<<"\n";
      else std::cout<<G[k].isconnect(u,v)<<"\n";
    }
  }

  return 0; 
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

