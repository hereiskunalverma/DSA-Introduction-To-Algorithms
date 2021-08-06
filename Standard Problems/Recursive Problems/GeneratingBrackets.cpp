/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-27 11:08:14  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

//geerate all possible n pairs of balanced parenthesis '(' and ')'
// input - 3
// output -
/*

()()()
(())()
()(())
(()())
((()))
*/

void solve(string res, int n, int open, int close, int i) {
	if (i == 2 * n) {
		cout << res << ln;
		return;
	}
	// open and less than n
	if (open < n)
		solve(res + '(', n, open + 1, close, i + 1);
	// close
	if (close < open)
		solve(res + ')', n, open, close + 1, i + 1);
}



int main()
{
	string res;
	int n = 3;
	solve(res, n, 0, 0, 0);
}
