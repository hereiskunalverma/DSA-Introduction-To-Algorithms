/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-22 09:15:48  (IST)
*/
// Given the list of strings, output the lexicographically smallest concatenation

// Example -
/*
3
c
cb
cba
Output : cbacbc
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
bool compare(string x, string y) {
	return x + y < y + x;
}
int main()
{
	string a[] = {"c", "cb", "cba"};
	int n = 3;
	sort(a, a + n, compare);
	for (auto s : a)
		cout << s; // cbacbc
	return 0;
}
