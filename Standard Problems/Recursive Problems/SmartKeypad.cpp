/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-27 11:14:52  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};


void printKeyOutput(string n, string res, int i = 0) {
	if (n[i] == '\0') {
		cout << res << ln;
		return;
	}
	// recursive case
	int cur_digit = n[i] - '0';
	if (cur_digit == 0 or cur_digit == 1) {
		printKeyOutput(n, res, i + 1);
	}

	for (int k = 0; k < keypad[cur_digit].size(); k++) {
		printKeyOutput(n, res + keypad[cur_digit][k], i + 1);
	}
}


int main()
{
	string n = "23";
	string res;
	printKeyOutput(n, res);
}
