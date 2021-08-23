/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-05 10:19:34  (IST)
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

node* insert(node* root, int data) {
	if (root == NULL)
		return new node(data);
	if (data < root->data)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);

	return root;
}


void print(node* root) { // inorder traversal
	if (root == NULL)
		return;
	print(root->left);
	cout << root->data << " ";
	print(root->right);
}

node* InorderSucc(node* root, node* target) {
	// righ tree exits...
	if (target->right != NULL) {
		node* temp = target->right;
		while (temp->left != NULL) {
			temp = temp->left;
		}
		return temp;
	}
	node* temp = root;
	node* succ = NULL;
	while (temp != NULL) {
		if (temp->data > target->data) {
			succ = temp;
			temp = temp->left;
		}
		else if (temp->data < target->data) {
			temp = temp->right;
		}
		else
			break;
	}
	return succ;
}

int main()
{
	node* root = NULL;
	root = insert(root, 8);
	root = insert(root, 3);
	root = insert(root, 10);
	root = insert(root, 1);
	root = insert(root, 6);
	root = insert(root, 14);
	root = insert(root, 4);
	root = insert(root, 7);
	root = insert(root, 13);
	node* t1 = root->left->right->right;
	node* t2 = root->right;
	if (InorderSucc(root, t1) == NULL) {
		cout << "NULL" << ln;
		return 0;
	}
	cout << "Inorder succ of 7 is " << InorderSucc(root, t1)->data << ln;
	cout << "Inorder succ of 10 is " << InorderSucc(root, t2)->data << ln;
	return 0;
}
