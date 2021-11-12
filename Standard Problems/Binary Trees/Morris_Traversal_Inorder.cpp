#include<iostream>

using namespace std;

// morris traversal for inorder traversal
// since morris algo changes the tree by creating new links so we need to restore the tree also

struct TreeNode
{
	char val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(char data) {
		val = data;
		left = NULL;
		right = NULL;
	}
};

void morris_inorder(TreeNode* root) {
	TreeNode* cur = root;
	while (cur) {
		if (cur->left == NULL) {
			cout << cur->val << " ";
			cur = cur->right;
		}
		else {
			// find inorder predecessor;
			TreeNode* pred = cur->left;
			while (pred->right and pred->right != cur) {
				pred = pred->right;
			}
			// make current as right child of its pred
			if (pred->right == NULL) {
				pred->right = cur;
				cur = cur->left;
			}
			// reverting the changes to restore the tree
			else {
				pred->right = NULL;
				cout << cur->val << " ";
				cur = cur->right;
			}
		}
	}
}
int main() {
	TreeNode* root = new TreeNode('A');
	root->left = new TreeNode('D');
	root->left->left = new TreeNode('H');
	root->left->right = new TreeNode('L');
	root->left->right->left = new TreeNode('P');
	root->right = new TreeNode('Z');
	root->right->right = new TreeNode('C');
	root->right->right->right = new TreeNode('E');
	cout << "Morris Inorder Traversal : ";
	morris_inorder(root);
	cout << "\n";
	return 0;

}