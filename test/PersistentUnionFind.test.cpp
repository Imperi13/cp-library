#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include <iostream>
#include <algorithm>
#include <vector>

#include "../lib/UnionFind/PersistentUnionFind.cpp"

#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(a) a.begin(),a.end()

using ll=long long;

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n,q;
  std::cin>>n>>q;

  PersistentUnionFind base(n);
  std::vector<PersistentUnionFind> G(q);

  rep(i,0,q){
    ll t,k,u,v;
    std::cin>>t>>k>>u>>v;
    if(t==0){
      if(k==-1)G[i]=base.unite(u,v);
      else G[i]=G[k].unite(u,v);
    }else{
      if(k==-1)std::cout<<base.isconnect(u,v)<<"\n";
      else std::cout<<G[k].isconnect(u,v)<<"\n";
    }
  }

  return 0; 
}