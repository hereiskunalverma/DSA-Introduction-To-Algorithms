/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-21 09:20:03  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
// given an array, find all segments of contigous values of array whose sum is exactly k
// Input: a = [1 3 2 1 4 1 3 2 1 1 2]
// k= 8
// Output:
// 2 5, 4 6, 5 9 (indices)


void housing(vector<int> a, int n, int k) {
	int i = 0;
	int j = 0;
	int cur = 0;
	while (j < n) {
		cur += a[j];
		j++;
		while (cur > k and i < j) {
			cur = cur - a[i];
			i++;
		}
		if (cur == k)
			cout << i << " " << j - 1 << ln;
	}
}
int main()
{
	vector<int> plots {1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
	int n = plots.size();
	int k = 8;
	housing(plots, n, k);
}
