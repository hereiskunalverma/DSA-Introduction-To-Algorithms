#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
struct Node {
  int data;
  Node* next;
};
Node* Insert(Node* head, int data){
  Node* temp=new Node();
  Node* temp1=head;
  temp->data = data;
  temp->next=NULL;
  if (head==NULL){
    head=temp;
  }
  else{
  while(temp1->next!=NULL)
    temp1=temp1->next;
  temp1->next=temp;
}
  return head;

}
void Print(Node* head){ // printing linked list using recursion
  if (head==NULL)
    return;
  cout<<head->data<<" ";
  Print(head->next); // Recursive Call
}
void ReversePrint(Node* head){
  if (head==NULL)
    return;
  ReversePrint(head->next); // Recursive Call
  cout<<head->data<<" ";
}
int main(){
  // Your code goes here
  Node* head=NULL; // empty list
  head=Insert(head,2);
  head=Insert(head,4);
  head=Insert(head,6);
  head=Insert(head,5);
  // list will be- 2 4 6 5
  cout<<"Elements in given order -: "<<ln;
  Print(head); // will print 2 4 6 5
  cout<<"\nElements in revese order :- "<<ln;
  ReversePrint(head);
  return 0;
}
