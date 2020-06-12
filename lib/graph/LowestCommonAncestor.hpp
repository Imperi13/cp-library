#pragma once

#include <vector>

class LowestCommonAncestor{
  public:
  using size_t=std::size_t;
  private:
  size_t n,bit;
  std::vector<size_t> depth;
  std::vector<std::vector<size_t>> par_dbl;

  size_t log(size_t tmp){
    size_t ret=1;
    while(tmp>0){
      ret++;
      tmp>>=1;
    }
    return ret;
  }
  public:
  template<typename Edge>
  LowestCommonAncestor(size_t root,const std::vector<std::vector<Edge>>& graph)
                      :n(graph.size()),bit(log(n)),depth(n),par_dbl(n,std::vector<size_t>(bit)){
    auto dfs=[&](auto f,size_t now,size_t par,size_t dep)->void{
      depth[now]=dep;
      if(dep!=0)par_dbl[now][0]=par;
      else par_dbl[now][0]=now;

      for(const auto& e:graph[now]){
        if(e!=par)f(f,e,now,dep+1);
      }
    };
    dfs(dfs,root,-1,0);
    for(size_t i=1;i<bit;i++){
      for(size_t j=0;j<n;j++)par_dbl[j][i]=par_dbl[par_dbl[j][i-1]][i-1];
    }
  }

  size_t lca(size_t a,size_t b){
    if(depth[a]<depth[b])std::swap(a,b);
    for(size_t i=0;i<bit;i++){
      if(((depth[a]-depth[b])>>i)&1)a=par_dbl[a][i];
    }
    if(a==b)return a;
    for(long long i=bit-1;i>=0;i--){
      if(par_dbl[a][i]!=par_dbl[b][i]){
        a=par_dbl[a][i];
        b=par_dbl[b][i];
      }
    }
    return par_dbl[a][0];
  }
};