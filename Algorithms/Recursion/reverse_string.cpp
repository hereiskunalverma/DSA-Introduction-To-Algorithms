/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-06-18 09:41:15  (IST)
*/



// Reverse a String

#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

void reverse_str(string s) {
	if (s.size() == 0)
		return;
	reverse_str(s.substr(1));
	cout << s[0];
}
int main()
{
	string s = "reverse me";
	reverse_str(s);

}
