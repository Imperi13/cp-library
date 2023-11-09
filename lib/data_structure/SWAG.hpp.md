---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/SWAG.test.cpp
    title: test/SWAG.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/SWAG.hpp\"\n\n#include <cassert>\n#include\
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
    \      tmp.pop();\n    }\n    front.pop();\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <stack>\n\ntemplate <typename\
    \ Semigroup>\nclass SWAG {\n public:\n  using value_t = typename Semigroup::value_t;\n\
    \  using size_t = std::size_t;\n\n private:\n  using P = std::pair<value_t, value_t>;\n\
    \  std::stack<P> front, back;\n\n public:\n  SWAG() {}\n\n  size_t size() { return\
    \ front.size() + back.size(); }\n  bool empty() { return size() == 0; }\n\n  value_t\
    \ fold_all() {\n    assert(!empty());\n    if (front.empty()) return back.top().second;\n\
    \    if (back.empty()) return front.top().second;\n    return Semigroup::op(front.top().second,\
    \ back.top().second);\n  }\n\n  void push_back(value_t val) {\n    if (back.empty())\n\
    \      back.emplace(val, val);\n    else {\n      P tmp = back.top();\n      back.emplace(val,\
    \ Semigroup::op(tmp.second, val));\n    }\n  }\n\n  void push_front(value_t val)\
    \ {\n    if (front.empty())\n      front.emplace(val, val);\n    else {\n    \
    \  P tmp = front.top();\n      front.emplace(val, Semigroup::op(val, tmp.second));\n\
    \    }\n  }\n\n  void pop_back() {\n    assert(!empty());\n    if (!back.empty())\
    \ {\n      back.pop();\n      return;\n    }\n    size_t n = front.size();\n \
    \   std::stack<value_t> tmp;\n    for (size_t i = 0; i < n / 2; i++) {\n     \
    \ tmp.emplace(front.top().first);\n      front.pop();\n    }\n    while (!front.empty())\
    \ {\n      push_back(front.top().first);\n      front.pop();\n    }\n    while\
    \ (!tmp.empty()) {\n      push_front(tmp.top());\n      tmp.pop();\n    }\n  \
    \  back.pop();\n  }\n\n  void pop_front() {\n    assert(!empty());\n    if (!front.empty())\
    \ {\n      front.pop();\n      return;\n    }\n    size_t n = back.size();\n \
    \   std::stack<value_t> tmp;\n    for (std::size_t i = 0; i < n / 2; i++) {\n\
    \      tmp.emplace(back.top().first);\n      back.pop();\n    }\n    while (!back.empty())\
    \ {\n      push_front(back.top().first);\n      back.pop();\n    }\n    while\
    \ (!tmp.empty()) {\n      push_back(tmp.top());\n      tmp.pop();\n    }\n   \
    \ front.pop();\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/SWAG.hpp
  requiredBy: []
  timestamp: '2023-11-10 03:27:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/SWAG.test.cpp
documentation_of: lib/data_structure/SWAG.hpp
layout: document
redirect_from:
- /library/lib/data_structure/SWAG.hpp
- /library/lib/data_structure/SWAG.hpp.html
title: lib/data_structure/SWAG.hpp
---
