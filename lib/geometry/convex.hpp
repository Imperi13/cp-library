#pragma once

#include <algorithm>
#include <vector>

#include "./template.hpp"

std::vector<std::pair<Point, long long>> convex(
    std::vector<std::pair<Point, long long>> set) {
  using Pa = std::pair<Point, long long>;
  if (set.size() == 1) return {set[0]};
  auto comp = [&](Pa a, Pa b) {
    return (EQ(a.first.real(), b.first.real()))
               ? (a.first.imag() > b.first.imag())
               : (a.first.real() < b.first.real());
  };

  std::sort(set.begin(), set.end(), comp);

  long long n = set.size();

  std::vector<Pa> lower, upper;

  lower.push_back(set[0]);
  long long lowernow = 0;
  for (long long i = 1; i < n; i++) {
    while (lowernow > 0) {
      Point add = set[i].first - lower[lowernow].first;
      Point last = lower[lowernow - 1].first - lower[lowernow].first;
      if (0 < std::arg(last / add) && std::arg(last / add) < PI - EPS) {
        break;
      } else {
        lower.pop_back();
        lowernow--;
      }
    }
    if (i != n - 1) lower.push_back(set[i]);
    lowernow++;
  }

  upper.push_back(set[n - 1]);
  long long uppernow = 0;
  for (long long i = n - 2; i >= 0; i--) {
    while (uppernow > 0) {
      Point add = set[i].first - upper[uppernow].first;
      Point last = upper[uppernow - 1].first - upper[uppernow].first;
      if (0 < std::arg(last / add) && std::arg(last / add) < PI - EPS) {
        break;
      } else {
        upper.pop_back();
        uppernow--;
      }
    }
    if (i != 0) upper.push_back(set[i]);
    uppernow++;
  }

  lower.reserve(lowernow + uppernow);
  std::copy(upper.begin(), upper.end(), std::back_inserter(lower));
  return lower;
}