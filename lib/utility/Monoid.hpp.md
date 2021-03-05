---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/utility/Monoid.hpp\"\n\n#include <cassert>\n\ntemplate\
    \ <typename Semigroup>\nclass OptionalMonoid {\n private:\n  using base_t = typename\
    \ Semigroup::value_t;\n\n public:\n  using value_t = std::pair<base_t, bool>;\n\
    \  constexpr static value_t id = {base_t(), false};\n  constexpr static value_t\
    \ op(value_t a, value_t b) {\n    if (a.second && b.second) return {Semigroup::op(a.first,\
    \ b.first), true};\n    if (a.second || b.second) return a.second ? a : b;\n \
    \   return id;\n  }\n};\n\ntemplate <typename Monoid>\nstruct ReverseMonoid {\n\
    \  using value_t = typename Monoid::value_t;\n  static constexpr value_t id =\
    \ Monoid::id;\n  static constexpr value_t op(value_t a, value_t b) { return Monoid::op(b,\
    \ a); }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n\ntemplate <typename Semigroup>\nclass\
    \ OptionalMonoid {\n private:\n  using base_t = typename Semigroup::value_t;\n\
    \n public:\n  using value_t = std::pair<base_t, bool>;\n  constexpr static value_t\
    \ id = {base_t(), false};\n  constexpr static value_t op(value_t a, value_t b)\
    \ {\n    if (a.second && b.second) return {Semigroup::op(a.first, b.first), true};\n\
    \    if (a.second || b.second) return a.second ? a : b;\n    return id;\n  }\n\
    };\n\ntemplate <typename Monoid>\nstruct ReverseMonoid {\n  using value_t = typename\
    \ Monoid::value_t;\n  static constexpr value_t id = Monoid::id;\n  static constexpr\
    \ value_t op(value_t a, value_t b) { return Monoid::op(b, a); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/utility/Monoid.hpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/utility/Monoid.hpp
layout: document
redirect_from:
- /library/lib/utility/Monoid.hpp
- /library/lib/utility/Monoid.hpp.html
title: lib/utility/Monoid.hpp
---
