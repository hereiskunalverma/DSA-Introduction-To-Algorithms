/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-22 10:27:19  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
#define debug(s) cout<<s<<ln
using namespace std;

// Given a sorted array of strings that is interspersed with empty strings, write a method to find the location of a given string
// Example :
// Input: ["ai", "", "", "bat", "", "", "car", "cat", "", "", "dog", ""]
// bat
// Output: 4
int sparse_search(vector<string>a, string key) {
	int left = 0;
	int right = a.size() - 1;
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (a[mid] == "") {
			// update mid to point to nearest non empty string
			int mid_left = mid - 1;
			int mid_right = mid + 1;
			while (true) {
				/*debug("I am here");*/
				if (mid_left<left and mid_right>right)
					return -1;
				else if (mid_right <= right and a[mid_right] != "") {
					mid = mid_right;
					break;
				}
				else if (mid_left >= left and a[mid_left] != "") {
					mid = mid_left;
					break;
				}
				mid_left--;
				mid_right++;
			}
		}
		if (a[mid] == key)
			return mid + 1;
		else if (a[mid] > key)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
int main()
{
	vector<string> a{"ai", "", "", "bat", "", "", "car", "cat", "", "", "dog", ""};
	string key = "bat";
	cout << sparse_search(a, key) << ln;
}

