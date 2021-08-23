/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-17 11:06:46  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// Top down
int wines_sell(int dp[][10], int prices[], int L, int R, int y) {
	if (L > R)
		return 0;
	if (dp[L][R] != 0)
		return dp[L][R];
	int pic_left = y * prices[L] + wines_sell(dp, prices, L + 1, R, y + 1);
	int pic_right = y * prices[R] + wines_sell(dp, prices, L, R - 1, y + 1);
	return dp[L][R] = max(pic_left, pic_right);
}

// Bottom Up
int wines_B(int prices[], int n) {
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	for (int i = n - 1; i >= 0; i--) {
		// bottom row to top row
		for (int j = 0; j < n; j++) {
			if (i == j)
				dp[i][j] = n * prices[i];
			else if (i <= j) {
				// dp[i...j]
				int y = n - (j - i);
				int pic_left = prices[i] * y + dp[i + 1][j];
				int pic_right = prices[j] * y + dp[i][j - 1];
				dp[i][j] = max(pic_left, pic_right);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << ln;
	}
	return dp[0][n - 1];
}

int main()
{
	int a[] = {2, 3, 5, 1, 4};
	int n = 5;
	int dp[10][10] = {0};
	cout << wines_sell(dp, a, 0, n - 1, 1) << ln;
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << ln;
	// }
	// Bottom Up
	cout << "Bottom Up" << ln;
	cout << wines_B(a, n) << ln;

	return 0;
}
