/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-30 10:55:49  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;


bool isBalanced(string str) {
	stack<char> s;
	for (auto ch : str) {
		switch (ch) {
		case '(':
		case '[':
		case '{': s.push(ch);
			break;
		case ')': if (not s.empty() and s.top() == '(') {
				s.pop();
			} else
				return false;
			break;

		case ']': if (not s.empty() and s.top() == '[') {
				s.pop();
			} else
				return false;
			break;

		case '}': if (not s.empty() and s.top() == '{') {
				s.pop();
			} else
				return false;
			break;

		default: continue;
		}
	}
	if (not s.empty())
		return false;
	return true;
}


int main()
{
	string s = "((a+b+c)+[d])"; // balanced
	// string s = "{a+(b+c)+([d+e]*f))+k}"; // not balanced
	if (isBalanced(s))
		cout << "Balanced" << ln;
	else
		cout << "Not Balanced" << ln;

}
