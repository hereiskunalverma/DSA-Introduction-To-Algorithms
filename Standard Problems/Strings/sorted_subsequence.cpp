/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-20 11:28:56  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;


// given a string generate all subsets sorted in first length wise and if length same then lexicographical wise
// example : abcd
// output: '',a,b,c,d,ab,ac,ad,bc,cd,abc,abd,acd,bcd,abcd

void subsequence(string s, string o, vector<string> &ans) {
	// base case
	if (s.size() == 0) {
		ans.push_back(o);
		return;
	}
	char ch = s[0];
	string new_str = s.substr(1);
	subsequence(new_str, o + ch, ans);
	subsequence(new_str, o, ans);
}
bool compare(string s1, string s2) {
	if (s1.length() == s2.length())
		return s1 < s2;
	return s1.length() < s2.length();
}
int main()
{
	string s;
	cin >> s;
	vector<string> ans;
	string res = "";
	subsequence(s, res, ans);
	sort(ans.begin(), ans.end(), compare);
	for (auto s : ans)
		cout << s << ", ";
}
