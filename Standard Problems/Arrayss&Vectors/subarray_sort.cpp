/*

R E X


* @Author: Kunal Verma

    CodeForces - kunalverma19
    CodeChef   - kunalverma_19
    AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-09 20:21:03  (IST)
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

// Given an array of size at-least two, find the smallest subarray that needs to be sorted in place so that entire input array becomes sorted.

// If the input array is already sorted, the function should return [-1,-1], otherwise return the start & end index of smalllest subarray.

// Time Complexity : O(n) and O(nlogn)


bool outOfOrder(v32 a, int i) {
	int x = a[i];
	if (i == 0)
		return x > a[1];
	if (i == a.size() - 1)
		return x < a[i - 1];
	return (x > a[i] or x < a[i]);
}

pair<int, int> On(vector<int> a) {
	int smallest = INT_MAX;
	int largest = INT_MIN;
	for (int i = 0; i < a.size(); i++) {
		int x = a[i];
		if (outOfOrder(a, i)) {
			cout << outOfOrder(a, i) << ln;
			smallest = min(smallest, x);
			largest = max(largest, x);
		}
	}
	if (smallest == INT_MAX)
		return { -1, -1};
	int left = 0;
	while (smallest >= a[left])
		left++;
	int right = a.size() - 1;
	while (largest <= a[right])
		right--;
	return {left, right};
}
void solve()
{
	// Here I am, Beautiful
	v32 a{1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
	int n = a.size();
	// Below is O(nlogn)+O(n) => O(nlogn)

	// v32 b;
	// for (auto el : a)
	// 	b.pb(el);
	// sort(all(b));
	// v32 ans;
	// int flag=0;
	// for (int i = 0; i < n; i++) {
	// 	if (a[i] != b[i]) {
	//      flag=1;
	// 		ans.pb(i + 1);
	// 	}
	// }
	// if (flag)

	// cout << ans.front() << " " << ans.back() << ln;
	//  else
	//     cout<<-1<<" "<<-1<<ln;

	// Below is O(n)
	auto p = On(a);
	cout << p.fi << " " << p.se << ln;
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

