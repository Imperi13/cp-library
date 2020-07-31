#pragma once

#include <cassert>

template <typename Semigroup>
class OptionalMonoid {
 private:
  using base_t = typename Semigroup::value_t;

 public:
  using value_t = std::pair<base_t, bool>;
  constexpr static value_t id = {base_t(), false};
  constexpr static value_t op(value_t a, value_t b) {
    if (a.second && b.second) return {Semigroup::op(a.first, b.first), true};
    if (a.second || b.second) return a.second ? a : b;
    return id;
  }
};

template <typename Monoid>
struct ReverseMonoid {
  using value_t = typename Monoid::value_t;
  static constexpr value_t id = Monoid::id;
  static constexpr value_t op(value_t a, value_t b) { return Monoid::op(b, a); }
};