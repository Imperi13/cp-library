---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/SegmentTree/LiChaoSegmentTree.hpp
    title: lib/SegmentTree/LiChaoSegmentTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/LiChaoSegmentTree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <chrono>\n#include <cmath>\n#include <complex>\n#include\
    \ <cstdint>\n#include <cstdlib>\n#include <deque>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <limits>\n#include <list>\n#include\
    \ <map>\n#include <memory>\n#include <numeric>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <utility>\n#include <vector>\n\n/* template\
    \ start */\n\nusing i64 = std::int_fast64_t;\nusing u64 = std::uint_fast64_t;\n\
    \n#define rep(i, a, b) for (i64 i = (a); (i) < (b); (i)++)\n#define all(i) i.begin(),\
    \ i.end()\n\n#ifdef LOCAL\n#define debug(...)                                \
    \                    \\\n  std::cerr << \"LINE: \" << __LINE__ << \"  [\" << #__VA_ARGS__\
    \ << \"]:\", \\\n      debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\
    \nvoid debug_out() { std::cerr << std::endl; }\n\ntemplate <typename Head, typename...\
    \ Tail>\nvoid debug_out(Head h, Tail... t) {\n  std::cerr << \" \" << h;\n  if\
    \ (sizeof...(t) > 0) std::cout << \" :\";\n  debug_out(t...);\n}\n\ntemplate <typename\
    \ T1, typename T2>\nstd::ostream& operator<<(std::ostream& os, std::pair<T1, T2>\
    \ pa) {\n  return os << pa.first << \" \" << pa.second;\n}\n\ntemplate <typename\
    \ T>\nstd::ostream& operator<<(std::ostream& os, std::vector<T> vec) {\n  for\
    \ (std::size_t i = 0; i < vec.size(); i++)\n    os << vec[i] << (i + 1 == vec.size()\
    \ ? \"\" : \" \");\n  return os;\n}\n\ntemplate <typename T1, typename T2>\ninline\
    \ bool chmax(T1& a, T2 b) {\n  return a < b && (a = b, true);\n}\n\ntemplate <typename\
    \ T1, typename T2>\ninline bool chmin(T1& a, T2 b) {\n  return a > b && (a = b,\
    \ true);\n}\n\ntemplate <typename Num>\nconstexpr Num mypow(Num a, u64 b, Num\
    \ id = 1) {\n  if (b == 0) return id;\n  Num x = id;\n  while (b > 0) {\n    if\
    \ (b & 1) x *= a;\n    a *= a;\n    b >>= 1;\n  }\n  return x;\n}\n\ntemplate\
    \ <typename T>\nstd::vector<std::pair<std::size_t, T>> enumerate(const std::vector<T>&\
    \ data) {\n  std::vector<std::pair<std::size_t, T>> ret;\n  for (std::size_t index\
    \ = 0; index < data.size(); index++)\n    ret.emplace_back(index, data[index]);\n\
    \  return ret;\n}\n\n/* template end */\n\n#line 2 \"lib/SegmentTree/LiChaoSegmentTree.hpp\"\
    \n\n#line 5 \"lib/SegmentTree/LiChaoSegmentTree.hpp\"\n\ntemplate <typename Int,\
    \ Int MAX = std::numeric_limits<Int>::max()>\nclass LiChaoSegmentTree {\n  static_assert(std::is_integral_v<Int>,\
    \ \"Int must be integer\");\n\n public:\n  using value_t = Int;\n  using size_t\
    \ = std::size_t;\n\n private:\n  struct Line {\n    value_t ax, b;\n    value_t\
    \ value(value_t x) { return ax * x + b; }\n    Line() : ax(0), b(MAX) {}\n   \
    \ Line(value_t ax_, value_t b_) : ax(ax_), b(b_) {}\n  };\n\n  struct Node;\n\
    \  using node_ptr = Node*;\n\n  struct Node {\n    node_ptr left, right;\n   \
    \ Line line;\n    Node() : left(), right(), line() {}\n    ~Node() {\n      if\
    \ (left) delete left;\n      if (right) delete right;\n      left = nullptr;\n\
    \      right = nullptr;\n    }\n  };\n\n  value_t l0, r0, lx, rx;\n  node_ptr\
    \ root;\n\n  void eval(Line f, value_t a, value_t b, node_ptr now, value_t l,\
    \ value_t r) {\n    if (a == b) return;\n    if (r <= a || b <= l) return;\n \
    \   if (f.value(l) >= now->line.value(l) &&\n        f.value(r - 1) >= now->line.value(r\
    \ - 1))\n      return;\n    if (r - l == 1 && f.value(l) > now->line.value(l))\
    \ {\n      std::swap(f, now->line);\n      return;\n    }\n\n    value_t mid =\
    \ l + (r - l) /2;\n    if (a <= l && r <= b) {\n      if (f.value(l) < now->line.value(l)\
    \ &&\n          f.value(r - 1) < now->line.value(r - 1)) {\n        std::swap(f,\
    \ now->line);\n        return;\n      }\n      if (f.value(mid - 1) < now->line.value(mid\
    \ - 1)) std::swap(f, now->line);\n      if (f.value(l) < now->line.value(l)) {\n\
    \        if (!now->left) now->left = new Node();\n        eval(f, a, b, now->left,\
    \ l, mid);\n      } else {\n        if (!now->right) now->right = new Node();\n\
    \        eval(f, a, b, now->right, mid, r);\n      }\n    } else {\n      if (mid\
    \ > a && b > l) {\n        if (!now->left) now->left = new Node();\n        eval(f,\
    \ a, b, now->left, l, mid);\n      }\n      if (r > a && b > mid) {\n        if\
    \ (!now->right) now->right = new Node();\n        eval(f, a, b, now->right, mid,\
    \ r);\n      }\n    }\n  }\n\n public:\n  LiChaoSegmentTree(value_t l, value_t\
    \ r)\n      : l0(l), r0(r), lx(l), root(new Node()) {\n    value_t n0 = 1;\n \
    \   while (n0 < (r - l)) n0 <<= 1;\n    rx = lx + n0;\n  }\n\n  ~LiChaoSegmentTree()\
    \ {\n    if (root) delete root;\n    root = nullptr;\n  }\n\n  void add_line(value_t\
    \ ax, value_t b) {\n    eval(Line(ax, b), lx, rx, root, lx, rx);\n  }\n\n  void\
    \ add_segment(value_t ax, value_t b, value_t l, value_t r) {\n    eval(Line(ax,\
    \ b), l, r, root, lx, rx);\n  }\n\n  value_t query(value_t x) {\n    value_t ans\
    \ = MAX;\n    node_ptr now(root);\n    value_t l = lx, r = rx;\n    while (r -\
    \ l > 1) {\n      if (ans > now->line.value(x)) ans = now->line.value(x);\n  \
    \    value_t mid = l + (r - l) /2;\n      if (x < mid) {\n        if (!now->left)\
    \ return ans;\n        now = now->left;\n        r = mid;\n      } else {\n  \
    \      if (!now->right) return ans;\n        now = now->right;\n        l = mid;\n\
    \      }\n    }\n    if (ans > now->line.value(x)) ans = now->line.value(x);\n\
    \    return ans;\n  }\n};\n#line 102 \"test/LiChaoSegmentTree.test.cpp\"\n\nconstexpr\
    \ i64 INF=1e9+100;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  i64 n,q;\n  std::cin>>n>>q;\n\n  LiChaoSegmentTree<i64> cht(-INF,INF);\n\n\
    \  rep(i,0,n){\n    i64 a,b;\n    std::cin>>a>>b;\n    cht.add_line(a,b);\n  }\n\
    \n  while(q--){\n    i64 mode;\n    std::cin>>mode;\n    if(mode==0){\n      i64\
    \ a,b;\n      std::cin>>a>>b;\n      cht.add_line(a,b);\n    }else{\n      i64\
    \ p;\n      std::cin>>p;\n\n      std::cout<<cht.query(p)<<\"\\n\";\n    }\n \
    \ }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <chrono>\n#include <cmath>\n#include <complex>\n#include\
    \ <cstdint>\n#include <cstdlib>\n#include <deque>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <limits>\n#include <list>\n#include\
    \ <map>\n#include <memory>\n#include <numeric>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <utility>\n#include <vector>\n\n/* template\
    \ start */\n\nusing i64 = std::int_fast64_t;\nusing u64 = std::uint_fast64_t;\n\
    \n#define rep(i, a, b) for (i64 i = (a); (i) < (b); (i)++)\n#define all(i) i.begin(),\
    \ i.end()\n\n#ifdef LOCAL\n#define debug(...)                                \
    \                    \\\n  std::cerr << \"LINE: \" << __LINE__ << \"  [\" << #__VA_ARGS__\
    \ << \"]:\", \\\n      debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\
    \nvoid debug_out() { std::cerr << std::endl; }\n\ntemplate <typename Head, typename...\
    \ Tail>\nvoid debug_out(Head h, Tail... t) {\n  std::cerr << \" \" << h;\n  if\
    \ (sizeof...(t) > 0) std::cout << \" :\";\n  debug_out(t...);\n}\n\ntemplate <typename\
    \ T1, typename T2>\nstd::ostream& operator<<(std::ostream& os, std::pair<T1, T2>\
    \ pa) {\n  return os << pa.first << \" \" << pa.second;\n}\n\ntemplate <typename\
    \ T>\nstd::ostream& operator<<(std::ostream& os, std::vector<T> vec) {\n  for\
    \ (std::size_t i = 0; i < vec.size(); i++)\n    os << vec[i] << (i + 1 == vec.size()\
    \ ? \"\" : \" \");\n  return os;\n}\n\ntemplate <typename T1, typename T2>\ninline\
    \ bool chmax(T1& a, T2 b) {\n  return a < b && (a = b, true);\n}\n\ntemplate <typename\
    \ T1, typename T2>\ninline bool chmin(T1& a, T2 b) {\n  return a > b && (a = b,\
    \ true);\n}\n\ntemplate <typename Num>\nconstexpr Num mypow(Num a, u64 b, Num\
    \ id = 1) {\n  if (b == 0) return id;\n  Num x = id;\n  while (b > 0) {\n    if\
    \ (b & 1) x *= a;\n    a *= a;\n    b >>= 1;\n  }\n  return x;\n}\n\ntemplate\
    \ <typename T>\nstd::vector<std::pair<std::size_t, T>> enumerate(const std::vector<T>&\
    \ data) {\n  std::vector<std::pair<std::size_t, T>> ret;\n  for (std::size_t index\
    \ = 0; index < data.size(); index++)\n    ret.emplace_back(index, data[index]);\n\
    \  return ret;\n}\n\n/* template end */\n\n#include \"../lib/SegmentTree/LiChaoSegmentTree.hpp\"\
    \n\nconstexpr i64 INF=1e9+100;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  i64 n,q;\n  std::cin>>n>>q;\n\n  LiChaoSegmentTree<i64> cht(-INF,INF);\n\n\
    \  rep(i,0,n){\n    i64 a,b;\n    std::cin>>a>>b;\n    cht.add_line(a,b);\n  }\n\
    \n  while(q--){\n    i64 mode;\n    std::cin>>mode;\n    if(mode==0){\n      i64\
    \ a,b;\n      std::cin>>a>>b;\n      cht.add_line(a,b);\n    }else{\n      i64\
    \ p;\n      std::cin>>p;\n\n      std::cout<<cht.query(p)<<\"\\n\";\n    }\n \
    \ }\n\n  return 0;\n}"
  dependsOn:
  - lib/SegmentTree/LiChaoSegmentTree.hpp
  isVerificationFile: true
  path: test/LiChaoSegmentTree.test.cpp
  requiredBy: []
  timestamp: '2020-10-07 02:35:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LiChaoSegmentTree.test.cpp
layout: document
redirect_from:
- /verify/test/LiChaoSegmentTree.test.cpp
- /verify/test/LiChaoSegmentTree.test.cpp.html
title: test/LiChaoSegmentTree.test.cpp
---
