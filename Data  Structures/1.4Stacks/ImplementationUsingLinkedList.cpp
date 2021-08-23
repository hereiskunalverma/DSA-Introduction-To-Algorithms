#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

// Stacks are the implementations of the following operations:
// 1. Push()
// 2. Pop()
// 3. Top()
// 4. IsEmpty()

struct Node
{
	int data;
	Node* link;
};
Node* top=NULL;
void Push(int data){ // Push operation 
	Node* temp=new Node();
	temp->data=data;
	temp->link=top;
	top=temp;
}
void Pop(){
	Node* temp;
	if(top==NULL)return;
	temp=top;
	top=top->link;
	delete temp; // free(temp) in C
}
void Top(){
	if (top==NULL)return;
	cout<<top->data<<" "<<ln;
}
void IsEmpty(){
	if (top==NULL)
			cout<<"Stack is Empty"<<ln;
	else
		cout<<"Stack is not Empty"<<ln;
}
void Print(){
	Node* temp=top;
	cout<<"\nStack is :- "<<ln;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->link;
	}
}
int main()
{
	IsEmpty();
	Push(2);Print();
	Push(4);Print();
	Push(5);Print();
	Push(6);Print();
	// Stack is 6 5 4 2
	Pop();Print();
	// Stack is 5 4 2
	cout<<"\nTop element is ";
	Top();
	Print();
}










