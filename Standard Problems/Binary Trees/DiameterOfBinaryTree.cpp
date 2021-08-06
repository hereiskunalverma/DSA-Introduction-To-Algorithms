/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-08-03 09:49:00  (IST)
*/
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// Diameter is defined as the largest distance between any (farthest) nodes of the tree

class node
{
public:
	int data;
	node* left;
	node* right;
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}

};


node* buildTree() {
	int d;
	cin >> d;
	if (d == -1)
		return NULL;
	node* n = new node(d);
	n->left = buildTree();
	n->right = buildTree();
	return n;
}
// level order traversal
void print(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while (not q.empty()) {
		node* temp = q.front();
		if (temp == NULL) {
			cout << ln;
			q.pop();
			if (not q.empty())
				q.push(NULL);
		}
		else {
			q.pop();
			cout << temp->data << " ";
			if (temp->left) {
				q.push(temp->left);
			}
			if (temp->right) {
				q.push(temp->right);
			}
		}
	}
	return;
}

/*
Input -

			1
		2       3
      4   5       6
         7

diameter between node 7 and 6 (farthest nodes) is 5
*/

int height(node* root) {
	if (root == NULL)
		return 0;
	int h1 = height(root->left);
	int h2 = height(root->right);
	return 1 + max(h1, h2);
}

// Diameter// Time Complexity - O(N^2);
int diameter(node* root) {
	// base case
	if (root == NULL)
		return 0;
	// rec case
	int D1 = height(root->left) + height(root->right);
	int D2 = diameter(root->left);
	int D3 = diameter(root->right);
	return max({
		D1,
		D2,
		D3
	});
}

// -------------- Diameter Optimised
class HDPair {
public:
	int height;
	int diameter;
};
HDPair optDiameter(node* root) {
	HDPair p;
	if (root == NULL) {
		p.height = p.diameter = NULL;
		return p;
	}
	HDPair Left = optDiameter(root->left);
	HDPair Right = optDiameter(root->right);
	p.height = max(Left.height, Right.height) + 1;
	int D1 = Left.height + Right.height;
	int D2 = Left.diameter;
	int D3 = Right.diameter;
	p.diameter = max({
		D1,
		D2,
		D3
	});
	return p;
}

int main()
{

	node* root = buildTree();
	print(root);
	cout << "\nDiameter is : " << diameter(root) << ln;
	cout << "\nOpt Diameter is :" << optDiameter(root).diameter << ln;

}
