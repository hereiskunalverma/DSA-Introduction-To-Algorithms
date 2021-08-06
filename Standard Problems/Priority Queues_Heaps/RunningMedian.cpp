/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-06 09:46:47  (IST)
*/

#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
int main()
{
	// 10 5 2 3 0 12 18 20 22 -1
	priority_queue<int> leftheap;
	priority_queue<int, vector<int>, greater<int>>  rightheap;
	int d;
	cin >> d;
	leftheap.push(d);
	float med = d;
	cout << med << " " << ln;
	cin >> d;
	while (d != -1) {
		// left or right or equal
		if (leftheap.size() > rightheap.size()) {
			if (d < med) {
				rightheap.push(leftheap.top());
				leftheap.pop();
				leftheap.push(d);
			}
			else
				rightheap.push(d);
			med = (leftheap.top() + rightheap.top()) / 2.0;
		}
		else if (leftheap.size() == rightheap.size()) {
			if (d < med) {
				leftheap.push(d);
				med = leftheap.top();
			}
			else {
				rightheap.push(d);
				med = rightheap.top();
			}
		}
		else {
			if (d < med) {
				leftheap.push(d);
			}
			else {
				leftheap.push(rightheap.top());
				rightheap.pop();
				rightheap.push(d);
			}
			med = (leftheap.top() + rightheap.top()) / 2;
		}
		cout << med << " " << ln;
		cin >> d;
	}
	return 0;

}
