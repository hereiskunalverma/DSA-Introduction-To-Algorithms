/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-26 11:02:48  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;


bool possible(int b, int n, vector<int> nests, int separation) {
	int birds = 1;
	int loc = 0;
	for (int i = 1; i <= n - 1; i++) {
		int cur_loc = nests[i];
		if (cur_loc - loc >= separation) {
			birds++;
			loc = cur_loc;
			if (birds == b)
				return  true;
		}
	}
	return false;
}

int main()
{
	int b = 3; // birds
	vector<int> nests{1, 2, 4, 8, 9}; // nests position
	int n = 5; // nests
	sort(nests.begin(), nests.end());


	// Binary Search
	int ans = -1;
	int i = 0;
	int j = nests[n - 1] - nests[0];
	while (i <= j) {
		int mid = (i + j) >> 1;
		bool ok = possible(b, n, nests, mid);
		if (ok) {
			ans = mid;
			i = mid + 1;
		}
		else
			j = mid - 1;
	}

	cout << ans << ln; // 4

}


