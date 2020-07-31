---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: lib/geometry/template.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7096d029078708cdbb96f2303d66dee8">lib/geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/geometry/template.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-31 15:44:20+09:00




## Required by

* :warning: <a href="convex.hpp.html">lib/geometry/convex.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <cmath>
#include <complex>
#include <vector>

using Point = std::complex<long double>;

constexpr long double EPS = 1e-10;
const long double PI = std::acos(-1.0l);

bool EQ(long double a, long double b) { return std::abs(a - b) < EPS; }
bool EQP(Point a, Point b) {
  return EQ(a.real(), b.real()) && EQ(a.imag(), b.imag());
}

Point unitvec(Point a) { return a / std::abs(a); }

// dot a・b = |a||b|cosθ
long double dot(Point a, Point b) {
  return a.real() * b.real() + a.imag() * b.imag();
}

// cross a×b = |a||b|sinθ
long double cross(Point a, Point b) {
  return a.real() * b.imag() - a.imag() * b.real();
}

bool on_line(Point a, Point b, Point c) {
  return EQ(cross(c - a, b - a), 0.0l);
}

bool on_segment(Point a, Point b, Point c) {
  return std::abs(c - a) + std::abs(b - c) < std::abs(b - a) + EPS;
}

std::vector<Point> crosspointCC(Point a, long double ra, Point b,
                                long double rb) {
  std::vector<Point> ret;
  Point ab = b - a;
  long double d = std::abs(ab);
  long double crL = (std::norm(ab) + ra * ra - rb * rb) / (2 * d);
  if (EQ(d, 0) || ra < std::abs(crL)) return ret;
  Point abN = ab * Point(0, std::sqrt(ra * ra - crL * crL) / d);
  Point cp = a + crL / d * ab;
  ret.emplace_back(cp + abN);
  if (!EQ(std::abs(abN), 0)) ret.emplace_back(cp - abN);
  return ret;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/geometry/template.hpp"

#include <cmath>
#include <complex>
#include <vector>

using Point = std::complex<long double>;

constexpr long double EPS = 1e-10;
const long double PI = std::acos(-1.0l);

bool EQ(long double a, long double b) { return std::abs(a - b) < EPS; }
bool EQP(Point a, Point b) {
  return EQ(a.real(), b.real()) && EQ(a.imag(), b.imag());
}

Point unitvec(Point a) { return a / std::abs(a); }

// dot a・b = |a||b|cosθ
long double dot(Point a, Point b) {
  return a.real() * b.real() + a.imag() * b.imag();
}

// cross a×b = |a||b|sinθ
long double cross(Point a, Point b) {
  return a.real() * b.imag() - a.imag() * b.real();
}

bool on_line(Point a, Point b, Point c) {
  return EQ(cross(c - a, b - a), 0.0l);
}

bool on_segment(Point a, Point b, Point c) {
  return std::abs(c - a) + std::abs(b - c) < std::abs(b - a) + EPS;
}

std::vector<Point> crosspointCC(Point a, long double ra, Point b,
                                long double rb) {
  std::vector<Point> ret;
  Point ab = b - a;
  long double d = std::abs(ab);
  long double crL = (std::norm(ab) + ra * ra - rb * rb) / (2 * d);
  if (EQ(d, 0) || ra < std::abs(crL)) return ret;
  Point abN = ab * Point(0, std::sqrt(ra * ra - crL * crL) / d);
  Point cp = a + crL / d * ab;
  ret.emplace_back(cp + abN);
  if (!EQ(std::abs(abN), 0)) ret.emplace_back(cp - abN);
  return ret;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

