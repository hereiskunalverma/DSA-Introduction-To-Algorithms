

// Height of a node - It is defined as the number of edges in the longest path from node to a leaf node

// Height of tree = Height of root

// Height of leaf node = 0

// Depth  - It is defined as the number of edges in path from root to that node.





#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};
BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
BstNode* Insert(BstNode* root, int data) { // Only creates binary search insertion
	if (root == NULL)
		root = GetNewNode(data);
	else if (data <= root->data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;
}
int FindHeight(BstNode* root) { // number of edges if want number of nodes then add return 0 in base case
	if (root == NULL)
		return -1;
	return max(FindHeight(root->left), FindHeight(root->right)) + 1;
	// +1 for edge connected to root
}
int main()
{
	BstNode* root = NULL; // empty tree
	root = GetNewNode(1);
	root->left = GetNewNode(2);
	root->right = GetNewNode(3);
	root->left->left = GetNewNode(4);
	root->left->right = GetNewNode(5);
	root->left->right->left = GetNewNode(8);
	root->left->right->right = GetNewNode(9);
	root->right->left = GetNewNode(6);
	root->right->right = GetNewNode(7);
	// Height should be 3
	cout << "Height is " << FindHeight(root) << ln;
}

