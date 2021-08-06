/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-05 09:13:45  (IST)
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
node* insert(node* root, int key) {
	if (root == NULL)
		return new node(key);
	if (key < root->data)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);
	return root;
}
void print(node* root) { // inorder traversal
	if (root == NULL)
		return;
	print(root->left);
	cout << root->data << " ";
	print(root->right);
}
node* createBST(vector<int> arr, int start, int end) {
	if (start > end)
		return NULL;
	int mid = (start + end) / 2;
	node* root = new node(arr[mid]);
	root->left = createBST(arr, start, mid - 1);
	root->right = createBST(arr, mid + 1, end);
	return root;
}
int main()
{
	vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	node* root = createBST(a, 0, a.size() - 1);
	print(root);

}
