/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-27 10:38:01  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

int solve(vector<int> a, int n, int i, int sum) {
	// base case
	if (i == n) {
		if (sum == 0)
			return 1;
		else
			return 0;
	}
	// recursive case
	return solve(a, n, i + 1, sum - a[i]) + solve(a, n, i + 1, sum);
}


int main()
{
	vector<int> a{1, 2, 3, 4, 5};
	int sum = 6;
	// check if there is a subset which sums in vector, if yes count them
	cout << solve(a, a.size(), 0, sum) << ln; // 3
}
