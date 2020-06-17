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
  using value_t=typename Monoid::value_t;
  using size_t=std::size_t;
  private:

  struct Node{
    value_t val;
    Node *left,*right,*par;
    Node(Node *par_=nullptr):val(Monoid::id),left(),right(),par(par_){}
    ~Node(){
      if(left)delete left;
      if(right)delete right;
      left=nullptr;right=nullptr;
      par=nullptr;
    }
  };

  using node_ptr=Node *;
  
  size_t n,n0;
  node_ptr root;

  value_t fold(size_t a,size_t b,const node_ptr& now,size_t l,size_t r){
    if(a<=l&&r<=b)return now->val;
    if(b<=l||r<=a)return Monoid::id;
    value_t lval=(now->left)?fold(a,b,now->left,l,l+(r-l)/2):Monoid::id;
    value_t rval=(now->right)?fold(a,b,now->right,l+(r-l)/2,r):Monoid::id;
    return Monoid::op(lval,rval);
  }

  void dfs(node_ptr node,node_ptr from){
    node->val=from->val;
    if(from->left){
      node->left=new Node(node);
      dfs(node->left,from->left);
    }
    if(from->right){
      node->right=new Node(node);
      dfs(node->right,from->right);
    }
  }

  public:
  DynamicSegmentTree(size_t n_=0):n(n_),root(nullptr){
    n0=1;
    while(n0<n)n0<<=1;
  }
  DynamicSegmentTree(const DynamicSegmentTree& from){
    n=from.n;n0=from.n0;root=nullptr;
    if(from.root){
      root=new Node();
      dfs(root,from.root);
    }
  }
  DynamicSegmentTree& operator=(const DynamicSegmentTree& from){
    n=from.n;n0=from.n0;root=nullptr;
    if(from.root){
      root=new Node();
      dfs(root,from.root);
    }
  }
  DynamicSegmentTree(DynamicSegmentTree&&)=default;
  DynamicSegmentTree& operator=(DynamicSegmentTree&&)=default;
  ~DynamicSegmentTree(){
    if(root)delete root;
    root=nullptr;
  }

  void update(size_t i,value_t val,bool change){
    assert(0<=i&&i<n);
    if(!root)root=new Node();
    node_ptr now=root;
    size_t l=0,r=n0;
    while(r-l>1){
      size_t mid=l+(r-l)/2;
      if(i<mid){
        if(!now->left)now->left=new Node(now);
        now=now->left;
        r=mid;
      }else{
        if(!now->right)now->right=new Node(now);
        now=now->right;
        l=mid;
      }
    }
    if(change)now->val=val;
    else now->val=Monoid::op(now->val,val);

    while(now->par){
      now=now->par;
      now->val=Monoid::op((now->left)?now->left->val:Monoid::id,
                          (now->right)?now->right->val:Monoid::id);
    }
  }

  value_t fold(size_t a,size_t b){
    assert(0<=a&&a<=b&&b<=n);
    if(!root)return Monoid::id;
    return fold(a,b,root,0,n0);
  }
};