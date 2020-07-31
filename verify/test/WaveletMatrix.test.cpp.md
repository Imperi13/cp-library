---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :x: test/WaveletMatrix.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/WaveletMatrix.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-31 15:44:20+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_kth_smallest">https://judge.yosupo.jp/problem/range_kth_smallest</a>


## Depends on

* :x: <a href="../../library/lib/WaveletMatrix/BitVector.hpp.html">lib/WaveletMatrix/BitVector.hpp</a>
* :x: <a href="../../library/lib/WaveletMatrix/WaveletMatrix.hpp.html">lib/WaveletMatrix/WaveletMatrix.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

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
#include <type_traits>

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
constexpr Num mypow(Num a, long long b) {
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

#include "../lib/WaveletMatrix/WaveletMatrix.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n,q;
  std::cin>>n>>q;

  using u32=uint32_t;

  std::vector<u32> a(n);
  for(auto&& e:a)std::cin>>e;

  WaveletMatric<u32,30> seq(a);

  while(q--){
    ll l,r,k;
    std::cin>>l>>r>>k;
    std::cout<<seq.quantile(l,r,k)<<"\n";
  }

  return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/WaveletMatrix.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

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
#include <type_traits>

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
constexpr Num mypow(Num a, long long b) {
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

#line 2 "lib/WaveletMatrix/WaveletMatrix.hpp"

#line 8 "lib/WaveletMatrix/WaveletMatrix.hpp"

#line 2 "lib/WaveletMatrix/BitVector.hpp"

#line 8 "lib/WaveletMatrix/BitVector.hpp"

template <std::size_t LBLOCK = 400, std::size_t SBLOCK = 16>
class BitVector {
  static_assert(LBLOCK % SBLOCK == 0, "");
  static_assert(0 < SBLOCK && SBLOCK <= 16, "");

 public:
  using size_t = std::size_t;
  using u32 = std::uint32_t;
  using u16 = std::uint16_t;

 private:
  static constexpr u16 popcount(u16 x) {
    x = (x & 0x5555) + (x >> 1 & 0x5555);
    x = (x & 0x3333) + (x >> 2 & 0x3333);
    x = (x & 0x0f0f) + (x >> 4 & 0x0f0f);
    return (x & 0x00ff) + (x >> 8 & 0x00ff);
  }

  size_t n;
  size_t bitcnt;

  std::vector<u32> l;
  std::vector<std::pair<u16, u16>> s;

 public:
  BitVector() = delete;
  explicit BitVector(size_t n_)
      : n(n_), l(n / LBLOCK + 1), s(n / SBLOCK + 1, {0, 0}) {}

  void set(size_t pos) {
    assert(0 <= pos && pos < n);
    s[pos / SBLOCK].second |= 1llu << (pos % SBLOCK);
  }

  void build() {
    u32 num = 0;
    for (size_t i = 0; i <= n; i++) {
      if (i % LBLOCK == 0) l[i / LBLOCK] = num;
      if (i % SBLOCK == 0) s[i / SBLOCK].first = num - l[i / LBLOCK];
      if (i != n && i % SBLOCK == 0) {
        num += popcount(s[i / SBLOCK].second);
      }
    }
    bitcnt = num;
  }

  bool operator[](size_t pos) {
    assert(0 <= pos && pos < n);
    return (s[pos / SBLOCK].second >> (pos % SBLOCK)) & 1;
  }

  size_t rank(size_t pos) {
    assert(0 <= pos && pos <= n);
    return l[pos / LBLOCK] + s[pos / SBLOCK].first +
           popcount(s[pos / SBLOCK].second & ((1llu << (pos % SBLOCK)) - 1));
  }
};
#line 10 "lib/WaveletMatrix/WaveletMatrix.hpp"

template <typename UInt, std::uint64_t BITLEN>
class WaveletMatric {
  static_assert(std::is_integral<UInt>::value, "UInt must be integer");
  static_assert(std::is_unsigned<UInt>::value, "UInt must be unsigned");
  static_assert(0 < BITLEN && BITLEN <= std::numeric_limits<UInt>::digits, "");

 public:
  using value_t = UInt;
  using size_t = std::size_t;

 private:
  using u32 = std::uint32_t;
  using BitVec = BitVector<>;

  size_t n;
  std::vector<BitVec> bitvec;
  std::vector<u32> zerocnt;
  std::map<value_t, std::pair<u32, u32>> index;

  size_t less(size_t l, size_t r, value_t num) {
    u32 ret = 0;
    for (int bit = BITLEN - 1; bit >= 0; bit--) {
      if ((num >> bit) & 1) {
        ret += (r - bitvec[bit].rank(r)) - (l - bitvec[bit].rank(l));
        l = zerocnt[bit] + bitvec[bit].rank(l);
        r = zerocnt[bit] + bitvec[bit].rank(r);
      } else {
        l -= bitvec[bit].rank(l);
        r -= bitvec[bit].rank(r);
      }
    }
    return ret;
  }

 public:
  explicit WaveletMatric(std::vector<value_t> seq)
      : n(seq.size()), bitvec(BITLEN, BitVec(n)), zerocnt(BITLEN) {
    for (int bit = BITLEN - 1; bit >= 0; bit--) {
      std::vector<value_t> zero, one;
      zero.reserve(n);
      for (size_t j = 0; j < n; j++) {
        if ((seq[j] >> bit) & 1) {
          bitvec[bit].set(j);
          one.emplace_back(seq[j]);
        } else {
          zero.emplace_back(seq[j]);
        }
      }
      bitvec[bit].build();
      std::copy(one.begin(), one.end(), std::back_inserter(zero));
      seq = zero;
      zerocnt[bit] = n - bitvec[bit].rank(n);
    }
    index[seq[0]] = {0, 0};
    value_t num = seq[0];
    for (size_t i = 0; i < n; i++) {
      if (seq[i] != num) {
        index[seq[i]] = {i, 1};
        num = seq[i];
      } else {
        index[num].second++;
      }
    }
  }

  value_t quantile(size_t l, size_t r, size_t pos) {
    assert(0 <= l && l < r && r <= n);
    assert(0 <= pos && pos < r - l);
    value_t ret = 0;
    for (int bit = BITLEN - 1; bit >= 0; bit--) {
      size_t zero = (r - bitvec[bit].rank(r)) - (l - bitvec[bit].rank(l));
      if (pos < zero) {
        l -= bitvec[bit].rank(l);
        r = l + zero;
      } else {
        ret += (1llu << bit);
        pos -= zero;
        size_t one = r - l - zero;
        l = zerocnt[bit] + bitvec[bit].rank(l);
        r = l + one;
      }
    }
    return ret;
  }

  size_t rangefreq(size_t l, size_t r, value_t lower, value_t upper) {
    assert(0 <= l && l <= r && r <= n);
    assert(lower <= upper);
    return less(l, r, upper) - less(l, r, lower);
  }
};
#line 87 "test/WaveletMatrix.test.cpp"

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n,q;
  std::cin>>n>>q;

  using u32=uint32_t;

  std::vector<u32> a(n);
  for(auto&& e:a)std::cin>>e;

  WaveletMatric<u32,30> seq(a);

  while(q--){
    ll l,r,k;
    std::cin>>l>>r>>k;
    std::cout<<seq.quantile(l,r,k)<<"\n";
  }

  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

