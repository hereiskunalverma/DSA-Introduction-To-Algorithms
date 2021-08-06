/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-05 09:04:00  (IST)
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

bool search(node* root, int key) {
	if (root == NULL)
		return false;
	else if (root->data == key)
		return true;
	else if (key < root->data)
		return search(root->left, key);
	else
		return search(root->right, key);
}
void print(node* root) { // inorder traversal
	if (root == NULL)
		return;
	print(root->left);
	cout << root->data << " ";
	print(root->right);
}
int main()
{
	node* root = NULL;
	int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
	for (int x : arr) {
		root = insert(root, x);
	}
	print(root);
	cout << ln;
	int key;
	cin >> key;
	cout << search(root, key) << ln;
}
