/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-05 09:49:52  (IST)
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


class LinkedList {
public:
	node* head;
	node* tail;
};
// PostOrder Traversal based;
// Time Complexity: O(n)
LinkedList treeToLL(node* root) {
	LinkedList l;
	if (root == NULL) {
		l.head = l.tail = NULL;
		return l;
	}
	// 4 cases

	if (root->left == NULL and root->right == NULL) {
		l.head = l.tail = root;
		return l;
	}
	else if (root->left != NULL and root->right == NULL) {
		LinkedList leftLL = treeToLL(root->left);
		leftLL.tail->right = root;
		l.head = leftLL.head;
		l.tail = root;
	}
	else if (root->left == NULL and root->right != NULL) {
		LinkedList rightLL = treeToLL(root->right);
		root->right = rightLL.head;
		l.head = root;
		l.tail = rightLL.tail;
	}
	else {
		LinkedList leftLL = treeToLL(root->left);
		LinkedList rightLL = treeToLL(root->right);
		leftLL.tail->right = root;
		root->right = rightLL.head;
		l.head = leftLL.head;
		l.tail = rightLL.tail;
	}
	return l;
}

int main()
{
	node* root = NULL;
	int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
	for (int x : arr) {
		root = insert(root, x);
	}
	cout << "Tree is : ";
	print(root);
	cout << ln;
	cout << "Linked List is : ";
	LinkedList l = treeToLL(root);
	node* temp = l.head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->right;
	}
	cout << ln;
}
