---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/data_structure/SegmentTree/DynamicSegmentTree.hpp
    title: lib/data_structure/SegmentTree/DynamicSegmentTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/DynamicSegmentTree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"lib/data_structure/SegmentTree/DynamicSegmentTree.hpp\"\
    \n\n#include <cassert>\n#include <memory>\n\n// Monoid\n// type value_t\n// static\
    \ var id\n// static (value_t,value_t)->value_t op\n\ntemplate <typename Monoid>\n\
    class DynamicSegmentTree {\n public:\n  using value_t = typename Monoid::value_t;\n\
    \  using size_t = std::size_t;\n\n private:\n  struct Node {\n    value_t val;\n\
    \    Node *left, *right, *par;\n    Node(Node* par_ = nullptr) : val(Monoid::id),\
    \ left(), right(), par(par_) {}\n    ~Node() {\n      if (left) delete left;\n\
    \      if (right) delete right;\n      left = nullptr;\n      right = nullptr;\n\
    \      par = nullptr;\n    }\n  };\n\n  using node_ptr = Node*;\n\n  size_t n,\
    \ n0;\n  node_ptr root;\n\n  value_t fold(size_t a, size_t b, const node_ptr&\
    \ now, size_t l, size_t r) {\n    if (a <= l && r <= b) return now->val;\n   \
    \ if (b <= l || r <= a) return Monoid::id;\n    value_t lval =\n        (now->left)\
    \ ? fold(a, b, now->left, l, l + (r - l) / 2) : Monoid::id;\n    value_t rval\
    \ =\n        (now->right) ? fold(a, b, now->right, l + (r - l) / 2, r) : Monoid::id;\n\
    \    return Monoid::op(lval, rval);\n  }\n\n  void copy_dfs(node_ptr& node, const\
    \ node_ptr& from) {\n    node->val = from->val;\n    if (from->left) {\n     \
    \ node->left = new Node(node);\n      copy_dfs(node->left, from->left);\n    }\n\
    \    if (from->right) {\n      node->right = new Node(node);\n      copy_dfs(node->right,\
    \ from->right);\n    }\n  }\n\n public:\n  DynamicSegmentTree(size_t n_ = 0) :\
    \ n(n_), root(nullptr) {\n    n0 = 1;\n    while (n0 < n) n0 <<= 1;\n  }\n  DynamicSegmentTree(const\
    \ DynamicSegmentTree& from) {\n    n = from.n;\n    n0 = from.n0;\n    root =\
    \ nullptr;\n    if (from.root) {\n      root = new Node();\n      copy_dfs(root,\
    \ from.root);\n    }\n  }\n  DynamicSegmentTree& operator=(const DynamicSegmentTree&\
    \ from) {\n    n = from.n;\n    n0 = from.n0;\n    root = nullptr;\n    if (from.root)\
    \ {\n      root = new Node();\n      copy_dfs(root, from.root);\n    }\n  }\n\
    \  DynamicSegmentTree(DynamicSegmentTree&&) = default;\n  DynamicSegmentTree&\
    \ operator=(DynamicSegmentTree&&) = default;\n  ~DynamicSegmentTree() {\n    if\
    \ (root) delete root;\n    root = nullptr;\n  }\n\n  void update(size_t i, value_t\
    \ val, bool change) {\n    assert(0 <= i && i < n);\n    if (!root) root = new\
    \ Node();\n    node_ptr now = root;\n    size_t l = 0, r = n0;\n    while (r -\
    \ l > 1) {\n      size_t mid = l + (r - l) / 2;\n      if (i < mid) {\n      \
    \  if (!now->left) now->left = new Node(now);\n        now = now->left;\n    \
    \    r = mid;\n      } else {\n        if (!now->right) now->right = new Node(now);\n\
    \        now = now->right;\n        l = mid;\n      }\n    }\n    if (change)\n\
    \      now->val = val;\n    else\n      now->val = Monoid::op(now->val, val);\n\
    \n    while (now->par) {\n      now = now->par;\n      now->val = Monoid::op((now->left)\
    \ ? now->left->val : Monoid::id,\n                            (now->right) ? now->right->val\
    \ : Monoid::id);\n    }\n  }\n\n  value_t fold(size_t a, size_t b) {\n    assert(0\
    \ <= a && a <= b && b <= n);\n    if (!root) return Monoid::id;\n    return fold(a,\
    \ b, root, 0, n0);\n  }\n};\n#line 7 \"test/DynamicSegmentTree.test.cpp\"\n\n\
    constexpr long long MOD=998244353;\n\nstruct Monoid{\n  using value_t=std::pair<long\
    \ long,long long>;\n  static constexpr value_t id={1,0};\n  static constexpr value_t\
    \ op(value_t a,value_t b){\n    return {a.first*b.first%MOD,(a.second*b.first%MOD\
    \ + b.second)%MOD};\n  }\n};\n\nusing ll=long long;\nusing P=std::pair<ll,ll>;\n\
    \nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \  ll n,q;\n  std::cin>>n>>q;\n\n  DynamicSegmentTree<Monoid> seg(n);\n\n  for(ll\
    \ i=0;i<n;i++){\n    ll a,b;\n    std::cin>>a>>b;\n    seg.update(i,{a,b},true);\n\
    \  }\n\n  for(ll i=0;i<q;i++){\n    ll mode;\n    std::cin>>mode;\n    if(mode==0){\n\
    \      ll p,c,d;\n      std::cin>>p>>c>>d;\n      seg.update(p,{c,d},true);\n\
    \    }else{\n      ll l,r,x;\n      std::cin>>l>>r>>x;\n      P fold=seg.fold(l,r);\n\
    \      std::cout<<(fold.first*x%MOD+fold.second)%MOD<<\"\\n\";\n    }\n  }\n\n\
    \  return 0; \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../lib/data_structure/SegmentTree/DynamicSegmentTree.hpp\"\
    \n\nconstexpr long long MOD=998244353;\n\nstruct Monoid{\n  using value_t=std::pair<long\
    \ long,long long>;\n  static constexpr value_t id={1,0};\n  static constexpr value_t\
    \ op(value_t a,value_t b){\n    return {a.first*b.first%MOD,(a.second*b.first%MOD\
    \ + b.second)%MOD};\n  }\n};\n\nusing ll=long long;\nusing P=std::pair<ll,ll>;\n\
    \nint main(){\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \  ll n,q;\n  std::cin>>n>>q;\n\n  DynamicSegmentTree<Monoid> seg(n);\n\n  for(ll\
    \ i=0;i<n;i++){\n    ll a,b;\n    std::cin>>a>>b;\n    seg.update(i,{a,b},true);\n\
    \  }\n\n  for(ll i=0;i<q;i++){\n    ll mode;\n    std::cin>>mode;\n    if(mode==0){\n\
    \      ll p,c,d;\n      std::cin>>p>>c>>d;\n      seg.update(p,{c,d},true);\n\
    \    }else{\n      ll l,r,x;\n      std::cin>>l>>r>>x;\n      P fold=seg.fold(l,r);\n\
    \      std::cout<<(fold.first*x%MOD+fold.second)%MOD<<\"\\n\";\n    }\n  }\n\n\
    \  return 0; \n}"
  dependsOn:
  - lib/data_structure/SegmentTree/DynamicSegmentTree.hpp
  isVerificationFile: true
  path: test/DynamicSegmentTree.test.cpp
  requiredBy: []
  timestamp: '2023-11-10 04:19:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DynamicSegmentTree.test.cpp
layout: document
redirect_from:
- /verify/test/DynamicSegmentTree.test.cpp
- /verify/test/DynamicSegmentTree.test.cpp.html
title: test/DynamicSegmentTree.test.cpp
---
