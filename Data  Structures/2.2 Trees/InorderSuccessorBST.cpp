// Given a node. Find the Inorder Successor in a binary search tree

#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
// Function to Insert Node in a Binary Search Tree
struct Node
{
	int data;
	Node* left;
	Node* right;
};
//Function to find some data in the tree
Node* Find(Node*root, int data) {
	if(root == NULL) return NULL;
	else if(root->data == data) return root;
	else if(root->data < data) return Find(root->right,data);
	else return Find(root->left,data);
}

// Function to insert
Node* Insert(Node *root,int data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}
void Inorder(Node* root){
	if(root==NULL)return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}
// Find the node with min value 
Node* FindMin(Node* root){
	if(root==NULL)return NULL;
	while(root->left!=NULL)
		root=root->left;
	return root;
}
// Function to find Successor
Node* GetSuccessor(Node* root, int data){
	// Search the node - O(h)
	Node* current=Find(root,data);
	if(current==NULL)return NULL;
	// Case 1: Node has right subtree
	if(current->right!=NULL){
		return FindMin(current->right);
	}
	// Case 2: No right subtree
	else {
		Node* successor=NULL;
		Node* ancestor=root;
		while(ancestor!=current){
			if(current->data < ancestor->data){
				successor=ancestor; // so far this is the deepest node for which current node is in left
				ancestor=ancestor->left;
			}
			else{
				ancestor=ancestor->right;
			}
		}
		return successor;
	}

}
int main()
{
	/*Code To Test the logic
	  Creating an example tree
	            5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
	Node* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4); 
	root = Insert(root,1); root = Insert(root,11);

	//Print Nodes in Inorder
	cout<<"Inorder Traversal: ";
	Inorder(root);
	cout<<"\n";

	// Find Inorder successor of some node. 
	struct Node* successor = GetSuccessor(root,1);
	if(successor == NULL) cout<<"No successor Found\n";
	else
    cout<<"Successor is "<<successor->data<<"\n";

  
}
