---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/geometry/template.hpp
    title: lib/geometry/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/geometry/convex.hpp\"\n\n#include <algorithm>\n#include\
    \ <vector>\n\n#line 2 \"lib/geometry/template.hpp\"\n\n#include <cmath>\n#include\
    \ <complex>\n#line 6 \"lib/geometry/template.hpp\"\n\nusing Point = std::complex<long\
    \ double>;\n\nconstexpr long double EPS = 1e-10;\nconst long double PI = std::acos(-1.0l);\n\
    \nbool EQ(long double a, long double b) { return std::abs(a - b) < EPS; }\nbool\
    \ EQP(Point a, Point b) {\n  return EQ(a.real(), b.real()) && EQ(a.imag(), b.imag());\n\
    }\n\nPoint unitvec(Point a) { return a / std::abs(a); }\n\n// dot a\u30FBb = |a||b|cos\u03B8\
    \nlong double dot(Point a, Point b) {\n  return a.real() * b.real() + a.imag()\
    \ * b.imag();\n}\n\n// cross a\xD7b = |a||b|sin\u03B8\nlong double cross(Point\
    \ a, Point b) {\n  return a.real() * b.imag() - a.imag() * b.real();\n}\n\nbool\
    \ on_line(Point a, Point b, Point c) {\n  return EQ(cross(c - a, b - a), 0.0l);\n\
    }\n\nbool on_segment(Point a, Point b, Point c) {\n  return std::abs(c - a) +\
    \ std::abs(b - c) < std::abs(b - a) + EPS;\n}\n\nbool is_intersected_ls(Point\
    \ a1, Point a2, Point b1, Point b2) {\n  return ( cross(a2-a1, b1-a1) * cross(a2-a1,\
    \ b2-a1) < EPS ) &&\n         ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS\
    \ );\n}\n\nstd::vector<Point> crosspointCC(Point a, long double ra, Point b,\n\
    \                                long double rb) {\n  std::vector<Point> ret;\n\
    \  Point ab = b - a;\n  long double d = std::abs(ab);\n  long double crL = (std::norm(ab)\
    \ + ra * ra - rb * rb) / (2 * d);\n  if (EQ(d, 0) || ra < std::abs(crL)) return\
    \ ret;\n  Point abN = ab * Point(0, std::sqrt(ra * ra - crL * crL) / d);\n  Point\
    \ cp = a + crL / d * ab;\n  ret.emplace_back(cp + abN);\n  if (!EQ(std::abs(abN),\
    \ 0)) ret.emplace_back(cp - abN);\n  return ret;\n}\n#line 7 \"lib/geometry/convex.hpp\"\
    \n\nstd::vector<std::pair<Point, long long>> convex(\n    std::vector<std::pair<Point,\
    \ long long>> set) {\n  using Pa = std::pair<Point, long long>;\n  if (set.size()\
    \ == 1) return {set[0]};\n  auto comp = [&](Pa a, Pa b) {\n    return (EQ(a.first.real(),\
    \ b.first.real()))\n               ? (a.first.imag() > b.first.imag())\n     \
    \          : (a.first.real() < b.first.real());\n  };\n\n  std::sort(set.begin(),\
    \ set.end(), comp);\n\n  long long n = set.size();\n\n  std::vector<Pa> lower,\
    \ upper;\n\n  lower.push_back(set[0]);\n  long long lowernow = 0;\n  for (long\
    \ long i = 1; i < n; i++) {\n    while (lowernow > 0) {\n      Point add = set[i].first\
    \ - lower[lowernow].first;\n      Point last = lower[lowernow - 1].first - lower[lowernow].first;\n\
    \      if (0 < std::arg(last / add) && std::arg(last / add) < PI - EPS) {\n  \
    \      break;\n      } else {\n        lower.pop_back();\n        lowernow--;\n\
    \      }\n    }\n    if (i != n - 1) lower.push_back(set[i]);\n    lowernow++;\n\
    \  }\n\n  upper.push_back(set[n - 1]);\n  long long uppernow = 0;\n  for (long\
    \ long i = n - 2; i >= 0; i--) {\n    while (uppernow > 0) {\n      Point add\
    \ = set[i].first - upper[uppernow].first;\n      Point last = upper[uppernow -\
    \ 1].first - upper[uppernow].first;\n      if (0 < std::arg(last / add) && std::arg(last\
    \ / add) < PI - EPS) {\n        break;\n      } else {\n        upper.pop_back();\n\
    \        uppernow--;\n      }\n    }\n    if (i != 0) upper.push_back(set[i]);\n\
    \    uppernow++;\n  }\n\n  lower.reserve(lowernow + uppernow);\n  std::copy(upper.begin(),\
    \ upper.end(), std::back_inserter(lower));\n  return lower;\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\n#include \"./template.hpp\"\
    \n\nstd::vector<std::pair<Point, long long>> convex(\n    std::vector<std::pair<Point,\
    \ long long>> set) {\n  using Pa = std::pair<Point, long long>;\n  if (set.size()\
    \ == 1) return {set[0]};\n  auto comp = [&](Pa a, Pa b) {\n    return (EQ(a.first.real(),\
    \ b.first.real()))\n               ? (a.first.imag() > b.first.imag())\n     \
    \          : (a.first.real() < b.first.real());\n  };\n\n  std::sort(set.begin(),\
    \ set.end(), comp);\n\n  long long n = set.size();\n\n  std::vector<Pa> lower,\
    \ upper;\n\n  lower.push_back(set[0]);\n  long long lowernow = 0;\n  for (long\
    \ long i = 1; i < n; i++) {\n    while (lowernow > 0) {\n      Point add = set[i].first\
    \ - lower[lowernow].first;\n      Point last = lower[lowernow - 1].first - lower[lowernow].first;\n\
    \      if (0 < std::arg(last / add) && std::arg(last / add) < PI - EPS) {\n  \
    \      break;\n      } else {\n        lower.pop_back();\n        lowernow--;\n\
    \      }\n    }\n    if (i != n - 1) lower.push_back(set[i]);\n    lowernow++;\n\
    \  }\n\n  upper.push_back(set[n - 1]);\n  long long uppernow = 0;\n  for (long\
    \ long i = n - 2; i >= 0; i--) {\n    while (uppernow > 0) {\n      Point add\
    \ = set[i].first - upper[uppernow].first;\n      Point last = upper[uppernow -\
    \ 1].first - upper[uppernow].first;\n      if (0 < std::arg(last / add) && std::arg(last\
    \ / add) < PI - EPS) {\n        break;\n      } else {\n        upper.pop_back();\n\
    \        uppernow--;\n      }\n    }\n    if (i != 0) upper.push_back(set[i]);\n\
    \    uppernow++;\n  }\n\n  lower.reserve(lowernow + uppernow);\n  std::copy(upper.begin(),\
    \ upper.end(), std::back_inserter(lower));\n  return lower;\n}"
  dependsOn:
  - lib/geometry/template.hpp
  isVerificationFile: false
  path: lib/geometry/convex.hpp
  requiredBy: []
  timestamp: '2020-12-19 20:24:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/geometry/convex.hpp
layout: document
redirect_from:
- /library/lib/geometry/convex.hpp
- /library/lib/geometry/convex.hpp.html
title: lib/geometry/convex.hpp
---
