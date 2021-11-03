---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: utility/type_alias.hpp:\
    \ line -1: no such header\n"
  code: "#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <chrono>\n#include <cmath>\n#include <complex>\n#include\
    \ <cstdint>\n#include <cstdlib>\n#include <deque>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <limits>\n#include <list>\n#include\
    \ <map>\n#include <memory>\n#include <numeric>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <stack>\n#include <string>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <utility>\n#include <vector>\n\n/* template\
    \ start */\n\n#include \"utility/type_alias.hpp\"\n\n#define rep(i, a, b) for\
    \ (i64 i = (a); (i) < (b); (i)++)\n#define all(i) i.begin(), i.end()\n\n#ifdef\
    \ LOCAL\n#define debug(...)                                                  \
    \  \\\n  std::cerr << \"LINE: \" << __LINE__ << \"  [\" << #__VA_ARGS__ << \"\
    ]:\", \\\n      debug_out(__VA_ARGS__)\n#else\n#define debug(...)\n#endif\n\n\
    void debug_out() { std::cerr << std::endl; }\n\ntemplate <typename Head, typename...\
    \ Tail>\nvoid debug_out(Head h, Tail... t) {\n  std::cerr << \" \" << h;\n  if\
    \ (sizeof...(t) > 0) std::cerr << \" :\";\n  debug_out(t...);\n}\n\ntemplate <typename\
    \ T1, typename T2>\nstd::ostream& operator<<(std::ostream& os, std::pair<T1, T2>\
    \ pa) {\n  return os << pa.first << \" \" << pa.second;\n}\n\ntemplate <typename\
    \ T>\nstd::ostream& operator<<(std::ostream& os, std::vector<T> vec) {\n  for\
    \ (std::size_t i = 0; i < vec.size(); i++)\n    os << vec[i] << (i + 1 == vec.size()\
    \ ? \"\" : \" \");\n  return os;\n}\n\ntemplate <typename T1, typename T2>\ninline\
    \ bool chmax(T1& a, T2 b) {\n  return a < b && (a = b, true);\n}\n\ntemplate <typename\
    \ T1, typename T2>\ninline bool chmin(T1& a, T2 b) {\n  return a > b && (a = b,\
    \ true);\n}\n\ntemplate <typename Num, typename Func = std::multiplies<Num>>\n\
    constexpr Num mypow(Num a, u64 b, Num id = 1, Func mul = Func()) {\n  if (b ==\
    \ 0) return id;\n  Num x = id;\n  while (b > 0) {\n    if (b & 1) x = mul(x, a);\n\
    \    a = mul(a, a);\n    b >>= 1;\n  }\n  return x;\n}\n\n/* template end */\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n\
    \n  return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/template/template.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/template/template.cpp
layout: document
redirect_from:
- /library/lib/template/template.cpp
- /library/lib/template/template.cpp.html
title: lib/template/template.cpp
---
