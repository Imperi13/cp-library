---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/SegmentTree/PersistentSegmentTree.hpp
    title: lib/SegmentTree/PersistentSegmentTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/PersistentSegmentTree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include <iostream>\n#include\
    \ <algorithm>\n#include <vector>\n\n#line 2 \"lib/SegmentTree/PersistentSegmentTree.hpp\"\
    \n\n#include <cassert>\n#include <memory>\n\ntemplate <typename Monoid>\nclass\
    \ PersistentSegmentTree {\n public:\n  using value_t = typename Monoid::value_t;\n\
    \  using size_t = std::size_t;\n\n private:\n  struct Node {\n    value_t val;\n\
    \    std::shared_ptr<Node> left, right;\n    std::weak_ptr<Node> par;\n    Node(value_t\
    \ val_, std::shared_ptr<Node> par_ = nullptr)\n        : val(val_), left(), right(),\
    \ par(par_) {}\n  };\n\n  using node_ptr = std::shared_ptr<Node>;\n  size_t n,\
    \ n0;\n  node_ptr root;\n\n  value_t fold(size_t a, size_t b, const node_ptr&\
    \ now, size_t l, size_t r) {\n    if (a <= l && r <= b) return now->val;\n   \
    \ if (b <= l || r <= a) return Monoid::id;\n    value_t lval =\n        (now->left)\
    \ ? fold(a, b, now->left, l, l + (r - l) / 2) : Monoid::id;\n    value_t rval\
    \ =\n        (now->right) ? fold(a, b, now->right, l + (r - l) / 2, r) : Monoid::id;\n\
    \    return Monoid::op(lval, rval);\n  }\n\n  PersistentSegmentTree(size_t n_,\
    \ size_t n0_, const node_ptr& root_)\n      : n(n_), n0(n0_), root(root_) {}\n\
    \n public:\n  PersistentSegmentTree(size_t n_ = 0) : n(n_), root(new Node(Monoid::id))\
    \ {\n    n0 = 1;\n    while (n0 < n) n0 <<= 1;\n  }\n\n  PersistentSegmentTree\
    \ update(size_t i, value_t value, bool change) {\n    assert(0 <= i && i < n);\n\
    \    node_ptr now(root);\n    node_ptr newroot = std::make_shared<Node>(Monoid::id),\
    \ cur(newroot);\n\n    size_t l = 0, r = n0;\n    bool isok = true;\n    while\
    \ (r - l > 1) {\n      size_t mid = l + (r - l) / 2;\n      if (i < mid) {\n \
    \       if (isok && now->right) cur->right = now->right;\n        cur->left =\
    \ std::make_shared<Node>(Monoid::id, cur);\n        if (isok) {\n          if\
    \ (!now->left)\n            isok = false;\n          else\n            now = now->left;\n\
    \        }\n        cur = cur->left;\n        r = mid;\n      } else {\n     \
    \   if (isok && now->left) cur->left = now->left;\n        cur->right = std::make_shared<Node>(Monoid::id,\
    \ cur);\n\n        if (isok) {\n          if (!now->right)\n            isok =\
    \ false;\n          else\n            now = now->right;\n        }\n        cur\
    \ = cur->right;\n        l = mid;\n      }\n    }\n\n    if (change)\n      cur->val\
    \ = value;\n    else\n      cur->val = Monoid::op((isok) ? now->val : Monoid::id,\
    \ value);\n\n    while (cur->par.lock()) {\n      cur = cur->par.lock();\n   \
    \   cur->val = Monoid::op((cur->left) ? cur->left->val : Monoid::id,\n       \
    \                     (cur->right) ? cur->right->val : Monoid::id);\n    }\n\n\
    \    return PersistentSegmentTree(n, n0, newroot);\n  }\n\n  value_t fold(size_t\
    \ l, size_t r) {\n    assert(0 <= l && l <= r && r <= n);\n    return fold(l,\
    \ r, root, 0, n0);\n  }\n};\n#line 8 \"test/PersistentSegmentTree.test.cpp\"\n\
    \n#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)\n#define all(a)\
    \ a.begin(),a.end()\n\nconstexpr long long MOD=998244353;\n\nstruct Monoid{\n\
    \  using value_t=long long;\n  static constexpr value_t id=0;\n  static constexpr\
    \ value_t op(value_t a,value_t b){\n    return a+b;\n  }\n};\n\nusing ll=long\
    \ long;\nusing P=std::pair<ll,ll>;\n\nint main(){\n  std::cin.tie(nullptr);\n\
    \  std::ios::sync_with_stdio(false);\n\n  ll n,q;\n  std::cin>>n>>q;\n\n  std::vector<PersistentSegmentTree<Monoid>>\
    \ seg(n+1);\n  seg[n]=PersistentSegmentTree<Monoid>(1e9+10);\n\n  struct Point{\n\
    \    ll x,y,w;\n    Point(ll a,ll b,ll c):x(a),y(b),w(c){}\n  };\n  std::vector<Point>\
    \ points(n,Point(-1,-1,-1));\n\n  rep(i,0,n)std::cin>>points[i].x>>points[i].y>>points[i].w;\n\
    \n  auto comp=[](const Point& a,const Point& b)->bool{return a.x<b.x;};\n  std::sort(points.begin(),points.end(),comp);\n\
    \n  for(ll i=n-1;i>=0;i--)seg[i]=seg[i+1].update(points[i].y,points[i].w,false);\n\
    \n  rep(i,0,q){\n    ll l,d,r,u;\n    std::cin>>l>>d>>r>>u;\n\n    ll ans=0;\n\
    \n    ans+=seg[std::lower_bound(all(points),Point(l,-1,-1),comp)-points.begin()].fold(d,u);\n\
    \    ans-=seg[std::lower_bound(all(points),Point(r,-1,-1),comp)-points.begin()].fold(d,u);\n\
    \    std::cout<<ans<<\"\\n\";\n  }\n\n  return 0; \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ <iostream>\n#include <algorithm>\n#include <vector>\n\n#include \"../lib/SegmentTree/PersistentSegmentTree.hpp\"\
    \n\n#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)\n#define all(a)\
    \ a.begin(),a.end()\n\nconstexpr long long MOD=998244353;\n\nstruct Monoid{\n\
    \  using value_t=long long;\n  static constexpr value_t id=0;\n  static constexpr\
    \ value_t op(value_t a,value_t b){\n    return a+b;\n  }\n};\n\nusing ll=long\
    \ long;\nusing P=std::pair<ll,ll>;\n\nint main(){\n  std::cin.tie(nullptr);\n\
    \  std::ios::sync_with_stdio(false);\n\n  ll n,q;\n  std::cin>>n>>q;\n\n  std::vector<PersistentSegmentTree<Monoid>>\
    \ seg(n+1);\n  seg[n]=PersistentSegmentTree<Monoid>(1e9+10);\n\n  struct Point{\n\
    \    ll x,y,w;\n    Point(ll a,ll b,ll c):x(a),y(b),w(c){}\n  };\n  std::vector<Point>\
    \ points(n,Point(-1,-1,-1));\n\n  rep(i,0,n)std::cin>>points[i].x>>points[i].y>>points[i].w;\n\
    \n  auto comp=[](const Point& a,const Point& b)->bool{return a.x<b.x;};\n  std::sort(points.begin(),points.end(),comp);\n\
    \n  for(ll i=n-1;i>=0;i--)seg[i]=seg[i+1].update(points[i].y,points[i].w,false);\n\
    \n  rep(i,0,q){\n    ll l,d,r,u;\n    std::cin>>l>>d>>r>>u;\n\n    ll ans=0;\n\
    \n    ans+=seg[std::lower_bound(all(points),Point(l,-1,-1),comp)-points.begin()].fold(d,u);\n\
    \    ans-=seg[std::lower_bound(all(points),Point(r,-1,-1),comp)-points.begin()].fold(d,u);\n\
    \    std::cout<<ans<<\"\\n\";\n  }\n\n  return 0; \n}"
  dependsOn:
  - lib/SegmentTree/PersistentSegmentTree.hpp
  isVerificationFile: true
  path: test/PersistentSegmentTree.test.cpp
  requiredBy: []
  timestamp: '2020-07-31 15:44:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/PersistentSegmentTree.test.cpp
layout: document
redirect_from:
- /verify/test/PersistentSegmentTree.test.cpp
- /verify/test/PersistentSegmentTree.test.cpp.html
title: test/PersistentSegmentTree.test.cpp
---
