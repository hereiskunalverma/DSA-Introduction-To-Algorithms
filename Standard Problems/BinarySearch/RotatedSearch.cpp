/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-22 11:04:29  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// Given an sorted array of distinct integers, which is rotated about a pivot point and finds the index of any given element
// a = [7,9,10,1,2,3,4,5,6]
// k = 4;
// output: 6
int rotated_search(vector<int> a, int key) {
	int n = a.size();
	int left = 0;
	int right = n - 1;
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (a[mid] == key)
			return mid;
		// 2 Cases

		// if mid lies on first line i.e., left
		if (a[left] <= a[mid]) {
			if (key >= a[left] and key <= a[right])
				right = mid - 1;
			else
				left = mid + 1;
		}
		else {
			// right
			if (key >= a[mid] and key <= a[right])
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
	return -1;
}
int main()
{
	vector<int> a{7, 9, 10, 1, 2, 3, 4, 5, 6};
	int k = 4;
	cout << rotated_search(a, k) << ln;

}
