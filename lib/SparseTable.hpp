#pragma once

#include <cassert>
#include <vector>

// Semigroup
// type value_t
// static (value_t ,value_t)->value_t op

// a op a == a

template <typename Semigroup>
class SparseTable {
 public:
  using value_t = typename Semigroup::value_t;
  using size_t = std::size_t;

 private:
  size_t n;
  std::vector<size_t> ln;
  std::vector<std::vector<value_t>> table;

 public:
  SparseTable(const std::vector<value_t>& a) : n(a.size()), ln(n + 1, 0) {
    for (size_t i = 1; i < n + 1; i++)
      ln[i] = ln[i - 1] + (i >= (1ull << (ln[i - 1] + 1)));
    table = std::vector<std::vector<value_t>>(
        ln[n] + 1, std::vector<value_t>(n, value_t()));
    for (size_t i = 0; i < n; i++) table[0][i] = a[i];
    for (size_t j = 1; j < ln[n] + 1; j++) {
      for (size_t i = 0; i < n; i++) {
        if (i + (1ll << j) > n)
          table[j][i] = value_t();
        else
          table[j][i] = Semigroup::op(table[j - 1][i],
                                      table[j - 1][i + (1ll << (j - 1))]);
      }
    }
  }

  value_t fold(size_t l, size_t r) {
    assert(0 <= l && l < r && r <= n);
    size_t m = r - l;
    return Semigroup::op(table[ln[m]][l], table[ln[m]][r - (1ll << ln[m])]);
  }
};