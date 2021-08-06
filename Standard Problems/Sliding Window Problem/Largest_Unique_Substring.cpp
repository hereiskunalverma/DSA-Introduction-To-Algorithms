/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-21 09:44:11  (IST)
*/
// Given a string, find the largest substring with unique characters

#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
string unique_substring(string s) {
	int i = 0;
	int j = 0;
	int window_len = 0;
	int max_window_len = 0;
	int start_window = -1;
	unordered_map<char , int> hash;
	while (j < s.length()) {
		char ch = s[j];
		while (hash.count(ch) and hash[ch] >= i) {
			i = hash[ch] + 1;
			window_len = j - i;
		}
		hash[ch] = j;
		window_len++;
		j++;
		if (window_len > max_window_len) {
			max_window_len = window_len;
			start_window = i;
		}
	}
	return s.substr(start_window, max_window_len);
}
int main()
{
	string s1 = "Kuunal"; // unal
	string s2 = "aabcdscbsds"; // abcds
	cout << unique_substring(s1) << ln;
	cout << unique_substring(s2) << ln;
}
