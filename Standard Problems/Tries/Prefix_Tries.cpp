/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-10 08:53:50  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;


// Build a Prefix Tree - Trie
class node {
public:
	char data;
	unordered_map<char, node*> m;
	bool isTerminal;

	node(char data) {
		this->data = data;
		this->isTerminal = false;
	}
};

class Trie {
	node* root;
public:
	Trie() {
		root = new node('\0');
	}

	void insert(string word) {
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
};


int main()
{
	string words[] = {"apple", "ape", "no", "news", "not", "never"};
	Trie t;
	for (auto w : words) {
		t.insert(w);
	}
	int q;
	cin >> q;
	string search_word;
	while (q--) {
		cin >> search_word;
		if (t.search(search_word))
			cout << "Yes" << ln;
		else
			cout << "No" << ln;
	}

}
