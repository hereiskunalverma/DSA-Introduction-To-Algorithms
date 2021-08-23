
// Breadth - First (Level Order Traversal)


// First we visit all the nodes at every levels

// Idea is to use Queue - Insert root and then its children and do the same with other nodes


// Time Complexity - O(n)
// Space Complexity - O(1) - best; O(n) - Worst/Avg

#include<bits/stdc++.h>
#include<queue>
#define ll long long
#define ln "\n"
using namespace std;
struct BstNode
{
	char data;
	BstNode* right;
	BstNode* left;
};
BstNode* GetNewNode(int data){
	BstNode* newNode = new BstNode();
	newNode->data=data;
	newNode->right=NULL;
	newNode->left=NULL;
	return newNode;
}
BstNode* Insert(BstNode* root, char data){
	if(root==NULL)
		root=GetNewNode(data);
	else if (data<=root->data)
		root->left=Insert(root->left,data);
	else
		root->right=Insert(root->right, data);
	return root;
}
void LevelOrder(BstNode* root){
	if (root==NULL)return;
	queue<BstNode*> Q;
	Q.push(root); // address of root node in queue
	while(!Q.empty()){
		BstNode* current = Q.front();
		cout<<current->data<<" ";
		if(current->left!=NULL)Q.push(current->left);
		if(current->right!=NULL)Q.push(current->right);
		Q.pop(); // removing the element at front
	}

}
int main()
{
	// Test Case 1
	/*
	             F
			   /   \
			  D     J
			 / \   / \
			B   E  G  K
		   / \      \
		   A  C      \
			          I
			         /
			        H
	*/
	cout<<"\nTest Case 1: \n";
	BstNode* root=GetNewNode('F');
	root->left=GetNewNode('D');
	root->left->left=GetNewNode('B');
	root->left->left->left=GetNewNode('A');
	root->left->left->right=GetNewNode('C');
	root->left->right=GetNewNode('E');
	root->right=GetNewNode('J');
	root->right->left=GetNewNode('G');
	root->right->left->right=GetNewNode('I');
	root->right->left->right->left=GetNewNode('H');
	root->right->right=GetNewNode('K');
	LevelOrder(root);
	// Test Case 2
	/*Code To Test the logic
	  Creating an example tree
	            M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */
    cout<<"\nTest Case 2: \n";
    BstNode* root1=NULL;
    root1=Insert(root1,'M');root1=Insert(root1,'B');
    root1=Insert(root1,'Q');root1=Insert(root1,'Z');
    root1=Insert(root1,'A');root1=Insert(root1,'C');
    LevelOrder(root1);
}
