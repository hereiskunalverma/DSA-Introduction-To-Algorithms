/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-13 09:30:47  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

/*Approaches

1. Recursive
2. Top Down
3. Bottom Up
4. Bottom Up Optimised Recurrence
*/

// O(k^n)
int recursive(int n, int k) {
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;
	int ans = 0;
	for (int i = 1; i <= k; i++)
		ans += recursive(n - i, k);
	return ans;
}

// O(n*k)
int top_down(int n, int k, int *dp) {
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;
	//check if state is computed
	if (dp[n] != 0)
		return dp[n];

	int ans = 0;
	for (int i = 1; i <= k; i++)
		ans += top_down(n - i, k, dp);
	return dp[n] = ans;
}

// O(n*k)
int bottom_up(int n, int k) {
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int jump = 1; jump <= k; jump++) {
			if (i - jump >= 0)
				dp[i] += dp[i - jump];
		}
	}
	return dp[n];
}

// O(n+k)

int bottom_up_opti(int n, int k) {
	vector<int> dp(n + 1, 0);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= k; i++)
		dp[i] = 2 * dp[i - 1];
	for (int i = k + 1; i <= n; i++)
		dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
	return dp[n];
}

int main()
{
	int n = 4;
	int k = 3;
	int dp[1000] = {0};
	// output : 7
	cout << recursive(n, k) << ln;
	cout << top_down(n, k, dp) << ln;
	cout << bottom_up(n, k) << ln;
	cout << bottom_up_opti(n, k) << ln;
}

