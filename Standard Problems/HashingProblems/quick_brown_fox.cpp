/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-09 09:46:26  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;


string s = "thequickbrownfox";
string words [] = {
	"the",
	"quickbrown",
	"fox",
	"quick",
	"brown"
};


int min_bars_helper(string s, string words[], int idx, unordered_set<string> &m) {
	// base case
	if (s[idx] == '\0')
		return 0;
	// rec case
	int ans = INT_MAX;
	string curr = "";
	for (int j = idx; s[j] != '\0'; j++) {
		curr += s[j];
		if (m.find(curr) != m.end()) {
			int rem_ans = min_bars_helper(s, words, j + 1, m);
			if (rem_ans != -1)
				ans = min(ans, 1 + rem_ans);
		}
	}
	if (ans == INT_MAX)
		return -1;
	return ans;
}


int min_bars() {
	unordered_set<string> m;
	for (string w : words)
		m.insert(w);

	int output = min_bars_helper(s, words, 0, m);
	return output - 1;
}


int main()
{
	cout << min_bars() << ln;
}
