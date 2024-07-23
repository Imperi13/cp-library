---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/data_structure/PersistentStack.hpp\"\n\n#include <cassert>\n\
    #include <memory>\n\ntemplate <typename T>\nclass PersistentStack {\n public:\n\
    \  using value_t = T;\n  using size_t = std::size_t;\n\n private:\n  struct Node\
    \ {\n    value_t val;\n    std::shared_ptr<Node> next;\n    Node(value_t val_,\
    \ std::shared_ptr<Node> next_ = nullptr)\n        : val(val_), next(next_) {}\n\
    \  };\n\n  using node_ptr = std::shared_ptr<Node>;\n  node_ptr root;\n\n  PersistentStack(const\
    \ node_ptr& root_) : root(root_) {}\n\n public:\n  PersistentStack() : root()\
    \ {}\n\n  bool empty() { return !root; }\n  value_t top() {\n    assert(root);\n\
    \    return root->val;\n  }\n\n  PersistentStack push(value_t value) {\n    return\
    \ PersistentStack(std::make_shared<Node>(value, root));\n  }\n\n  PersistentStack\
    \ pop() {\n    assert(root);\n    return PersistentStack(root->next);\n  }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <memory>\n\ntemplate <typename\
    \ T>\nclass PersistentStack {\n public:\n  using value_t = T;\n  using size_t\
    \ = std::size_t;\n\n private:\n  struct Node {\n    value_t val;\n    std::shared_ptr<Node>\
    \ next;\n    Node(value_t val_, std::shared_ptr<Node> next_ = nullptr)\n     \
    \   : val(val_), next(next_) {}\n  };\n\n  using node_ptr = std::shared_ptr<Node>;\n\
    \  node_ptr root;\n\n  PersistentStack(const node_ptr& root_) : root(root_) {}\n\
    \n public:\n  PersistentStack() : root() {}\n\n  bool empty() { return !root;\
    \ }\n  value_t top() {\n    assert(root);\n    return root->val;\n  }\n\n  PersistentStack\
    \ push(value_t value) {\n    return PersistentStack(std::make_shared<Node>(value,\
    \ root));\n  }\n\n  PersistentStack pop() {\n    assert(root);\n    return PersistentStack(root->next);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: lib/data_structure/PersistentStack.hpp
  requiredBy: []
  timestamp: '2023-11-10 03:27:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data_structure/PersistentStack.hpp
layout: document
redirect_from:
- /library/lib/data_structure/PersistentStack.hpp
- /library/lib/data_structure/PersistentStack.hpp.html
title: lib/data_structure/PersistentStack.hpp
---