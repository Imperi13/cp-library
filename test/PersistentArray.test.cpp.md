---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/PersistentArray.hpp
    title: lib/PersistentArray.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"test/PersistentArray.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cstdint>\n#include <cstdlib>\n#include <cmath>\n\
    #include <complex>\n#include <chrono>\n#include <deque>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <map>\n#include <memory>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <vector>\n#include <random>\n#include <utility>\n\
    #include <limits>\n#include <list>\n#line 31 \"test/PersistentArray.test.cpp\"\
    \n\n/* template start */\n \n#define rep(i, a, b) for (long long i = (a); (i)\
    \ < (b); (i)++)\n#define all(i) i.begin(), i.end()\n\nusing ll=long long;\n\n\
    #line 2 \"lib/PersistentArray.hpp\"\n\n#line 5 \"lib/PersistentArray.hpp\"\n\n\
    template <typename T, std::size_t BITSIZE = 4>\nclass PersistentArray {\n public:\n\
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
    #line 40 \"test/PersistentArray.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios::sync_with_stdio(false);\n\n  PersistentArray<ll> ary(0);\n  \n  ll\
    \ q;\n  std::cin>>q;\n  while(q--){\n    ll mode;\n    std::cin>>mode;\n    if(mode==0){\n\
    \      ll k,v;\n      std::cin>>k>>v;\n      ary=ary.update(k,v);\n    }else{\n\
    \      ll k;\n      std::cin>>k;\n      std::cout<<ary[k]<<\"\\n\";\n    }\n \
    \ }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n\
    #include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cstdint>\n#include <cstdlib>\n#include <cmath>\n\
    #include <complex>\n#include <chrono>\n#include <deque>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <map>\n#include <memory>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <vector>\n#include <random>\n#include <utility>\n\
    #include <limits>\n#include <list>\n#include <cmath>\n\n/* template start */\n\
    \ \n#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)\n#define all(i)\
    \ i.begin(), i.end()\n\nusing ll=long long;\n\n#include \"../lib/PersistentArray.hpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  PersistentArray<ll> ary(0);\n  \n  ll q;\n  std::cin>>q;\n  while(q--){\n\
    \    ll mode;\n    std::cin>>mode;\n    if(mode==0){\n      ll k,v;\n      std::cin>>k>>v;\n\
    \      ary=ary.update(k,v);\n    }else{\n      ll k;\n      std::cin>>k;\n   \
    \   std::cout<<ary[k]<<\"\\n\";\n    }\n  }\n\n  return 0;\n}"
  dependsOn:
  - lib/PersistentArray.hpp
  isVerificationFile: true
  path: test/PersistentArray.test.cpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/PersistentArray.test.cpp
layout: document
redirect_from:
- /verify/test/PersistentArray.test.cpp
- /verify/test/PersistentArray.test.cpp.html
title: test/PersistentArray.test.cpp
---
