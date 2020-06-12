#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"

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

#include "../lib/PersistentArray.hpp"

template<typename T>
class PersistentQueue{
  public:
  using value_t=T;
  using size_t=std::size_t;
  private:
  size_t l,r;
  PersistentArray<value_t> que;

  PersistentQueue(size_t l_,size_t r_,const PersistentArray<value_t>& que_):l(l_),r(r_),que(que_){}
  public:
  PersistentQueue():l(0),r(0),que(){}

  PersistentQueue push(value_t value){
    return PersistentQueue(l,r+1,que.update(r,value));
  }

  PersistentQueue pop(){
    return PersistentQueue(l+1,r,que);
  }

  value_t front(){
    return que[l];
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll q;
  std::cin>>q;

  PersistentQueue<ll> base;

  std::vector<PersistentQueue<ll>> s(q);

  rep(i,0,q){
    ll mode;
    std::cin>>mode;
    
    if(mode==0){
      ll t,x;
      std::cin>>t>>x;
      if(t==-1)s[i]=base.push(x);
      else s[i]=s[t].push(x);
    }else{
      ll t;
      std::cin>>t;
      std::cout<<s[t].front()<<"\n";
      s[i]=s[t].pop();
    }
  }

  return 0;
}