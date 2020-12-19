#pragma once

#include <cassert>
#include <vector>

#include "../utility/type_alias.hpp"
#include "../utility/bit.hpp"

class BitVector {
 private:
  constexpr static std::size_t LBLOCK = 1ul << 16;
  constexpr static std::size_t SBLOCK = 64;

  usize n;
  usize bitcnt;

  std::vector<u64> raw_bit;

  std::vector<u32> rank_l;
  std::vector<u16> rank_s;

  bool build_flag;

 public:
  BitVector() = delete;
  explicit BitVector(usize n_)
      : n(n_),
        raw_bit(n / SBLOCK + 1),
        rank_l(n / LBLOCK + 1),
        rank_s(n / SBLOCK + 1),
        build_flag(false) {
    assert(n_ <= std::numeric_limits<u32>::max());
  }

  void set(usize pos) {
    assert(!build_flag);
    assert(pos < n);
    raw_bit[pos / SBLOCK] |= 1_u64 << (pos % SBLOCK);
  }

  void build() {
    assert(!build_flag);
    u32 cnt = 0;
    for (usize i = 0; i <= n; i++) {
      if (i % LBLOCK == 0) rank_l[i / LBLOCK] = cnt;
      if (i % SBLOCK == 0) rank_s[i / SBLOCK] = cnt - rank_l[i / LBLOCK];
      if (i != n && i % SBLOCK == 0) cnt += popcount64(raw_bit[i / SBLOCK]);
    }
    bitcnt = cnt;
    build_flag = true;
  }

  bool operator[](usize pos){
    assert(build_flag);
    assert(pos < n);
    return (raw_bit[pos/SBLOCK] >> (pos % SBLOCK)) & 1;
  }

  usize rank(usize pos){
    assert(build_flag);
    assert(pos <= n);
    return rank_l[pos/LBLOCK] + rank_s[pos / SBLOCK] + popcount64(raw_bit[pos/SBLOCK] & ((1_u64 << (pos % SBLOCK))-1) );
  }
};