#pragma once

#include "./PersistentArray.cpp"

class PersistentUnionFind{
  public:
  using size_t=std::size_t;
  private:
  PersistentArray<long long> uni;
  size_t group;

  PersistentUnionFind(PersistentArray<long long> uni_,size_t group_):uni(uni_),group(group_){}
  public:
  PersistentUnionFind(size_t n=0):uni(-1),group(n){}

  size_t root(size_t a){
    if(uni[a]<0)return a;
    size_t tmp=root(uni[a]);
    uni=uni.update(a,tmp);
    return tmp;
  }

  PersistentUnionFind unite(size_t a,size_t b){
    a=root(a);
    b=root(b);
    if(a==b)return *this;
    group--;
    if(uni[a]>uni[b])std::swap(a,b);

    PersistentArray<long long> newuni=uni;
    long long va=uni[a],vb=uni[b];
    newuni=newuni.update(a,va+vb);
    newuni=newuni.update(b,a);
    return PersistentUnionFind(newuni,group);
  }

  bool isconnect(size_t a,size_t b){return root(a)==root(b);}
  size_t group_size(size_t a){return -uni[root(a)];}
  size_t groups(){return group;}
};