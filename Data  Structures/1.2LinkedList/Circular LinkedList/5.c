// Insertion at nth position
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
void Insert(int data){ // appending
	struct Node* new_node=GetNewNode(data);
	if(head==NULL){
		head=new_node;
		new_node->next=head;
		return;
	}
	new_node->next=head->next;
	head->next=new_node;
	head=new_node;
}
void DeleteAtHead(){
	struct Node *temp=head->next, *first=head->next;
	while(temp->next!=head->next){
		temp=temp->next; // last 
	}
	temp->next=first->next;
	head=temp;
	free(first);
}
void DeleteAtNth(int n){
	if(n==1){
		DeleteAtHead();
		return;
	}
	struct Node* temp=head;
	for(int i=1;i<n-2;i++){
		temp=temp->next; // poiting to previous of to be deleted node
	}
	struct Node* temp1=temp->next; // node to be deleted
	temp->next=temp1->next;
	free(temp1);

}
void DeleteAtEnd(){
	struct Node *temp=head, *last=head;
	while(temp->next!=head){
		temp=temp->next; // second last
	}
	temp->next=last->next;
	head=temp;
	free(last);
}
void Print(struct Node* head){
	if(head==NULL)
		return;
	struct Node* temp=head->next;
	do
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}while(temp!=head->next);
}
int main(){
	// Your Head is pointing to last element
	head=NULL;
	for(int i=1;i<=10;i++){
		Insert(i);
	}
	printf("\nThe initial list is -> ");
	Print(head);
	printf("\n");
	printf("\n\t\tDeleting element at head...\n");
	DeleteAtHead();
	printf("\nThe list is -> ");
	Print(head);
	printf("\n");
	printf("\n\t\tDeleting element at end...\n");
	DeleteAtEnd();
	printf("\nThe list is -> ");
	Print(head);
	printf("\n");
	printf("\n\t\tDeleting element at 3rd position...\n");
	DeleteAtNth(3+2); // add two because head is pointing to last element
	printf("\nThe list is -> ");
	Print(head);
	printf("\n");
}