---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/LowestCommonAncestor.hpp
    title: lib/graph/LowestCommonAncestor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/LowestCommonAncestor.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/lca\"\n\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <cctype>\n#include <cstdint>\n\
    #include <cstdlib>\n#include <cmath>\n#include <complex>\n#include <chrono>\n\
    #include <deque>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <map>\n#include <memory>\n#include <numeric>\n#include <queue>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n#include\
    \ <unordered_map>\n#include <vector>\n#include <random>\n#include <utility>\n\
    #include <limits>\n#include <list>\n\n/* template start */\n \n#define rep(i,\
    \ a, b) for (long long i = (a); (i) < (b); (i)++)\n#define all(i) i.begin(), i.end()\n\
    \n#ifdef LOCAL\n#define debug(...) std::cerr << \"[\" << #__VA_ARGS__ << \"]:\"\
    , debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\nvoid debug_out(){std::cerr<<std::endl;}\n\
    \ntemplate<typename Head,typename... Tail>\nvoid debug_out(Head h,Tail... t){\n\
    \  std::cerr<<\" \"<<h;\n  if(sizeof...(t)>0)std::cout<<\" :\";\n  debug_out(t...);\n\
    }\n \ntemplate <typename T1, typename T2>\nstd::ostream& operator<<(std::ostream&\
    \ os, std::pair<T1, T2> pa) {\n  return os << pa.first << \" \" << pa.second;\n\
    }\n \ntemplate <typename T>\nstd::ostream& operator<<(std::ostream& os, std::vector<T>\
    \ vec) {\n  for (std::size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1\
    \ == vec.size() ? \"\" : \" \");\n  return os;\n}\n \ntemplate<typename T1,typename\
    \ T2>\ninline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}\n \ntemplate<typename\
    \ T1,typename T2>\ninline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}\n\n\
    template<typename Num>\nconstexpr Num mypow(Num a, unsigned long long b) {\n \
    \ if(b==0)return 1;\n  if (a==0)return 0;\n  Num x = 1;\n  while (b > 0) {\n \
    \   if(b & 1)x*=a;\n    a*=a;\n    b >>= 1;\n  }\n  return x;\n}\n\n/* template\
    \ end */\n\nusing ll = long long;\n\n#line 2 \"lib/graph/LowestCommonAncestor.hpp\"\
    \n\n#line 4 \"lib/graph/LowestCommonAncestor.hpp\"\n\nclass LowestCommonAncestor\
    \ {\n public:\n  using size_t = std::size_t;\n\n private:\n  size_t n, bit;\n\
    \  std::vector<size_t> depth;\n  std::vector<std::vector<size_t>> par_dbl;\n\n\
    \  size_t log(size_t tmp) {\n    size_t ret = 1;\n    while (tmp > 0) {\n    \
    \  ret++;\n      tmp >>= 1;\n    }\n    return ret;\n  }\n\n public:\n  template\
    \ <typename Edge>\n  LowestCommonAncestor(size_t root, const std::vector<std::vector<Edge>>&\
    \ graph)\n      : n(graph.size()),\n        bit(log(n)),\n        depth(n),\n\
    \        par_dbl(n, std::vector<size_t>(bit)) {\n    auto dfs = [&](auto f, size_t\
    \ now, size_t par, size_t dep) -> void {\n      depth[now] = dep;\n      if (dep\
    \ != 0)\n        par_dbl[now][0] = par;\n      else\n        par_dbl[now][0] =\
    \ now;\n\n      for (const auto& e : graph[now]) {\n        if (e != par) f(f,\
    \ e, now, dep + 1);\n      }\n    };\n    dfs(dfs, root, -1, 0);\n    for (size_t\
    \ i = 1; i < bit; i++) {\n      for (size_t j = 0; j < n; j++)\n        par_dbl[j][i]\
    \ = par_dbl[par_dbl[j][i - 1]][i - 1];\n    }\n  }\n\n  size_t lca(size_t a, size_t\
    \ b) {\n    if (depth[a] < depth[b]) std::swap(a, b);\n    for (size_t i = 0;\
    \ i < bit; i++) {\n      if (((depth[a] - depth[b]) >> i) & 1) a = par_dbl[a][i];\n\
    \    }\n    if (a == b) return a;\n    for (long long i = bit - 1; i >= 0; i--)\
    \ {\n      if (par_dbl[a][i] != par_dbl[b][i]) {\n        a = par_dbl[a][i];\n\
    \        b = par_dbl[b][i];\n      }\n    }\n    return par_dbl[a][0];\n  }\n\
    };\n#line 87 \"test/LowestCommonAncestor.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios::sync_with_stdio(false);\n\n  ll n,q;\n  std::cin>>n>>q;\n\n  std::vector<std::vector<std::size_t>>\
    \ graph(n);\n  rep(i,1,n){\n    ll p;\n    std::cin>>p;\n    graph[p].emplace_back(i);\n\
    \  }\n\n  LowestCommonAncestor lca(0,graph);\n\n  while(q--){\n    ll u,v;\n \
    \   std::cin>>u>>v;\n    std::cout<<lca.lca(u,v)<<\"\\n\";\n  }\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cctype>\n#include\
    \ <cstdint>\n#include <cstdlib>\n#include <cmath>\n#include <complex>\n#include\
    \ <chrono>\n#include <deque>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <map>\n#include <memory>\n#include <numeric>\n#include\
    \ <queue>\n#include <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <vector>\n#include <random>\n#include <utility>\n\
    #include <limits>\n#include <list>\n\n/* template start */\n \n#define rep(i,\
    \ a, b) for (long long i = (a); (i) < (b); (i)++)\n#define all(i) i.begin(), i.end()\n\
    \n#ifdef LOCAL\n#define debug(...) std::cerr << \"[\" << #__VA_ARGS__ << \"]:\"\
    , debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\nvoid debug_out(){std::cerr<<std::endl;}\n\
    \ntemplate<typename Head,typename... Tail>\nvoid debug_out(Head h,Tail... t){\n\
    \  std::cerr<<\" \"<<h;\n  if(sizeof...(t)>0)std::cout<<\" :\";\n  debug_out(t...);\n\
    }\n \ntemplate <typename T1, typename T2>\nstd::ostream& operator<<(std::ostream&\
    \ os, std::pair<T1, T2> pa) {\n  return os << pa.first << \" \" << pa.second;\n\
    }\n \ntemplate <typename T>\nstd::ostream& operator<<(std::ostream& os, std::vector<T>\
    \ vec) {\n  for (std::size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1\
    \ == vec.size() ? \"\" : \" \");\n  return os;\n}\n \ntemplate<typename T1,typename\
    \ T2>\ninline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}\n \ntemplate<typename\
    \ T1,typename T2>\ninline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}\n\n\
    template<typename Num>\nconstexpr Num mypow(Num a, unsigned long long b) {\n \
    \ if(b==0)return 1;\n  if (a==0)return 0;\n  Num x = 1;\n  while (b > 0) {\n \
    \   if(b & 1)x*=a;\n    a*=a;\n    b >>= 1;\n  }\n  return x;\n}\n\n/* template\
    \ end */\n\nusing ll = long long;\n\n#include \"../lib/graph/LowestCommonAncestor.hpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  ll n,q;\n  std::cin>>n>>q;\n\n  std::vector<std::vector<std::size_t>> graph(n);\n\
    \  rep(i,1,n){\n    ll p;\n    std::cin>>p;\n    graph[p].emplace_back(i);\n \
    \ }\n\n  LowestCommonAncestor lca(0,graph);\n\n  while(q--){\n    ll u,v;\n  \
    \  std::cin>>u>>v;\n    std::cout<<lca.lca(u,v)<<\"\\n\";\n  }\n\n  return 0;\n\
    }"
  dependsOn:
  - lib/graph/LowestCommonAncestor.hpp
  isVerificationFile: true
  path: test/LowestCommonAncestor.test.cpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LowestCommonAncestor.test.cpp
layout: document
redirect_from:
- /verify/test/LowestCommonAncestor.test.cpp
- /verify/test/LowestCommonAncestor.test.cpp.html
title: test/LowestCommonAncestor.test.cpp
---
