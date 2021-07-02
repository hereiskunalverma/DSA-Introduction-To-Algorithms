#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// Binary Tree Implementation

struct Node
{
  int data;
  struct Node* left;
  struct Node* right;
};
struct Node* create() {
  struct Node* root;
  int data;
  printf("Enter data (-1 for no data) : ");
  scanf("%d", &data);
  if (data == -1)
    return NULL;
  root = (struct Node* )malloc(sizeof(struct Node*));
  root->data = data;
  printf("Enter left child of %d : \n", data);
  root->left = create();
  printf("Enter right child of %d : \n", data);
  root->right = create();
  return root;
}

void Inorder(struct Node* root) {
  if (root == NULL)
    return;
  Inorder(root->left);
  printf("%d ", root->data);
  Inorder(root->right);
}
void Postorder(struct Node* root) {
  if (root == NULL)
    return;
  Postorder(root->left);
  Postorder(root->right);
  printf("%d ", root->data);
}
void Preorder(struct Node* root) {
  if (root == NULL)
    return;
  printf("%d ", root->data);
  Preorder(root->left);
  Preorder(root->right);
}
int main() {
  struct Node* root = NULL; // empty tree
  root = create();
  printf("\n\t\t\t Inorder \t\t\t\n");
  Inorder(root);
  printf("\n\t\t\t Preorder \t\t\t\n");
  Preorder(root);
  printf("\n\t\t\t Postorder \t\t\t\n");
  Postorder(root);
}