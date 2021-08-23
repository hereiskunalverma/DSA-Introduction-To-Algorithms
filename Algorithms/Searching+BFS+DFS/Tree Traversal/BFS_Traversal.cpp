/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-06-22 11:33:23  (IST)
*/

#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

/*

// Breadth First Search Traversal / Level - Order Traversal

1. Good for Shortest path

2. Good for nodes present in upper level

3. More Memory


// Some questions for Why BFS ?

1. If we know the solution is not far from the root of the tree
2. If the tree is very wide
3. Finding the shortest path
4. If the tree is very deep and solutions are rare. (DFS will take long time)


// Binary Search Tree


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
void BFS(BstNode* root) {
	if (root == NULL)
		return;
	queue<BstNode*> q;
	q.push(root);
	while (not q.empty()) {
		BstNode* current = q.front();
		cout << current->data << " ";
		q.pop();
		if (current->left != NULL)
			q.push(current->left);
		if (current->right != NULL)
			q.push(current->right);
	}
	cout << ln;
}
int main() {
	BstNode* root = NULL; // empty tree
	vector<int> a {9, 4, 20, 1, 6, 15, 170}; // 9 is the root node
	for (auto x : a)
		root = Insert(root, x);
	cout << "The BFS traversal is : " << ln;
	BFS(root);
	return 0;
}