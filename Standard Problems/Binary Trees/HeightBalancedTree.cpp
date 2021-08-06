/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-03 10:55:56  (IST)
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
		left = right = NULL;
	}
};

node* levelOrderBuild() {
	int d;
	cin >> d;
	node* root = new node(d);
	queue<node*> q;
	q.push(root);
	while (not q.empty()) {
		node* current = q.front();
		int c1, c2;
		cin >> c1 >> c2;
		q.pop();
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
void print(node* root) { // level order traversal
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
int height(node* root) {
	if (root == NULL)
		return 0;
	return max(height(root->left), height(root->right)) + 1;
}


pair<int, bool> isHeightBalanced(node* root) {
	pair<int, bool> p, Left, Right;
	if (root == NULL) {
		p.first = 0; // height
		p.second = true; // balanced
		return p;
	}
	// rec case
	Left = isHeightBalanced(root->left);
	Right = isHeightBalanced(root->right);
	int height = max(Left.first, Right.first) + 1;
	if (abs(Left.first - Right.first) <= 1 and Left.second and Right.second) {
		return {height, true};
	}
	return {height, false};
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


	cout << "\nTEST 1\n" << ln;
	pair<int, bool> p = isHeightBalanced(root); // O(n)
	if (p.second)
		cout << "Yes, its height balanced" << ln;
	else
		cout << "Not a height balanced tree" << ln;

	cout << "\nTEST 2\n" << ln;
	node* root1 = new node(1);
	root1->left = new node(2);
	root1->right = new node(3);
	root1->left->left = new node(4);
	root1->left->right = new node(5);
	root1->right->right = new node(6);
	root1->left->right->left = new node(7);
	root1->left->right->right = new node(8);
	p = isHeightBalanced(root1); // O(n)
	if (p.second)
		cout << "Yes, its height balanced" << ln;
	else
		cout << "Not a height balanced tree" << ln;
}
