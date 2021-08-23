/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-20 11:16:19  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
// given two non-empty strings, write a function that determines whether the second string is subsequence of first one
// example: kunalverma to check "uvrm"
// Yes

int main()
{
	string s = "kunalverma";
	string h = "uvrm";
	int i = s.length() - 1;
	int j = h.length() - 1;
	while (j >= 0 and i >= 0) {
		if (h[j] == s[i])
			i--, j--;
		else
			i--;
	}
	if (j == -1)
		cout << "Yes" << ln;
	else
		cout << "No" << ln;
}
