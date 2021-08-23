/*

R E X


* @Author: Kunal Verma

    CodeForces - kunalverma19
    CodeChef   - kunalverma_19
    AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-06-16 11:30:34  (IST)
*/

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1000000007;
double eps = 1e-12;
#define ln "\n"
#define printVector(a) for(int i=0; i<a.size(); i++){cout<<a[i]<<" ";}cout<<ln;
#define print_array(a,n) for(int i=0; i<n; i++){cout<<a[i]<<" ";}cout<<ln;
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define take_vector(a) for(auto &x:a)cin>>x;
#define take_array(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define take_matrix(a,m,n) for(int i=0; i<m; i++){for(int j=0; j<n; j++){cin>>a[i][j];}}
#define print_matrix(a,m,n) for(int i=0; i<m; i++){for(int j=0; j<n; j++){cout<<a[i][j]<<" ";}cout<<ln;}
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/gcd(a,b))*b
#define count(a,x) count(a.begin(), a.end(),x)
#define sum(a) accumulate(a.begin(), a.end(),0)
#define max_ele(a) *max_element(a.begin(), a.end())
#define min_ele(a) *min_element(a.begin(), a.end())



/*

  Imlementation of Directed Unweighted

https://www.researchgate.net/profile/Tong-Wook-Shinn/publication/241689146/figure/fig1/AS:669015487815690@1536517130827/An-example-of-directed-unweighted-graph-with-edge-capacities.png

*/

// Function to add an edge between two vertices/nodes
void addEdge(vector<int> adjList[], int u, int v) {
  adjList[u].push_back(v);
}

// Function to print adjacency list representation of graph
void printGraph(vector<int> adj[], int nodes) {
  for (int u = 1; u <= nodes; u++) {
    cout << "Node " << u << " is connected with " << "\n head";
    for (auto x : adj[u])
      cout << " -> " << x;
    cout << ln;
  }
}


int main() {
  int nodes = 8;
  vector<int> adj[nodes + 1];
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 3);
  addEdge(adj, 1, 4);
  addEdge(adj, 2, 5);
  addEdge(adj, 3, 2);
  addEdge(adj, 3, 6);
  addEdge(adj, 3, 5);
  addEdge(adj, 4, 3);
  addEdge(adj, 4, 6);
  addEdge(adj, 4, 7);
  addEdge(adj, 5, 6);
  addEdge(adj, 5, 8);
  addEdge(adj, 6, 7);
  addEdge(adj, 6, 8);
  addEdge(adj, 7, 8);
  printGraph(adj, nodes);
  return 0;
}