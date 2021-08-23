/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-16 09:41:19  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

bool compareBoxes(vector<int> b1, vector<int> b2) {
	return b1[2] > b2[2];
}

bool canPlace(vector<int> b1, vector<int> b2) {
	if (b1[0] > b2[0] and b1[0] > b2[0] and b1[0] > b2[0])
		return true;
	return false;
}

int boxStacking(vector<vector<int>> boxes) {

	// 1. Sort
	sort(boxes.begin(), boxes.end(), compareBoxes);

	// 2. DP
	int n = boxes.size();
	vector<int> dp(n + 1, 0);
	for (int i = 0; i < n; i++) {
		dp[i] = boxes[i][2]; // height of the ith box
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (canPlace(boxes[j], boxes[i])) {
				int cur_height = boxes[i][2];
				if (dp[j] + cur_height > dp[i]) {
					dp[i] = dp[j] + cur_height;
				}
			}
		}
	}
	int max_height = 0;
	for (int i = 0; i < n; i++) {
		max_height = max(max_height, dp[i]);
	}
	return max_height;
}

int main()
{
	vector<vector<int>> boxes = {
		{2, 1, 2},
		{3, 2, 3},
		{2, 2, 8},
		{2, 3, 4},
		{2, 2, 1},
		{4, 4, 5}
	};

	int height = boxStacking(boxes);
	cout << height << ln;
	return 0;

}
