// Implementation of Queues using Linked List


// rear - Enqueue
// front - Dequeue
#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* front=NULL; // head
Node* rear=NULL; //  tail 

void Enqueue(int x){
	Node* temp=new Node();
	temp->data=x;
	temp->next=NULL;
	if(front==NULL and rear==NULL){
		front=rear=temp;
		return;
	}
	rear->next=temp;
	rear=temp;
}
void Dequeue(){
	Node* temp=front;
	cout<<"\nDequeuing \n";
	if(front==NULL)return;
	if(front==rear)
		front=rear=NULL;
	else
		front=front->next;
	delete temp;
}
void Print(){
	Node* temp=front;
	cout<<"\nQueue is ";
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
void Front(){
	Node* temp=front;
	if(front==NULL)return;
	cout<<"\nFront is ";
	cout<<front->data;

}
void IsEmpty(){
	if (front==NULL and rear==NULL){
		cout<<"\nQueue is Empty\n";
		return;
	}
	cout<<"\nQueue is Not Empty\n";
}
int main(){
	IsEmpty();
	Enqueue(2);Print();
	Enqueue(4);Print();
	Enqueue(6);Print(); // queue is : 2 4 6
	Dequeue();
	Enqueue(8);Print();
	Front();
	IsEmpty();
}
