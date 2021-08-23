/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-03 10:40:40  (IST)
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
int main()
{
	// 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
	node* root = levelOrderBuild();
	print(root);
	cout << "Height of the tree is : " << height(root) << ln;
}
