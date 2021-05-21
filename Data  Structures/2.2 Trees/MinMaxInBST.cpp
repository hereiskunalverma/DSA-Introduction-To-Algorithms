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
int FindMin_Iterative(BstNode* root){
	if (root==NULL){
		cout<<"Error: Tree is empty"<<ln;
		return -1;
	}
	BstNode* current=root;
	while(current->left!=NULL){
		current=current->left;
	}
	return current->data;
}
int FindMax_Iterative(BstNode* root){
	if (root==NULL){
		cout<<"Error: Tree is empty"<<ln;
		return -1;
	}
	BstNode* current=root;
	while(current->right!=NULL){
		current=current->right;
	}
	return current->data;
}
int FindMin_Recursive(BstNode* root){
	if (root==NULL){
		cout<<"Error: Tree is empty"<<ln;
		return -1;
	}
	else if (root->left==NULL)
		return root->data;
	return FindMin_Recursive(root->left);
}
int FindMax_Recursive(BstNode* root){
	if(root==NULL){
		cout<<"Error: Tree is empty"<<ln;
		return -1;
	}
	else if (root->right==NULL)
		return root->data;
	return FindMax_Recursive(root->right);
}
BstNode* GetNewNode(int data){
	BstNode* newNode=new BstNode();
	newNode->data=data;
	newNode->right=NULL;
	newNode->left=NULL;
	return newNode;
}
BstNode* Insert(BstNode* root, int data){
	if(root==NULL)// empty tree
	{
		root=GetNewNode(data);
	}
	else if (data<=root->data)
		root->left=Insert(root->left,data);
	else
		root->right=Insert(root->right,data);
	return root;
}
int main()
{
  	BstNode* root; // to store address of root address
	root=NULL; // empty tree
	root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	cout<<"Iterative :- \n\n";
	int mxt=FindMax_Iterative(root);
	cout<<"Max element is : "<<mxt<<ln;
	int mnt=FindMin_Iterative(root);
	cout<<"Min Element is : "<<mnt<<ln;
	cout<<"\n\nRecursive :- \n\n";
	int mxr=FindMax_Recursive(root);
	cout<<"Max element is : "<<mxr<<ln;
	int mnr=FindMin_Recursive(root);
	cout<<"Min Element is : "<<mnr<<ln;
	return 0;
}



