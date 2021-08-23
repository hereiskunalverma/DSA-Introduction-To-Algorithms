/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-18 08:50:05  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// Recursive Code => Top Down
int knapsack(vector<int> wts, vector<int> prices, int n, int w) {
	// base case
	if (n == 0 or w == 0)
		return 0;
	// rec case
	int inc = 0, exc = 0;
	if (wts[n - 1] <= w) {
		inc = prices[n - 1] + knapsack(wts, prices, n - 1, w - wts[n - 1]);
	}
	exc = knapsack(wts, prices, n - 1, w);
	return max(inc, exc);
}

// Bottom Approach
// O(N*W)
int knapsack_BU(vector<int> wt, vector<int> prices, int N, int W) {
	vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
	for (int n = 1; n <= N; n++) {
		for (int w = 1; w <= W; w++) {
			int inc = 0, exc = 0;
			if (wt[n - 1] <= w)
				inc = prices[n - 1] + dp[n - 1][w - wt[n - 1]];
			exc = dp[n - 1][w];
			dp[n][w] = max(inc, exc);
		}
	}
	return dp[N][W];
}
int main()
{
	int n = 4, w = 11;
	vector<int> wts{2, 7, 3, 4};
	vector<int> prices{5, 20, 20, 10};
	cout << knapsack(wts, prices, n, w) << ln; // 40
	cout << knapsack_BU(wts, prices, n, w) << ln; // 40
}
