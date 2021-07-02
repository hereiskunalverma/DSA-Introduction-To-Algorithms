#include<iostream>
#include<stack>
#include <unordered_set>
#define ln "\n";
using namespace std;
struct Node {
  int data;
  Node* left;
  Node* right;
  Node (int data) {
    this->data = data;
    left = right = NULL;
  }
};
void Inorder(Node* root) {
  if (root == NULL)
    return;
  stack<Node *> s;
  Node* current = root;
  while (current != NULL or s.empty() == false) {
    while (current != NULL) {
      s.push(current);
      current = current->left;
    }
    current = s.top(); //set current to last left child's root
    s.pop();
    cout << current->data << " ";
    current = current->right;
  }
}
void Preorder(Node* root) {
  if (root == NULL)
    return;
  stack<Node*> s;
  s.push(root);
  /*
  pop items, print it, push it righ child, push its left child
  */
  while (s.empty() == false) {
    Node* current = s.top();
    cout << current->data << " ";
    s.pop();
    if (current->right)
      s.push(current->right);
    if (current->left)
      s.push(current->left);
  }
}
void Postorder(Node* root) {
  if (root == NULL)
    return;
  struct Node* temp = root;
  unordered_set<Node*> visited;
  while (temp and visited.find(temp) == visited.end()) {
    if (temp->left and visited.find(temp->left) == visited.end())
      temp = temp->left;
    else if (temp->right and visited.find(temp->right) == visited.end())
      temp = temp->right;
    else {
      cout << temp->data << " ";
      visited.insert(temp);
      temp = root;
    }
  }

}
int main() {
  /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  cout << "\n\t\t\tInorder\t\t\t\n"
       Inorder(root);
  cout << ln;
  cout << "\n\t\t\tPreorder\t\t\t\n"
       Preorder(root);
  cout << ln;
  cout << "\n\t\t\tPostorder\t\t\t\n"
       Postorder(root);
}