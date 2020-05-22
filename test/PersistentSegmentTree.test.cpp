#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <iostream>
#include <algorithm>
#include <vector>

#include "../lib/SegmentTree/PersistentSegmentTree.cpp"

#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(a) a.begin(),a.end()

constexpr long long MOD=998244353;

struct Monoid{
  using value_t=long long;
  static constexpr value_t id=0;
  static constexpr value_t op(value_t a,value_t b){
    return a+b;
  }
};

using ll=long long;
using P=std::pair<ll,ll>;

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n,q;
  std::cin>>n>>q;

  std::vector<PersistentSegmentTree<Monoid>> seg(n+1);
  seg[n]=PersistentSegmentTree<Monoid>(1e9+10);

  struct Point{
    ll x,y,w;
    Point(ll a,ll b,ll c):x(a),y(b),w(c){}
  };
  std::vector<Point> points(n,Point(-1,-1,-1));

  rep(i,0,n)std::cin>>points[i].x>>points[i].y>>points[i].w;

  auto comp=[](const Point& a,const Point& b)->bool{return a.x<b.x;};
  std::sort(points.begin(),points.end(),comp);

  for(ll i=n-1;i>=0;i--)seg[i]=seg[i+1].update(points[i].y,points[i].w,false);

  rep(i,0,q){
    ll l,d,r,u;
    std::cin>>l>>d>>r>>u;

    ll ans=0;

    ans+=seg[std::lower_bound(all(points),Point(l,-1,-1),comp)-points.begin()].fold(d,u);
    ans-=seg[std::lower_bound(all(points),Point(r,-1,-1),comp)-points.begin()].fold(d,u);
    std::cout<<ans<<"\n";
  }

  return 0; 
}