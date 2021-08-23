/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-06-22 09:02:21  (IST)
*/

#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// Binary Search

// Prerequisite : Array must be sorted

// Time Complexity - O(log(n))

void binary_search(vector<int> a, int data, int l, int r) {
	if (l <= r) {
		int mid = (l + r) / 2;
		if (mid == data) {
			cout << "Item is present" << ln;
			return;
		}
		else if (data < mid)
			mid = r - 1;
		else
			mid = l + 1;
	}
	cout << "Item is not present" << ln;
}

int main() {
	vector<int> a {8, 4, 3, 5, 9, 6, 2, 1};
	sort(a.begin(), a.end()); // sorting the data
	binary_search(a, 10, 0, a.size() - 1); // not present
	binary_search(a, 3, 0, a.size() - 1); // Item present at 3
	return 0;
}