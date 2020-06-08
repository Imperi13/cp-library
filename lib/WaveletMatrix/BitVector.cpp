#pragma once

#include <cstdint>
#include <vector>
#include <cassert>
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