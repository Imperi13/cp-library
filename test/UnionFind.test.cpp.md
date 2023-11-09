---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/UnionFind/UnionFind.hpp
    title: lib/data_structure/UnionFind/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/UnionFind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#include <iostream>\n#line 2 \"lib/data_structure/UnionFind/UnionFind.hpp\"\
    \n\n#include <cstddef>\n#include <numeric>\n#include <vector>\n\nclass UnionFind\
    \ {\n public:\n  using size_t = std::size_t;\n\n private:\n  std::vector<size_t>\
    \ par, sz;\n  size_t group;\n\n public:\n  UnionFind(size_t n = 0) : par(n, 0),\
    \ sz(n, 1), group(n) {\n    std::iota(par.begin(), par.end(), 0);\n  }\n\n  size_t\
    \ root(size_t n) {\n    if (par[n] == n) return n;\n    return par[n] = root(par[n]);\n\
    \  }\n\n  bool unite(size_t a, size_t b) {\n    a = root(a);\n    b = root(b);\n\
    \    if (a == b) return false;\n    group--;\n    if (sz[a] < sz[b]) std::swap(a,\
    \ b);\n    sz[a] += sz[b];\n    par[b] = a;\n    return true;\n  }\n\n  size_t\
    \ size() { return par.size(); }\n  size_t groups() { return group; }\n  size_t\
    \ group_size(size_t n) { return sz[root(n)]; }\n\n  bool same(size_t a, size_t\
    \ b) { return root(a) == root(b); }\n};\n#line 5 \"test/UnionFind.test.cpp\"\n\
    \n#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)\n\nusing ll=long\
    \ long;\n\nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \  ll n,q;\n  std::cin>>n>>q;\n\n  UnionFind uni(n);\n\n  rep(i,0,q){\n    ll\
    \ t,u,v;\n    std::cin>>t>>u>>v;\n    if(t==0)uni.unite(u,v);\n    else std::cout<<(uni.same(u,v)?1:0)<<\"\
    \\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <iostream>\n#include \"../lib/data_structure/UnionFind/UnionFind.hpp\"\n\n#define\
    \ rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)\n\nusing ll=long long;\n\
    \nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \  ll n,q;\n  std::cin>>n>>q;\n\n  UnionFind uni(n);\n\n  rep(i,0,q){\n    ll\
    \ t,u,v;\n    std::cin>>t>>u>>v;\n    if(t==0)uni.unite(u,v);\n    else std::cout<<(uni.same(u,v)?1:0)<<\"\
    \\n\";\n  }\n}"
  dependsOn:
  - lib/data_structure/UnionFind/UnionFind.hpp
  isVerificationFile: true
  path: test/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2023-11-10 04:27:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/UnionFind.test.cpp
- /verify/test/UnionFind.test.cpp.html
title: test/UnionFind.test.cpp
---
