/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-18 08:30:01  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;


int sub_cnt(string s1, string s2, int i, int j) {
	// base case
	if ((i == -1 and j == -1) or j == -1)
		return 1;
	if (i == -1)
		return 0;
	if (s1[i] == s2[j])
		return sub_cnt(s1, s2, i - 1, j - 1) + sub_cnt(s1, s2, i - 1, j);
	return sub_cnt(s1, s2, i - 1, j);
}


// Bottom Up
int cntBU(string a, string b) {
	int m = a.size();
	int n = b.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	// Filling the table
	for (int i = 0; i <= m; i++)
		dp[i][0] = 1;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[m][n];
}

int main()
{
	string s1 = "ABCDCE";
	string s2 = "ABC";
	cout << sub_cnt(s1, s2, s1.size() - 1, s2.size() - 1) << ln;
	cout << cntBU(s1, s2) << ln;
}
