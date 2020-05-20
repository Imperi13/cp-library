#pragma once

#include <memory>
#include <cassert>

//Monoid
// type value_t
// static var id
// static (value_t,value_t)->value_t op

template<typename Monoid>
class DynamicSegmentTree{
  public:
  using value_t = typename Monoid::value_t;
  using size_t=std::size_t;
  private:

  struct Node{
    value_t val;
    std::shared_ptr<Node> left,right;
    std::weak_ptr<Node> par;
    Node(value_t val_,const std::shared_ptr<Node>& par_=nullptr):val(val_),left(),right(),par(par_){}
  };

  using node_ptr=std::shared_ptr<Node>;
  using weak_ptr=std::weak_ptr<Node>;

  size_t n,n0;
  node_ptr root;

  value_t fold(size_t a,size_t b,const node_ptr& now,size_t l,size_t r){
    if(a<=l&&r<=b)return now->val;
    if(b<=l||r<=a)return Monoid::id;
    value_t lval=(now->left)?fold(a,b,now->left,l,l+(r-l)/2):Monoid::id;
    value_t rval=(now->right)?fold(a,b,now->right,l+(r-l)/2,r):Monoid::id;
    return Monoid::op(lval,rval);
  }

  public:
  DynamicSegmentTree(size_t n_):n(n_),root(new Node(Monoid::id)){
    n0=1;
    while(n0<n)n0<<=1;
  }

  void update(size_t i,value_t val,bool change){
    assert(0<=i&&i<n);
    node_ptr now(root);
    size_t l=0,r=n0;
    while(r-l>1){
      size_t mid=l+(r-l)/2;
      if(i<mid){
        if(!now->left)now->left=std::make_shared<Node>(Monoid::id,now);
        now=now->left;
        r=mid;
      }else{
        if(!now->right)now->right=std::make_shared<Node>(Monoid::id,now);
        now=now->right;
        l=mid;
      }
    }

    if(change)now->val=val;
    else now->val=Monoid::op(now->val,val);

    while(now->par.lock()){
      now=now->par.lock();
      now->val=Monoid::op((now->left)?now->left->val:Monoid::id,
                          (now->right)?now->right->val:Monoid::id);
    }
  }

  value_t fold(size_t a,size_t b){
    assert(0<=a&&a<=b&&b<=n);
    return fold(a,b,root,0,n0);
  }
};