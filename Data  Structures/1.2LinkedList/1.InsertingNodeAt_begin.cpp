// Inserting a Node at beginning

#include<bits/stdc++.h>
using namespace std;
#define ln "\n"
struct Node {
  int data; // value at node
  Node* next; // address to point to next
  // struct node* next; // In C
};
Node* head; // In C just add struct Node* head
void Insert(int x) {
  Node* temp = new Node(); //(Node*)malloc(sizeof(Node)) In C; // void memory
  temp->data = x;
  temp->next = head; // address of the next Node
  head = temp; // pointing head to list
}
void Print() {
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next; // going to next head
  }
  cout << ln;

}
int main() {
  head = NULL; // address of first
  cout << "How many numbers ?" << ln;
  int n, i, x;
  cin >> n;
  for (i = 0; i < n; i++) {
    cout << "Enter the number : ";
    cin >> x;
    Insert(x); // funtion to insert element in linked list
    Print(); // Printing elements of linked list
  }
  return 0;
}
