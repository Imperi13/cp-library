---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/UnionFind/PotentialUnionFind.hpp
    title: lib/UnionFind/PotentialUnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "#line 1 \"test/PotentialUnionFind.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cstdint>\n#include <cstdlib>\n#include <cmath>\n\
    #include <complex>\n#include <chrono>\n#include <deque>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <map>\n#include <memory>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <vector>\n#include <random>\n#include <utility>\n\
    #include <limits>\n#include <list>\n#line 31 \"test/PotentialUnionFind.test.cpp\"\
    \n\n/* template start */\n \n#define rep(i, a, b) for (long long i = (a); (i)\
    \ < (b); (i)++)\n#define all(i) i.begin(), i.end()\n\nusing ll=long long;\n\n\
    #line 2 \"lib/UnionFind/PotentialUnionFind.hpp\"\n\n#line 6 \"lib/UnionFind/PotentialUnionFind.hpp\"\
    \n\ntemplate <typename Group>\nclass PotentialUnionFind {\n public:\n  using value_t\
    \ = typename Group::value_t;\n  using size_t = std::size_t;\n\n private:\n  size_t\
    \ group;\n  std::vector<size_t> par, sz;\n  std::vector<value_t> df;  // val[par]=val[x]+df[x]\n\
    \n  value_t fold_to_root(size_t x) {\n    value_t ret = Group::id;\n    while\
    \ (par[x] != x) {\n      df[x] = Group::op(df[x], df[par[x]]);\n      par[x] =\
    \ par[par[x]];\n      ret = Group::op(ret, df[x]);\n      x = par[x];\n    }\n\
    \    return ret;\n  }\n\n public:\n  PotentialUnionFind(size_t n = 0)\n      :\
    \ group(n), par(n), sz(n, 1), df(n, Group::id) {\n    std::iota(par.begin(), par.end(),\
    \ 0);\n  }\n\n  size_t root(size_t x) {\n    while (par[x] != x) {\n      df[x]\
    \ = Group::op(df[x], df[par[x]]);\n      par[x] = par[par[x]];\n      x = par[x];\n\
    \    }\n    return x;\n  }\n\n  bool same(size_t a, size_t b) { return root(a)\
    \ == root(b); }\n  size_t size() { return par.size(); }\n  size_t groups() { return\
    \ group; }\n  size_t group_size(size_t x) { return sz[root(x)]; }\n\n  // unite\
    \ A=B+value\n  bool unite(size_t a, size_t b, value_t value) {\n    size_t aroot\
    \ = root(a), broot = root(b);\n    if (aroot == broot) return false;\n    group--;\n\
    \    if (sz[aroot] < sz[broot]) {\n      std::swap(aroot, broot);\n      std::swap(a,\
    \ b);\n      value = Group::inv(value);\n    }\n    sz[aroot] += sz[broot];\n\
    \    value = Group::op(value, fold_to_root(a));\n    value = Group::op(Group::inv(fold_to_root(b)),\
    \ value);\n    df[broot] = value;\n    par[broot] = aroot;\n    return true;\n\
    \  }\n\n  // return diff  such as A=B+diff\n  value_t diff(size_t a, size_t b)\
    \ {\n    assert(same(a, b));\n    return Group::op(fold_to_root(b), Group::inv(fold_to_root(a)));\n\
    \  }\n};\n#line 40 \"test/PotentialUnionFind.test.cpp\"\n\nstruct Group{\n  using\
    \ value_t=ll;\n  static constexpr value_t id=0;\n  static constexpr value_t op(value_t\
    \ a,value_t b){\n    return a+b;\n  }\n  static constexpr value_t inv(value_t\
    \ a){return -a;}\n};\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  ll n,q;\n  std::cin>>n>>q;\n\n  PotentialUnionFind<Group> uni(n);\n\n  while(q--){\n\
    \    ll mode;\n    std::cin>>mode;\n    if(mode==0){\n      ll x,y,z;\n      std::cin>>x>>y>>z;\n\
    \      if(!uni.same(x,y))uni.unite(y,x,z);\n    }else{\n      ll x,y;\n      std::cin>>x>>y;\n\
    \      if(!uni.same(x,y))std::cout<<\"?\\n\";\n      else std::cout<<uni.diff(y,x)<<\"\
    \\n\";\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cstdint>\n#include <cstdlib>\n#include <cmath>\n\
    #include <complex>\n#include <chrono>\n#include <deque>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <map>\n#include <memory>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <vector>\n#include <random>\n#include <utility>\n\
    #include <limits>\n#include <list>\n#include <cmath>\n\n/* template start */\n\
    \ \n#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)\n#define all(i)\
    \ i.begin(), i.end()\n\nusing ll=long long;\n\n#include \"../lib/UnionFind/PotentialUnionFind.hpp\"\
    \n\nstruct Group{\n  using value_t=ll;\n  static constexpr value_t id=0;\n  static\
    \ constexpr value_t op(value_t a,value_t b){\n    return a+b;\n  }\n  static constexpr\
    \ value_t inv(value_t a){return -a;}\n};\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios::sync_with_stdio(false);\n\n  ll n,q;\n  std::cin>>n>>q;\n\n  PotentialUnionFind<Group>\
    \ uni(n);\n\n  while(q--){\n    ll mode;\n    std::cin>>mode;\n    if(mode==0){\n\
    \      ll x,y,z;\n      std::cin>>x>>y>>z;\n      if(!uni.same(x,y))uni.unite(y,x,z);\n\
    \    }else{\n      ll x,y;\n      std::cin>>x>>y;\n      if(!uni.same(x,y))std::cout<<\"\
    ?\\n\";\n      else std::cout<<uni.diff(y,x)<<\"\\n\";\n    }\n  }\n\n  return\
    \ 0;\n}"
  dependsOn:
  - lib/UnionFind/PotentialUnionFind.hpp
  isVerificationFile: true
  path: test/PotentialUnionFind.test.cpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/PotentialUnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/PotentialUnionFind.test.cpp
- /verify/test/PotentialUnionFind.test.cpp.html
title: test/PotentialUnionFind.test.cpp
---
