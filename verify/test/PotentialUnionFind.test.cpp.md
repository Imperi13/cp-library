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


# :heavy_check_mark: test/PotentialUnionFind.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/PotentialUnionFind.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-26 13:15:45+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/UnionFind/PotentialUnionFind.cpp.html">lib/UnionFind/PotentialUnionFind.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

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
#include <unordered_map>
#include <vector>
#include <random>
#include <utility>
#include <limits>
#include <list>
#include <cmath>

/* template start */
 
#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(i) i.begin(), i.end()

using ll=long long;

#include "../lib/UnionFind/PotentialUnionFind.cpp"

struct Group{
  using value_t=ll;
  static constexpr value_t id=0;
  static constexpr value_t op(value_t a,value_t b){
    return a+b;
  }
  static constexpr value_t inv(value_t a){return -a;}
};

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n,q;
  std::cin>>n>>q;

  PotentialUnionFind<Group> uni(n);

  while(q--){
    ll mode;
    std::cin>>mode;
    if(mode==0){
      ll x,y,z;
      std::cin>>x>>y>>z;
      if(!uni.same(x,y))uni.unite(y,x,z);
    }else{
      ll x,y;
      std::cin>>x>>y;
      if(!uni.same(x,y))std::cout<<"?\n";
      else std::cout<<uni.diff(y,x)<<"\n";
    }
  }

  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/PotentialUnionFind.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

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
#include <unordered_map>
#include <vector>
#include <random>
#include <utility>
#include <limits>
#include <list>
#line 31 "test/PotentialUnionFind.test.cpp"

/* template start */
 
#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(i) i.begin(), i.end()

using ll=long long;

#line 2 "lib/UnionFind/PotentialUnionFind.cpp"

#line 6 "lib/UnionFind/PotentialUnionFind.cpp"

template<typename Group>
class PotentialUnionFind{
  public:
  using value_t=typename Group::value_t;
  using size_t=std::size_t;
  private:
  size_t group;
  std::vector<size_t> par,sz;
  std::vector<value_t> df; //val[par]=val[x]+df[x]

  value_t fold_to_root(size_t x){
    value_t ret=Group::id;
    while(par[x]!=x){
      df[x]=Group::op(df[x],df[par[x]]);
      par[x]=par[par[x]];
      ret=Group::op(ret,df[x]);
      x=par[x];
    }
    return ret;
  }

  public:
  PotentialUnionFind(size_t n=0):group(n),par(n),sz(n,1),df(n,Group::id){
    std::iota(par.begin(),par.end(),0);
  }

  size_t root(size_t x){
    while(par[x]!=x){
      df[x]=Group::op(df[x],df[par[x]]);
      par[x]=par[par[x]];
      x=par[x];
    }
    return x;
  }

  bool same(size_t a,size_t b){return root(a)==root(b);}
  size_t size(){return par.size();}
  size_t groups(){return group;}
  size_t group_size(size_t x){return sz[root(x)];}

  // unite A=B+value
  bool unite(size_t a,size_t b,value_t value){
    size_t aroot=root(a),broot=root(b);
    if(aroot==broot)return false;
    group--;
    if(sz[aroot]<sz[broot]){
      std::swap(aroot,broot);
      std::swap(a,b);
      value=Group::inv(value);
    }
    sz[aroot]+=sz[broot];
    value=Group::op(value,fold_to_root(a));
    value=Group::op(Group::inv(fold_to_root(b)),value);
    df[broot]=value;
    par[broot]=aroot;
    return true;
  }

  // return diff  such as A=B+diff
  value_t diff(size_t a,size_t b){
    assert(same(a,b));
    return Group::op(fold_to_root(b),Group::inv(fold_to_root(a)));
  }
};
#line 40 "test/PotentialUnionFind.test.cpp"

struct Group{
  using value_t=ll;
  static constexpr value_t id=0;
  static constexpr value_t op(value_t a,value_t b){
    return a+b;
  }
  static constexpr value_t inv(value_t a){return -a;}
};

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n,q;
  std::cin>>n>>q;

  PotentialUnionFind<Group> uni(n);

  while(q--){
    ll mode;
    std::cin>>mode;
    if(mode==0){
      ll x,y,z;
      std::cin>>x>>y>>z;
      if(!uni.same(x,y))uni.unite(y,x,z);
    }else{
      ll x,y;
      std::cin>>x>>y;
      if(!uni.same(x,y))std::cout<<"?\n";
      else std::cout<<uni.diff(y,x)<<"\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

