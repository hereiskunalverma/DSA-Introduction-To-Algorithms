// Depth - First 

//                 D     L      R
// 1. Preorder - <root><left><right>

//                 L     D      R
// 2. Inorder  - <left><root><right>

//                 L     R      D
// 3. Preorder - <left><right><root>


// Time Complexity - O(n)
// Space Complexity - O(h); h-> height of tree, Best/Average: O(logn)

#include<bits/stdc++.h>
#include<queue>
#define ll long long
#define ln "\n"
using namespace std;
struct Node
{
	char data;
	Node* left;
	Node* right;
};
Node* GetNewNode(char data){
	Node* newNode=new Node();
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	return newNode;
}
Node* Insert(Node* root, char data){
	if(root==NULL)
		root=GetNewNode(data);
	else if (data<=root->data)
		root->left=Insert(root->left,data);
	else
		root->right=Insert(root->right,data);
	return root;
}
void Preorder(Node* root){
	if(root==NULL)return; // if subtree is empty
	cout<<root->data<<" "; // root data
	Preorder(root->left); // visit left
	Preorder(root->right); // visit right
}
void Inorder(Node* root){
	if(root==NULL)return;
	Inorder(root->left); // left 
	cout<<root->data<<" "; // root data
	Inorder(root->right); // right
}
void Postorder(Node* root){
	if(root==NULL)return;
	Postorder(root->left);
	Postorder(root->right);
	cout<<root->data<<" ";
}
void Print(Node* root) // breadth first to
{
	
	if(root==NULL)return;
	queue<Node*> Q;
	Q.push(root);
	while(!Q.empty()){
		Node* current=Q.front();
		cout<<current->data<<" ";
		if(current->left!=NULL)Q.push(current->left);
		if(current->right!=NULL)Q.push(current->right);
		Q.pop();
	}
}
int main()
{
  Node* root=NULL;
  root=Insert(root,'F');
  root=Insert(root,'D');
  root=Insert(root,'J');
  root=Insert(root,'B');
  root=Insert(root,'E');
  root=Insert(root,'G');
  root=Insert(root,'K');
  root=Insert(root,'A');
  root=Insert(root,'C');
  root=Insert(root,'I');
  cout<<"\nThe elements in tree are (Breadth-First) : ";
  Print(root); // this is correct
  cout<<"\nPreorder : ";
  Preorder(root);
  cout<<"\nInorder : ";
  Inorder(root);
  cout<<"\nPostorder : ";
  Postorder(root);

}

