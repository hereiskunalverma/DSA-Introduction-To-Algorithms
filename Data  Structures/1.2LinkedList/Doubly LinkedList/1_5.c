// Deletion on LinkedList
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
void Insert(int data){
	struct Node* new_node=GetNewNode(data);
	if(head==NULL)
		head=new_node;
	else{
		struct Node* temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=new_node;
		new_node->prev=temp;
	}
}
void DeleteHead(){
	struct Node* temp=head;
	head=temp->next;
	free(temp);
}
void DeleteEnd(){
	struct Node* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->prev->next=NULL;
	free(temp);
}
void DeleteNth(int n){
	struct Node* temp=head;
	int i;
	if(n==1){ // deleting head
		DeleteHead();
		return;
	}
	for(int i=0; i<n-2;i++){
		temp=temp->next; // points to n-1 node
	}
	struct Node* temp1=temp->next; // points to nth node
	temp->next=temp1->next;
	free(temp1);
}
void Print(struct Node* head){
	if(head==NULL)
		return;
	printf("%d ", head->data);
	Print(head->next);
}
int main(){
	head=NULL;// empty list
	for(int i=1;i<=10;i++)
		Insert(i);
	printf("\n\t\t\tInitial List is\t\t\t\n");
	printf("\nList is -> ");
	Print(head);
	printf("\n");
	//<=======================================
	printf("\n\t\t\tDeletion at Head\t\t\t\n");
	printf("\nDeleting head ...\n");
	DeleteHead();
	printf("\nList is -> ");
	Print(head);
	printf("\n");
	//<=======================================
	printf("\n\t\t\tDeletion at End\t\t\t\n");
	printf("\nDeleting end node ...\n");
	DeleteEnd();
	printf("\nList is -> ");
	Print(head);
	printf("\n");
	//<=======================================
	printf("\n\t\t\tDeletion at Nth\t\t\t\n");
	printf("\nEnter position to delete node : ");
	int pos;
	scanf("%d",&pos);
	printf("\nDeleting node at %d position...\n",pos);
	DeleteNth(pos);
	printf("\nList is -> ");
	Print(head);
	printf("\n");
}
