/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-30 11:45:03  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;



void maxSubArray(vector<int>a, int k) {
	deque<int> q(k);
	int i;
	// the first k elements
	for (i = 0; i < k; i++) {
		while (not q.empty() and a[i] > a[q.back()])
			q.pop_back();
		q.push_back(i);
	}

	// remaininig elements of the array
	for (; i < a.size(); i++) {
		cout << a[q.front()] << " ";
		// remove elements from left if lies outside the current window
		while (not q.empty() and q.front() <= i - k) {
			q.pop_front();
		}
		while (not q.empty() and a[i] >= a[q.back()])
			q.pop_back();
		q.push_back(i);

	}
}


int main()
{
	vector<int> a{1, 2, 3, 1, 4, 5, 2, 3, 5};
	int k = 3;
	maxSubArray(a, k);
}
