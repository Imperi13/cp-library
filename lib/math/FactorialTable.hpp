#pragma once

#include "../local/modint.hpp"

#include <vector>
#include <cassert>
#include <cstdint>

template<std::size_t N,std::uint_fast64_t MOD>
class Factorial{
  public:
  using mint=modint<MOD>;
  using size_t=std::size_t;
  private:
  std::vector<mint> factorial,factorial_inv;
  public:
  Factorial():factorial(N+1),factorial_inv(N+1){
    factorial[0]=1;
    for(size_t i=1;i<N+1;i++)factorial[i]=factorial[i-1]*i;
    factorial_inv[N]=mint(1)/factorial[N];
    for(size_t i=N;i>0;i--)factorial_inv[i-1]=factorial_inv[i]*i;
  }

  mint fact(size_t pos)const{
    assert(0<=pos&&pos<=N);
    return factorial[pos];
  }
  mint fact_inv(size_t pos)const{
    assert(0<=pos&&pos<=N);
    return factorial_inv[pos];
  }
  mint binom(size_t n,size_t k)const{
    assert(0<=n&&n<=N);
    assert(0<=k&&k<=n);
    return fact(n)*fact_inv(k)*fact_inv(n-k);
  }
};