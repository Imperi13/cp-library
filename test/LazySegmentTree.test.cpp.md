---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/SegmentTree/LazySegmentTree.hpp
    title: lib/SegmentTree/LazySegmentTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/LazySegmentTree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"lib/SegmentTree/LazySegmentTree.hpp\"\
    \n\n#include <cassert>\n#line 5 \"lib/SegmentTree/LazySegmentTree.hpp\"\n\n//\
    \ Lazy\n// type value_t\n// type lazy_t\n// static value_t id_val\n// static value_t\
    \ id_lazy\n// static (value_t,value_t) -> value_t f\n// static (value_t,lazy_t)\
    \ -> value_t g\n// static (lazy_t,lazy_t) -> lazy_t h\n// static (lazy_t,size_t)\
    \ -> lazy_t p\n\n/* Lazy template\n\nstruct Lazy{\n  using value_t= ~~ ;\n  using\
    \ lazy_t= ~~ ;\n  static constexpr value_t id_val= ~~ ;\n  static constexpr lazy_t\
    \ id_lazy= ~~ ;\n  static value_t f(value_t a,value_t b){\n    return ~~ ;\n \
    \ }\n  static value_t g(value_t a,lazy_t b){\n    return ~~ ;\n  }\n  static lazy_t\
    \ h(lazy_t a,lazy_t b){\n    return ~~ ;\n  }\n  static lazy_t p(lazy_t a,std::size_t\
    \ n){\n    return ~~ ;\n  }\n};\n\n*/\n\ntemplate <typename Lazy>\nclass LazySegmentTree\
    \ {\n public:\n  using value_t = typename Lazy::value_t;\n  using lazy_t = typename\
    \ Lazy::lazy_t;\n  using size_t = std::size_t;\n\n private:\n  size_t n, n0;\n\
    \  std::vector<value_t> val;\n  std::vector<lazy_t> lazy;\n\n  value_t update(size_t\
    \ a, size_t b, lazy_t laz, size_t l, size_t r, size_t k) {\n    if (lazy[k] !=\
    \ Lazy::id_lazy) {\n      if (k < n0 - 1) {\n        lazy[2 * k + 1] = Lazy::h(lazy[2\
    \ * k + 1], lazy[k]);\n        lazy[2 * k + 2] = Lazy::h(lazy[2 * k + 2], lazy[k]);\n\
    \      }\n      val[k] = Lazy::g(val[k], Lazy::p(lazy[k], r - l));\n      lazy[k]\
    \ = Lazy::id_lazy;\n    }\n\n    if (r <= a || b <= l) return val[k];\n    if\
    \ (a <= l && r <= b) {\n      lazy[k] = Lazy::h(lazy[k], laz);\n      return Lazy::g(val[k],\
    \ Lazy::p(lazy[k], r - l));\n    }\n    return val[k] = Lazy::f(update(a, b, laz,\
    \ l, l + (r - l) / 2, 2 * k + 1),\n                            update(a, b, laz,\
    \ l + (r - l) / 2, r, 2 * k + 2));\n  }\n\n  value_t fold(size_t a, size_t b,\
    \ size_t l, size_t r, size_t k) {\n    if (lazy[k] != Lazy::id_lazy) {\n     \
    \ if (k < n0 - 1) {\n        lazy[2 * k + 1] = Lazy::h(lazy[2 * k + 1], lazy[k]);\n\
    \        lazy[2 * k + 2] = Lazy::h(lazy[2 * k + 2], lazy[k]);\n      }\n     \
    \ val[k] = Lazy::g(val[k], Lazy::p(lazy[k], r - l));\n      lazy[k] = Lazy::id_lazy;\n\
    \    }\n\n    if (r <= a || b <= l) return Lazy::id_val;\n    if (a <= l && r\
    \ <= b) return val[k];\n    return Lazy::f(fold(a, b, l, l + (r - l) / 2, 2 *\
    \ k + 1),\n                   fold(a, b, l + (r - l) / 2, r, 2 * k + 2));\n  }\n\
    \n  inline size_t beki(size_t n_) {\n    size_t ret = 1;\n    while (ret < n_)\
    \ ret <<= 1;\n    return ret;\n  }\n\n public:\n  LazySegmentTree(size_t n_)\n\
    \      : n(n_),\n        n0(beki(n)),\n        val(2 * n0 - 1, Lazy::id_val),\n\
    \        lazy(2 * n0 - 1, Lazy::id_lazy) {}\n\n  LazySegmentTree(std::vector<value_t>\
    \ val_)\n      : n(val_.size()),\n        n0(beki(n)),\n        val(2 * n0 - 1,\
    \ Lazy::id_val),\n        lazy(2 * n0 - 1, Lazy::id_lazy) {\n    for (size_t i\
    \ = 0; i < n; i++) val[i + n0 - 1] = val_[i];\n    for (long long i = n0 - 2;\
    \ i >= 0; i--)\n      val[i] = Lazy::f(val[2 * i + 1], val[2 * i + 2]);\n  }\n\
    \n  void update(size_t a, size_t b, lazy_t laz) { update(a, b, laz, 0, n0, 0);\
    \ }\n\n  value_t fold(size_t a, size_t b) { return fold(a, b, 0, n0, 0); }\n};\n\
    #line 7 \"test/LazySegmentTree.test.cpp\"\n\n/* template start */\n \n#define\
    \ rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)\n#define all(i) i.begin(),\
    \ i.end()\n\nusing ll=long long;\n\nconstexpr ll MOD=998244353;\n\nstruct Lazy{\n\
    \  using value_t=std::pair<ll,ll>;\n  using lazy_t=std::pair<ll,ll>;\n  static\
    \ constexpr value_t id_val={0,1};\n  static constexpr lazy_t id_lazy={1,0};\n\
    \  static value_t f(value_t a,value_t b){\n    return {(a.first+b.first)%MOD,(a.second+b.second)%MOD};\n\
    \  }\n  static value_t g(value_t a,lazy_t b){\n    return {(a.first*b.first%MOD+a.second*b.second%MOD)%MOD,a.second};\n\
    \  }\n  static lazy_t h(lazy_t a,lazy_t b){\n    return {b.first*a.first%MOD,(b.first*a.second%MOD+b.second)%MOD};\n\
    \  }\n  static lazy_t p(lazy_t a,std::size_t n){\n    return a;\n  }\n};\n\nint\
    \ main() {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\n\
    \  ll n,q;\n  std::cin>>n>>q;\n\n  std::vector<std::pair<ll,ll>> a(n,{0,1});\n\
    \  for(auto&& e:a)std::cin>>e.first;\n\n  LazySegmentTree<Lazy> seg(a);\n\n  while(q--){\n\
    \    ll mode;\n    std::cin>>mode;\n    if(mode==0){\n      ll l,r,b,c;\n    \
    \  std::cin>>l>>r>>b>>c;\n      seg.update(l,r,{b,c});\n    }else{\n      ll l,r;\n\
    \      std::cin>>l>>r;\n      std::cout<<seg.fold(l,r).first<<\"\\n\";\n    }\n\
    \  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../lib/SegmentTree/LazySegmentTree.hpp\"\
    \n\n/* template start */\n \n#define rep(i, a, b) for (long long i = (a); (i)\
    \ < (b); (i)++)\n#define all(i) i.begin(), i.end()\n\nusing ll=long long;\n\n\
    constexpr ll MOD=998244353;\n\nstruct Lazy{\n  using value_t=std::pair<ll,ll>;\n\
    \  using lazy_t=std::pair<ll,ll>;\n  static constexpr value_t id_val={0,1};\n\
    \  static constexpr lazy_t id_lazy={1,0};\n  static value_t f(value_t a,value_t\
    \ b){\n    return {(a.first+b.first)%MOD,(a.second+b.second)%MOD};\n  }\n  static\
    \ value_t g(value_t a,lazy_t b){\n    return {(a.first*b.first%MOD+a.second*b.second%MOD)%MOD,a.second};\n\
    \  }\n  static lazy_t h(lazy_t a,lazy_t b){\n    return {b.first*a.first%MOD,(b.first*a.second%MOD+b.second)%MOD};\n\
    \  }\n  static lazy_t p(lazy_t a,std::size_t n){\n    return a;\n  }\n};\n\nint\
    \ main() {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\n\
    \  ll n,q;\n  std::cin>>n>>q;\n\n  std::vector<std::pair<ll,ll>> a(n,{0,1});\n\
    \  for(auto&& e:a)std::cin>>e.first;\n\n  LazySegmentTree<Lazy> seg(a);\n\n  while(q--){\n\
    \    ll mode;\n    std::cin>>mode;\n    if(mode==0){\n      ll l,r,b,c;\n    \
    \  std::cin>>l>>r>>b>>c;\n      seg.update(l,r,{b,c});\n    }else{\n      ll l,r;\n\
    \      std::cin>>l>>r;\n      std::cout<<seg.fold(l,r).first<<\"\\n\";\n    }\n\
    \  }\n\n  return 0;\n}"
  dependsOn:
  - lib/SegmentTree/LazySegmentTree.hpp
  isVerificationFile: true
  path: test/LazySegmentTree.test.cpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LazySegmentTree.test.cpp
layout: document
redirect_from:
- /verify/test/LazySegmentTree.test.cpp
- /verify/test/LazySegmentTree.test.cpp.html
title: test/LazySegmentTree.test.cpp
---
