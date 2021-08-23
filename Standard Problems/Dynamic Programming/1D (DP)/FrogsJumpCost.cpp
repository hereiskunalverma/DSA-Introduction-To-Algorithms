/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-16 09:03:15  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// Bottom Ups
int frog_cost_min(vector<int> a, int n) {
	vector<int> dp(n, 0);
	dp[1] = abs(a[1] - a[0]);
	for (int i = 2; i < n; i++) {
		int op1 = abs(a[i] - a[i - 1]) + dp[i - 1];
		int op2 = abs(a[i] - a[i - 2]) + dp[i - 2];
		dp[i] = min(op1, op2);
	}
	return dp[n - 1];
}

int main()
{
	vector<int> a{10, 30, 40, 20};
	int n = a.size();
	cout << frog_cost_min(a, n) << ln; // 30
}
