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


# :heavy_check_mark: lib/SWAG.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/SWAG.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-20 19:54:08+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/SWAG.test.cpp.html">test/SWAG.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <stack>
#include <cassert>

template<typename Semigroup>
class SWAG{
  public:
  using value_t=typename Semigroup::value_t;
  using size_t=std::size_t;
  private:

  using P=std::pair<value_t,value_t>;
  std::stack<P> front,back;

  public:
  SWAG(){}

  size_t size(){return front.size()+back.size();}
  bool empty(){return size()==0;}

  value_t fold_all(){
    assert(!empty());
    if(front.empty())return back.top().second;
    if(back.empty())return front.top().second;
    return Semigroup::op(front.top().second,back.top().second);
  }

  void push_back(value_t val){
    if(back.empty())back.emplace(val,val);
    else{
      P tmp=back.top();
      back.emplace(val,Semigroup::op(tmp.second,val));
    }
  }

  void push_front(value_t val){
    if(front.empty())front.emplace(val,val);
    else{
      P tmp=front.top();
      front.emplace(val,Semigroup::op(val,tmp.second));
    }
  }

  void pop_back(){
    assert(!empty());
    if(!back.empty()){
      back.pop();
      return;
    }
    size_t n=front.size();
    std::stack<value_t> tmp;
    for(size_t i=0;i<n/2;i++){
      tmp.emplace(front.top().first);
      front.pop();
    }
    while(!front.empty()){
      push_back(front.top().first);
      front.pop();
    }
    while(!tmp.empty()){
      push_front(tmp.top());
      tmp.pop();
    }
    back.pop();
  }

  void pop_front(){
    assert(!empty());
    if(!front.empty()){
      front.pop();
      return;
    }
    size_t n=back.size();
    std::stack<value_t> tmp;
    for(std::size_t i=0;i<n/2;i++){
      tmp.emplace(back.top().first);
      back.pop();
    }
    while(!back.empty()){
      push_front(back.top().first);
      back.pop();
    }
    while(!tmp.empty()){
      push_back(tmp.top());
      tmp.pop();
    }
    front.pop();
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/SWAG.cpp"

#include <stack>
#include <cassert>

template<typename Semigroup>
class SWAG{
  public:
  using value_t=typename Semigroup::value_t;
  using size_t=std::size_t;
  private:

  using P=std::pair<value_t,value_t>;
  std::stack<P> front,back;

  public:
  SWAG(){}

  size_t size(){return front.size()+back.size();}
  bool empty(){return size()==0;}

  value_t fold_all(){
    assert(!empty());
    if(front.empty())return back.top().second;
    if(back.empty())return front.top().second;
    return Semigroup::op(front.top().second,back.top().second);
  }

  void push_back(value_t val){
    if(back.empty())back.emplace(val,val);
    else{
      P tmp=back.top();
      back.emplace(val,Semigroup::op(tmp.second,val));
    }
  }

  void push_front(value_t val){
    if(front.empty())front.emplace(val,val);
    else{
      P tmp=front.top();
      front.emplace(val,Semigroup::op(val,tmp.second));
    }
  }

  void pop_back(){
    assert(!empty());
    if(!back.empty()){
      back.pop();
      return;
    }
    size_t n=front.size();
    std::stack<value_t> tmp;
    for(size_t i=0;i<n/2;i++){
      tmp.emplace(front.top().first);
      front.pop();
    }
    while(!front.empty()){
      push_back(front.top().first);
      front.pop();
    }
    while(!tmp.empty()){
      push_front(tmp.top());
      tmp.pop();
    }
    back.pop();
  }

  void pop_front(){
    assert(!empty());
    if(!front.empty()){
      front.pop();
      return;
    }
    size_t n=back.size();
    std::stack<value_t> tmp;
    for(std::size_t i=0;i<n/2;i++){
      tmp.emplace(back.top().first);
      back.pop();
    }
    while(!back.empty()){
      push_front(back.top().first);
      back.pop();
    }
    while(!tmp.empty()){
      push_back(tmp.top());
      tmp.pop();
    }
    front.pop();
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

