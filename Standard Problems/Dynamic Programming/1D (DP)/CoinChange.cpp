/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-13 09:56:41  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// top down approach
int top_down(vector<int> coins, int sum, vector<int> &dp) {
	if (sum < 0)
		return -1;
	if (sum == 0)
		return 0;
	if (dp[sum] != 0)
		return dp[sum];
	int ans = INT_MAX;
	for (int i = 0; i < coins.size(); i++) {
		int val = top_down(coins, sum - coins[i], dp);
		if (val >= 0 and val < ans)
			ans = val + 1;
	}
	dp[sum] = (ans == INT_MAX) ? -1 : ans;
	return dp[sum];
}

// bottom up approach
int minNumberOfCoinChange(vector<int> coins, int sum) {
	vector<int> dp(sum + 1, 0);
	dp[0] = 0;
	for (int i = 1; i <= sum; i++) {
		dp[i] = INT_MAX;
		for (int c : coins) {
			if (i - c >= 0 and dp[i - c] != INT_MAX)
				dp[i] = min(dp[i], dp[i - c]) + 1;
		}
	}
	return dp[sum] == INT_MAX ? -1 : dp[sum];
}


int main()
{
	vector<int> coins{1, 5, 7, 10};
	int sum = 8;
	cout << minNumberOfCoinChange(coins, sum) << ln;
	vector<int> dp(sum + 1, 0);
	cout << top_down(coins, sum, dp) << ln;
}
