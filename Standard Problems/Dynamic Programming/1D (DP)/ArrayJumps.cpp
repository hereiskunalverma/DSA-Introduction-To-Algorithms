/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-16 08:46:20  (IST)
*/

#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// Top Down
int min_jumps(vector<int> a, int n, vector<int> dp, int i = 0) {
	if (i == n - 1)
		return 0;
	if (i >= n)
		return INT_MAX;
	// rec case
	if (dp[i] != 0)
		return dp[i];
	int steps = INT_MAX;
	int max_jump = a[i];
	for (int jump = 1; jump <= max_jump; jump++) {
		int next_cell = i + jump;
		int subprob = min_jumps(a, n, dp, next_cell);
		if (subprob != INT_MAX)
			steps = min(steps, subprob + 1);
	}
	return dp[i] = steps;
}

int min_jumps_bd(vector<int> a, int n) {
	int dp[n];
	if (n == 0 or a[0] == 0)
		return INT_MAX;
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		dp[i] = INT_MAX;
		for (int j = 0; j < i; j++) {
			if (i <= j + a[j] and dp[j] != INT_MAX) {
				dp[i] = min(dp[i], dp[j] + 1);
				break;
			}
		}
	}
	return dp[n - 1];
}

int main()
{
	vector<int> jumps{3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 2, 5};
	int n = jumps.size();
	vector<int> dp(n, 0);
	cout << min_jumps(jumps, n, dp, 0) << ln;
	cout << min_jumps_bd(jumps, n) << ln;
}
