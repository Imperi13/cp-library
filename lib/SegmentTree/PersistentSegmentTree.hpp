#pragma once

#include <memory>
#include <cassert>

template<typename Monoid>
class PersistentSegmentTree{
  public:
  using value_t=typename Monoid::value_t;
  using size_t=std::size_t;
  private:
  struct Node{
    value_t val;
    std::shared_ptr<Node> left,right;
    std::weak_ptr<Node> par;
    Node(value_t val_,std::shared_ptr<Node> par_=nullptr):val(val_),left(),right(),par(par_){}
  };

  using node_ptr=std::shared_ptr<Node>;
  size_t n,n0;
  node_ptr root;

  value_t fold(size_t a,size_t b,const node_ptr& now,size_t l,size_t r){
    if(a<=l&&r<=b)return now->val;
    if(b<=l||r<=a)return Monoid::id;
    value_t lval=(now->left)?fold(a,b,now->left,l,l+(r-l)/2):Monoid::id;
    value_t rval=(now->right)?fold(a,b,now->right,l+(r-l)/2,r):Monoid::id;
    return Monoid::op(lval,rval);
  }

  PersistentSegmentTree(size_t n_,size_t n0_,const node_ptr& root_):n(n_),n0(n0_),root(root_){}
  public:
  PersistentSegmentTree(size_t n_=0):n(n_),root(new Node(Monoid::id)){
    n0=1;
    while(n0<n)n0<<=1;
  }

  PersistentSegmentTree update(size_t i,value_t value,bool change){
    assert(0<=i&&i<n);
    node_ptr now(root);
    node_ptr newroot=std::make_shared<Node>(Monoid::id),cur(newroot);

    size_t l=0,r=n0;
    bool isok=true;
    while(r-l>1){
      size_t mid=l+(r-l)/2;
      if(i<mid){
        if(isok&&now->right)cur->right=now->right;
        cur->left=std::make_shared<Node>(Monoid::id,cur);
        if(isok){
          if(!now->left)isok=false;
          else now=now->left;
        }
        cur=cur->left;
        r=mid;
      }else{
        if(isok&&now->left)cur->left=now->left;
        cur->right=std::make_shared<Node>(Monoid::id,cur);

        if(isok){
          if(!now->right)isok=false;
          else now=now->right;
        }
        cur=cur->right;
        l=mid;
      }
    }

    if(change)cur->val=value;
    else cur->val=Monoid::op((isok)?now->val:Monoid::id,value);

    while(cur->par.lock()){
      cur=cur->par.lock();
      cur->val=Monoid::op((cur->left)?cur->left->val:Monoid::id,
                          (cur->right)?cur->right->val:Monoid::id);
    }

    return PersistentSegmentTree(n,n0,newroot);
  }

  value_t fold(size_t l,size_t r){
    assert(0<=l&&l<=r&&r<=n);
    return fold(l,r,root,0,n0);
  }
};