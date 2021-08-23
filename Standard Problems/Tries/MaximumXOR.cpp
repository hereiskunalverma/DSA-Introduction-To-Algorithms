/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-10 11:09:19  (IST)
*/


// find the maximum XOR that you can form by picking two numbers from the array

#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;


class node
{
public:
	node* left; // 0
	node* right;// 1
};

class Trie {
	node* root;
public:
	Trie() {
		root = new node();
	}
	void insert(int n) {
		// bits of that number in the trie
		node* temp = root;
		for (int i = 31; i >= 0; i--) {
			int bit = (n >> i) & 1; // getting ith bit, and with 'and' to check if it is 0 and 1
			if (bit == 0) {
				if (temp->left == NULL) {
					temp->left = new node();
				}
				temp = temp->left;
			}
			else {
				if (temp->right == NULL)
					temp->right = new node();
				temp = temp->right;
			}
		}
	}
	int max_xor_helper(int val) {
		int cur_ans = 0;
		node* temp = root;
		for (int j = 31; j >= 0; j--) {
			int bit = (val >> j) & 1;
			if (bit == 0) {
				if (temp->right != NULL) {
					temp = temp->right;
					cur_ans += (1 << j);
				}
				else {
					temp = temp->left;
				}
			}
			else {
				if (temp->left != NULL) {
					temp = temp->left;
					cur_ans += (1 << j);
				}
				else {
					temp = temp->right;
				}
			}
		}
		return cur_ans;
	}
	int max_xor(int *input, int n) {
		int max_xor = 0;
		for (int i = 0; i < n; i++) {
			int val = input[i];
			insert(val);
			int cur_xor = max_xor_helper(val);
			max_xor = max(max_xor, cur_xor);
		}
		return max_xor;
	}
};


int main()
{
	int input[] = {3, 10, 5, 25, 9, 2};
	int n = sizeof(input) / sizeof(int);
	Trie t;
	cout << t.max_xor(input, n) << ln;
}
