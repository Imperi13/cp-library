---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LiChaoSegmentTree.test.cpp
    title: test/LiChaoSegmentTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/SegmentTree/LiChaoSegmentTree.hpp\"\n\
    \n#include <limits>\n#include <type_traits>\n\ntemplate <typename Int, Int MAX\
    \ = std::numeric_limits<Int>::max()>\nclass LiChaoSegmentTree {\n  static_assert(std::is_integral_v<Int>,\
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
    \    return ans;\n  }\n};\n"
  code: "#pragma once\n\n#include <limits>\n#include <type_traits>\n\ntemplate <typename\
    \ Int, Int MAX = std::numeric_limits<Int>::max()>\nclass LiChaoSegmentTree {\n\
    \  static_assert(std::is_integral_v<Int>, \"Int must be integer\");\n\n public:\n\
    \  using value_t = Int;\n  using size_t = std::size_t;\n\n private:\n  struct\
    \ Line {\n    value_t ax, b;\n    value_t value(value_t x) { return ax * x + b;\
    \ }\n    Line() : ax(0), b(MAX) {}\n    Line(value_t ax_, value_t b_) : ax(ax_),\
    \ b(b_) {}\n  };\n\n  struct Node;\n  using node_ptr = Node*;\n\n  struct Node\
    \ {\n    node_ptr left, right;\n    Line line;\n    Node() : left(), right(),\
    \ line() {}\n    ~Node() {\n      if (left) delete left;\n      if (right) delete\
    \ right;\n      left = nullptr;\n      right = nullptr;\n    }\n  };\n\n  value_t\
    \ l0, r0, lx, rx;\n  node_ptr root;\n\n  void eval(Line f, value_t a, value_t\
    \ b, node_ptr now, value_t l, value_t r) {\n    if (a == b) return;\n    if (r\
    \ <= a || b <= l) return;\n    if (f.value(l) >= now->line.value(l) &&\n     \
    \   f.value(r - 1) >= now->line.value(r - 1))\n      return;\n    if (r - l ==\
    \ 1 && f.value(l) > now->line.value(l)) {\n      std::swap(f, now->line);\n  \
    \    return;\n    }\n\n    value_t mid = l + (r - l) /2;\n    if (a <= l && r\
    \ <= b) {\n      if (f.value(l) < now->line.value(l) &&\n          f.value(r -\
    \ 1) < now->line.value(r - 1)) {\n        std::swap(f, now->line);\n        return;\n\
    \      }\n      if (f.value(mid - 1) < now->line.value(mid - 1)) std::swap(f,\
    \ now->line);\n      if (f.value(l) < now->line.value(l)) {\n        if (!now->left)\
    \ now->left = new Node();\n        eval(f, a, b, now->left, l, mid);\n      }\
    \ else {\n        if (!now->right) now->right = new Node();\n        eval(f, a,\
    \ b, now->right, mid, r);\n      }\n    } else {\n      if (mid > a && b > l)\
    \ {\n        if (!now->left) now->left = new Node();\n        eval(f, a, b, now->left,\
    \ l, mid);\n      }\n      if (r > a && b > mid) {\n        if (!now->right) now->right\
    \ = new Node();\n        eval(f, a, b, now->right, mid, r);\n      }\n    }\n\
    \  }\n\n public:\n  LiChaoSegmentTree(value_t l, value_t r)\n      : l0(l), r0(r),\
    \ lx(l), root(new Node()) {\n    value_t n0 = 1;\n    while (n0 < (r - l)) n0\
    \ <<= 1;\n    rx = lx + n0;\n  }\n\n  ~LiChaoSegmentTree() {\n    if (root) delete\
    \ root;\n    root = nullptr;\n  }\n\n  void add_line(value_t ax, value_t b) {\n\
    \    eval(Line(ax, b), lx, rx, root, lx, rx);\n  }\n\n  void add_segment(value_t\
    \ ax, value_t b, value_t l, value_t r) {\n    eval(Line(ax, b), l, r, root, lx,\
    \ rx);\n  }\n\n  value_t query(value_t x) {\n    value_t ans = MAX;\n    node_ptr\
    \ now(root);\n    value_t l = lx, r = rx;\n    while (r - l > 1) {\n      if (ans\
    \ > now->line.value(x)) ans = now->line.value(x);\n      value_t mid = l + (r\
    \ - l) /2;\n      if (x < mid) {\n        if (!now->left) return ans;\n      \
    \  now = now->left;\n        r = mid;\n      } else {\n        if (!now->right)\
    \ return ans;\n        now = now->right;\n        l = mid;\n      }\n    }\n \
    \   if (ans > now->line.value(x)) ans = now->line.value(x);\n    return ans;\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/SegmentTree/LiChaoSegmentTree.hpp
  requiredBy: []
  timestamp: '2023-11-10 03:27:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LiChaoSegmentTree.test.cpp
documentation_of: lib/data_structure/SegmentTree/LiChaoSegmentTree.hpp
layout: document
redirect_from:
- /library/lib/data_structure/SegmentTree/LiChaoSegmentTree.hpp
- /library/lib/data_structure/SegmentTree/LiChaoSegmentTree.hpp.html
title: lib/data_structure/SegmentTree/LiChaoSegmentTree.hpp
---
