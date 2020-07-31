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


# :heavy_check_mark: test/RBST_Seq.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/RBST_Seq.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-31 15:44:20+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_set_range_composite">https://judge.yosupo.jp/problem/point_set_range_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../library/lib/RBST_Seq.hpp.html">lib/RBST_Seq.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <iostream>

#include "../lib/RBST_Seq.hpp"

constexpr long long MOD=998244353;

struct Monoid{
  using value_t=std::pair<long long,long long>;
  static constexpr value_t id={1,0};
  static constexpr value_t op(value_t a,value_t b){
    return {a.first*b.first%MOD,(a.second*b.first%MOD + b.second)%MOD};
  }
};

using ll=long long;
using P=std::pair<ll,ll>;

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  ll n,q;
  std::cin>>n>>q;

  std::vector<P> tmp(n);
  for(auto&& e:tmp)std::cin>>e.first>>e.second;

  RBST_Seq<Monoid> seq(tmp);

  for(ll i=0;i<q;i++){
    ll mode;
    std::cin>>mode;
    if(mode==0){
      ll p,c,d;
      std::cin>>p>>c>>d;
      seq.erase(p);
      seq.insert(p,{c,d});
    }else{
      ll l,r,x;
      std::cin>>l>>r>>x;
      P fold=seq.fold(l,r);
      std::cout<<(fold.first*x%MOD+fold.second)%MOD<<"\n";
    }
  }

  return 0; 
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/RBST_Seq.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <iostream>

#line 2 "lib/RBST_Seq.hpp"

#include <memory>
#include <utility>
#include <vector>

template <typename Monoid>
class RBST_Seq {
 public:
  using value_t = typename Monoid::value_t;
  using size_t = std::size_t;

 private:
  unsigned int rnd() {
    static unsigned int x(123456789), y(362436069), z(521288629), w(88675123);
    unsigned int t = (x ^ (x << 11));
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }

  struct Node {
    value_t val, sum;
    size_t cnt;
    std::shared_ptr<Node> left, right;
    Node(value_t val_) : val(val_), sum(val_), cnt(1), left(), right() {}
  };

  using node_ptr = std::shared_ptr<Node>;
  node_ptr root;

  value_t calc(const node_ptr& t) { return t ? t->sum : Monoid::id; }
  size_t count(const node_ptr& t) { return t ? t->cnt : 0; }

  node_ptr update(node_ptr t) {
    if (!t) return t;
    t->sum = Monoid::op(Monoid::op(calc(t->left), t->val), calc(t->right));
    t->cnt = count(t->left) + count(t->right) + 1;
    return t;
  }

  node_ptr merge(node_ptr l, node_ptr r) {
    if (!l || !r) return l ? l : r;

    if (rnd() % (count(l) + count(r)) < count(l)) {
      l->right = merge(l->right, r);
      return update(l);
    } else {
      r->left = merge(l, r->left);
      return update(r);
    }
  }

  std::pair<node_ptr, node_ptr> split(node_ptr t, size_t k) {
    if (!t) return std::make_pair(t, t);

    if (k <= count(t->left)) {
      auto temp = split(t->left, k);
      t->left = temp.second;
      return std::make_pair(temp.first, update(t));
    } else {
      auto temp = split(t->right, k - count(t->left) - 1);
      t->right = temp.first;
      return std::make_pair(update(t), temp.second);
    }
  }

  void insert(node_ptr& t, node_ptr newnode, size_t k) {
    auto temp = split(t, k);
    t = merge(merge(temp.first, newnode), temp.second);
  }

  void erase(node_ptr& t, size_t k) {
    auto temp = split(t, k + 1);
    auto temp2 = split(temp.first, k);
    t = merge(temp2.first, temp.second);
  }

  void build(node_ptr& t, const std::vector<value_t>& val_, size_t l,
             size_t r) {
    if (l == r) {
      t = nullptr;
      return;
    }
    if (r == l + 1) {
      t = std::make_shared<Node>(val_[l]);
      return;
    }

    size_t mid = l + (r - l) / 2;
    t = std::make_shared<Node>(val_[mid]);
    build(t->left, val_, l, mid);
    build(t->right, val_, mid + 1, r);
    update(t);
  }

  void copy_dfs(node_ptr& now, const node_ptr& copy_from) {
    now->val = copy_from->val;
    now->sum = copy_from->sum;
    now->cnt = copy_from->cnt;
    if (copy_from->left) {
      now->left = std::make_shared<Node>(Monoid::id);
      copy_dfs(now->left, copy_from->left);
    }
    if (copy_from->right) {
      now->right = std::make_shared<Node>(Monoid::id);
      copy_dfs(now->right, copy_from->right);
    }
  }

  RBST_Seq(const node_ptr& t) : root(t) {}

 public:
  RBST_Seq() : root() {}
  RBST_Seq(const std::vector<value_t>& seq_) : root() {
    build(root, seq_, 0, seq_.size());
  }
  RBST_Seq(const RBST_Seq& from) {
    root = nullptr;
    if (from.root) {
      root = std::make_shared<Node>(Monoid::id);
      copy_dfs(root, from.root);
    }
  }
  RBST_Seq& operator=(const RBST_Seq& from) {
    root = nullptr;
    if (from.root) {
      root = std::make_shared<Node>(Monoid::id);
      copy_dfs(root, from.root);
    }
  }
  RBST_Seq(RBST_Seq&&) = default;
  RBST_Seq& operator=(RBST_Seq&&) = default;

  size_t size() { return count(root); }
  void insert(size_t k, const value_t& value) {
    insert(root, std::make_shared<Node>(value), k);
  }
  void erase(size_t k) { erase(root, k); }

  RBST_Seq split(size_t l, size_t r) {
    assert(0 <= l && l <= r && r <= size());
    auto tmp = split(root, r);
    auto tmp2 = split(tmp.first, l);
    root = merge(tmp2.first, tmp.second);
    return RBST_Seq(tmp2.second);
  }

  void insert(size_t pos, RBST_Seq seq) {
    assert(0 <= pos && pos <= size());
    auto tmp = split(root, pos);
    tmp.first = merge(tmp.first, seq.root);
    root = merge(tmp.first, tmp.second);
    seq.root = nullptr;
  }

  value_t fold_all() { return calc(root); }
  value_t fold(size_t l, size_t r) {
    auto temp = split(root, r);
    auto temp2 = split(temp.first, l);
    value_t ret = calc(temp2.second);
    root = merge(merge(temp2.first, temp2.second), temp.second);

    return ret;
  }
};
#line 6 "test/RBST_Seq.test.cpp"

constexpr long long MOD=998244353;

struct Monoid{
  using value_t=std::pair<long long,long long>;
  static constexpr value_t id={1,0};
  static constexpr value_t op(value_t a,value_t b){
    return {a.first*b.first%MOD,(a.second*b.first%MOD + b.second)%MOD};
  }
};

using ll=long long;
using P=std::pair<ll,ll>;

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  ll n,q;
  std::cin>>n>>q;

  std::vector<P> tmp(n);
  for(auto&& e:tmp)std::cin>>e.first>>e.second;

  RBST_Seq<Monoid> seq(tmp);

  for(ll i=0;i<q;i++){
    ll mode;
    std::cin>>mode;
    if(mode==0){
      ll p,c,d;
      std::cin>>p>>c>>d;
      seq.erase(p);
      seq.insert(p,{c,d});
    }else{
      ll l,r,x;
      std::cin>>l>>r>>x;
      P fold=seq.fold(l,r);
      std::cout<<(fold.first*x%MOD+fold.second)%MOD<<"\n";
    }
  }

  return 0; 
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

