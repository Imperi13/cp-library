---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/SWAG.hpp
    title: lib/SWAG.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/SWAG.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include <iostream>\n#line 2 \"lib/SWAG.hpp\"\n\n#include <cassert>\n#include\
    \ <stack>\n\ntemplate <typename Semigroup>\nclass SWAG {\n public:\n  using value_t\
    \ = typename Semigroup::value_t;\n  using size_t = std::size_t;\n\n private:\n\
    \  using P = std::pair<value_t, value_t>;\n  std::stack<P> front, back;\n\n public:\n\
    \  SWAG() {}\n\n  size_t size() { return front.size() + back.size(); }\n  bool\
    \ empty() { return size() == 0; }\n\n  value_t fold_all() {\n    assert(!empty());\n\
    \    if (front.empty()) return back.top().second;\n    if (back.empty()) return\
    \ front.top().second;\n    return Semigroup::op(front.top().second, back.top().second);\n\
    \  }\n\n  void push_back(value_t val) {\n    if (back.empty())\n      back.emplace(val,\
    \ val);\n    else {\n      P tmp = back.top();\n      back.emplace(val, Semigroup::op(tmp.second,\
    \ val));\n    }\n  }\n\n  void push_front(value_t val) {\n    if (front.empty())\n\
    \      front.emplace(val, val);\n    else {\n      P tmp = front.top();\n    \
    \  front.emplace(val, Semigroup::op(val, tmp.second));\n    }\n  }\n\n  void pop_back()\
    \ {\n    assert(!empty());\n    if (!back.empty()) {\n      back.pop();\n    \
    \  return;\n    }\n    size_t n = front.size();\n    std::stack<value_t> tmp;\n\
    \    for (size_t i = 0; i < n / 2; i++) {\n      tmp.emplace(front.top().first);\n\
    \      front.pop();\n    }\n    while (!front.empty()) {\n      push_back(front.top().first);\n\
    \      front.pop();\n    }\n    while (!tmp.empty()) {\n      push_front(tmp.top());\n\
    \      tmp.pop();\n    }\n    back.pop();\n  }\n\n  void pop_front() {\n    assert(!empty());\n\
    \    if (!front.empty()) {\n      front.pop();\n      return;\n    }\n    size_t\
    \ n = back.size();\n    std::stack<value_t> tmp;\n    for (std::size_t i = 0;\
    \ i < n / 2; i++) {\n      tmp.emplace(back.top().first);\n      back.pop();\n\
    \    }\n    while (!back.empty()) {\n      push_front(back.top().first);\n   \
    \   back.pop();\n    }\n    while (!tmp.empty()) {\n      push_back(tmp.top());\n\
    \      tmp.pop();\n    }\n    front.pop();\n  }\n};\n#line 5 \"test/SWAG.test.cpp\"\
    \n\n#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)\n\nusing ll=long\
    \ long;\n\nconstexpr long long MOD=998244353;\n\nstruct Semigroup{\n  using value_t=std::pair<long\
    \ long,long long>;\n  static constexpr value_t op(value_t a,value_t b){\n    return\
    \ {a.first*b.first%MOD,(a.second*b.first%MOD + b.second)%MOD};\n  }\n};\n\nint\
    \ main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\n \
    \ SWAG<Semigroup> swag;\n\n  ll q;\n  std::cin>>q;\n\n  rep(i,0,q){\n    ll mode;\n\
    \    std::cin>>mode;\n\n    if(mode==0){\n      ll a,b;\n      std::cin>>a>>b;\n\
    \      swag.push_back({a,b});\n    }else if(mode==1){\n      swag.pop_front();\n\
    \    }else{\n      ll x;\n      std::cin>>x;\n      if(swag.empty())std::cout<<x<<\"\
    \\n\";\n      else{\n        auto tmp=swag.fold_all();\n        std::cout<<(tmp.first*x%MOD+tmp.second)%MOD<<\"\
    \\n\";\n      }\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include <iostream>\n#include \"../lib/SWAG.hpp\"\n\n#define rep(i, a, b)\
    \ for (long long i = (a); (i) < (b); (i)++)\n\nusing ll=long long;\n\nconstexpr\
    \ long long MOD=998244353;\n\nstruct Semigroup{\n  using value_t=std::pair<long\
    \ long,long long>;\n  static constexpr value_t op(value_t a,value_t b){\n    return\
    \ {a.first*b.first%MOD,(a.second*b.first%MOD + b.second)%MOD};\n  }\n};\n\nint\
    \ main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\n \
    \ SWAG<Semigroup> swag;\n\n  ll q;\n  std::cin>>q;\n\n  rep(i,0,q){\n    ll mode;\n\
    \    std::cin>>mode;\n\n    if(mode==0){\n      ll a,b;\n      std::cin>>a>>b;\n\
    \      swag.push_back({a,b});\n    }else if(mode==1){\n      swag.pop_front();\n\
    \    }else{\n      ll x;\n      std::cin>>x;\n      if(swag.empty())std::cout<<x<<\"\
    \\n\";\n      else{\n        auto tmp=swag.fold_all();\n        std::cout<<(tmp.first*x%MOD+tmp.second)%MOD<<\"\
    \\n\";\n      }\n    }\n  }\n}"
  dependsOn:
  - lib/SWAG.hpp
  isVerificationFile: true
  path: test/SWAG.test.cpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/SWAG.test.cpp
layout: document
redirect_from:
- /verify/test/SWAG.test.cpp
- /verify/test/SWAG.test.cpp.html
title: test/SWAG.test.cpp
---
