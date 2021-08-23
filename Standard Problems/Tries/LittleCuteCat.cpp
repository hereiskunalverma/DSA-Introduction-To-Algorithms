/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-10 10:46:59  (IST)
*/


// Given a document and a list of words, check if the words in list is present in the document.


#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;


class node
{
public:
	char data;
	unordered_map<char, node*> children;
	bool isTerminal;
	node(char d) {
		data = d;
		isTerminal = false;
	}
};


class Trie
{
public:
	node* root;
	Trie() {
		root = new node('\0');
	}
	void insert(string word) {
		node* temp = root;
		for (char ch : word) {
			if (temp->children.count(ch) == 0) {
				node* n = new node(ch);
				temp->children[ch] = n;
			}
			temp = temp->children[ch];
		}
		temp->isTerminal = true;
	}
};

void searchHelper(Trie t, string document, int i, unordered_map<string, bool> &m) {
	node* temp = t.root;
	for (int j = i; j < document.length(); j++) {
		char ch = document[j];
		if (temp->children.count(ch) == 0) {
			return;
		}
		temp = temp->children[ch];
		if (temp->isTerminal) {
			string out = document.substr(i, j - i + 1);
			m[out] = true;
		}
	}
	return;
}

void documentSearch(string document, vector<string> words) {
	Trie t;
	for (auto w : words)
		t.insert(w);
	unordered_map<string, bool> m;
	for (int i = 0; i < document.length(); i++)
		searchHelper(t, document, i, m);
	for (auto w : words) {
		if (m[w])
			cout << w << " -> True" << ln;
		else
			cout << w << " -> False" << ln;
	}
}



int main()
{
	string document = "little cute cat loves to code in c++, java & python.";
	vector<string> words = {"cute cat", "ttle", "cat", "quick", "big"};
	documentSearch(document, words);
	return 0;
}
