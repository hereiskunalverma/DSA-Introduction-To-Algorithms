/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-22 10:49:10  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
#define debug(s) cout<<s<<ln
using namespace std;
// Given an sorted array which can contain repeated elements and an element k, we neee to find the frequency of a given elemetn.
int lower_bound(vector<int> a, int k) {
	int left = 0;
	int right = a.size() - 1;
	int ans = -1;
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (a[mid] == k) {
			ans = mid;
			right = mid - 1;
		}
		else if (a[mid] > k) {
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return ans;
}
int upper_bound(vector<int>a, int k) {
	int left = 0;
	int right = a.size() - 1;
	int ans = -1;
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (a[mid] == k) {
			ans = mid;
			left = mid + 1;
		}
		else if (a[mid] > k) {
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return ans;
}
int main()
{
	// hasing
	vector<int>a{0, 1, 1, 1, 1, 2, 2, 2, 3, 4, 4, 5, 10};
	int k = 3;
	map<int, int> hash;
	for (int i = 0; i < a.size(); i++)
		hash[a[i]]++;
	cout << "using hashing" << ln;
	cout << hash[k] << ln;

	// Binary Search
	cout << "Using binary search" << ln;
	// cout << lower_bound(a, k) << ln; // first occurence is at 5
	// cout << upper_bound(a, k) << ln; // second occurence is at 8;
	cout << abs(upper_bound(a, k) - lower_bound(a, k)) + 1 << ln;

}
