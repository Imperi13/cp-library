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


# :heavy_check_mark: lib/WaveletMatrix/BitVector.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e9d5fea60f5f423df499112093a5df91">lib/WaveletMatrix</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/WaveletMatrix/BitVector.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-09 13:11:01+09:00




## Required by

* :heavy_check_mark: <a href="WaveletMatrix.cpp.html">lib/WaveletMatrix/WaveletMatrix.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../../verify/test/WaveletMatrix.test.cpp.html">test/WaveletMatrix.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <cstdint>
#include <vector>
#include <cassert>
#include <utility>

template<std::size_t LBLOCK=400,std::size_t SBLOCK=16>
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/WaveletMatrix/BitVector.cpp"

#include <cstdint>
#include <vector>
#include <cassert>
#include <utility>

template<std::size_t LBLOCK=400,std::size_t SBLOCK=16>
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

