/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-22 11:24:22  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
// given an interger n and p, find the square root of number n upto p places without any inbuilt-function
// N = 10, p = 3
// output: 3.162
float square_root(int n, int p) {
	int left = 0;
	int right = n;
	float ans = 0;
	// Binary Search for interger part
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (mid * mid == n)
			return mid;
		else if (mid * mid < n) {
			ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	// Linear Search for floating part
	float inc = 0.1;
	for (int place = 1; place <= p; place++) {
		while (ans * ans <= n) {
			ans += inc;
		}
		ans = ans - inc;
		inc = inc / 10.0;
	}
	return ans;
}
int main()
{
	int n, k;
	cin >> n >> k;
	cout << square_root(n, k) << ln;
}
