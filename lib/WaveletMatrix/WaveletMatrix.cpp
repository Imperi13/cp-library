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