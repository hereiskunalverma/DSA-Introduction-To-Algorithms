// Insertion in Circular LinkedList
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
};
struct Node* head;
struct Node* GetNewNode(int data){
	struct Node* new_node=(struct Node*)(malloc(sizeof(struct Node*)));
	new_node->data=data;
	new_node->next=NULL;
	return new_node;
}
void InsertAtHead(int data){
	struct Node* new_node=GetNewNode(data);
	if(head==NULL){
		head=new_node;
		new_node->next=head;
		return;
	}
	new_node->next=head->next;
	head->next=new_node;
}
void InsertionAtEnd(int data){ 
	struct Node* new_node=GetNewNode(data);
	new_node->next=head->next;
	head->next=new_node;
	head=new_node;
}
void InsertAtNth(int n, int data){
	struct Node* new_node=GetNewNode(data);
	struct Node* temp=head;
	if(n==1){
		InsertAtHead(data);
		return;
	}
	for(int i=1;i<n-2;i++){
		temp=temp->next;
	}
	new_node->next=temp->next;
	temp->next=new_node;
}
void Print(struct Node* head){
	struct Node* temp=head->next;
	if(head!=NULL){
		do
		{
			printf("%d ", temp->data);
			temp=temp->next;
		}while(temp!=head->next);
	}
}
int main(){
	head=NULL; // empty list

	// Insertion At Head
	printf("\n\t\tInsertion At Head (1 2 3 4 5)\n");
	for(int i=5;i>=1;i--)
		InsertAtHead(i);
	printf("\nThe Circular List is -> "); // 1 2 3 4 5
	Print(head);
	printf("\n");

	// InsertionAtEnd
	printf("\n\t\tInsertion At End (8 9 10)\n");
	for(int i=8;i<=10;i++)
		InsertionAtEnd(i);
	printf("\nThe Circular List is -> ");
	// List -> 1 2 3 4 5 8 9 10
	Print(head);
	printf("\n");

	// Insert At Given Position
	printf("\n\t\tInsertion At Given Position (6 7)\n");
	InsertAtNth(6+2,6);
	InsertAtNth(7+2,7);
	printf("\nThe Circular List is -> ");
	// List -> 1 2 3 4 ... 8 9 10
	Print(head);
	printf("\n");
}
