/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-16 08:28:35  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

int max_profit(vector<int> prices, int n) {
	if (n <= 0)
		return 0;
	int ans = INT_MIN;
	for (int i = 0; i < n; i++) {
		int cut = i + 1;
		int cur_ans = prices[i] + max_profit(prices, n - cut);
		ans = max(ans, cur_ans);
	}
	return ans;
}

int max_profit_dp(vector<int> prices, int n) {
	int dp[n + 1];
	dp[0] = 0;
	for (int len = 1; len <= n; len++) {
		int ans = INT_MIN;
		for (int i = 0; i < len; i++) {
			int cut = i + 1;
			int cur_ans = prices[i] + dp[len - cut];
			ans = max(cur_ans, ans);
		}
		dp[len] = ans;
	}
	return dp[n];
}

int main()
{
	vector<int> price{1, 5, 8, 9, 10, 17, 17, 20};
	int n = price.size();
	cout << max_profit_dp(price, n) << ln; // 2
}
