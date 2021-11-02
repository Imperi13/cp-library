#pragma once

/*
  author:noshi91
  reference:https://noshi91.hatenablog.com/entry/2019/03/31/174006
            https://github.com/noshi91/Library/blob/master/other/modint.cpp

  1つめのmodintにoperator==,!=を追加したものです

  thx @noshi91!!
*/

#include <cstdint>
#include <iostream>
#include "./type_alias.hpp"

template <u64 Modulus>
class modint {

 public:
  constexpr static u64 mod = Modulus;
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr bool operator==(const modint rhs) const noexcept {
    return a == rhs.a;
  }
  constexpr bool operator!=(const modint rhs) const noexcept {
    return !(*this == rhs);
  }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};

template <u64 MOD>
std::ostream& operator<<(std::ostream& os, modint<MOD> a) {
  return os << a.value();
}