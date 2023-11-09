#pragma once

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <map>
#include <vector>

#include "./BitVector.hpp"

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
  using BitVec = BitVector;

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