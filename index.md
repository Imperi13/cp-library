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
<script type="text/javascript" src="assets/js/copy-button.js"></script>
<link rel="stylesheet" href="assets/css/copy-button.css" />


# {{ site.title }}

[![Actions Status]({{ site.github.repository_url }}/workflows/verify/badge.svg)]({{ site.github.repository_url }}/actions)
<a href="{{ site.github.repository_url }}"><img src="https://img.shields.io/github/last-commit/{{ site.github.owner_name }}/{{ site.github.repository_name }}" /></a>

{% if site.github.project_tagline %}{{ site.github.project_tagline }}{% else %}This documentation is automatically generated by <a href="https://github.com/online-judge-tools/verification-helper">online-judge-tools/verification-helper</a>.{% endif %}

## Library Files

<div id="e8acc63b1e238f3255c900eed37254b8"></div>

### lib

* :heavy_check_mark: <a href="library/lib/PersistentArray.cpp.html">lib/PersistentArray.cpp</a>
* :warning: <a href="library/lib/PersistentStack.cpp.html">lib/PersistentStack.cpp</a>
* :warning: <a href="library/lib/RBST_Multiset.cpp.html">lib/RBST_Multiset.cpp</a>
* :heavy_check_mark: <a href="library/lib/RBST_Seq.cpp.html">lib/RBST_Seq.cpp</a>
* :heavy_check_mark: <a href="library/lib/SWAG.cpp.html">lib/SWAG.cpp</a>
* :heavy_check_mark: <a href="library/lib/SparseTable.cpp.html">lib/SparseTable.cpp</a>


<div id="8d75131a1ef4f10f86f251b50b9a3462"></div>

### lib/SegmentTree

* :heavy_check_mark: <a href="library/lib/SegmentTree/DualSegmentTree.cpp.html">lib/SegmentTree/DualSegmentTree.cpp</a>
* :heavy_check_mark: <a href="library/lib/SegmentTree/DynamicSegmentTree.cpp.html">lib/SegmentTree/DynamicSegmentTree.cpp</a>
* :heavy_check_mark: <a href="library/lib/SegmentTree/LazySegmentTree.cpp.html">lib/SegmentTree/LazySegmentTree.cpp</a>
* :heavy_check_mark: <a href="library/lib/SegmentTree/PersistentSegmentTree.cpp.html">lib/SegmentTree/PersistentSegmentTree.cpp</a>
* :heavy_check_mark: <a href="library/lib/SegmentTree/SegmentTree.cpp.html">lib/SegmentTree/SegmentTree.cpp</a>


<div id="d8ce77e7929e89891ebe5f859497af18"></div>

### lib/UnionFind

* :heavy_check_mark: <a href="library/lib/UnionFind/PersistentUnionFind.cpp.html">lib/UnionFind/PersistentUnionFind.cpp</a>
* :heavy_check_mark: <a href="library/lib/UnionFind/PotentialUnionFind.cpp.html">lib/UnionFind/PotentialUnionFind.cpp</a>
* :heavy_check_mark: <a href="library/lib/UnionFind/UnionFind.cpp.html">lib/UnionFind/UnionFind.cpp</a>


<div id="e9d5fea60f5f423df499112093a5df91"></div>

### lib/WaveletMatrix

* :heavy_check_mark: <a href="library/lib/WaveletMatrix/BitVector.cpp.html">lib/WaveletMatrix/BitVector.cpp</a>
* :heavy_check_mark: <a href="library/lib/WaveletMatrix/WaveletMatrix.cpp.html">lib/WaveletMatrix/WaveletMatrix.cpp</a>


<div id="6e267a37887a7dcb68cbf7008d6c7e48"></div>

### lib/graph

* :heavy_check_mark: <a href="library/lib/graph/LowestCommonAncestor.cpp.html">lib/graph/LowestCommonAncestor.cpp</a>


<div id="b524a7b47b8ed72180f0e5150ab6d934"></div>

### lib/math

* :heavy_check_mark: <a href="library/lib/math/DynamicMatrix.cpp.html">lib/math/DynamicMatrix.cpp</a>
* :warning: <a href="library/lib/math/Matrix.cpp.html">lib/math/Matrix.cpp</a>


<div id="a6e10e9711dc4788c3e9e6f87d9357db"></div>

### lib/utility

* :warning: <a href="library/lib/utility/Monoid.cpp.html">lib/utility/Monoid.cpp</a>
* :heavy_check_mark: <a href="library/lib/utility/runtime_modint.cpp.html">lib/utility/runtime_modint.cpp</a>


## Verify Files

* :heavy_check_mark: <a href="verify/test/DualSegmentTree.test.cpp.html">test/DualSegmentTree.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/DynamicMatrix.test.cpp.html">test/DynamicMatrix.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/DynamicMatrix_2.test.cpp.html">test/DynamicMatrix_2.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/DynamicSegmentTree.test.cpp.html">test/DynamicSegmentTree.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/LazySegmentTree.test.cpp.html">test/LazySegmentTree.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/LowestCommonAncestor.test.cpp.html">test/LowestCommonAncestor.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/PersistentArray.test.cpp.html">test/PersistentArray.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/PersistentArray_2.test.cpp.html">test/PersistentArray_2.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/PersistentSegmentTree.test.cpp.html">test/PersistentSegmentTree.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/PersistentUnionFind.test.cpp.html">test/PersistentUnionFind.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/PotentialUnionFind.test.cpp.html">test/PotentialUnionFind.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/RBST_Seq.test.cpp.html">test/RBST_Seq.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/SWAG.test.cpp.html">test/SWAG.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/SegmentTree.test.cpp.html">test/SegmentTree.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/SparseTable.test.cpp.html">test/SparseTable.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/UnionFind.test.cpp.html">test/UnionFind.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/WaveletMatrix.test.cpp.html">test/WaveletMatrix.test.cpp</a>

