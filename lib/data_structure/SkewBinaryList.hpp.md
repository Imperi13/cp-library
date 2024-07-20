---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/utility/type_alias.hpp
    title: lib/utility/type_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/SkewBinaryList.hpp\"\n\n#include <cassert>\n\
    #include <list>\n\n#line 2 \"lib/utility/type_alias.hpp\"\n\n#include <cstdint>\n\
    \nusing i64 = std::int64_t;\nusing i32 = std::int32_t;\nusing i16 = std::int16_t;\n\
    using i8 = std::int8_t;\n\nusing u64 = std::uint64_t;\nusing u32 = std::uint32_t;\n\
    using u16 = std::uint16_t;\nusing u8 = std::uint8_t;\n\nusing usize = std::size_t;\n\
    using isize = std::ptrdiff_t;\n\nconstexpr i64 operator\"\" _i64(unsigned long\
    \ long num) { return i64(num); }\nconstexpr i32 operator\"\" _i32(unsigned long\
    \ long num) { return i32(num); }\nconstexpr i16 operator\"\" _i16(unsigned long\
    \ long num) { return i16(num); }\nconstexpr i8 operator\"\" _i8(unsigned long\
    \ long num) { return i8(num); }\n\nconstexpr u64 operator\"\" _u64(unsigned long\
    \ long num) { return u64(num); }\nconstexpr u32 operator\"\" _u32(unsigned long\
    \ long num) { return u32(num); }\nconstexpr u16 operator\"\" _u16(unsigned long\
    \ long num) { return u16(num); }\nconstexpr u8 operator\"\" _u8(unsigned long\
    \ long num) { return u8(num); }\n#line 7 \"lib/data_structure/SkewBinaryList.hpp\"\
    \n\ntemplate <typename T>\nclass SkewBinaryList {\n public:\n  using value_t =\
    \ T;\n\n private:\n  struct Node {\n    value_t val;\n    size_t cnt;\n    Node\
    \ *left, *right;\n    Node(value_t val_, Node *left_ = nullptr, Node *right_ =\
    \ nullptr)\n        : val(val_), cnt(1), left(left_), right(right_) {\n      if\
    \ (left_) cnt += left_->cnt;\n      if (right_) cnt += right_->cnt;\n    }\n \
    \   ~Node() {\n      if (left)delete left;\n      if (right)delete right;\n  \
    \    left = nullptr;\n      right = nullptr;\n    }\n  };\n\n  using node_ptr\
    \ = Node*;\n\n  size_t cnt;\n  std::list<node_ptr> roots;\n\n public:\n  SkewBinaryList()\
    \ : cnt(0), roots() {}\n\n  SkewBinaryList(const SkewBinaryList&) = delete;\n\
    \  SkewBinaryList& operator=(const SkewBinaryList&) = delete;\n\n  ~SkewBinaryList()\
    \ {\n    for (auto&& e : roots) {\n      delete e;\n      e = nullptr;\n    }\n\
    \  }\n\n  size_t size() { return cnt; }\n  bool empty() { return size() == 0;\
    \ }\n\n  value_t front() {\n    assert(!empty());\n    return roots.front()->val;\n\
    \  }\n\n  void push_front(value_t x) {\n    cnt++;\n    if (roots.size() < 2)\
    \ {\n      roots.emplace_front(new Node(x));\n      return;\n    }\n    node_ptr\
    \ first = *roots.begin();\n    node_ptr second = *(++roots.begin());\n    if(first->cnt\
    \ != second ->cnt){\n      roots.emplace_front(new Node(x));\n      return;  \
    \ \n    }else{\n      roots.pop_front();\n      roots.pop_front();\n      roots.emplace_front(new\
    \ Node(x,first,second));\n    }\n  }\n\n  void pop_front(){\n    assert(!empty());\n\
    \    if(roots.front()->cnt == 1){\n      delete roots.front();\n      roots.pop_front();\n\
    \      return;\n    }\n    node_ptr erase_node = roots.front();\n    roots.pop_front();\n\
    \    roots.push_front(erase_node->right);\n    erase_node->right=nullptr;\n  \
    \  roots.push_front(erase_node->left);\n    erase_node->left=nullptr;\n    delete\
    \ erase_node;\n    return;\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <list>\n\n#include \"../utility/type_alias.hpp\"\
    \n\ntemplate <typename T>\nclass SkewBinaryList {\n public:\n  using value_t =\
    \ T;\n\n private:\n  struct Node {\n    value_t val;\n    size_t cnt;\n    Node\
    \ *left, *right;\n    Node(value_t val_, Node *left_ = nullptr, Node *right_ =\
    \ nullptr)\n        : val(val_), cnt(1), left(left_), right(right_) {\n      if\
    \ (left_) cnt += left_->cnt;\n      if (right_) cnt += right_->cnt;\n    }\n \
    \   ~Node() {\n      if (left)delete left;\n      if (right)delete right;\n  \
    \    left = nullptr;\n      right = nullptr;\n    }\n  };\n\n  using node_ptr\
    \ = Node*;\n\n  size_t cnt;\n  std::list<node_ptr> roots;\n\n public:\n  SkewBinaryList()\
    \ : cnt(0), roots() {}\n\n  SkewBinaryList(const SkewBinaryList&) = delete;\n\
    \  SkewBinaryList& operator=(const SkewBinaryList&) = delete;\n\n  ~SkewBinaryList()\
    \ {\n    for (auto&& e : roots) {\n      delete e;\n      e = nullptr;\n    }\n\
    \  }\n\n  size_t size() { return cnt; }\n  bool empty() { return size() == 0;\
    \ }\n\n  value_t front() {\n    assert(!empty());\n    return roots.front()->val;\n\
    \  }\n\n  void push_front(value_t x) {\n    cnt++;\n    if (roots.size() < 2)\
    \ {\n      roots.emplace_front(new Node(x));\n      return;\n    }\n    node_ptr\
    \ first = *roots.begin();\n    node_ptr second = *(++roots.begin());\n    if(first->cnt\
    \ != second ->cnt){\n      roots.emplace_front(new Node(x));\n      return;  \
    \ \n    }else{\n      roots.pop_front();\n      roots.pop_front();\n      roots.emplace_front(new\
    \ Node(x,first,second));\n    }\n  }\n\n  void pop_front(){\n    assert(!empty());\n\
    \    if(roots.front()->cnt == 1){\n      delete roots.front();\n      roots.pop_front();\n\
    \      return;\n    }\n    node_ptr erase_node = roots.front();\n    roots.pop_front();\n\
    \    roots.push_front(erase_node->right);\n    erase_node->right=nullptr;\n  \
    \  roots.push_front(erase_node->left);\n    erase_node->left=nullptr;\n    delete\
    \ erase_node;\n    return;\n  }\n};"
  dependsOn:
  - lib/utility/type_alias.hpp
  isVerificationFile: false
  path: lib/data_structure/SkewBinaryList.hpp
  requiredBy: []
  timestamp: '2024-07-20 17:36:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data_structure/SkewBinaryList.hpp
layout: document
redirect_from:
- /library/lib/data_structure/SkewBinaryList.hpp
- /library/lib/data_structure/SkewBinaryList.hpp.html
title: lib/data_structure/SkewBinaryList.hpp
---
