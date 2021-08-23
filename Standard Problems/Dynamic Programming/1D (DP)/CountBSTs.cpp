/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-16 09:55:30  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// Top Down
int countBST(int n, int dp[]) {
	if (n == 0 or n == 1)
		return 1;
	if (dp[n] != 0)
		return dp[n];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = countBST(i - 1, dp);
		int y = countBST(n - i, dp);
		ans += x * y;
	}
	return dp[n] = ans;
}

// Bottom Up
int countBSTBU(int n) {
	vector<int> dp(n + 1, 0);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] += (dp[j - 1] * dp[i - j]);
		}
	}
	return dp[n];
}

int main()
{
	int n = 3;
	int dp[n + 1] = {0};
	cout << countBST(n, dp) << ln; // 5
	cout << countBSTBU(n) << ln;
	return 0;
}
