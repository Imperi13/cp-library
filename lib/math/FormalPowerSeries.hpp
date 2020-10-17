#pragma once

#include <cassert>
#include <cstdint>

#include "../utility/modint.hpp"

template<std::uint_fast64_t MOD,std::uint_fast64_t PRI_ROOT,std::uint_fast64_t BITLEN>
class FPS{
  static_assert([](){
    u64 val = MOD-1;
    for(u64 len=0;len<BITLEN;len++){
      if(val&1)return false;
      val>>=1;
    }
    return true;
  }(),"(MOD-1) % (1<<BITLEN) must be equal to 0 !!");

  public:
  using mint = modint<MOD>;

  private:

  static constexpr std::size_t len=1ull<<BITLEN;
  static constexpr mint root=[](){
    mint a=PRI_ROOT;
    mint ret=1;
    u64 bit=(MOD-1)>>BITLEN;
    while(bit>0){
      if(bit&1)ret*=a;
      a*=a;
      bit>>=1;
    }
    return ret;
  }();


};