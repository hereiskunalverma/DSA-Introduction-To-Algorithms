#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
struct Node{
  int data;
  Node* next;
};
Node* Insert(Node* head, int data){ // adding element at end
  Node* new_node=new Node();
  Node* temp=head;
  new_node->data=data;
  new_node->next=NULL;
  if (head==NULL){
    head=new_node;
  }
  else{
  while(temp->next!=NULL)temp=temp->next;
  temp->next=new_node;
}
  return head;
}
void Print(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<ln;
}
int main(){
  // Your code goes here
  Node* head=NULL;
  head=Insert(head,2); // Insert: struct Node* Insert(struct Node* head, int data)
  head=Insert(head,4);
  head=Insert(head,6);
  head=Insert(head,8);
  Print(head);
  return 0;
}
