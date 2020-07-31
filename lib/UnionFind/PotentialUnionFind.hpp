#pragma once

#include <cassert>
#include <numeric>
#include <vector>

template <typename Group>
class PotentialUnionFind {
 public:
  using value_t = typename Group::value_t;
  using size_t = std::size_t;

 private:
  size_t group;
  std::vector<size_t> par, sz;
  std::vector<value_t> df;  // val[par]=val[x]+df[x]

  value_t fold_to_root(size_t x) {
    value_t ret = Group::id;
    while (par[x] != x) {
      df[x] = Group::op(df[x], df[par[x]]);
      par[x] = par[par[x]];
      ret = Group::op(ret, df[x]);
      x = par[x];
    }
    return ret;
  }

 public:
  PotentialUnionFind(size_t n = 0)
      : group(n), par(n), sz(n, 1), df(n, Group::id) {
    std::iota(par.begin(), par.end(), 0);
  }

  size_t root(size_t x) {
    while (par[x] != x) {
      df[x] = Group::op(df[x], df[par[x]]);
      par[x] = par[par[x]];
      x = par[x];
    }
    return x;
  }

  bool same(size_t a, size_t b) { return root(a) == root(b); }
  size_t size() { return par.size(); }
  size_t groups() { return group; }
  size_t group_size(size_t x) { return sz[root(x)]; }

  // unite A=B+value
  bool unite(size_t a, size_t b, value_t value) {
    size_t aroot = root(a), broot = root(b);
    if (aroot == broot) return false;
    group--;
    if (sz[aroot] < sz[broot]) {
      std::swap(aroot, broot);
      std::swap(a, b);
      value = Group::inv(value);
    }
    sz[aroot] += sz[broot];
    value = Group::op(value, fold_to_root(a));
    value = Group::op(Group::inv(fold_to_root(b)), value);
    df[broot] = value;
    par[broot] = aroot;
    return true;
  }

  // return diff  such as A=B+diff
  value_t diff(size_t a, size_t b) {
    assert(same(a, b));
    return Group::op(fold_to_root(b), Group::inv(fold_to_root(a)));
  }
};