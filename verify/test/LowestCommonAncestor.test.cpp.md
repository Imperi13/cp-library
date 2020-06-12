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


# :heavy_check_mark: test/LowestCommonAncestor.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/LowestCommonAncestor.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-12 12:00:09+09:00


* see: <a href="https://judge.yosupo.jp/problem/lca">https://judge.yosupo.jp/problem/lca</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/graph/LowestCommonAncestor.hpp.html">lib/graph/LowestCommonAncestor.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <chrono>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <vector>
#include <random>
#include <utility>
#include <limits>
#include <list>

/* template start */
 
#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(i) i.begin(), i.end()

#ifdef LOCAL
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out(){std::cerr<<std::endl;}

template<typename Head,typename... Tail>
void debug_out(Head h,Tail... t){
  std::cerr<<" "<<h;
  if(sizeof...(t)>0)std::cout<<" :";
  debug_out(t...);
}
 
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << pa.first << " " << pa.second;
}
 
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (std::size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}
 
template<typename T1,typename T2>
inline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}
 
template<typename T1,typename T2>
inline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}

template<typename Num>
constexpr Num mypow(Num a, unsigned long long b) {
  if(b==0)return 1;
  if (a==0)return 0;
  Num x = 1;
  while (b > 0) {
    if(b & 1)x*=a;
    a*=a;
    b >>= 1;
  }
  return x;
}

/* template end */

using ll = long long;

#include "../lib/graph/LowestCommonAncestor.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n,q;
  std::cin>>n>>q;

  std::vector<std::vector<std::size_t>> graph(n);
  rep(i,1,n){
    ll p;
    std::cin>>p;
    graph[p].emplace_back(i);
  }

  LowestCommonAncestor lca(0,graph);

  while(q--){
    ll u,v;
    std::cin>>u>>v;
    std::cout<<lca.lca(u,v)<<"\n";
  }

  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/LowestCommonAncestor.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <chrono>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <vector>
#include <random>
#include <utility>
#include <limits>
#include <list>

/* template start */
 
#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(i) i.begin(), i.end()

#ifdef LOCAL
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out(){std::cerr<<std::endl;}

template<typename Head,typename... Tail>
void debug_out(Head h,Tail... t){
  std::cerr<<" "<<h;
  if(sizeof...(t)>0)std::cout<<" :";
  debug_out(t...);
}
 
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << pa.first << " " << pa.second;
}
 
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (std::size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}
 
template<typename T1,typename T2>
inline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}
 
template<typename T1,typename T2>
inline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}

template<typename Num>
constexpr Num mypow(Num a, unsigned long long b) {
  if(b==0)return 1;
  if (a==0)return 0;
  Num x = 1;
  while (b > 0) {
    if(b & 1)x*=a;
    a*=a;
    b >>= 1;
  }
  return x;
}

/* template end */

using ll = long long;

#line 2 "lib/graph/LowestCommonAncestor.hpp"

#line 4 "lib/graph/LowestCommonAncestor.hpp"

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
#line 87 "test/LowestCommonAncestor.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n,q;
  std::cin>>n>>q;

  std::vector<std::vector<std::size_t>> graph(n);
  rep(i,1,n){
    ll p;
    std::cin>>p;
    graph[p].emplace_back(i);
  }

  LowestCommonAncestor lca(0,graph);

  while(q--){
    ll u,v;
    std::cin>>u>>v;
    std::cout<<lca.lca(u,v)<<"\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

