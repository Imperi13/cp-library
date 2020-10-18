#pragma once

#include <cassert>
#include <cstdint>

#include "../utility/modint.hpp"

using u64=std::uint_fast64_t;

template <u64 MOD, u64 PRI_ROOT>
class FPSoperator {
 public:
  using mint = modint<MOD>;
  using FPS = std::vector<mint>;

 private:
  u64 len_real, len;

  std::vector<mint> w;

  FPS fft(const FPS& a,u64 l,bool inv){
    if(l==1)return a;
    u64 half = l/2,haba = 2*len/l;
    FPS even(half),odd(half);
    for(std::size_t i=0;i<l;i++){
      if(i%2==0)even[i/2]=a[i];
      else odd[i/2]=a[i];
    }
    even = fft(even,half,inv);
    odd = fft(odd,half,inv);
    FPS ret(l);
    for(std::size_t i=0;i<l;i++){
      ret[i] = even[i%half] + w[inv ? (2*len-haba * i)%(2*len) : haba*i] * odd[i%half];
    }
    return ret;
  }

  FPS div(FPS a,u64 x){
    mint inv =mint(1)/x;
    for(auto&& e:a)e*=inv;
    return a;
  }

  FPS mul(FPS a,FPS b,u64 l){
    assert(a.size() == l && b.size() == l);
    a.resize(2*l);b.resize(2*l);
    a = fft(a,2*l,false);b = fft(b,2*l,false);
    for(std::size_t i=0;i<2*l;i++)a[i] *= b[i];
    a = fft(a,2*l,true);
    a = div(a,2*l);
    a.resize(l);
    return a;
  }

 public:
  FPSoperator(u64 len_) : len_real(len_){
    len = 1;
    while (len < len_real) len <<= 1;
    w = FPS(2*len,1);
    assert((MOD - 1) % (2*len) == 0);
    u64 bit = (MOD - 1) / (2*len);
    mint a = PRI_ROOT;
    while (bit > 0) {
      if (bit & 1) w[1] *= a;
      a *= a;
      bit >>= 1;
    }
    for (std::size_t i = 2; i < 2*len; i++) w[i] = w[i - 1] * w[1];
  }

  FPS mul(FPS a,FPS b){
    assert(a.size() <= len_real && b.size() <= len_real);
    a.resize(len);b.resize(len);
    a = mul(a,b,len);
    a.resize(len_real);
    return a;
  }

  FPS inv(FPS a){
    assert(a.size() <= len_real);
    assert(a[0]!=0);
    a.resize(len);
    u64 now = 1;
    FPS ret(1,mint(1)/a[0]);
    while(now < len){
      now<<=1;
      ret.resize(now);
      auto tmp = mul(FPS(a.begin(),a.begin()+now) , mul(ret,ret,now) ,now);
      for(std::size_t i=0;i<now;i++)ret[i] = ret[i] * 2 - tmp[i];
    }
    ret.resize(len_real);
    return ret;
  }
};