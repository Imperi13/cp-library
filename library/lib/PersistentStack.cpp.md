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


# :x: lib/PersistentStack.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e8acc63b1e238f3255c900eed37254b8">lib</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/PersistentStack.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-25 10:44:16+09:00




## Required by

* :x: <a href="PersistentDeque.cpp.html">lib/PersistentDeque.cpp</a>


## Verified with

* :x: <a href="../../verify/test/PersistentDeque.test.cpp.html">test/PersistentDeque.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <memory>
#include <cassert>

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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/PersistentStack.cpp"

#include <memory>
#include <cassert>

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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

