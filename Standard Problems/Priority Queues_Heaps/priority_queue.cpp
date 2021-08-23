/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-06 08:46:30  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
class Compare
{
public:
	bool operator()(int a, int b) {
		return a > b;
	}

};
int main()
{
	int arr[] = {10, 15, 20, 13, 6, 90};
	int n = sizeof(arr) / sizeof(int);
	priority_queue<int, vector<int>, Compare> heap; // to get min heap
	for (int x : arr)
		heap.push(x);
	while (not heap.empty()) {
		cout << heap.top() << ln;
		heap.pop();

	}

}
