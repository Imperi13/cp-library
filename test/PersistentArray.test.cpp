#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

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

#include "../lib/PersistentArray.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  PersistentArray<ll> ary(0);
  
  ll q;
  std::cin>>q;
  while(q--){
    ll mode;
    std::cin>>mode;
    if(mode==0){
      ll k,v;
      std::cin>>k>>v;
      ary=ary.update(k,v);
    }else{
      ll k;
      std::cin>>k;
      std::cout<<ary[k]<<"\n";
    }
  }

  return 0;
}