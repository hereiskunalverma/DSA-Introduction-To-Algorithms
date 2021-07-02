/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-06-22 08:56:18  (IST)
*/

#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// Linear Search


// Time Complexity - O(n)

void linear_search(vector<int> a, int data) {
	for (int i = 0; i < a.size(); i++) {
		if (data == a[i]) {
			cout << "Item present at " << i + 1 << ln;
			return;
		}
	}
	cout << "Not present" << ln;
}

int main() {
	vector<int> a {8, 4, 3, 5, 9, 6, 2, 1};
	linear_search(a, 10);// not present
	linear_search(a, 3); // Item present at 3
	return 0;
}