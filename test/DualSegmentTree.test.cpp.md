---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/SegmentTree/DualSegmentTree.hpp
    title: lib/SegmentTree/DualSegmentTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
  bundledCode: "#line 1 \"test/DualSegmentTree.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n\n#include <iostream>\n#include <algorithm>\n#include <vector>\n\n#line 2 \"\
    lib/SegmentTree/DualSegmentTree.hpp\"\n\n#include <cassert>\n#include <memory>\n\
    \n// commutative Monoid\n// type value_t\n// static value_t id\n// static (value_t,value_t)->value_t\
    \ op\n\ntemplate <typename Monoid>\nclass DualSegmentTree {\n public:\n  using\
    \ value_t = typename Monoid::value_t;\n  using size_t = std::size_t;\n\n private:\n\
    \  struct Node {\n    value_t val;\n    std::shared_ptr<Node> left, right;\n \
    \   Node(value_t val_) : val(val_), left(), right() {}\n  };\n\n  using node_ptr\
    \ = std::shared_ptr<Node>;\n\n  size_t n, n0;\n  node_ptr root;\n\n  void update(size_t\
    \ a, size_t b, value_t value, const node_ptr& now, size_t l,\n              size_t\
    \ r) {\n    if (a <= l && r <= b) {\n      now->val = Monoid::op(now->val, value);\n\
    \      return;\n    }\n    if (b <= l || r <= a) return;\n\n    if (!now->left)\
    \ now->left = std::make_shared<Node>(Monoid::id);\n    if (!now->right) now->right\
    \ = std::make_shared<Node>(Monoid::id);\n    update(a, b, value, now->left, l,\
    \ l + (r - l) / 2);\n    update(a, b, value, now->right, l + (r - l) / 2, r);\n\
    \  }\n\n public:\n  DualSegmentTree(size_t n_) : n(n_), root(new Node(Monoid::id))\
    \ {\n    n0 = 1;\n    while (n0 < n) n0 <<= 1;\n  }\n\n  void update(size_t l,\
    \ size_t r, value_t value) {\n    assert(0 <= l && l <= r && r <= n);\n    update(l,\
    \ r, value, root, 0, n0);\n  }\n\n  value_t at(size_t i) {\n    assert(0 <= i\
    \ && i < n);\n    node_ptr now(root);\n    value_t ret = now->val;\n\n    size_t\
    \ l = 0, r = n0;\n    while (r - l > 1) {\n      size_t mid = l + (r - l) / 2;\n\
    \      if (i < mid) {\n        if (!now->left) break;\n        now = now->left;\n\
    \        r = mid;\n      } else {\n        if (!now->right) break;\n        now\
    \ = now->right;\n        l = mid;\n      }\n      ret = Monoid::op(ret, now->val);\n\
    \    }\n    return ret;\n  }\n};\n#line 8 \"test/DualSegmentTree.test.cpp\"\n\n\
    #define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)\n#define all(a)\
    \ a.begin(),a.end()\n\nstruct Monoid{\n  using value_t=long long;\n  static constexpr\
    \ value_t id=0;\n  static constexpr value_t op(value_t a,value_t b){\n    return\
    \ a+b;\n  }\n};\n\nusing ll=long long;\n\nint main(){\n  std::cin.tie(nullptr);\n\
    \  std::ios::sync_with_stdio(false);\n\n  ll n,q;\n  std::cin>>n>>q;\n\n  DualSegmentTree<Monoid>\
    \ seg(n);\n\n  while(q--){\n    ll mode;\n    std::cin>>mode;\n    if(mode==0){\n\
    \      ll s,t,x;\n      std::cin>>s>>t>>x;\n      seg.update(s-1,t,x);\n    }else{\n\
    \      ll t;\n      std::cin>>t;\n      std::cout<<seg.at(t-1)<<\"\\n\";\n   \
    \ }\n  }\n\n  return 0; \n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n\n#include <iostream>\n#include <algorithm>\n#include <vector>\n\n#include \"\
    ../lib/SegmentTree/DualSegmentTree.hpp\"\n\n#define rep(i, a, b) for (long long\
    \ i = (a); (i) < (b); (i)++)\n#define all(a) a.begin(),a.end()\n\nstruct Monoid{\n\
    \  using value_t=long long;\n  static constexpr value_t id=0;\n  static constexpr\
    \ value_t op(value_t a,value_t b){\n    return a+b;\n  }\n};\n\nusing ll=long\
    \ long;\n\nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  ll n,q;\n  std::cin>>n>>q;\n\n  DualSegmentTree<Monoid> seg(n);\n\n  while(q--){\n\
    \    ll mode;\n    std::cin>>mode;\n    if(mode==0){\n      ll s,t,x;\n      std::cin>>s>>t>>x;\n\
    \      seg.update(s-1,t,x);\n    }else{\n      ll t;\n      std::cin>>t;\n   \
    \   std::cout<<seg.at(t-1)<<\"\\n\";\n    }\n  }\n\n  return 0; \n}"
  dependsOn:
  - lib/SegmentTree/DualSegmentTree.hpp
  isVerificationFile: true
  path: test/DualSegmentTree.test.cpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DualSegmentTree.test.cpp
layout: document
redirect_from:
- /verify/test/DualSegmentTree.test.cpp
- /verify/test/DualSegmentTree.test.cpp.html
title: test/DualSegmentTree.test.cpp
---
