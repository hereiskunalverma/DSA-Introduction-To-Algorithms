// Reverse Doubly LinkedList
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
	struct Node* temp=(struct Node*)(malloc(sizeof(struct Node*)));
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}
void Insert(int data){
	struct Node* temp=GetNewNode(data);
	if(head==NULL)
		head=temp;
	else{
		struct Node* temp1=head;
		while(temp1->next!=NULL){
			temp1=temp1->next;
		}
		temp1->next=temp;
		temp->prev=temp1;
		temp->next=NULL;
	}
}
void Reverse(){
	struct Node* temp=NULL;
	struct Node* current=head;
	while(current!=NULL){
		temp=current->prev;
		current->prev=current->next;
		current->next=temp;
		current=current->prev;
	}
	head=temp->prev;

}
void Print(struct Node* head){
	if(head==NULL)
		return;
	printf("%d ", head->data);
	Print(head->next);
}
int main(){
	head=NULL; // empty list
	for(int i=1; i<=10;i++)
		Insert(i);
	printf("\nInitial List is -> ");
	Print(head);
	printf("\n");
	printf("\nReversed List is -> ");
	Reverse();
	Print(head);
	printf("\n");
}
