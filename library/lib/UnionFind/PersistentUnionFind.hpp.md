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


# :heavy_check_mark: lib/UnionFind/PersistentUnionFind.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#d8ce77e7929e89891ebe5f859497af18">lib/UnionFind</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/UnionFind/PersistentUnionFind.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-31 15:44:20+09:00




## Depends on

* :heavy_check_mark: <a href="../PersistentArray.hpp.html">lib/PersistentArray.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/PersistentUnionFind.test.cpp.html">test/PersistentUnionFind.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "../PersistentArray.hpp"

class PersistentUnionFind {
 public:
  using size_t = std::size_t;

 private:
  PersistentArray<long long> uni;
  size_t group;

  PersistentUnionFind(PersistentArray<long long> uni_, size_t group_)
      : uni(uni_), group(group_) {}

 public:
  PersistentUnionFind(size_t n = 0) : uni(-1), group(n) {}

  size_t root(size_t a) {
    if (uni[a] < 0) return a;
    size_t tmp = root(uni[a]);
    uni = uni.update(a, tmp);
    return tmp;
  }

  PersistentUnionFind unite(size_t a, size_t b) {
    a = root(a);
    b = root(b);
    if (a == b) return *this;
    group--;
    if (uni[a] > uni[b]) std::swap(a, b);

    PersistentArray<long long> newuni = uni;
    long long va = uni[a], vb = uni[b];
    newuni = newuni.update(a, va + vb);
    newuni = newuni.update(b, a);
    return PersistentUnionFind(newuni, group);
  }

  bool isconnect(size_t a, size_t b) { return root(a) == root(b); }
  size_t group_size(size_t a) { return -uni[root(a)]; }
  size_t groups() { return group; }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/UnionFind/PersistentUnionFind.hpp"

#line 2 "lib/PersistentArray.hpp"

#include <cassert>
#include <memory>

template <typename T, std::size_t BITSIZE = 4>
class PersistentArray {
 public:
  using value_t = T;
  using size_t = std::size_t;

 private:
  struct Node {
    value_t val;
    std::array<std::shared_ptr<Node>, 1 << BITSIZE> ch;
    Node(value_t val_) : val(val_) { ch.fill(nullptr); }
  };
  using node_ptr = std::shared_ptr<Node>;

  value_t init;
  node_ptr root;

  node_ptr update(size_t k, value_t value, node_ptr now) {
    node_ptr ret =
        (now ? std::make_shared<Node>(*now) : std::make_shared<Node>(init));
    if (k == 0)
      ret->val = value;
    else {
      size_t mask = (1 << BITSIZE) - 1;
      ret->ch[k & mask] = update(k >> BITSIZE, value, ret->ch[k & mask]);
    }
    return ret;
  }

  value_t at(size_t k, node_ptr now) {
    if (!now) return init;
    if (k == 0) return now->val;
    return at(k >> BITSIZE, now->ch[k & ((1 << BITSIZE) - 1)]);
  }

  PersistentArray(value_t init_, const node_ptr& root_)
      : init(init_), root(root_) {}

 public:
  PersistentArray(value_t init_ = value_t()) : init(init_), root(nullptr) {}

  PersistentArray update(size_t k, const value_t& value) {
    return PersistentArray(init, update(k, value, root));
  }

  value_t operator[](size_t k) { return at(k, root); }
};
#line 4 "lib/UnionFind/PersistentUnionFind.hpp"

class PersistentUnionFind {
 public:
  using size_t = std::size_t;

 private:
  PersistentArray<long long> uni;
  size_t group;

  PersistentUnionFind(PersistentArray<long long> uni_, size_t group_)
      : uni(uni_), group(group_) {}

 public:
  PersistentUnionFind(size_t n = 0) : uni(-1), group(n) {}

  size_t root(size_t a) {
    if (uni[a] < 0) return a;
    size_t tmp = root(uni[a]);
    uni = uni.update(a, tmp);
    return tmp;
  }

  PersistentUnionFind unite(size_t a, size_t b) {
    a = root(a);
    b = root(b);
    if (a == b) return *this;
    group--;
    if (uni[a] > uni[b]) std::swap(a, b);

    PersistentArray<long long> newuni = uni;
    long long va = uni[a], vb = uni[b];
    newuni = newuni.update(a, va + vb);
    newuni = newuni.update(b, a);
    return PersistentUnionFind(newuni, group);
  }

  bool isconnect(size_t a, size_t b) { return root(a) == root(b); }
  size_t group_size(size_t a) { return -uni[root(a)]; }
  size_t groups() { return group; }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

