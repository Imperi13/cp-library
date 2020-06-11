#include <memory>
#include <vector>
#include <utility>

template<typename Monoid>
class RBST_Seq{
  public:
  using value_t=typename Monoid::value_t;
  using size_t=std::size_t;
  private:
  unsigned int rnd(){
    static unsigned int x(123456789),y(362436069),z(521288629),w(88675123);
    unsigned int t=(x^(x<<11));
    x=y;y=z;z=w;
    return w=(w^(w>>19))^(t^(t>>8));
  }

  struct Node{
    value_t val,sum;
    size_t cnt;
    std::shared_ptr<Node> left,right;
    Node(value_t val_):val(val_),sum(val_),cnt(1),left(),right(){}
  };

  using node_ptr=std::shared_ptr<Node>;
  node_ptr root;

  value_t calc(const node_ptr& t){return t?t->sum:Monoid::id;}
  size_t count(const node_ptr& t){return t?t->cnt:0;}

  node_ptr update(node_ptr t){
    if(!t)return t;
    t->sum=Monoid::op(Monoid::op(calc(t->left),t->val),calc(t->right));
    t->cnt=count(t->left)+count(t->right)+1;
    return t;
  }

  node_ptr merge(node_ptr l,node_ptr r){
    if(!l||!r)return l?l:r;

    if(rnd()%(count(l)+count(r)) < count(l)){
      l->right=merge(l->right,r);
      return update(l);
    }else{
      r->left=merge(l,r->left);
      return update(r);
    }
  }

  std::pair<node_ptr,node_ptr> split(node_ptr t,size_t k){
    if(!t)return std::make_pair(t,t);

    if(k<=count(t->left)){
      auto temp=split(t->left,k);
      t->left=temp.second;
      return std::make_pair(temp.first,update(t));
    }else{
      auto temp=split(t->right,k-count(t->left)-1);
      t->right=temp.first;
      return std::make_pair(update(t),temp.second);
    }
  }

  void insert(node_ptr& t,node_ptr newnode,size_t k){
    auto temp=split(t,k);
    t=merge(merge(temp.first,newnode),temp.second);
  }

  void erase(node_ptr& t,size_t k){
    auto temp=split(t,k+1);
    auto temp2=split(temp.first,k);
    t=merge(temp2.first,temp.second);
  }

  void build(node_ptr& t,const std::vector<value_t>& val_,size_t l,size_t r){
    if(l==r){
      t=nullptr;
      return;
    }
    if(r==l+1){
      t=std::make_shared<Node>(val_[l]);
      return;
    }

    size_t mid=l+(r-l)/2;
    t=std::make_shared<Node>(val_[mid]);
    build(t->left,val_,l,mid);
    build(t->right,val_,mid+1,r);
    update(t);
  }

  RBST_Seq(const node_ptr& t):root(t){}
  public:
  RBST_Seq():root(){}
  RBST_Seq(const std::vector<value_t>& seq_):root(){
    build(root,seq_,0,seq_.size());
  }

  size_t size(){return count(root);}
  void insert(size_t k,const value_t& value){insert(root,std::make_shared<Node>(value),k);}
  void erase(size_t k){erase(root,k);}

  RBST_Seq split(size_t l,size_t r){
    assert(0<=l&&l<=r&&r<=size());
    auto tmp=split(root,r);
    auto tmp2=split(tmp.first,l);
    root=merge(tmp2.first,tmp.second);
    return RBST_Seq(tmp2.second);
  }

  void insert(size_t pos,RBST_Seq seq){
    assert(0<=pos&&pos<=size());
    auto tmp=split(root,pos);
    tmp.first=merge(tmp.first,seq.root);
    root=merge(tmp.first,tmp.second);
  }

  value_t fold_all(){return calc(root);}
  value_t fold(size_t l,size_t r){
    auto temp=split(root,r);
    auto temp2=split(temp.first,l);
    value_t ret=calc(temp2.second);
    root=merge(merge(temp2.first,temp2.second),temp.second);

    return ret;
  }
};