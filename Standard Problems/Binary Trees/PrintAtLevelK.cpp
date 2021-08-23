/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-04 09:42:03  (IST)
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


int main()
{
	// input : 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
	node* root = buildTree();
	levelOrderPrint(root);
	cout << "Node at level k : ";
	printKNode(root, 2);
}
