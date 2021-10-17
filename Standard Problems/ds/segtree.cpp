/*Made by Shivam Solanki*/
#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define ll long long int
#define endl '\n'
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<pii> vp;
typedef vector<pll> vpll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef set<int> sii;
typedef set<ll> sll;
typedef queue<int> qii;
typedef priority_queue<int> pq;
typedef unordered_map<int,int> umii;
typedef unordered_map<ll,ll> umll;
#define all(x) x.begin(),x.end()
#define rep(i,k,n) for (int i = k; i < n; ++i) 
#define repr(i,k,n) for (int i = n; i>=k; --i)
#define repll(i,k,n) for (ll i = k; i < n; ++i) 
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define F first
#define S second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int INF = 1e9+5;
const int MOD = 1e9+7;
double pi = 2 * acos(0.0); 

//Codeforces EDU Step 1 and Step 2 practise solutions Basic Sum Over Segment Tree,RMQ, RMQ with counts

struct dat{
   int data;
};

dat func(dat a,dat b){
   return {max(a.data,b.data)};
}

dat NEUTRAL_ELEMENT={-INF};

dat single(int v){
   return {v};
   //if(v>0) return {v};
   //return {v};
}

vector<dat>segtree;

int init(int n,int size){
   while(size<n) size*=2;
   segtree.resize(2*size);
   return size;
}

void build(vi &a,int x,int lx,int rx){
   if(rx-lx==1){
      if(lx<(int)a.size()) segtree[x]=single(a[lx]);
   }
   else{
      int m=(lx+rx)/2;
      build(a,x*2+1,lx,m);
      build(a,x*2+2,m,rx);
      segtree[x]=func(segtree[x*2+1],segtree[x*2+2]);
   }
}

void update(int i,int v,int x,int lx,int rx){
   if(rx-lx==1) segtree[x]=single(v);
   else{
      int m=(lx+rx)/2;
      if(i<m) update(i,v,2*x+1,lx,m);
      else update(i,v,2*x+2,m,rx);
      segtree[x]=func(segtree[x*2+1],segtree[x*2+2]);
   }
}

dat query(int l,int r,int x,int lx,int rx){
   if(lx>=r||l>=rx) return NEUTRAL_ELEMENT;
   if(lx>=l&&rx<=r) return segtree[x];
   int m=(lx+rx)/2;
   return func(query(l,r,x*2+1,lx,m),query(l,r,x*2+2,m,rx));
}

dat find(int k,int x,int lx,int rx){
   if(rx-lx==1) return {lx};
   int m=(lx+rx)/2;
   dat sl=segtree[2*x+1];
   if(k<sl.data) return find(k,2*x+1,lx,m);
   else return find(k-sl.data,2*x+2,m,rx);
}

dat first_above(int v,int l,int x,int lx,int rx){
   if(segtree[x].data<v) return {-1};
   if(rx<=l) return {-1};
   if(rx-lx==1) return {lx};
   int m=(lx+rx)/2;
   dat res=first_above(v,l,2*x+1,lx,m);
   if(res.data==-1){
      res=first_above(v,l,x*2+2,m,rx);
   }
   return res;
}

void solve(){
   int n,m;
   cin>>n>>m;
   int size=init(n,1);
   vi a(n);
   rep(i,0,n) cin>>a[i];
   build(a,0,0,size);
   int i,v;
   while(m--){
      int op;
      cin>>op;
      if(op==1){
         int i,v;
         cin>>i>>v;
         update(i,v,0,0,size);
      }
      else{
         int k,l;
         cin>>k>>l;
         cout<<first_above(k,l,0,0,size).data<<'\n';
      }
   }
}

int main(){ 
   // #ifndef ONLINE_JUDGE  
      // freopen("input.txt", "r", stdin); 
      // freopen("output.txt", "w", stdout); 
   // #endif 
   fastio;
   int t=1;
   //cin>>t;
   while(t--)
      solve();
   return 0;
}
