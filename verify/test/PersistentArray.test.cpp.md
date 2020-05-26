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


# :x: test/PersistentArray.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/PersistentArray.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-26 09:29:12+09:00




## Depends on

* :question: <a href="../../library/lib/PersistentArray.cpp.html">lib/PersistentArray.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

#include "../lib/PersistentArray.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  PersistentArray<ll> ary(0);
  
  ll q;
  std::cin>>q;
  while(q--){
    ll mode;
    std::cin>>mode;
    if(mode==0){
      ll k,v;
      std::cin>>k>>v;
      ary=ary.update(k,v);
    }else{
      ll k;
      std::cin>>k;
      std::cout<<ary[k]<<"\n";
    }
  }

  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/PersistentArray.test.cpp"
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
#line 29 "test/PersistentArray.test.cpp"

/* template start */
 
#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(i) i.begin(), i.end()

using ll=long long;

#line 2 "lib/PersistentArray.cpp"

#line 5 "lib/PersistentArray.cpp"

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
#line 38 "test/PersistentArray.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  PersistentArray<ll> ary(0);
  
  ll q;
  std::cin>>q;
  while(q--){
    ll mode;
    std::cin>>mode;
    if(mode==0){
      ll k,v;
      std::cin>>k>>v;
      ary=ary.update(k,v);
    }else{
      ll k;
      std::cin>>k;
      std::cout<<ary[k]<<"\n";
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

