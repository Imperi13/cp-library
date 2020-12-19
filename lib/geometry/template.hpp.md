---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lib/geometry/convex.hpp
    title: lib/geometry/convex.hpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/geometry/template.hpp\"\n\n#include <cmath>\n#include\
    \ <complex>\n#include <vector>\n\nusing Point = std::complex<long double>;\n\n\
    constexpr long double EPS = 1e-10;\nconst long double PI = std::acos(-1.0l);\n\
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
    \ 0)) ret.emplace_back(cp - abN);\n  return ret;\n}\n"
  code: "#pragma once\n\n#include <cmath>\n#include <complex>\n#include <vector>\n\
    \nusing Point = std::complex<long double>;\n\nconstexpr long double EPS = 1e-10;\n\
    const long double PI = std::acos(-1.0l);\n\nbool EQ(long double a, long double\
    \ b) { return std::abs(a - b) < EPS; }\nbool EQP(Point a, Point b) {\n  return\
    \ EQ(a.real(), b.real()) && EQ(a.imag(), b.imag());\n}\n\nPoint unitvec(Point\
    \ a) { return a / std::abs(a); }\n\n// dot a\u30FBb = |a||b|cos\u03B8\nlong double\
    \ dot(Point a, Point b) {\n  return a.real() * b.real() + a.imag() * b.imag();\n\
    }\n\n// cross a\xD7b = |a||b|sin\u03B8\nlong double cross(Point a, Point b) {\n\
    \  return a.real() * b.imag() - a.imag() * b.real();\n}\n\nbool on_line(Point\
    \ a, Point b, Point c) {\n  return EQ(cross(c - a, b - a), 0.0l);\n}\n\nbool on_segment(Point\
    \ a, Point b, Point c) {\n  return std::abs(c - a) + std::abs(b - c) < std::abs(b\
    \ - a) + EPS;\n}\n\nbool is_intersected_ls(Point a1, Point a2, Point b1, Point\
    \ b2) {\n  return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&\n   \
    \      ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );\n}\n\nstd::vector<Point>\
    \ crosspointCC(Point a, long double ra, Point b,\n                           \
    \     long double rb) {\n  std::vector<Point> ret;\n  Point ab = b - a;\n  long\
    \ double d = std::abs(ab);\n  long double crL = (std::norm(ab) + ra * ra - rb\
    \ * rb) / (2 * d);\n  if (EQ(d, 0) || ra < std::abs(crL)) return ret;\n  Point\
    \ abN = ab * Point(0, std::sqrt(ra * ra - crL * crL) / d);\n  Point cp = a + crL\
    \ / d * ab;\n  ret.emplace_back(cp + abN);\n  if (!EQ(std::abs(abN), 0)) ret.emplace_back(cp\
    \ - abN);\n  return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/geometry/template.hpp
  requiredBy:
  - lib/geometry/convex.hpp
  timestamp: '2020-12-19 20:24:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/geometry/template.hpp
layout: document
redirect_from:
- /library/lib/geometry/template.hpp
- /library/lib/geometry/template.hpp.html
title: lib/geometry/template.hpp
---
