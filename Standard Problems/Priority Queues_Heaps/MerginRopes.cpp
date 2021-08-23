/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-06 09:29:21  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

int join_ropes(int ropes[], int n) {
	priority_queue<int, vector<int>, greater<int>> pq(ropes, ropes + n);
	int cost = 0;
	while (pq.size() > 1) {
		int A = pq.top();
		pq.pop();
		int B = pq.top();
		pq.pop();
		int new_rope = (A + B);
		cost += new_rope;
		pq.push(new_rope);
	}
	return cost;
}


int main()
{
	int n = 4;
	int ropes[] = {4, 3, 2, 6}; // output : 29
	// int n;
	// cin >> n;
	// vector<int> ropes(n);
	// for (int i = 0; i < n; i++)cin >> ropes[i];
	// sort(ropes.begin(), ropes.end());
	// for (int i = 1; i < n; i++)
	// 	ropes[i] += ropes[i - 1];
	// int ans = 0;
	// for (int i = 1; i < n; i++)
	// 	ans += ropes[i];
	// cout << ans << ln;
	cout << join_ropes(ropes, n) << ln;
}
