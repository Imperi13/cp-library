#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include <iostream>
#include "../lib/SWAG.hpp"

#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)

using ll=long long;

constexpr long long MOD=998244353;

struct Semigroup{
  using value_t=std::pair<long long,long long>;
  static constexpr value_t op(value_t a,value_t b){
    return {a.first*b.first%MOD,(a.second*b.first%MOD + b.second)%MOD};
  }
};

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  SWAG<Semigroup> swag;

  ll q;
  std::cin>>q;

  rep(i,0,q){
    ll mode;
    std::cin>>mode;

    if(mode==0){
      ll a,b;
      std::cin>>a>>b;
      swag.push_back({a,b});
    }else if(mode==1){
      swag.pop_front();
    }else{
      ll x;
      std::cin>>x;
      if(swag.empty())std::cout<<x<<"\n";
      else{
        auto tmp=swag.fold_all();
        std::cout<<(tmp.first*x%MOD+tmp.second)%MOD<<"\n";
      }
    }
  }
}