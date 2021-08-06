/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-30 11:25:44  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
int main()
{
	queue<char>q;
	map<char, int> hash;
	char ch;
	cin >> ch;
	while (ch != '.') {
		q.push(ch);
		hash[ch - 'a']++;
		// query -> remove all chars from front of queue till you get a char with freq 1
		while (not q.empty()) {
			int idx = q.front() - 'a';
			if (hash[idx] > 1)
				q.pop();
			else {
				cout << q.front() << ln;
				break;
			}
		}
		if (q.empty())
			cout << -1 << ln;
		cin >> ch;
	}

}
