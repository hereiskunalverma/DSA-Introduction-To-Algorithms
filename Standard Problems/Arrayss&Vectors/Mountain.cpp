/*

R E X


* @Author: Kunal Verma

    CodeForces - kunalverma19
    CodeChef   - kunalverma_19
    AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-06 09:40:04  (IST)
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

// Write a function that takes input an array of distinct integers, and returns the lenght of the highest mountian

// A mountain is defined as adjacent integers that are strictly increasing until they reach a peak, at which they becoming decreasing.

// At least 3 numbers are required to form a mountain.



// Time Complexity : O(2n) => O(n)
void solve()
{
	// Here I am, Beautiful
	v32 a {6, 5, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
	int n = a.size();
	int largest = 0;
	for (int i = 1; i < n - 1; i++) {
		if (a[i] > a[i - 1] and a[i] > a[i + 1]) {
			int count = 1; // peak
			int j = i;
			while (j >= 1 and a[j] > a[j - 1]) {
				j--;
				count++;
			}
			j = i;
			while (j < n - 1 and a[j] > a[j + 1]) {
				j++;
				count++;
			}
			largest = max(largest, count);
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
