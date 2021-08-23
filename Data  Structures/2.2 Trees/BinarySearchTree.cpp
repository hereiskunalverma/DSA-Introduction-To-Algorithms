// Binary Search Tree Implementation

#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
struct BstNode
{
	int data;
	BstNode* right;
	BstNode* left;
};
// Function to create new node
BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->right = NULL;
	newNode->left = NULL;
	return newNode;
}
// Function to insert data in tree
BstNode* Insert(BstNode* root, int data) {
	if (root == NULL) { // empty tree
		root = GetNewNode(data); // this is local variable so return it
		return root;
	}
	else if (data <= root->data) { // if data is less or equal to root data than make it left child
		root->left = Insert(root->left, data);
	}
	else { // if data is greater than root data than make it left child
		root->right = Insert(root->right, data);
	}
	return root;
}
bool Search(BstNode* root, int data) {
	if (root == NULL)
		return false;
	else if (root->data == data)
		return true;
	else if (data <= root->data)
		return Search(root->left, data);
	else
		return Search(root->right, data);
}
void Inorder(BstNode* root) {
	if (root == NULL)
		return;
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}
int main()
{
	BstNode* root; // to store address of root address
	root = NULL; // empty tree
	vector<int> a {15, 10, 20, 25, 8, 12};
	for (auto x : a)
		root = Insert(root, x);
	cout << "The tree is in sorted order : " << ln;
	Inorder(root);
	int num;
	cout << "Enter the number to search : " << ln;
	cin >> num;
	if (Search(root, num))cout << "Found\n";
	else cout << "Not Found" << ln;
}
