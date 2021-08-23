/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-16 09:18:01  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// Bottom Up
int no_adj_sum(vector<int> a, int n) {
	vector<int> dp(n + 1, 0);
	dp[0] = max(a[0], 0);
	dp[1] = max({0, a[0], a[1]});
	if (n == 1)
		return max(a[0], 0);
	else if (n == 2)
		return max({0, a[0], a[1]});
	for (int i = 2; i < n; i++) {
		int inc = a[i] + dp[i - 2];
		int exc = dp[i - 1];
		dp[i] = max(inc, exc);
	}
	return dp[n - 1];
}

int no_adj_sum_topdown(vector<int> a, int n, vector<int> dp, int i) {
	if (i >= n)
		return 0;
	if (dp[i] != 0)
		return dp[i];
	dp[i] = max(no_adj_sum_topdown(a, n, dp, i + 1), a[i] + no_adj_sum_topdown(a, n, dp, i + 2));
	return dp[i];
}

int main()
{
	vector<int> a{6, 10, 12, 7, 9, 14};
	int n = a.size();
	cout << no_adj_sum(a, n) << ln; // 32
	vector<int> dp(n, 0);
	cout << no_adj_sum_topdown(a, n, dp, 0) << ln;
	return 0;
}
