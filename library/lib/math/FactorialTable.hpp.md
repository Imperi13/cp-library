---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: lib/math/FactorialTable.hpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#b524a7b47b8ed72180f0e5150ab6d934">lib/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/math/FactorialTable.hpp">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "../local/modint.hpp"

#include <vector>
#include <cassert>
#include <cstdint>

template<std::size_t N,std::uint_fast64_t MOD>
class Factorial{
  public:
  using mint=modint<MOD>;
  using size_t=std::size_t;
  private:
  std::vector<mint> factorial,factorial_inv;
  public:
  Factorial():factorial(N+1),factorial_inv(N+1){
    factorial[0]=1;
    for(size_t i=1;i<N+1;i++)factorial[i]=factorial[i-1]*i;
    factorial_inv[N]=mint(1)/factorial[N];
    for(size_t i=N;i>0;i--)factorial_inv[i-1]=factorial_inv[i]*i;
  }

  mint fact(size_t pos)const{
    assert(0<=pos&&pos<=N);
    return factorial[pos];
  }
  mint fact_inv(size_t pos)const{
    assert(0<=pos&&pos<=N);
    return factorial_inv[pos];
  }
  mint binom(size_t n,size_t k)const{
    assert(0<=n&&n<=N);
    assert(0<=k&&k<=n);
    return fact(n)*fact_inv(k)*fact_inv(n-k);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 307, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 187, in _resolve
    raise BundleErrorAt(path, -1, "no such header")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../local/modint.hpp: line -1: no such header

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

