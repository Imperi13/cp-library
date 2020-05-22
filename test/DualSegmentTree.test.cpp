#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include <iostream>
#include <algorithm>
#include <vector>

#include "../lib/SegmentTree/DualSegmentTree.cpp"

#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(a) a.begin(),a.end()

struct Monoid{
  using value_t=long long;
  static constexpr value_t id=0;
  static constexpr value_t op(value_t a,value_t b){
    return a+b;
  }
};

using ll=long long;

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n,q;
  std::cin>>n>>q;

  DualSegmentTree<Monoid> seg(n);

  while(q--){
    ll mode;
    std::cin>>mode;
    if(mode==0){
      ll s,t,x;
      std::cin>>s>>t>>x;
      seg.update(s-1,t,x);
    }else{
      ll t;
      std::cin>>t;
      std::cout<<seg.at(t-1)<<"\n";
    }
  }

  return 0; 
}