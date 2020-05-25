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


# :x: lib/PersistentDeque.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/PersistentDeque.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-25 10:44:16+09:00




## Depends on

* :x: <a href="PersistentStack.cpp.html">lib/PersistentStack.cpp</a>


## Verified with

* :x: <a href="../../verify/test/PersistentDeque.test.cpp.html">test/PersistentDeque.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <cassert>
#include <stack>

#include "./PersistentStack.cpp"

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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

