// Deleting a node from Binary Search Tree
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};
//Function to find minimum in a tree. 
Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}
Node* Delete(Node* root, int data){
	if(root==NULL)return root;
	else if (data < root->data)
		root->left = Delete(root->left,data);
	else if(data > root->data)
		root->right=Delete(root->right,data);
	else { // found
		// Case 1: No child
		if(root->left==NULL and root->right==NULL){
			delete root;
			root=NULL;
		}
		// Case 2: One Child
		else if (root->left==NULL){
			Node* temp=root;
			root=root->right;
			delete temp;
		}
		else if (root->right==NULL){
			Node* temp=root;
			root=root->left;
			delete temp;
		}
		// Case 3: Two children
		else{
			Node* temp=FindMin(root->right); // finding min in right subtree
			root->data=temp->data;
			root->right=Delete(root->right,temp->data);
		}
	}
	return root;
}
//Function to visit nodes in Inorder
void Inorder(Node *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}
// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root,char data) {
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
	cout<<"\nTree is ";
	Inorder(root);
	cout<<ln;

	// Deleting node with value 5, change this value to test other cases
	root = Delete(root,5);

	//Print Nodes in Inorder
	cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";
}
