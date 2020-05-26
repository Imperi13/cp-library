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


# :heavy_check_mark: test/UnionFind.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/UnionFind.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-26 13:06:12+09:00


* see: <a href="https://judge.yosupo.jp/problem/unionfind">https://judge.yosupo.jp/problem/unionfind</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/UnionFind.cpp.html">lib/UnionFind.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <iostream>
#include "../lib/UnionFind.cpp"

#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)

using ll=long long;

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  ll n,q;
  std::cin>>n>>q;

  UnionFind uni(n);

  rep(i,0,q){
    ll t,u,v;
    std::cin>>t>>u>>v;
    if(t==0)uni.unite(u,v);
    else std::cout<<(uni.same(u,v)?1:0)<<"\n";
  }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/UnionFind.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <iostream>
#line 2 "lib/UnionFind.cpp"

#include <cstddef>
#include <vector>
#include <numeric>

class UnionFind{
  public:
  using size_t=std::size_t;
  private:
  std::vector<size_t> par,sz;
  size_t group;

  public:

  UnionFind(size_t n=0):par(n,0),sz(n,1),group(n){
    std::iota(par.begin(),par.end(),0);
  }

  size_t root(size_t n){
    if(par[n]==n)return n;
    return par[n]=root(par[n]);
  }

  bool unite(size_t a,size_t b){
    a=root(a);b=root(b);
    if(a==b)return false;
    group--;
    if(sz[a]<sz[b])std::swap(a,b);
    sz[a]+=sz[b];
    par[b]=a;
    return true;
  }

  size_t size(){return par.size();}
  size_t groups(){return group;}
  size_t group_size(size_t n){return sz[root(n)];}

  bool same(size_t a,size_t b){return root(a)==root(b);}
};
#line 5 "test/UnionFind.test.cpp"

#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)

using ll=long long;

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  ll n,q;
  std::cin>>n>>q;

  UnionFind uni(n);

  rep(i,0,q){
    ll t,u,v;
    std::cin>>t>>u>>v;
    if(t==0)uni.unite(u,v);
    else std::cout<<(uni.same(u,v)?1:0)<<"\n";
  }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

