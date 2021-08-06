/*

R E X


* @Author: Kunal Verma

    CodeForces - kunalverma19
    CodeChef   - kunalverma_19
    AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-09 19:04:42  (IST)
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

// Write a function that takes input an array of distinct integers, and returns the lenght of the longest band

// A band is defined as a subsequence which can be re-ordered in such a manner all elemnent appear consecutive (i.e., with absolute difference of 1 between neighbouring elements)

// A longest band is the band (subsequence) which contains maximum integers.

// Time Complexity : O(n)

// an array has 2^n subsequences.
void solve()
{
	// Here I am, Beautiful
	v32 a{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6}; // output -> 8

	// Below is O(nlogn)

	// int largest = INT_MIN;
	// int curr_len = 1;
	// sort(all(a));
	// int n = a.size();
	// for (int i = 0; i < n; i ++) {
	// 	if (a[i + 1] == a[i] + 1)
	// 		curr_len++;
	// 	else if (a[i] == a[i + 1])
	// 		continue;
	// 	else
	// 		curr_len = 1;
	// 	largest = max(largest, curr_len);
	// }
	// cout << max(largest, curr_len) << ln;

	// Below is O(n)
	int n = a.size();
	unordered_set<int> hash;
	int largest = 1;
	for (auto x : a)
		hash.insert(x);
	for (auto el : a) {
		int parent = el - 1;
		if (hash.find(parent) == hash.end()) {
			int next_no = el + 1;
			int curr = 1;
			while (hash.find(next_no) != hash.end()) {
				next_no++;
				curr++;
			}
			if (curr > largest)
				largest = curr;
		}
	}
	cout << largest << ln;
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
