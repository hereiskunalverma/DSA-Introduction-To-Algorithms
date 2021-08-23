/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-04 09:28:59  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};

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
class Pair {
public:
	int inc;
	int exc;
};

// Time Complexity: O(n)
Pair maxSubsetSum(node* root) {
	Pair p;
	if (root == NULL) {
		p.inc = p.exc = 0;
		return p;
	}
	Pair Left = maxSubsetSum(root->left);
	Pair Right = maxSubsetSum(root->right);
	p.inc = root->data + Left.exc + Right.exc;
	p.exc = max(Left.inc, Left.exc) + max(Right.inc, Right.exc);
	return p;
}

void levelOrderPrint(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (not q.empty()) {
		node* temp = q.front();
		if (temp == NULL) {
			cout << ln;
			q.pop();
			if (not q.empty())
				q.push(NULL);
		}
		else {
			q.pop();
			cout << temp->data << " ";
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
	}
	return;
}
node* levelOrderBuild() {
	int d;
	cin >> d;
	queue<node*> q;
	node* root = new node(d);
	q.push(root);
	while (not q.empty()) {
		node* current = q.front();
		q.pop();
		int c1, c2;
		cin >> c1 >> c2;
		if (c1 != -1) {
			current->left = new node(c1);
			q.push(current->left);
		}
		if (c2 != -1) {
			current->right = new node(c2);
			q.push(current->right);
		}
	}
	return root;
}
int main()
{
	// input : 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
	node* root = levelOrderBuild();
	levelOrderPrint(root);
	Pair p = maxSubsetSum(root);
	cout << max(p.inc, p.exc) << ln;

}
