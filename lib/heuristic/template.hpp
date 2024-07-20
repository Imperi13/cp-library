#pragma once

#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <limits>
#include <vector>

// https://github.com/niuez/niuristic/blob/main/utility/xorshift.hpp
struct Xor64 {
  using state_type = std::uint64_t;
  using result_type = std::uint64_t;
  state_type a;
  static constexpr result_type min() {
    return std::numeric_limits<result_type>::min();
  }
  static constexpr result_type max() {
    return std::numeric_limits<result_type>::max();
  }
  constexpr Xor64(state_type seed = 88675123) : a(seed) {}
  constexpr void seed(state_type seed = 88675123) { a = seed; }
  constexpr result_type operator()() {
    a ^= a << 7;
    a ^= a >> 9;
    return a;
  }

  //[l,r)
  constexpr result_type int_dist(int l, int r) {
    assert(l < r);
    return l + ((*this)() % (r - l));
  }

  //[0,1]
  constexpr long double prob_dist() {
    return (long double)((*this)()) / std::numeric_limits<state_type>::max();
  }

  // choice index with prob
  //  ex) prob = {4,6}; => return 0 : 40% , 1 : 60%
  size_t choice_with_prob(std::vector<int> prob) {
    size_t n = prob.size();
    for (size_t i = 1; i < n; i++)
      prob[i] += prob[i - 1];
    int max = prob.back();
    int r = int_dist(0, max);
    return std::upper_bound(prob.begin(), prob.end(), r) - prob.begin();
  }

  void discard(unsigned long long z) {
    while (z-- > 0) {
      (*this)();
    }
  }
};

struct Timer {
  std::chrono::system_clock::time_point start;

  Timer() : start(std::chrono::system_clock::now()) {}

  double now_sec() {
    auto now = std::chrono::system_clock::now();
    return static_cast<double>(
               std::chrono::duration_cast<std::chrono::nanoseconds>(now - start)
                   .count()) /
           1000000000;
  }
};
