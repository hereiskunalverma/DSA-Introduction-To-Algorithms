/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-21 10:04:38  (IST)
*/

/*
Given two strings, one big string and one small string, find the 'smallest window' in the big string that contains all characters of the small string.
- Window can have additional characters than required.
- If small string has duplicates, then those duplicates must be present with same or higher count in window

Input - s1 = hello_world
		s2 = lol
Output - llo

Input - s1 = fizzbuzz
        s2 = fuzz

Output - fizzbu
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

string string_window(string s1, string s2) {
	int fp[256] = {0};
	int fs[256] = {0};
	int cnt = 0;
	int start = 0;
	int start_idx = -1;
	int min_so_far = INT_MAX;
	int window_size;
	for (int i = 0; i < s2.length(); i++)
		fp[s2[i]]++;
	for (int i = 0; i < s1.length(); i++) {
		char ch = s1[i];
		fs[s1[i]]++;
		if (fp[ch] and fs[ch] <= fp[ch])
			cnt++;
		if (cnt == s2.length()) {
			while (fp[s1[start]] == 0 or fs[s1[start]] > fp[s1[start]]) {
				fs[s1[start]]--;
				start++;
			}
			window_size = i - start + 1;
			if (window_size < min_so_far) {
				min_so_far = window_size;
				start_idx = start;
			}
		}
	}
	if (start_idx == -1)
		return "No window found";
	return s1.substr(start_idx, min_so_far);
}
int main()
{
	cout << string_window("hello_world", "lol") << ln; // llo
	cout << string_window("fizzbuzz", "fuzz") << ln; // fizzbu
}
