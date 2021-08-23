/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-16 09:32:35  (IST)
*/

#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// Bottom Up
int lis(vector<int> a, int n) {
	vector<int> dp(n + 1, 1);
	int len = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				dp[i] = max(dp[i], 1 + dp[j]);
				len = max(len, dp[i]);
			}
		}
	}
	return len;
}

int main()
{
	vector<int> a{50, 4, 10, 8, 30, 100};
	int n = a.size();
	cout << lis(a, n) << ln; // 4
}
