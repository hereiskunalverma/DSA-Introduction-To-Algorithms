/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-09 08:37:44  (IST)
*/

#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

int count_triplets(vector<int> a, int r) {
	int n = a.size();
	unordered_map<long, long> right, left;
	for (auto x : a) {
		right[x]++;
		left[x] = 0;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		right[a[i]]--;
		if (a[i] % r == 0) {
			long b = a[i];
			long a_r = a[i] / r;
			long cr = a[i] * r;
			ans += left[a_r] * right[cr];
		}
		left[a[i]]++;
	}
	return ans;
}

int main()
{
	/*
	6 4
	1 16 4 16 64 16
	*/
	int n, r;
	cin >> n >> r;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << count_triplets(a, r) << ln; // 3

}
