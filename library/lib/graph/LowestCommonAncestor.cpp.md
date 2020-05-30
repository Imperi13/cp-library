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


# :heavy_check_mark: lib/graph/LowestCommonAncestor.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/LowestCommonAncestor.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-30 18:17:39+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/LowestCommonAncestor.test.cpp.html">test/LowestCommonAncestor.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <vector>

class LowestCommonAncestor{
  public:
  using size_t=std::size_t;
  private:
  size_t n,bit;
  std::vector<size_t> depth;
  std::vector<std::vector<size_t>> par_dbl;

  size_t log(size_t tmp){
    size_t ret=1;
    while(tmp>0){
      ret++;
      tmp>>=1;
    }
    return ret;
  }
  public:
  template<typename Edge>
  LowestCommonAncestor(size_t root,const std::vector<std::vector<Edge>>& graph)
                      :n(graph.size()),bit(log(n)),depth(n),par_dbl(n,std::vector<size_t>(bit)){
    auto dfs=[&](auto f,size_t now,size_t par,size_t dep)->void{
      depth[now]=dep;
      if(dep!=0)par_dbl[now][0]=par;
      else par_dbl[now][0]=now;

      for(const auto& e:graph[now]){
        if(e!=par)f(f,e,now,dep+1);
      }
    };
    dfs(dfs,root,-1,0);
    for(size_t i=1;i<bit;i++){
      for(size_t j=0;j<n;j++)par_dbl[j][i]=par_dbl[par_dbl[j][i-1]][i-1];
    }
  }

  size_t lca(size_t a,size_t b){
    if(depth[a]<depth[b])std::swap(a,b);
    for(size_t i=0;i<bit;i++){
      if(((depth[a]-depth[b])>>i)&1)a=par_dbl[a][i];
    }
    if(a==b)return a;
    for(long long i=bit-1;i>=0;i--){
      if(par_dbl[a][i]!=par_dbl[b][i]){
        a=par_dbl[a][i];
        b=par_dbl[b][i];
      }
    }
    return par_dbl[a][0];
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/graph/LowestCommonAncestor.cpp"

#include <vector>

class LowestCommonAncestor{
  public:
  using size_t=std::size_t;
  private:
  size_t n,bit;
  std::vector<size_t> depth;
  std::vector<std::vector<size_t>> par_dbl;

  size_t log(size_t tmp){
    size_t ret=1;
    while(tmp>0){
      ret++;
      tmp>>=1;
    }
    return ret;
  }
  public:
  template<typename Edge>
  LowestCommonAncestor(size_t root,const std::vector<std::vector<Edge>>& graph)
                      :n(graph.size()),bit(log(n)),depth(n),par_dbl(n,std::vector<size_t>(bit)){
    auto dfs=[&](auto f,size_t now,size_t par,size_t dep)->void{
      depth[now]=dep;
      if(dep!=0)par_dbl[now][0]=par;
      else par_dbl[now][0]=now;

      for(const auto& e:graph[now]){
        if(e!=par)f(f,e,now,dep+1);
      }
    };
    dfs(dfs,root,-1,0);
    for(size_t i=1;i<bit;i++){
      for(size_t j=0;j<n;j++)par_dbl[j][i]=par_dbl[par_dbl[j][i-1]][i-1];
    }
  }

  size_t lca(size_t a,size_t b){
    if(depth[a]<depth[b])std::swap(a,b);
    for(size_t i=0;i<bit;i++){
      if(((depth[a]-depth[b])>>i)&1)a=par_dbl[a][i];
    }
    if(a==b)return a;
    for(long long i=bit-1;i>=0;i--){
      if(par_dbl[a][i]!=par_dbl[b][i]){
        a=par_dbl[a][i];
        b=par_dbl[b][i];
      }
    }
    return par_dbl[a][0];
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

