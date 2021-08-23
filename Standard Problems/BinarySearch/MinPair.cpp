/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-26 11:10:49  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// find the pair of numbers whose absolute difference is minimum. Print any one pair with the smallest difference

pair<int, int> min_pair(vector<int> a, vector<int> b) {
	sort(b.begin(), b.end());
	int diff = INT_MAX;
	int p1, p2;
	for (int x : a) {
		auto lb = lower_bound(b.begin(), b.end(), x) - b.begin();
		// left
		if (lb >= 1 and x - b[lb - 1] < diff) {
			diff = x - b[lb - 1];
			p1 = x;
			p2 = b[lb - 1];
		}
		// right i.e., greater
		if (lb != b.size() and b[lb] - x < diff) {
			diff = b[lb] - x;
			p1 = x;
			p2 = b[lb];
		}
	}
	return {p1, p2};
}


int main()
{
	vector<int> a{ -1, 5, 10, 20, 3};
	vector<int> b{26, 134, 135, 15, 17};
	auto it = min_pair(a, b);
	cout << it.first << " " << it.second << ln;
}
