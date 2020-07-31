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