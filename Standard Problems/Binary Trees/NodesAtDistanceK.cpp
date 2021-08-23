/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-04 11:29:42  (IST)
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

node* buildTree() { // level order build
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


void levelOrderPrint(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (not q.empty()) {
		node* temp = q.front();
		if (temp == NULL) {
			cout << ln;
			q.pop();
			if (not q.empty()) {
				q.push(NULL);
			}
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

void printKNode(node* root, int k) {
	if (root == NULL or k < 0)
		return;
	if (k == 0) {
		cout << root->data << " ";
		return;
	}
	printKNode(root->left, k - 1);
	printKNode(root->right, k - 1);
}

int printNOdesAtDistance(node* root, node* target, int k) {
	// base case
	if (root == NULL)
		return -1;
	// reach the target node
	if (root == target) {
		printKNode(target, k);
		return 0;
	}
	// other case
	int DL = printNOdesAtDistance(root->left, target, k);
	if (DL != -1) {
		// 2 cases
		// Print the current node
		if (DL + 1 == k) {
			cout << root->data;
		}
		// or print somenodes in rightsubtree
		else {
			printKNode(root->right, k - 2 - DL);
		}
		return 1 + DL;
	}
	int DR = printNOdesAtDistance(root->right, target, k);
	if (DR != -1) {
		// 2 cases
		// Print the current node
		if (DR + 1 == k) {
			cout << root->data;
		}
		// or print somenodes in rightsubtree
		else {
			printKNode(root->left, k - 2 - DR);
		}
		return 1 + DR;
	}
	return -1;
}

int main()
{
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->right = new node(6);
	root->left->right->left = new node(7);
	root->left->right->right = new node(8);
	root->left->right->right->left = new node(9);
	root->left->right->right->right = new node(10);

	// target node
	node* target = root->left->right;
	int k = 2;
	printNOdesAtDistance(root, target, k);
	cout << ln;
}
