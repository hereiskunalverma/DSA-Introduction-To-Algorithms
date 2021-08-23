/*

Check if a given binary is BST


Approaches - 

1. Making functions like IsSubtreeLesser and IsSubtreeGreater
2. Finding Max in left subtree and Min in right subtree{
	if Max < root->data and Min > root->data:
		return tree is BST
}


*/

#include<bits/stdc++.h>
#include<queue>
#define ll long long
#define ln "\n"
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};
Node* GetNewNode(int data){
	Node* newNode=new Node();
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	return newNode;
}
Node* Insert(Node* root, int data){
	if(root==NULL)
		root=GetNewNode(data);
	else if (data<=root->data)
		root->left=Insert(root->left,data);
	else
		root->right=Insert(root->right,data);
	return root;
}
bool IsSubtreeLesser(Node* root, int val){ // if all elements are less than val
	if(root==NULL)return true;
	if(root->data < val
		and IsSubtreeLesser(root->left,val)
		and IsSubtreeLesser(root->right,val))
		return true;
	return false;
}
bool IsSubtreeGreater(Node* root, int val){ // if all elements are larger than val
	if(root==NULL)return true;
	if(root->data>val
		and IsSubtreeGreater(root->left,val)
		and IsSubtreeGreater(root->right,val))
		return true;
	return false;
}
bool IsBinarySearchTree(Node* root){
	if(root==NULL)return true;
	if(IsSubtreeLesser(root->left,root->data) 
		and IsSubtreeGreater(root->right,root->data)
		and IsBinarySearchTree(root->left)
		and IsBinarySearchTree(root->right))
		return true;
	return false;
}
void Print(Node* root){
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

// This is efficient
bool IsBSTUtil(Node* root, int minval, int maxval){
	if(root==NULL)return true;
	if(root->data<maxval
	   and root->data>minval
	   and IsBSTUtil(root->left, minval, root->data)
	   and IsBSTUtil(root->right, root->data, maxval))
		return true;
	return false;
}
bool IsBinarySearchTreeEff(Node*root){
	return IsBSTUtil(root, INT_MIN, INT_MAX);
}
int main()
{
  Node* root=NULL;
  cout<<"\nTest Case 1"<<ln; // Yes
  root=Insert(root,7);root=Insert(root,4);root=Insert(root,9);root=Insert(root,1);root=Insert(root,6);
  cout<<(IsBinarySearchTree(root)?"YES":"NO")<<ln;
  cout<<(IsBinarySearchTreeEff(root)?"YES":"NO")<<ln;
  Print(root);
  cout<<ln<<ln;
  Node* root1=NULL;
  cout<<"\n\nTest Case 2"<<ln; // Yes
  root1=Insert(root1,8);root1=Insert(root1,6);root1=Insert(root1,4);
  cout<<(IsBinarySearchTree(root1)?"YES":"NO")<<ln;
  cout<<(IsBinarySearchTreeEff(root1)?"YES":"NO")<<ln;
  Print(root1);
  cout<<ln<<ln;
  Node* root2=NULL;
  cout<<"\n\nTest Case 3"<<ln; // No
  root2=Insert(root2,10);root2=Insert(root2,5);root2=Insert(root2,16);root2=Insert(root2,4);root2=Insert(root2,7);root2=Insert(root2,1);root2=Insert(root2,11);
  cout<<(IsBinarySearchTree(root2)?"YES":"NO")<<ln;
  cout<<(IsBinarySearchTreeEff(root2)?"YES":"NO")<<ln;
  Print(root2);
  cout<<ln<<ln;
}






