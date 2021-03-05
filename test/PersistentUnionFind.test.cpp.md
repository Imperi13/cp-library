---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/PersistentArray.hpp
    title: lib/PersistentArray.hpp
  - icon: ':heavy_check_mark:'
    path: lib/UnionFind/PersistentUnionFind.hpp
    title: lib/UnionFind/PersistentUnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/PersistentUnionFind.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n#include <iostream>\n\
    #include <algorithm>\n#include <vector>\n\n#line 2 \"lib/UnionFind/PersistentUnionFind.hpp\"\
    \n\n#line 2 \"lib/PersistentArray.hpp\"\n\n#include <cassert>\n#include <memory>\n\
    \ntemplate <typename T, std::size_t BITSIZE = 4>\nclass PersistentArray {\n public:\n\
    \  using value_t = T;\n  using size_t = std::size_t;\n\n private:\n  struct Node\
    \ {\n    value_t val;\n    std::array<std::shared_ptr<Node>, 1 << BITSIZE> ch;\n\
    \    Node(value_t val_) : val(val_) { ch.fill(nullptr); }\n  };\n  using node_ptr\
    \ = std::shared_ptr<Node>;\n\n  value_t init;\n  node_ptr root;\n\n  node_ptr\
    \ update(size_t k, value_t value, node_ptr now) {\n    node_ptr ret =\n      \
    \  (now ? std::make_shared<Node>(*now) : std::make_shared<Node>(init));\n    if\
    \ (k == 0)\n      ret->val = value;\n    else {\n      size_t mask = (1 << BITSIZE)\
    \ - 1;\n      ret->ch[k & mask] = update(k >> BITSIZE, value, ret->ch[k & mask]);\n\
    \    }\n    return ret;\n  }\n\n  value_t at(size_t k, node_ptr now) {\n    if\
    \ (!now) return init;\n    if (k == 0) return now->val;\n    return at(k >> BITSIZE,\
    \ now->ch[k & ((1 << BITSIZE) - 1)]);\n  }\n\n  PersistentArray(value_t init_,\
    \ const node_ptr& root_)\n      : init(init_), root(root_) {}\n\n public:\n  PersistentArray(value_t\
    \ init_ = value_t()) : init(init_), root(nullptr) {}\n\n  PersistentArray update(size_t\
    \ k, const value_t& value) {\n    return PersistentArray(init, update(k, value,\
    \ root));\n  }\n\n  value_t operator[](size_t k) { return at(k, root); }\n};\n\
    #line 4 \"lib/UnionFind/PersistentUnionFind.hpp\"\n\nclass PersistentUnionFind\
    \ {\n public:\n  using size_t = std::size_t;\n\n private:\n  PersistentArray<long\
    \ long> uni;\n  size_t group;\n\n  PersistentUnionFind(PersistentArray<long long>\
    \ uni_, size_t group_)\n      : uni(uni_), group(group_) {}\n\n public:\n  PersistentUnionFind(size_t\
    \ n = 0) : uni(-1), group(n) {}\n\n  size_t root(size_t a) {\n    if (uni[a] <\
    \ 0) return a;\n    size_t tmp = root(uni[a]);\n    uni = uni.update(a, tmp);\n\
    \    return tmp;\n  }\n\n  PersistentUnionFind unite(size_t a, size_t b) {\n \
    \   a = root(a);\n    b = root(b);\n    if (a == b) return *this;\n    group--;\n\
    \    if (uni[a] > uni[b]) std::swap(a, b);\n\n    PersistentArray<long long> newuni\
    \ = uni;\n    long long va = uni[a], vb = uni[b];\n    newuni = newuni.update(a,\
    \ va + vb);\n    newuni = newuni.update(b, a);\n    return PersistentUnionFind(newuni,\
    \ group);\n  }\n\n  bool isconnect(size_t a, size_t b) { return root(a) == root(b);\
    \ }\n  size_t group_size(size_t a) { return -uni[root(a)]; }\n  size_t groups()\
    \ { return group; }\n};\n#line 8 \"test/PersistentUnionFind.test.cpp\"\n\n#define\
    \ rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)\n#define all(a) a.begin(),a.end()\n\
    \nusing ll=long long;\n\nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  ll n,q;\n  std::cin>>n>>q;\n\n  PersistentUnionFind base(n);\n  std::vector<PersistentUnionFind>\
    \ G(q);\n\n  rep(i,0,q){\n    ll t,k,u,v;\n    std::cin>>t>>k>>u>>v;\n    if(t==0){\n\
    \      if(k==-1)G[i]=base.unite(u,v);\n      else G[i]=G[k].unite(u,v);\n    }else{\n\
    \      if(k==-1)std::cout<<base.isconnect(u,v)<<\"\\n\";\n      else std::cout<<G[k].isconnect(u,v)<<\"\
    \\n\";\n    }\n  }\n\n  return 0; \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include <iostream>\n#include <algorithm>\n#include <vector>\n\n#include \"\
    ../lib/UnionFind/PersistentUnionFind.hpp\"\n\n#define rep(i, a, b) for (long long\
    \ i = (a); (i) < (b); (i)++)\n#define all(a) a.begin(),a.end()\n\nusing ll=long\
    \ long;\n\nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  ll n,q;\n  std::cin>>n>>q;\n\n  PersistentUnionFind base(n);\n  std::vector<PersistentUnionFind>\
    \ G(q);\n\n  rep(i,0,q){\n    ll t,k,u,v;\n    std::cin>>t>>k>>u>>v;\n    if(t==0){\n\
    \      if(k==-1)G[i]=base.unite(u,v);\n      else G[i]=G[k].unite(u,v);\n    }else{\n\
    \      if(k==-1)std::cout<<base.isconnect(u,v)<<\"\\n\";\n      else std::cout<<G[k].isconnect(u,v)<<\"\
    \\n\";\n    }\n  }\n\n  return 0; \n}"
  dependsOn:
  - lib/UnionFind/PersistentUnionFind.hpp
  - lib/PersistentArray.hpp
  isVerificationFile: true
  path: test/PersistentUnionFind.test.cpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/PersistentUnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/PersistentUnionFind.test.cpp
- /verify/test/PersistentUnionFind.test.cpp.html
title: test/PersistentUnionFind.test.cpp
---
