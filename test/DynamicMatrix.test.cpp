#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1327"

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
#include <type_traits>
#include <unordered_map>
#include <vector>
#include <random>
#include <utility>
#include <limits>
#include <list>

/* template start */
 
#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(i) i.begin(), i.end()

#ifdef LOCAL
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out(){std::cerr<<std::endl;}

template<typename Head,typename... Tail>
void debug_out(Head h,Tail... t){
  std::cerr<<" "<<h;
  if(sizeof...(t)>0)std::cout<<" :";
  debug_out(t...);
}
 
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << pa.first << " " << pa.second;
}
 
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (std::size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}
 
template<typename T1,typename T2>
inline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}
 
template<typename T1,typename T2>
inline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}

template<typename Num>
constexpr Num mypow(Num a, unsigned long long b) {
  if(b==0)return 1;
  if (a==0)return 0;
  Num x = 1;
  while (b > 0) {
    if(b & 1)x*=a;
    a*=a;
    b >>= 1;
  }
  return x;
}

/* template end */

using ll = long long;

#include "../lib/utility/runtime_modint.cpp"

#include "../lib/math/DynamicMatrix.cpp"

std::uint_fast16_t modint::Modulus;

using mat=DynamicMatrix<modint>;

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n,a,b,c,t;

  while(std::cin>>n>>modint::Modulus>>a>>b>>c>>t,n){
    mat tmp(n,n);
    rep(i,0,n){
      if(i-1>=0)tmp(i,i-1)=a;
      tmp(i,i)=b;
      if(i+1<n)tmp(i,i+1)=c;
    }


    mat ret=mat::id(n);

    while(t>0){
      if(t&1)ret*=tmp;
      tmp*=tmp;
      t>>=1;
    }

    mat init(n,1);
    rep(i,0,n){
      ll e;
      std::cin>>e;
      init(i,0)=e;
    }

    ret*=init;

    rep(i,0,n)std::cout<<ret(i,0).value()<<(i!=n-1?" ":"");
    std::cout<<"\n";
  }

  return 0;
}