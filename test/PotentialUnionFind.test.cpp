#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

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

/* template start */
 
#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(i) i.begin(), i.end()

using ll=long long;

#include "../lib/UnionFind/PotentialUnionFind.cpp"

struct Group{
  using value_t=ll;
  static constexpr value_t id=0;
  static constexpr value_t op(value_t a,value_t b){
    return a+b;
  }
  static constexpr value_t inv(value_t a){return -a;}
};

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n,q;
  std::cin>>n>>q;

  PotentialUnionFind<Group> uni(n);

  while(q--){
    ll mode;
    std::cin>>mode;
    if(mode==0){
      ll x,y,z;
      std::cin>>x>>y>>z;
      if(!uni.same(x,y))uni.unite(y,x,z);
    }else{
      ll x,y;
      std::cin>>x>>y;
      if(!uni.same(x,y))std::cout<<"?\n";
      else std::cout<<uni.diff(y,x)<<"\n";
    }
  }

  return 0;
}