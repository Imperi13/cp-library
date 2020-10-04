#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H"

#include <iostream>
#include <vector>

#include "../lib/SegmentTree/LazySegmentTree.hpp"

/* template start */
 
#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(i) i.begin(), i.end()

using i64=std::int_fast64_t;

struct Lazy{
  using value_t=i64;
  using lazy_t=i64;
  static constexpr value_t id_val=1e18;
  static constexpr lazy_t id_lazy=0;
  static value_t f(value_t a,value_t b){
    return std::min(a,b);
  }
  static value_t g(value_t a,lazy_t b){
    return a+b;
  }
  static lazy_t h(lazy_t a,lazy_t b){
    return a+b;
  }
  static lazy_t p(lazy_t a,std::size_t n){
    return a;
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  i64 n,q;
  std::cin>>n>>q;

  LazySegmentTree<Lazy> seg(std::vector<i64>(n,0));

  while(q--){
    i64 com;
    std::cin>>com;

    if(com==0){
      i64 s,t,x;
      std::cin>>s>>t>>x;
      seg.update(s,t+1,x);
    }else{
      i64 s,t;
      std::cin>>s>>t;

      std::cout<<seg.fold(s,t+1)<<"\n";
    }
  }

  return 0;
}