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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: lib/WaveletMatrix/WaveletMatrix.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e9d5fea60f5f423df499112093a5df91">lib/WaveletMatrix</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/WaveletMatrix/WaveletMatrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-09 03:56:43+09:00




## Depends on

* :heavy_check_mark: <a href="BitVector.cpp.html">lib/WaveletMatrix/BitVector.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/WaveletMatrix.test.cpp.html">test/WaveletMatrix.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <vector>
#include <cstdint>
#include <map>
#include <cassert>
#include <algorithm>

#include "./BitVector.cpp"

template<std::uint64_t BITLEN>
class WaveletMatric{
  public:
  using u64=std::uint64_t;
  using u32=std::uint32_t;
  using size_t=std::size_t;

  private:

  size_t n;
  std::vector<BitVector<>> bitvec;
  std::vector<u32> zerocnt;
  std::map<u64,std::pair<u32,u32>> index;

  size_t less(size_t l,size_t r,u64 num){
    u32 ret=0;
    for(int bit=BITLEN-1;bit>=0;bit--){
      if((num>>bit)&1){
        ret+=(r-bitvec[bit].rank(r))-(l-bitvec[bit].rank(l));
        l=zerocnt[bit]+bitvec[bit].rank(l);
        r=zerocnt[bit]+bitvec[bit].rank(r);
      }else{
        l-=bitvec[bit].rank(l);
        r-=bitvec[bit].rank(r);
      }
    }
    return ret;
  }

  public:
  WaveletMatric(std::vector<u64> seq):n(seq.size()),bitvec(BITLEN,n),zerocnt(BITLEN){
    for(int bit=BITLEN-1;bit>=0;bit--){
      std::vector<u64> zero,one;
      zero.reserve(n);
      for(size_t j=0;j<n;j++){
        if((seq[j]>>bit)&1){
          bitvec[bit].set(j);
          one.emplace_back(seq[j]);
        }else{
          zero.emplace_back(seq[j]);
        }
      }
      bitvec[bit].build();
      std::copy(one.begin(),one.end(),std::back_inserter(zero));
      seq=zero;
      zerocnt[bit]=n-bitvec[bit].rank(n);
    }
    index[seq[0]]={0,0};
    u64 num=seq[0];
    for(size_t i=0;i<n;i++){
      if(seq[i]!=num){
        index[seq[i]]={i,1};
        num=seq[i];
      }else{
        index[num].second++;
      }
    }
  }

  u64 quantile(size_t l,size_t r,size_t pos){
    assert(0<=l&&l<r&&r<=n);
    assert(0<=pos&&pos<r-l);
    u64 ret=0;
    for(int bit=BITLEN-1;bit>=0;bit--){
      size_t zero=(r-bitvec[bit].rank(r))-(l-bitvec[bit].rank(l));
      if(pos<zero){
        l-=bitvec[bit].rank(l);
        r=l+zero;
      }else{
        ret+=(1llu<<bit);
        pos-=zero;
        size_t one=r-l-zero;
        l=zerocnt[bit]+bitvec[bit].rank(l);
        r=l+one;
      }
    }
    return ret;
  }

  size_t rangefreq(size_t l,size_t r,u64 lower,u64 upper){
    assert(0<=l&&l<=r&&r<=n);
    assert(lower<=upper);
    return less(l,r,upper)-less(l,r,lower);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/WaveletMatrix/WaveletMatrix.cpp"

#include <vector>
#include <cstdint>
#include <map>
#include <cassert>
#include <algorithm>

#line 2 "lib/WaveletMatrix/BitVector.cpp"

#line 6 "lib/WaveletMatrix/BitVector.cpp"
#include <utility>

template<std::uint64_t LBLOCK=400,std::uint64_t SBLOCK=16>
class BitVector{
  static_assert(LBLOCK%SBLOCK==0,"");
  static_assert(0<SBLOCK&&SBLOCK<=16,"");
  public:
  using size_t=std::size_t;
  using u32=std::uint32_t;
  using u16=std::uint16_t;

  private:

  static constexpr u16 popcount(u16 x){
    x=(x& 0x5555)+(x>>1 & 0x5555);
    x=(x& 0x3333)+(x>>2 & 0x3333);
    x=(x& 0x0f0f)+(x>>4 & 0x0f0f);
    return (x&0x00ff)+(x>>8 & 0x00ff);
  }

  size_t n;
  size_t bitcnt;

  std::vector<u32> l;
  std::vector<std::pair<u16,u16>> s;

  public:
  BitVector(size_t n_):n(n_),l(n/LBLOCK+1),s(n/SBLOCK+1,{0,0}){}

  void set(size_t pos){
    assert(0<=pos&&pos<n);
    s[pos/SBLOCK].second|=1llu<<(pos%SBLOCK);
  }

  void build(){
    u32 num=0;
    for(size_t i=0;i<=n;i++){
      if(i%LBLOCK==0)l[i/LBLOCK]=num;
      if(i%SBLOCK==0)s[i/SBLOCK].first=num-l[i/LBLOCK];
      if(i!=n&&i%SBLOCK==0){
        num+=popcount(s[i/SBLOCK].second);
      }
    }
    bitcnt=num;
  }

  bool access(size_t pos){
    assert(0<=pos&&pos<n);
    return (s[pos/SBLOCK].second>>(pos%SBLOCK))&1;
  }

  size_t rank(size_t pos){
    assert(0<=pos&&pos<=n);
    return l[pos/LBLOCK]+s[pos/SBLOCK].first
          +popcount(s[pos/SBLOCK].second&((1llu<<(pos%SBLOCK))-1));
  }
};
#line 10 "lib/WaveletMatrix/WaveletMatrix.cpp"

template<std::uint64_t BITLEN>
class WaveletMatric{
  public:
  using u64=std::uint64_t;
  using u32=std::uint32_t;
  using size_t=std::size_t;

  private:

  size_t n;
  std::vector<BitVector<>> bitvec;
  std::vector<u32> zerocnt;
  std::map<u64,std::pair<u32,u32>> index;

  size_t less(size_t l,size_t r,u64 num){
    u32 ret=0;
    for(int bit=BITLEN-1;bit>=0;bit--){
      if((num>>bit)&1){
        ret+=(r-bitvec[bit].rank(r))-(l-bitvec[bit].rank(l));
        l=zerocnt[bit]+bitvec[bit].rank(l);
        r=zerocnt[bit]+bitvec[bit].rank(r);
      }else{
        l-=bitvec[bit].rank(l);
        r-=bitvec[bit].rank(r);
      }
    }
    return ret;
  }

  public:
  WaveletMatric(std::vector<u64> seq):n(seq.size()),bitvec(BITLEN,n),zerocnt(BITLEN){
    for(int bit=BITLEN-1;bit>=0;bit--){
      std::vector<u64> zero,one;
      zero.reserve(n);
      for(size_t j=0;j<n;j++){
        if((seq[j]>>bit)&1){
          bitvec[bit].set(j);
          one.emplace_back(seq[j]);
        }else{
          zero.emplace_back(seq[j]);
        }
      }
      bitvec[bit].build();
      std::copy(one.begin(),one.end(),std::back_inserter(zero));
      seq=zero;
      zerocnt[bit]=n-bitvec[bit].rank(n);
    }
    index[seq[0]]={0,0};
    u64 num=seq[0];
    for(size_t i=0;i<n;i++){
      if(seq[i]!=num){
        index[seq[i]]={i,1};
        num=seq[i];
      }else{
        index[num].second++;
      }
    }
  }

  u64 quantile(size_t l,size_t r,size_t pos){
    assert(0<=l&&l<r&&r<=n);
    assert(0<=pos&&pos<r-l);
    u64 ret=0;
    for(int bit=BITLEN-1;bit>=0;bit--){
      size_t zero=(r-bitvec[bit].rank(r))-(l-bitvec[bit].rank(l));
      if(pos<zero){
        l-=bitvec[bit].rank(l);
        r=l+zero;
      }else{
        ret+=(1llu<<bit);
        pos-=zero;
        size_t one=r-l-zero;
        l=zerocnt[bit]+bitvec[bit].rank(l);
        r=l+one;
      }
    }
    return ret;
  }

  size_t rangefreq(size_t l,size_t r,u64 lower,u64 upper){
    assert(0<=l&&l<=r&&r<=n);
    assert(lower<=upper);
    return less(l,r,upper)-less(l,r,lower);
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

