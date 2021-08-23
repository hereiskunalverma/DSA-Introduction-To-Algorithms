/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-20 10:05:22  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
// find all occurences of the given word in a string
int main()
{
	string s = "Hi do you wanna be mine? Hi how are you ?";
	string h = "Hi";
	vector<int> res;
	int index = s.find(h);
	while (index != -1) {
		res.push_back(index);
		index = s.find(h, index + 1);
	}
	cout << "The given word is present at " << ln;
	for (auto i : res)
		cout << i + 1 << ln;
}
