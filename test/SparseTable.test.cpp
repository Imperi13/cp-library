#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <cassert>
#include <algorithm>

#include <vector>

#include "../lib/SparseTable.cpp"

struct Semigroup{
  using value_t=long long;
  static constexpr value_t none=2e9;
  static constexpr value_t op(const value_t& a,const value_t& b){
    return std::min(a,b);
  }
};

using ll=long long;
using P=std::pair<ll,ll>;

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n,q;
  std::cin>>n>>q;

  std::vector<ll> a(n);
  for(auto&& e:a)std::cin>>e;

  SparseTable<Semigroup> sp(a);

  while(q--){
    ll l,r;
    std::cin>>l>>r;
    std::cout<<sp.fold(l,r)<<"\n";
  }

  return 0; 
}