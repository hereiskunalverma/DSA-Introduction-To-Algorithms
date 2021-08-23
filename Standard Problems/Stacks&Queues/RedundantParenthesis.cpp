/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-30 11:07:28  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;


bool isRedundant(string str) {
	stack<char> s;
	for (char ch : str) {
		if (ch != ')')
			s.push(ch); // a,b,+,-,(......
		else {
			// ')'
			bool op = false;
			while (not s.empty() and s.top() != '(') {
				char top = s.top();
				if (top == '+' or top == '-' or top == '*' or top == '/')
					op = true;
				s.pop();
			}
			s.pop(); // pop the opening bracket after the loop is done
			if (not op)
				return true;
		}
	}
	return false;
}


int main()
{
	cout << isRedundant("((a+b))") << ln; // yes
	cout << isRedundant("(a+(b)/c)") << ln; // yes
	cout << isRedundant("(a+b*(c-d))") << ln; // no

}
