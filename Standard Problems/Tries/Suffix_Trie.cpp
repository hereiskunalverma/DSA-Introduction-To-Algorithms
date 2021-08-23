/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-10 10:01:25  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

class node {
public:
	char data;
	unordered_map<char, node*> m;
	bool isTerminal = false;
	node(char d) {
		data = d;
		isTerminal = false;
	}
};


class SuffixTrie {
	node* root;
public:
	SuffixTrie() {
		root = new node('\0');
	}
	void insert_helper(string word) {
		node* temp = root;
		for (char ch : word) {
			if (temp->m.count(ch) == 0) {
				node* n = new node(ch);
				temp->m[ch] = n;
			}
			temp = temp->m[ch];
		}
		temp->isTerminal = true;
	}
	bool search(string word) {
		node* temp = root;
		for (char ch : word) {
			if (temp->m.count(ch) == 0)
				return false;
			temp = temp->m[ch];
		}
		return temp->isTerminal;
	}
	void insert(string word) {
		for (int i = 0; word[i] != '\0'; i++)
			insert_helper(word.substr(i));
	}
};

int main()
{
	string input = "hello";
	string suffixes[] = {"lo", "ell", "hello"};
	SuffixTrie t;
	t.insert(input);
	for (auto sf : suffixes) {
		if (t.search(sf))
			cout << "Yes" << ln;
		else
			cout << "No" << ln;
	}
}
