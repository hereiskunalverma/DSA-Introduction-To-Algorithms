#include<bits/stdc++.h>
#include<stack>
#define ll long long
#define ln "\n"
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* head;
void Insert(int data){
	Node* temp=new Node();
	temp->data=data;
	temp->next=head;
	head=temp;
}
void Reverse(){
	if(head==NULL)return;
	stack<struct Node*> S;
	Node* temp=head;
	while(temp!=NULL){
		S.push(temp);
		temp=temp->next;
	}
	temp=S.top();
	head=temp;
	S.pop();
	while(!S.empty()){
		temp->next=S.top();
		S.pop();
		temp=temp->next;
	}
	temp->next=NULL;
}
void Print(){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main()
{
	head=NULL;
	// adding elements in the list at beginning
	Insert(2);
	Insert(4);
	Insert(5);
	Insert(6);
	cout<<"\nList is "<<ln;
	Print();
	cout<<"\nReverse List is "<<ln;
	Reverse();
	Print();
	return 0;
}
