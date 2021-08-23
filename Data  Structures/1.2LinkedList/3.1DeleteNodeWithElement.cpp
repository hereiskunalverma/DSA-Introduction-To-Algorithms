// Deleting a node at ith position
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
struct Node {
  int data;
  Node* next;
};
Node* head;
void Delete(int key){
  Node* temp=head;
  Node* prev=NULL;
  if (temp!=NULL and temp->data==key){
    head=temp->next;
    delete temp;
    return;
  }
  while(temp!=NULL and temp->data!=key){
    prev=temp;
    temp=temp->next;
  }
  if(temp==NULL) // key not present
    return;
  prev->next=temp->next;
  delete temp;
}
void Insert(int data){ // insert at end
  Node* temp=new Node();
  temp->data=data;
  temp->next=NULL;
  if(head==NULL){
    head=temp;
    return;
  }
  Node* temp1=head;
  while(temp1->next!=NULL){
    temp1=temp1->next;
  }
  temp1->next=temp;

}
void Print(){
  Node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<ln;
}
int main(){
  // Your code goes here
  head=NULL; // empty list
  Insert(2);
  Insert(4);
  Insert(6);
  Insert(5);
  // List will be : 2 4 6 5
  cout<<"The list is "<<ln;
  Print();
  Delete(4);
  cout<<"\nThe list is after deleting"<<ln;
  Print();
}
