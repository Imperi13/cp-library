#pragma once

#include <cstddef>
#include <vector>
#include <numeric>

class UnionFind{
  public:
  using size_t=std::size_t;
  private:
  std::vector<size_t> par,sz;
  size_t group;

  public:

  UnionFind(size_t n=0):par(n,0),sz(n,1),group(n){
    std::iota(par.begin(),par.end(),0);
  }

  size_t root(size_t n){
    if(par[n]==n)return n;
    return par[n]=root(par[n]);
  }

  bool unite(size_t a,size_t b){
    a=root(a);b=root(b);
    if(a==b)return false;
    group--;
    if(sz[a]<sz[b])std::swap(a,b);
    sz[a]+=sz[b];
    par[b]=a;
    return true;
  }

  size_t size(){return par.size();}
  size_t groups(){return group;}
  size_t group_size(size_t n){return sz[root(n)];}

  bool same(size_t a,size_t b){return root(a)==root(b);}
};