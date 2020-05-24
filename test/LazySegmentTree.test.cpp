#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <chrono>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <random>
#include <utility>
#include <limits>
#include <list>
#include <cmath>

#include "../lib/SegmentTree/LazySegmentTree.cpp"

/* template start */
 
#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(i) i.begin(), i.end()

using ll=long long;

constexpr ll MOD=998244353;

struct Lazy{
  using value_t=std::pair<ll,ll>;
  using lazy_t=std::pair<ll,ll>;
  static constexpr value_t id_val={0,1};
  static constexpr lazy_t id_lazy={1,0};
  static value_t f(value_t a,value_t b){
    return {(a.first+b.first)%MOD,(a.second+b.second)%MOD};
  }
  static value_t g(value_t a,lazy_t b){
    return {(a.first*b.first%MOD+a.second*b.second%MOD)%MOD,a.second};
  }
  static lazy_t h(lazy_t a,lazy_t b){
    return {b.first*a.first%MOD,(b.first*a.second%MOD+b.second)%MOD};
  }
  static lazy_t p(lazy_t a,std::size_t n){
    return a;
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n,q;
  std::cin>>n>>q;

  std::vector<std::pair<ll,ll>> a(n,{0,1});
  for(auto&& e:a)std::cin>>e.first;

  LazySegmentTree<Lazy> seg(a);

  while(q--){
    ll mode;
    std::cin>>mode;
    if(mode==0){
      ll l,r,b,c;
      std::cin>>l>>r>>b>>c;
      seg.update(l,r,{b,c});
    }else{
      ll l,r;
      std::cin>>l>>r;
      std::cout<<seg.fold(l,r).first<<"\n";
    }
  }

  return 0;
}