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

void morris_preorder(TreeNode* root) {
	TreeNode* cur = root;
	while (cur) {
		if (cur->left == NULL) {
			cout << cur->val << " ";
			cur = cur->right;
		}
		else {
			// inorder predecessor
			TreeNode* pred = cur->left;
			while (pred->right and pred->right != cur) {
				pred = pred->right;
			}
			// make current as right child of its pred
			if (pred->right == NULL) {
				pred->right = cur;
				cout << cur->val << " ";
				cur = cur->left;
			}
			else {
				// restore the tree
				pred->right = NULL;
				cur = cur->right;
			}
		}
	}
}
int main(int argc, char* argv[]) {
	TreeNode* root = new TreeNode('A');
	root->left = new TreeNode('D');
	root->left->left = new TreeNode('H');
	root->left->right = new TreeNode('L');
	root->left->right->left = new TreeNode('P');
	root->right = new TreeNode('Z');
	root->right->right = new TreeNode('C');
	root->right->right->right = new TreeNode('E');
	cout << "Morris Preorder Traversal : ";
	morris_preorder(root);
	cout << "\n";
	remove(argv[0]);
	return 0;

}