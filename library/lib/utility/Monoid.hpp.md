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


# :warning: lib/utility/Monoid.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a6e10e9711dc4788c3e9e6f87d9357db">lib/utility</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/utility/Monoid.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-12 12:00:09+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <cassert>

template<typename Semigroup>
class OptionalMonoid{
  private:
  using base_t=typename Semigroup::value_t;
  public:
  using value_t=std::pair<base_t,bool>;
  constexpr static value_t id={base_t(),false};
  constexpr static value_t op(value_t a,value_t b){
    if(a.second&&b.second)return {Semigroup::op(a.first,b.first),true};
    if(a.second||b.second) return a.second?a:b;
    return id;
  }
};

template<typename Monoid>
struct ReverseMonoid{
  using value_t=typename Monoid::value_t;
  static constexpr value_t id=Monoid::id;
  static constexpr value_t op(value_t a,value_t b){
    return Monoid::op(b,a);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/utility/Monoid.hpp"

#include <cassert>

template<typename Semigroup>
class OptionalMonoid{
  private:
  using base_t=typename Semigroup::value_t;
  public:
  using value_t=std::pair<base_t,bool>;
  constexpr static value_t id={base_t(),false};
  constexpr static value_t op(value_t a,value_t b){
    if(a.second&&b.second)return {Semigroup::op(a.first,b.first),true};
    if(a.second||b.second) return a.second?a:b;
    return id;
  }
};

template<typename Monoid>
struct ReverseMonoid{
  using value_t=typename Monoid::value_t;
  static constexpr value_t id=Monoid::id;
  static constexpr value_t op(value_t a,value_t b){
    return Monoid::op(b,a);
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

