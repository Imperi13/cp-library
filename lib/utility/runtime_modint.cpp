#include <cstdint>

class modint {
  using u64 = std::uint_fast64_t;

public:
  u64 a;
  static u64 Modulus;

  modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  u64 &value() noexcept { return a; }
  const u64 &value() const noexcept { return a; }
  bool operator==(const modint rhs) const noexcept {return a==rhs.a;}
  bool operator!=(const modint rhs) const noexcept {return !(*this==rhs);}
  modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  modint &operator/=(modint rhs) noexcept {
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