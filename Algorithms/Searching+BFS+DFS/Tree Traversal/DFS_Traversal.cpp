/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-06-22 11:33:14  (IST)
*/

#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

/*

Depth First Search Traversal / Consists of three traversal namely ....

1. PreOrder  - Visiting Order -> Root | Left Child | Right Child

2. InOrder   - Visiting Order -> Left Child | Root | Right Child

3. PostOrder - Visiting Order -> Left Child | Right Child | Root



// Some Points :

1. If nodes are present in lower level

2. Uses Less Memory

3. Good for question like Does path exists ...


// Some questions for Why DFS ?

1. If the tree is very wide. (BFS takes too much memory)
2. If the solutions are frequent but located deep in the tree
3. Determining whether a path exits.

 Binary Search Tree


*/

struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};
BstNode* GetNewNode(int data) {
	BstNode* new_node = new BstNode();
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}
BstNode* Insert(BstNode* root, int data) {
	if (root == NULL)
		root = GetNewNode(data);
	else if (data <= root->data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;
}
void PreOrder(BstNode* root) {
	if (root == NULL)
		return;
	cout << root->data << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}
void InOrder(BstNode* root) {
	if (root == NULL)
		return;
	InOrder(root->left);
	cout << root->data << " ";
	InOrder(root->right);
}
void PostOrder(BstNode* root) {
	if (root == NULL)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->data << " ";
}
int main() {
	BstNode* root = NULL; // empty tree
	vector<int> a {9, 4, 20, 1, 6, 15, 170}; // 9 is the root node
	for (auto x : a)
		root = Insert(root, x);
	cout << "\t\t\tDepth First Search/Traversal\t\t\t" << ln << ln;
	cout << "\t\t1. PreOrder -> ";
	PreOrder(root);
	cout << ln << ln;
	cout << "\t\t2. InOrder -> ";
	InOrder(root);
	cout << ln << ln;
	cout << "\t\t3. PostOrder -> ";
	PostOrder(root);
	cout << ln << ln;
	return 0;
}