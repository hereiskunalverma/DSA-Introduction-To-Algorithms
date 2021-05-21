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
void Insert(int data) // Insert at end of list
{
  Node* temp=new Node();
  Node* temp1=head;
  temp->data = data;
  temp->next=NULL;
  if (head==NULL){ // since head is null we have to add initial element
    head=temp;
    return;
  }
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
void Delete(int n)// Delete at nth position
{
  struct Node* temp1=head;
  int i;
  if(n==1){ // to delete at 1st position
    head=temp1->next; // head now points to second node
    delete temp1; // In C we use free(temp1) freeing memory
    return;
  }
  for(int i=0;i<n-2;i++){
    temp1=temp1->next;
  } // temp1 points to n-1 node
  Node* temp2=temp1->next; // nth node
  temp1->next=temp2->next; // n+1 node
  delete temp2; // In C we use free(temp1)
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
  int n;
  cout<<"Enter the position to delete the node at ";
  cin>>n;
  Delete(n);
  cout<<"The list is "<<ln;
  Print();
}
