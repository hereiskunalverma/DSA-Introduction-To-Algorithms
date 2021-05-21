// Insertion in linkedlist
#include<stdio.h>
#include<stdlib.h>
#define and &&
#define or ||
#include<math.h>
#define take_array(a,n) for(int i=0; i<n;i++)scanf("%d",&a[i]);
#define print_array(a,n) for(int i=0; i<n;i++){printf("%d ",a[i]);}printf("\n");
struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};
struct Node* head;
struct Node* GetNewNode(int data){
	struct Node* new_node=(struct Node*)(malloc(sizeof(struct Node*)));
	new_node->data=data;
	new_node->next=NULL;
	new_node->prev=NULL;
	return new_node;
}
void InsertAtHead(int data){
	struct Node* temp=GetNewNode(data);
	if(head==NULL){
		head=temp;
		return;
	}
	head->prev=temp;
	temp->next=head;
	head=temp;
}
void InsertAtTail(int data){
	struct Node* temp=GetNewNode(data);
	if(head==NULL){
		head=temp;
		return;
	}
	else{
		struct Node* temp1=head;
		while(temp1->next!=NULL)
			temp1=temp1->next;
		temp1->next=temp;
		temp->prev=temp1;
		temp->next=NULL;
	}
}
void InsertAtNth(int data, int n){
	struct Node* new_node=GetNewNode(data);
	if(n==1){
		InsertAtHead(data);
		return;
	}
	else{
	struct Node* temp=head;
	struct Node* temp1;
	for(int i=1;i<n-1;i++){
		temp=temp->next; // previous of node to be inserted
		temp1=temp->next; // next of node to be inserted
	}
	new_node->next=temp1;
	temp1->prev=new_node->next;
	temp->next=new_node;
	new_node->prev=temp;
}
}
void Print(struct Node* head){
	if(head==NULL)
		return;
	printf("%d ", head->data);
	Print(head->next);
}
int main(){
	head=NULL;
	for(int i=1;i<=5;i++){
		InsertAtHead(i);
	}
	printf("\n\t\t\tInsertion at Head\t\t\t\n");
	printf("List is -> ");
	Print(head);
	printf("\n");
	// <============================================
	for(int i=6;i<=10;i++)
		InsertAtTail(i);
	printf("\n\t\t\tInsertion at Tail\t\t\t\n");
	printf("List is -> ");
	Print(head);
	printf("\n");

	// // <=============================================
	printf("\n\t\t\tInsertion at Nth\t\t\t\n");
	printf("List is -> ");
	Print(head);
	printf("\n");
	int item,pos;
	printf("\nEnter element to insert : ");
	scanf("%d",&item);
	printf("\nEnter position of the item : ");
	scanf("%d",&pos);
	InsertAtNth(item,pos);
	printf("\nThe List is -> ");
	Print(head);
	printf("\n");
}
