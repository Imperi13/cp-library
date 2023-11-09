#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

/* template start */

using i64 = std::int_fast64_t;
using u64 = std::uint_fast64_t;

#define rep(i, a, b) for (i64 i = (a); (i) < (b); (i)++)
#define all(i) i.begin(), i.end()

#ifdef LOCAL
#define debug(...)                                                    \
  std::cerr << "LINE: " << __LINE__ << "  [" << #__VA_ARGS__ << "]:", \
      debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out() { std::cerr << std::endl; }

template <typename Head, typename... Tail>
void debug_out(Head h, Tail... t) {
  std::cerr << " " << h;
  if (sizeof...(t) > 0) std::cout << " :";
  debug_out(t...);
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << pa.first << " " << pa.second;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (std::size_t i = 0; i < vec.size(); i++)
    os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}

template <typename T1, typename T2>
inline bool chmax(T1& a, T2 b) {
  return a < b && (a = b, true);
}

template <typename T1, typename T2>
inline bool chmin(T1& a, T2 b) {
  return a > b && (a = b, true);
}

template <typename Num>
constexpr Num mypow(Num a, u64 b, Num id = 1) {
  if (b == 0) return id;
  Num x = id;
  while (b > 0) {
    if (b & 1) x *= a;
    a *= a;
    b >>= 1;
  }
  return x;
}

template <typename T>
std::vector<std::pair<std::size_t, T>> enumerate(const std::vector<T>& data) {
  std::vector<std::pair<std::size_t, T>> ret;
  for (std::size_t index = 0; index < data.size(); index++)
    ret.emplace_back(index, data[index]);
  return ret;
}

/* template end */

#include "../lib/data_structure/SegmentTree/LiChaoSegmentTree.hpp"

constexpr i64 INF=1e9+100;

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  i64 n,q;
  std::cin>>n>>q;

  LiChaoSegmentTree<i64> cht(-INF,INF);

  rep(i,0,n){
    i64 a,b;
    std::cin>>a>>b;
    cht.add_line(a,b);
  }

  while(q--){
    i64 mode;
    std::cin>>mode;
    if(mode==0){
      i64 a,b;
      std::cin>>a>>b;
      cht.add_line(a,b);
    }else{
      i64 p;
      std::cin>>p;

      std::cout<<cht.query(p)<<"\n";
    }
  }

  return 0;
}