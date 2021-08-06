/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-27 10:26:00  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

int countWays(int n) {
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
}

int main()
{
	int n = 4;
	cout << countWays(n) << ln; // 7
}
