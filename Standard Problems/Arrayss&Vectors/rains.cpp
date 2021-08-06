/*

R E X


* @Author: Kunal Verma

    CodeForces - kunalverma19
    CodeChef   - kunalverma_19
    AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-09 19:44:05  (IST)
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
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define gcd(a,b) __gcd(a,b)
#define memset(a,val) fill(a.begin(), a.end(),val)
#define lcm(a,b) (a/gcd(a,b))*b
#define count(a,x) count(a.begin(), a.end(),x)
#define sum(a) accumulate(a.begin(), a.end(),0)
#define max_ele(a) *max_element(a.begin(), a.end())
#define min_ele(a) *min_element(a.begin(), a.end())
#define setbit(x)  __builtin_popcount(x)

// Write a function that takes input an array of distinct integers, representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Time Complexity : O(n)
void solve()
{
	// Here I am, Beautiful
	v32 a{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = a.size();
	v32 left(n, -1), right(n, -1);
	left[0] = a[0];
	right[n - 1] = a[n - 1];
	for (int i = 1; i < n; i++) {
		left[i] = max(left[i - 1], a[i]);
		right[n - i - 1] = max(right[n - i], a[n - i - 1]);
	}
	int water = 0;
	for (int i = 0; i < n; i++) {
		water += min(left[i], right[i]) - a[i];
	}
	cout << water << ln;
}
int main()
{
#ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	fast_cin();
	ll t = 1;
	// cin >> t;
	for (int it = 1; it <= t; it++)
	{
		//cout << "Case #" << it+1 << ": ";
		solve();
	}
	return 0;
}
