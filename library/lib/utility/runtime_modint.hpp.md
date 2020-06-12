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


# :heavy_check_mark: lib/utility/runtime_modint.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a6e10e9711dc4788c3e9e6f87d9357db">lib/utility</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/utility/runtime_modint.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-12 12:00:09+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/DynamicMatrix.test.cpp.html">test/DynamicMatrix.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/utility/runtime_modint.hpp"
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

