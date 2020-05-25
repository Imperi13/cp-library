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


# :x: test/PersistentDeque.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/PersistentDeque.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-25 10:44:16+09:00


* see: <a href="https://judge.yosupo.jp/problem/persistent_queue">https://judge.yosupo.jp/problem/persistent_queue</a>


## Depends on

* :x: <a href="../../library/lib/PersistentDeque.cpp.html">lib/PersistentDeque.cpp</a>
* :x: <a href="../../library/lib/PersistentStack.cpp.html">lib/PersistentStack.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"

#include <iostream>
#include <vector>

/* template start */
 
#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(i) i.begin(), i.end()

using ll=long long;

#include "../lib/PersistentDeque.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll q;
  std::cin>>q;

  PersistentDeque<ll> base;

  std::vector<PersistentDeque<ll>> s(q);

  for(ll i=0;i<q;i++){
    ll mode;
    std::cin>>mode;
    if(mode==0){
      ll t,x;
      std::cin>>t>>x;
      if(t==-1){
        s[i]=base.push_back(x);
      }else{
        s[i]=s[t].push_back(x);
      }
    }else{
      ll t;
      std::cin>>t;
      if(t==-1){
        std::cout<<base.front()<<"\n";
        s[i]=base.pop_front();
      }else{
        std::cout<<s[t].front()<<"\n";
        s[i]=s[t].pop_front();
      }
    }
  }

  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/PersistentDeque.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"

#include <iostream>
#include <vector>

/* template start */
 
#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(i) i.begin(), i.end()

using ll=long long;

#line 2 "lib/PersistentDeque.cpp"

#include <cassert>
#include <stack>

#line 2 "lib/PersistentStack.cpp"

#include <memory>
#line 5 "lib/PersistentStack.cpp"

template<typename T>
class PersistentStack{
  public:
  using value_t=T;
  using size_t=std::size_t;
  private:
  struct Node{
    value_t val;
    std::shared_ptr<Node> next;
    Node(value_t val_,std::shared_ptr<Node> next_=nullptr):val(val_),next(next_){}
  };

  using node_ptr=std::shared_ptr<Node>;
  size_t n;
  node_ptr root;

  PersistentStack(size_t n_,const node_ptr& root_):n(n_),root(root_){}
  public:
  PersistentStack():n(0),root(){}

  size_t size(){return n;}
  bool empty(){return n==0;}
  value_t top(){
    assert(!empty());
    return root->val;
  }

  PersistentStack push(value_t value){
    return PersistentStack(n+1,std::make_shared<Node>(value,root));
  }

  PersistentStack pop(){
    assert(!empty());
    return PersistentStack(n-1,root->next);
  }
};
#line 7 "lib/PersistentDeque.cpp"

template<typename T>
class PersistentDeque{
  public:
  using value_t=T;
  using size_t=std::size_t;
  private:
  PersistentStack<value_t> frt,bk;

  void f_to_b(){
    assert(bk.empty());
    size_t n=frt.size();
    std::stack<value_t> tmp;
    for(size_t i=0;i<n/2;i++){
      tmp.emplace(frt.top());
      frt=frt.pop();
    }
    while(!frt.empty()){
      bk=bk.push(frt.top());
      frt=frt.pop();
    }
    while(!tmp.empty()){
      frt=frt.push(tmp.top());
      tmp.pop();
    }
  }

  void b_to_f(){
    assert(frt.empty());
    size_t n=bk.size();
    std::stack<value_t> tmp;
    for(size_t i=0;i<n/2;i++){
      tmp.emplace(bk.top());
      bk=bk.pop();
    }
    while(!bk.empty()){
      frt=frt.push(bk.top());
      bk=bk.pop();
    }
    while(!tmp.empty()){
      bk=bk.push(tmp.top());
      tmp.pop();
    }
  }

  PersistentDeque(const PersistentStack<value_t>& frt_,
                  const PersistentStack<value_t>& bk_):frt(frt_),bk(bk_){}
  public:
  PersistentDeque():frt(),bk(){}

  size_t size(){return frt.size()+bk.size();}
  bool empty(){return size()==0;}

  value_t front(){
    assert(!empty());
    if(frt.empty())b_to_f();
    return frt.top();
  }
  value_t back(){
    assert(!empty());
    if(bk.empty())f_to_b();
    return bk.top();
  }

  PersistentDeque push_front(value_t value){
    return PersistentDeque(frt.push(value),bk);
  }
  PersistentDeque push_back(value_t value){
    return PersistentDeque(frt,bk.push(value));
  }

  PersistentDeque pop_front(){
    assert(!empty());
    if(frt.empty())b_to_f();
    return PersistentDeque(frt.pop(),bk);
  }
  PersistentDeque pop_back(){
    assert(!empty());
    if(bk.empty())f_to_b();
    return PersistentDeque(frt,bk.pop());
  }
};
#line 14 "test/PersistentDeque.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll q;
  std::cin>>q;

  PersistentDeque<ll> base;

  std::vector<PersistentDeque<ll>> s(q);

  for(ll i=0;i<q;i++){
    ll mode;
    std::cin>>mode;
    if(mode==0){
      ll t,x;
      std::cin>>t>>x;
      if(t==-1){
        s[i]=base.push_back(x);
      }else{
        s[i]=s[t].push_back(x);
      }
    }else{
      ll t;
      std::cin>>t;
      if(t==-1){
        std::cout<<base.front()<<"\n";
        s[i]=base.pop_front();
      }else{
        std::cout<<s[t].front()<<"\n";
        s[i]=s[t].pop_front();
      }
    }
  }

  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

