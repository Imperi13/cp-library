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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: utility/type_alias.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include <functional>\n\n#include \"utility/type_alias.hpp\"\
    \n\ntemplate <typename T1, typename T2>\ninline bool chmax(T1 &a, T2 b) {\n  return\
    \ a < b && (a = b, true);\n}\n\ntemplate <typename T1, typename T2>\ninline bool\
    \ chmin(T1 &a, T2 b) {\n  return a > b && (a = b, true);\n}\n\ntemplate <typename\
    \ Num, typename Func = std::multiplies<Num>>\nconstexpr Num mypow(Num a, u64 b,\
    \ Num id = 1, Func mul = Func()) {\n  if (b == 0) return id;\n  Num x = id;\n\
    \  while (b > 0) {\n    if (b & 1) x = mul(x, a);\n    a = mul(a, a);\n    b >>=\
    \ 1;\n  }\n  return x;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/utility/template.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/utility/template.hpp
layout: document
redirect_from:
- /library/lib/utility/template.hpp
- /library/lib/utility/template.hpp.html
title: lib/utility/template.hpp
---
