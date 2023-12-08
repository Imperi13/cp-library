---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/niuez/niuristic/blob/main/utility/xorshift.hpp
  bundledCode: "#line 2 \"lib/heuristic/template.hpp\"\n\n#include <cassert>\n#include\
    \ <chrono>\n#include <cstdint>\n#include <limits>\n\n// https://github.com/niuez/niuristic/blob/main/utility/xorshift.hpp\n\
    struct Xor64 {\n  using state_type = std::uint64_t;\n  using result_type = std::uint64_t;\n\
    \  state_type a;\n  static constexpr result_type min() {\n    return std::numeric_limits<result_type>::min();\n\
    \  }\n  static constexpr result_type max() {\n    return std::numeric_limits<result_type>::max();\n\
    \  }\n  constexpr Xor64(state_type seed = 88675123) : a(seed) {}\n  constexpr\
    \ void seed(state_type seed = 88675123) { a = seed; }\n  constexpr result_type\
    \ operator()() {\n    a ^= a << 7;\n    a ^= a >> 9;\n    return a;\n  }\n\n \
    \ //[l,r)\n  constexpr result_type int_dist(int l, int r) {\n    assert(l < r);\n\
    \    return l + ((*this)() % (r - l));\n  }\n\n  //[0,1]\n  constexpr long double\
    \ prob_dist() {\n    return (long double)((*this)()) / std::numeric_limits<state_type>::max();\n\
    \  }\n\n  // choice index with prob\n  //  ex) prob = {4,6}; => return 0 : 40%\
    \ , 1 : 60%\n  size_t choice_with_prob(std::vector<int> prob) {\n    int n = prob.size();\n\
    \    rep(i, 1, n) prob[i] += prob[i - 1];\n    int max = prob.back();\n    int\
    \ r = int_dist(0, max);\n    return std::upper_bound(all(prob), r) - prob.begin();\n\
    \  }\n  \n  void discard(unsigned long long z) {\n    while (z-- > 0) {\n    \
    \  (*this)();\n    }\n  }\n};\n\nstruct Timer {\n  std::chrono::system_clock::time_point\
    \ start;\n\n  Timer() : start(std::chrono::system_clock::now()) {}\n\n  double\
    \ now_sec() {\n    auto now = std::chrono::system_clock::now();\n    return static_cast<double>(\n\
    \               std::chrono::duration_cast<std::chrono::nanoseconds>(now - start)\n\
    \                   .count()) /\n           1000000000;\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <chrono>\n#include <cstdint>\n\
    #include <limits>\n\n// https://github.com/niuez/niuristic/blob/main/utility/xorshift.hpp\n\
    struct Xor64 {\n  using state_type = std::uint64_t;\n  using result_type = std::uint64_t;\n\
    \  state_type a;\n  static constexpr result_type min() {\n    return std::numeric_limits<result_type>::min();\n\
    \  }\n  static constexpr result_type max() {\n    return std::numeric_limits<result_type>::max();\n\
    \  }\n  constexpr Xor64(state_type seed = 88675123) : a(seed) {}\n  constexpr\
    \ void seed(state_type seed = 88675123) { a = seed; }\n  constexpr result_type\
    \ operator()() {\n    a ^= a << 7;\n    a ^= a >> 9;\n    return a;\n  }\n\n \
    \ //[l,r)\n  constexpr result_type int_dist(int l, int r) {\n    assert(l < r);\n\
    \    return l + ((*this)() % (r - l));\n  }\n\n  //[0,1]\n  constexpr long double\
    \ prob_dist() {\n    return (long double)((*this)()) / std::numeric_limits<state_type>::max();\n\
    \  }\n\n  // choice index with prob\n  //  ex) prob = {4,6}; => return 0 : 40%\
    \ , 1 : 60%\n  size_t choice_with_prob(std::vector<int> prob) {\n    int n = prob.size();\n\
    \    rep(i, 1, n) prob[i] += prob[i - 1];\n    int max = prob.back();\n    int\
    \ r = int_dist(0, max);\n    return std::upper_bound(all(prob), r) - prob.begin();\n\
    \  }\n  \n  void discard(unsigned long long z) {\n    while (z-- > 0) {\n    \
    \  (*this)();\n    }\n  }\n};\n\nstruct Timer {\n  std::chrono::system_clock::time_point\
    \ start;\n\n  Timer() : start(std::chrono::system_clock::now()) {}\n\n  double\
    \ now_sec() {\n    auto now = std::chrono::system_clock::now();\n    return static_cast<double>(\n\
    \               std::chrono::duration_cast<std::chrono::nanoseconds>(now - start)\n\
    \                   .count()) /\n           1000000000;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/heuristic/template.hpp
  requiredBy: []
  timestamp: '2023-12-09 04:05:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/heuristic/template.hpp
layout: document
redirect_from:
- /library/lib/heuristic/template.hpp
- /library/lib/heuristic/template.hpp.html
title: lib/heuristic/template.hpp
---
