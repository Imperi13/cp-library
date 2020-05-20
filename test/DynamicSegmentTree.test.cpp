#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <iostream>
#include <vector>

#include "../lib/DynamicSegmentTree.cpp"

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
  ll n,q;
  std::cin>>n>>q;

  DynamicSegmentTree<Monoid> seg(n);

  for(ll i=0;i<n;i++){
    ll a,b;
    std::cin>>a>>b;
    seg.update(i,{a,b},true);
  }

  for(ll i=0;i<q;i++){
    ll mode;
    std::cin>>mode;
    if(mode==0){
      ll p,c,d;
      std::cin>>p>>c>>d;
      seg.update(p,{c,d},true);
    }else{
      ll l,r,x;
      std::cin>>l>>r>>x;
      P fold=seg.fold(l,r);
      std::cout<<(fold.first*x%MOD+fold.second)%MOD<<"\n";
    }
  }

  return 0; 
}