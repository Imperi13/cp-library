---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/SegmentTree/SegmentTree.hpp
    title: lib/SegmentTree/SegmentTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/SegmentTree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <iostream>\n\n#line 2 \"lib/SegmentTree/SegmentTree.hpp\"\n\n#include\
    \ <cassert>\n#include <vector>\n\n// Monoid\n// type value_t\n// static value_t\
    \ id\n// static (value_t,value_t)->value_t op\n\ntemplate <typename Monoid>\n\
    class SegmentTree {\n public:\n  using value_t = typename Monoid::value_t;\n \
    \ using size_t = std::size_t;\n\n private:\n  size_t n, n0;\n  std::vector<value_t>\
    \ dat;\n\n public:\n  SegmentTree(size_t n_) : n(n_) {\n    assert(n_ > 0);\n\
    \    n0 = 1;\n    while (n0 < n) n0 <<= 1;\n    dat = std::vector<value_t>(2 *\
    \ n0 - 1, Monoid::id);\n  }\n\n  SegmentTree(const std::vector<value_t>& tmp)\
    \ : n(tmp.size()) {\n    assert(n > 0);\n    n0 = 1;\n    while (n0 < n) n0 <<=\
    \ 1;\n    dat = std::vector<value_t>(2 * n0 - 1, Monoid::id);\n    for (size_t\
    \ i = 0; i < n; i++) dat[i + n0 - 1] = tmp[i];\n    for (long long i = n0 - 2;\
    \ i >= 0; i--)\n      dat[i] = Monoid::op(dat[2 * i + 1], dat[2 * i + 2]);\n \
    \ }\n\n  void update(size_t i, value_t val, bool change) {\n    assert(0 <= i\
    \ && i < n);\n    std::size_t now = i + n0 - 1;\n    if (change)\n      dat[now]\
    \ = val;\n    else\n      dat[now] = Monoid::op(dat[now], val);\n\n    while (now\
    \ > 0) {\n      now = (now - 1) >> 1;\n      dat[now] = Monoid::op(dat[2 * now\
    \ + 1], dat[2 * now + 2]);\n    }\n  }\n\n  value_t fold(size_t a, size_t b) {\n\
    \    assert(0 <= a && a <= b && b <= n);\n    value_t rval = Monoid::id, lval\
    \ = Monoid::id;\n    size_t l = a + n0 - 1, r = b + n0 - 1;\n    for (; l < r;\
    \ l >>= 1, r >>= 1) {\n      if (!(r & 1)) {\n        r--;\n        rval = Monoid::op(dat[r],\
    \ rval);\n      }\n      if (!(l & 1)) {\n        lval = Monoid::op(lval, dat[l]);\n\
    \        l++;\n      }\n    }\n\n    return Monoid::op(lval, rval);\n  }\n};\n\
    #line 6 \"test/SegmentTree.test.cpp\"\n\nconstexpr long long MOD=998244353;\n\n\
    struct Monoid{\n  using value_t=std::pair<long long,long long>;\n  static constexpr\
    \ value_t id={1,0};\n  static constexpr value_t op(value_t a,value_t b){\n   \
    \ return {a.first*b.first%MOD,(a.second*b.first%MOD + b.second)%MOD};\n  }\n};\n\
    \nusing ll=long long;\nusing P=std::pair<ll,ll>;\n\nint main(){\n  std::cin.tie(nullptr);\n\
    \  std::ios::sync_with_stdio(false);\n  ll n,q;\n  std::cin>>n>>q;\n\n  std::vector<P>\
    \ tmp(n);\n  for(auto&& e:tmp)std::cin>>e.first>>e.second;\n\n  SegmentTree<Monoid>\
    \ seg(tmp);\n\n  for(ll i=0;i<q;i++){\n    ll mode;\n    std::cin>>mode;\n   \
    \ if(mode==0){\n      ll p,c,d;\n      std::cin>>p>>c>>d;\n      seg.update(p,{c,d},true);\n\
    \    }else{\n      ll l,r,x;\n      std::cin>>l>>r>>x;\n      P fold=seg.fold(l,r);\n\
    \      std::cout<<(fold.first*x%MOD+fold.second)%MOD<<\"\\n\";\n    }\n  }\n\n\
    \  return 0; \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <iostream>\n\n#include \"../lib/SegmentTree/SegmentTree.hpp\"\n\n\
    constexpr long long MOD=998244353;\n\nstruct Monoid{\n  using value_t=std::pair<long\
    \ long,long long>;\n  static constexpr value_t id={1,0};\n  static constexpr value_t\
    \ op(value_t a,value_t b){\n    return {a.first*b.first%MOD,(a.second*b.first%MOD\
    \ + b.second)%MOD};\n  }\n};\n\nusing ll=long long;\nusing P=std::pair<ll,ll>;\n\
    \nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \  ll n,q;\n  std::cin>>n>>q;\n\n  std::vector<P> tmp(n);\n  for(auto&& e:tmp)std::cin>>e.first>>e.second;\n\
    \n  SegmentTree<Monoid> seg(tmp);\n\n  for(ll i=0;i<q;i++){\n    ll mode;\n  \
    \  std::cin>>mode;\n    if(mode==0){\n      ll p,c,d;\n      std::cin>>p>>c>>d;\n\
    \      seg.update(p,{c,d},true);\n    }else{\n      ll l,r,x;\n      std::cin>>l>>r>>x;\n\
    \      P fold=seg.fold(l,r);\n      std::cout<<(fold.first*x%MOD+fold.second)%MOD<<\"\
    \\n\";\n    }\n  }\n\n  return 0; \n}"
  dependsOn:
  - lib/SegmentTree/SegmentTree.hpp
  isVerificationFile: true
  path: test/SegmentTree.test.cpp
  requiredBy: []
  timestamp: '2020-12-19 20:24:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/SegmentTree.test.cpp
layout: document
redirect_from:
- /verify/test/SegmentTree.test.cpp
- /verify/test/SegmentTree.test.cpp.html
title: test/SegmentTree.test.cpp
---
