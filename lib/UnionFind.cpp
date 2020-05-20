#pragma once

#include <cstddef>
#include <vector>
#include <numeric>

class UnionFind{
  private:
  using size_type=std::size_t;

  std::vector<size_type> par,sz;
  size_type group;

  public:

  UnionFind(size_type n):par(n,0),sz(n,1),group(n){
    std::iota(par.begin(),par.end(),0);
  }

  size_type root(size_type n){
    if(par[n]==n)return n;
    return par[n]=root(par[n]);
  }

  bool unite(size_type a,size_type b){
    a=root(a);b=root(b);
    if(a==b)return false;
    if(sz[a]<sz[b])std::swap(a,b);
    sz[a]+=sz[b];
    par[b]=a;
    return true;
  }

  size_type size(){return par.size();}
  size_type groups(){return group;}
  size_type group_size(size_type n){return sz[root(n)];}

  bool same(size_type a,size_type b){return root(a)==root(b);}
};