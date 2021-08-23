/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-17 10:37:49  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// Top Down
int lcs(string s1, string s2, int i, int j, vector<vector<int>> dp) {
	if (i == s1.length() or j == s2.length())
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	// rec case
	if (s1[i] == s2[i])
		return dp[i][j] = 1 + lcs(s1, s2, i + 1, j + 1, dp);
	int op1 = lcs(s1, s2, i + 1, j, dp);
	int op2 = lcs(s1, s2, i, j + 1, dp);
	return dp[i][j] = max(op1, op2);
}

// Bottom Up
int lcs_B(string s1, string s2) {
	int n1 = s1.length();
	int n2 = s2.length();
	// 2D dp array
	vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else {
				int op1 = dp[i - 1][j];
				int op2 = dp[i][j - 1];
				dp[i][j] = max(op1, op2);
			}
		}
	}
	/*
	for (int i = 0; i <= n1; i++) {
		for (int j = 0; j <= n2; j++)
			cout << dp[i][j] << " ";
		cout << ln;
	}
	*/
	vector<char> res;
	int i = n1, j = n2;
	while (i != 0 and j != 0) {
		if (dp[i][j] == dp[i][j - 1])
			j--;
		else if (dp[i][j] == dp[i - 1][j])
			i--;
		else {
			res.push_back(s1[i - 1]);
			i--;
			j--;
		}
	}
	reverse(res.begin(), res.end());
	for (char x : res)
		cout << x;
	cout << ln;
	return dp[n1][n2];
}
int main()
{
	string s1 = "ABCD";
	string s2 = "ABEDG";
	int n1 = s1.length();
	int n2 = s2.length();
	vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1)); // n1 x n2
	cout << lcs(s1, s2, 0, 0, dp) << ln;
	cout << lcs_B(s1, s2) << ln;

	return 0;
}
