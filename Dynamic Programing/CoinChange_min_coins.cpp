/*
Given denominations of coins and a value N. Find the minimum number of coins to make N.
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <functional>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define ln "\n"
#define printVector(a) for(int i=0; i<a.size(); i++){cout<<a[i]<<" ";}cout<<ln;
#define print_array(a,n) for(int i=0; i<n; i++){cout<<a[i]<<" ";}cout<<ln;
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define take_vector(a) for(int &x:a)cin>>x;
#define take_array(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define take_matrix(a,m,n) for(int i=0; i<m; i++){for(int j=0; j<n; j++){cin>>a[i][j];}}
#define print_matrix(a,m,n) for(int i=0; i<m; i++){for(int j=0; j<n; j++){cout<<a[i][j]<<" ";}cout<<ln;}
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int coins(vector<int> a, int sum, int size){
  int dp[sum+1];
  for(int i=0; i<=sum;i++)
    dp[i]=INT_MAX;
  dp[0]=0;
  for(int i=1; i<=sum; i++){
    for(int j=0; j<size; j++){
      if (i>=a[j])
        dp[i]=min(dp[i],dp[i-a[j]]+1);
    }
  }
  return dp[sum];
}
void solve(){
  int n;
  cin>>n; // number of elements
  vector<int> a(n);
  take_vector(a); // taking array
  int elem;
  cin>>elem; // taking target N
  cout<<coins(a,elem,n)<<ln;
}

int main()
{
 fast_cin();
 ll t=1;
 //cin >> t;
 for(int it=1;it<=t;it++) {
     //cout << "Case #" << it+1 << ": ";
     solve();
 }
 return 0;
}
