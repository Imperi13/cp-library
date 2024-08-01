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
  bundledCode: "#line 2 \"lib/utility/debug.hpp\"\n\n#include <iostream>\n#include\
    \ <vector>\n\n#ifdef LOCAL\n#define debug(...)                               \
    \                              \\\n  std::cerr << \"LINE: \" << __LINE__ << \"\
    \  [\" << #__VA_ARGS__ << \"]:\",          \\\n      debug_out(__VA_ARGS__)\n\
    #define debug_assert(e) assert(e)\n#else\n#define debug(...)\n#define debug_assert(e)\n\
    #endif\n\ninline void debug_out() { std::cerr << std::endl; }\n\ntemplate <typename\
    \ T1, typename T2>\nstd::ostream &operator<<(std::ostream &os, std::pair<T1, T2>\
    \ pa) {\n  return os << pa.first << \" \" << pa.second;\n}\n\ntemplate <typename\
    \ T>\nstd::ostream &operator<<(std::ostream &os, std::vector<T> vec) {\n  for\
    \ (std::size_t i = 0; i < vec.size(); i++)\n    os << vec[i] << (i + 1 == vec.size()\
    \ ? \"\" : \" \");\n  return os;\n}\n\ntemplate <typename Head, typename... Tail>\
    \ void debug_out(Head h, Tail... t) {\n  std::cerr << \" \" << h;\n  if (sizeof...(t)\
    \ > 0)\n    std::cerr << \" :\";\n  debug_out(t...);\n}\n"
  code: "#pragma once\n\n#include <iostream>\n#include <vector>\n\n#ifdef LOCAL\n\
    #define debug(...)                                                           \
    \  \\\n  std::cerr << \"LINE: \" << __LINE__ << \"  [\" << #__VA_ARGS__ << \"\
    ]:\",          \\\n      debug_out(__VA_ARGS__)\n#define debug_assert(e) assert(e)\n\
    #else\n#define debug(...)\n#define debug_assert(e)\n#endif\n\ninline void debug_out()\
    \ { std::cerr << std::endl; }\n\ntemplate <typename T1, typename T2>\nstd::ostream\
    \ &operator<<(std::ostream &os, std::pair<T1, T2> pa) {\n  return os << pa.first\
    \ << \" \" << pa.second;\n}\n\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream\
    \ &os, std::vector<T> vec) {\n  for (std::size_t i = 0; i < vec.size(); i++)\n\
    \    os << vec[i] << (i + 1 == vec.size() ? \"\" : \" \");\n  return os;\n}\n\n\
    template <typename Head, typename... Tail> void debug_out(Head h, Tail... t) {\n\
    \  std::cerr << \" \" << h;\n  if (sizeof...(t) > 0)\n    std::cerr << \" :\"\
    ;\n  debug_out(t...);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/utility/debug.hpp
  requiredBy: []
  timestamp: '2024-08-01 15:13:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/utility/debug.hpp
layout: document
redirect_from:
- /library/lib/utility/debug.hpp
- /library/lib/utility/debug.hpp.html
title: lib/utility/debug.hpp
---
