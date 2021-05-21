#include<bits/stdc++.h>
using namespace std;
#define ln "\n"
struct Node{
  int data;
  Node* next;
};
Node* head;
void Insert(int data, int n){
  Node* temp1=new Node();
  temp1->data = data;
  temp1->next = NULL;
  if (n==1) // handling when insert at 1st position
  {
    temp1->next=head;
    head=temp1;
    return;
  }
  Node* temp2=head; // traversing to list
  for(int i=0;i<n-2;i++){ // n-2 because we are pointing at head which is 1st node
    temp2=temp2->next;
  }
  temp1->next=temp2->next;
  temp2->next=temp1;
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
  head=NULL; // empty list
  Insert(2,1); // List: 2;
  Insert(3,2); // List: 2, 3
  Insert(4,1); // List: 4,2,3
  Insert(5,2); // List: 4,5,2,3
  Print();
}
