#pragma once

#include <cassert>
#include <vector>

template <typename Semigroup>
class DisjointSparseTable {
 public:
  using value_t = typename Semigroup::value_t;
  using size_t = std::size_t;

 private:
  size_t n, n0;
  std::vector<size_t> ln;
  std::vector<std::vector<value_t>> table;

 public:
  DisjointSparseTable(const std::vector<value_t>& a) : n(a.size()) {
    n0 = 1;
    while (n0 < n) n0 <<= 1;
    ln = std::vector<size_t>(n0 + 1, 0);
    for (size_t i = 1; i < n0 + 1; i++)
      ln[i] = ln[i - 1] + (i >= (1ull << (ln[i - 1] + 1)));
    table = std::vector<std::vector<value_t>>(ln[n0] + 1, a);
    for (size_t i = 1; i < ln[n0] + 1; i++) {
      for (long long j = 1ll << (i - 1); j < n; j += 1ll << i) {
        for (long long k = j - 2; k >= j - (1ll << (i - 1)); k--)
          table[i][k] = Semigroup::op(a[k], table[i][k + 1]);
        for (long long k = j + 1;
             k < std::min(j + (1ll << (i - 1)), (long long)n); k++)
          table[i][k] = Semigroup::op(table[i][k - 1], a[k]);
      }
    }
  }

  value_t fold(size_t l, size_t r) {
    assert(0 <= l && l < r && r <= n);
    if (r == l + 1) return table[0][l];
    size_t m = ln[l ^ (r - 1)];
    return Semigroup::op(table[m + 1][l], table[m + 1][r - 1]);
  }
};