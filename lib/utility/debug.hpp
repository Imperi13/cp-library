#pragma once

#include <iostream>
#include <vector>

#ifdef LOCAL
#define debug(...)                                                             \
  std::cerr << "LINE: " << __LINE__ << "  [" << #__VA_ARGS__ << "]:",          \
      debug_out(__VA_ARGS__)
#define debug_assert(e) assert(e)
#else
#define debug(...)
#define debug_assert(e)
#endif

inline void debug_out() { std::cerr << std::endl; }

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, std::pair<T1, T2> pa) {
  return os << pa.first << " " << pa.second;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> vec) {
  for (std::size_t i = 0; i < vec.size(); i++)
    os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}

template <typename Head, typename... Tail> void debug_out(Head h, Tail... t) {
  std::cerr << " " << h;
  if (sizeof...(t) > 0)
    std::cerr << " :";
  debug_out(t...);
}
