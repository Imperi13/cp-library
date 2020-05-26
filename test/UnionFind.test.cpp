#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <iostream>
#include "../lib/UnionFind/UnionFind.cpp"

#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)

using ll=long long;

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  ll n,q;
  std::cin>>n>>q;

  UnionFind uni(n);

  rep(i,0,q){
    ll t,u,v;
    std::cin>>t>>u>>v;
    if(t==0)uni.unite(u,v);
    else std::cout<<(uni.same(u,v)?1:0)<<"\n";
  }
}