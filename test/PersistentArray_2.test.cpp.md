---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/PersistentArray.hpp
    title: lib/data_structure/PersistentArray.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_queue
    links:
    - https://judge.yosupo.jp/problem/persistent_queue
  bundledCode: "#line 1 \"test/PersistentArray_2.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cstdint>\n#include <cstdlib>\n#include <cmath>\n\
    #include <complex>\n#include <chrono>\n#include <deque>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <map>\n#include <memory>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <vector>\n#include <random>\n#include <utility>\n\
    #include <limits>\n#include <list>\n#line 31 \"test/PersistentArray_2.test.cpp\"\
    \n\n/* template start */\n \n#define rep(i, a, b) for (long long i = (a); (i)\
    \ < (b); (i)++)\n#define all(i) i.begin(), i.end()\n\nusing ll=long long;\n\n\
    #line 2 \"lib/data_structure/PersistentArray.hpp\"\n\n#line 6 \"lib/data_structure/PersistentArray.hpp\"\
    \n\ntemplate <typename T, std::size_t BITSIZE = 4>\nclass PersistentArray {\n\
    \ public:\n  using value_t = T;\n  using size_t = std::size_t;\n\n private:\n\
    \  struct Node {\n    value_t val;\n    std::array<std::shared_ptr<Node>, 1 <<\
    \ BITSIZE> ch;\n    Node(value_t val_) : val(val_) { ch.fill(nullptr); }\n  };\n\
    \  using node_ptr = std::shared_ptr<Node>;\n\n  value_t init;\n  node_ptr root;\n\
    \n  node_ptr update(size_t k, value_t value, node_ptr now) {\n    node_ptr ret\
    \ =\n        (now ? std::make_shared<Node>(*now) : std::make_shared<Node>(init));\n\
    \    if (k == 0)\n      ret->val = value;\n    else {\n      size_t mask = (1\
    \ << BITSIZE) - 1;\n      ret->ch[k & mask] = update(k >> BITSIZE, value, ret->ch[k\
    \ & mask]);\n    }\n    return ret;\n  }\n\n  value_t at(size_t k, node_ptr now)\
    \ {\n    if (!now) return init;\n    if (k == 0) return now->val;\n    return\
    \ at(k >> BITSIZE, now->ch[k & ((1 << BITSIZE) - 1)]);\n  }\n\n  PersistentArray(value_t\
    \ init_, const node_ptr& root_)\n      : init(init_), root(root_) {}\n\n public:\n\
    \  PersistentArray(value_t init_ = value_t()) : init(init_), root(nullptr) {}\n\
    \n  PersistentArray update(size_t k, const value_t& value) {\n    return PersistentArray(init,\
    \ update(k, value, root));\n  }\n\n  value_t operator[](size_t k) { return at(k,\
    \ root); }\n};\n#line 40 \"test/PersistentArray_2.test.cpp\"\n\ntemplate<typename\
    \ T>\nclass PersistentQueue{\n  public:\n  using value_t=T;\n  using size_t=std::size_t;\n\
    \  private:\n  size_t l,r;\n  PersistentArray<value_t> que;\n\n  PersistentQueue(size_t\
    \ l_,size_t r_,const PersistentArray<value_t>& que_):l(l_),r(r_),que(que_){}\n\
    \  public:\n  PersistentQueue():l(0),r(0),que(){}\n\n  PersistentQueue push(value_t\
    \ value){\n    return PersistentQueue(l,r+1,que.update(r,value));\n  }\n\n  PersistentQueue\
    \ pop(){\n    return PersistentQueue(l+1,r,que);\n  }\n\n  value_t front(){\n\
    \    return que[l];\n  }\n};\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  ll q;\n  std::cin>>q;\n\n  PersistentQueue<ll> base;\n\n  std::vector<PersistentQueue<ll>>\
    \ s(q);\n\n  rep(i,0,q){\n    ll mode;\n    std::cin>>mode;\n    \n    if(mode==0){\n\
    \      ll t,x;\n      std::cin>>t>>x;\n      if(t==-1)s[i]=base.push(x);\n   \
    \   else s[i]=s[t].push(x);\n    }else{\n      ll t;\n      std::cin>>t;\n   \
    \   std::cout<<s[t].front()<<\"\\n\";\n      s[i]=s[t].pop();\n    }\n  }\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n\n\
    #include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cstdint>\n#include <cstdlib>\n#include <cmath>\n\
    #include <complex>\n#include <chrono>\n#include <deque>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <map>\n#include <memory>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <vector>\n#include <random>\n#include <utility>\n\
    #include <limits>\n#include <list>\n#include <cmath>\n\n/* template start */\n\
    \ \n#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)\n#define all(i)\
    \ i.begin(), i.end()\n\nusing ll=long long;\n\n#include \"../lib/data_structure/PersistentArray.hpp\"\
    \n\ntemplate<typename T>\nclass PersistentQueue{\n  public:\n  using value_t=T;\n\
    \  using size_t=std::size_t;\n  private:\n  size_t l,r;\n  PersistentArray<value_t>\
    \ que;\n\n  PersistentQueue(size_t l_,size_t r_,const PersistentArray<value_t>&\
    \ que_):l(l_),r(r_),que(que_){}\n  public:\n  PersistentQueue():l(0),r(0),que(){}\n\
    \n  PersistentQueue push(value_t value){\n    return PersistentQueue(l,r+1,que.update(r,value));\n\
    \  }\n\n  PersistentQueue pop(){\n    return PersistentQueue(l+1,r,que);\n  }\n\
    \n  value_t front(){\n    return que[l];\n  }\n};\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios::sync_with_stdio(false);\n\n  ll q;\n  std::cin>>q;\n\n  PersistentQueue<ll>\
    \ base;\n\n  std::vector<PersistentQueue<ll>> s(q);\n\n  rep(i,0,q){\n    ll mode;\n\
    \    std::cin>>mode;\n    \n    if(mode==0){\n      ll t,x;\n      std::cin>>t>>x;\n\
    \      if(t==-1)s[i]=base.push(x);\n      else s[i]=s[t].push(x);\n    }else{\n\
    \      ll t;\n      std::cin>>t;\n      std::cout<<s[t].front()<<\"\\n\";\n  \
    \    s[i]=s[t].pop();\n    }\n  }\n\n  return 0;\n}"
  dependsOn:
  - lib/data_structure/PersistentArray.hpp
  isVerificationFile: true
  path: test/PersistentArray_2.test.cpp
  requiredBy: []
  timestamp: '2023-11-10 04:55:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/PersistentArray_2.test.cpp
layout: document
redirect_from:
- /verify/test/PersistentArray_2.test.cpp
- /verify/test/PersistentArray_2.test.cpp.html
title: test/PersistentArray_2.test.cpp
---
