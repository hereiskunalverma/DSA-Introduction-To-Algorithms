/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-05 09:33:14  (IST)
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

int findClosestInBST(node* root, int target) {
	int closest;
	int diff = INT_MAX;
	node* temp = root;
	while (temp != NULL) {
		int current_diff = abs(temp->data - target);
		if (current_diff == 0)
			return temp->data;
		if (current_diff < diff) {
			diff = current_diff;
			closest = temp->data;
		}
		// right or left
		if (temp->data < target)
			temp = temp->right;
		else
			temp = temp->left;
	}
	return closest;
}
int main()
{
	node* root = NULL;
	int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
	for (int x : arr) {
		root = insert(root, x);
	}
	// print(root);
	cout << findClosestInBST(root, 12); // 13
}
