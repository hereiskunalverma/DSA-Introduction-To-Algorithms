/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-03 08:46:11  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

// Input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

node* buildTree() {
	int d;
	cin >> d;
	if (d == -1)
		return NULL;
	node* n = new node(d);
	n->left = buildTree();
	n->right = buildTree();
	return n;
}

// Level Order Traversal
// Expected output
/*

1
2 3
4 5 6
7
*/
void levelOrderPrint(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (not q.empty()) {
		node* temp = q.front();
		if (temp == NULL) {
			cout << ln;
			q.pop();
			// insert a new null for next level
			if (not q.empty()) {
				q.push(NULL);
			}
		}
		else {
			q.pop();
			cout << temp->data << " ";
			if (temp->left) {
				q.push(temp->left);
			}
			if (temp->right)
				q.push(temp->right);
		}
	}
	return;
}
int main()
{
	node* root = buildTree();
	levelOrderPrint(root);
}
