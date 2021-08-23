#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
struct Node {
  int data;
  Node* next;
};
Node* head;
Node* Insert(int data){
  Node* temp=new Node();
  temp->data=data;
  temp->next=NULL;
  Node* temp1=head;
  if (head==NULL) // checking for empty list first
    head=temp;
  else{
    while(temp1->next!=NULL)
      temp1=temp1->next;
    temp1->next=temp;
  }
  return head;
}
void Reverse(Node* p){
  if (p->next==NULL){
    head=p; // making the last to head
    return;
  }
  Reverse(p->next);
  Node* q=p->next;
  q->next=p;
  p->next=NULL;
}
void Print(Node* head){
  if (head==NULL)
    return;
   cout<<head->data<<" ";
   Print(head->next);
}
int main(){
  // Your code goes here
  head=NULL;
  Insert(2);
  Insert(4);
  Insert(6);
  Insert(5);
  Print(head); // list 2 4 6 5
  Reverse(head); // Reversing list
  cout<<ln;
  Print(head); // list 5 6 4 2
  return 0;
}
