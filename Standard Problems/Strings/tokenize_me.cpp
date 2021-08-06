/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-20 10:34:05  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// given a string, split it with respect to some delimiter(s)
// example : "today is a sunny day"
// output  : "today","is","a","sunny","day"
void tokenize(string s, string del = " ") {
	int start = 0;
	int end = s.find(del);
	vector<string> res;
	while (end != -1) {
		string temp = s.substr(start, end - start);
		res.push_back(temp);
		start = end + del.size();
		end = s.find(del, start);
	}
	for (auto i : res)
		cout << i << ln;
}
int main()
{
	string s = "today is a sunny day";
	tokenize(s, " ");
}
