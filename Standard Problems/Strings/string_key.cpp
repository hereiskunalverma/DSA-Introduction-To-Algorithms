/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-20 11:02:47  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;



/*
Sample Input:

3
92 022
82 12
77 13
2 false numeric

Sample Output:

82 12
77 13
92 022

*/


string result(string str, int key) {
	// string tokenizer
	char *s = strtok((char *)str.c_str(), " ");
	while (key > 1) {
		s = strtok(NULL, " ");
		key--;
	}
	return (string)s;
}
int converToInt(string s) {
	int ans = 0;
	int p = 1;
	for (int i = s.length() - 1; i >= 0; i--) {
		ans += ((s[i] - '0') * p);
		p = p * 10;
	}
	return ans;
}
bool numericCompare(pair<string, string> s1, pair<string, string> s2) {
	string key1, key2;
	key1 = s1.second;
	key2 = s2.second;
	return converToInt(key1) < converToInt(key2);
}
bool lexicoCompare(pair<string, string> s1, pair<string, string> s2) {
	string key1, key2;
	key1 = s1.second;
	key2 = s2.second;
	return key1 < key2;
}
int main()
{

	int n;
	cin >> n;
	cin.get(); // consume the extra '\n'
	string temp;
	vector<string> a;
	for (int i = 0; i < n; i++) {
		getline(cin, temp);
		a.push_back(temp);
	}
	int key;
	string reversal, ordering;
	cin >> key >> reversal >> ordering;
	vector<pair<string, string>> vp;
	for (int i = 0; i < n; i++) {
		vp.push_back({a[i], result(a[i], key)});
	}
	// sort
	if (ordering == "numeric")
		sort(vp.begin(), vp.end(), numericCompare);
	else
		sort(vp.begin(), vp.end(), lexicoCompare);
	// reversal
	if (reversal == "true")
		reverse(vp.begin(), vp.end());
	for (int i = 0; i < n; i++)
		cout << vp[i].first << ln;
	return 0;
}
