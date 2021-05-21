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
void Insert(int data){ // Insertion at end
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
void InsertAtNth(int n, int data){
	struct Node* new_node=GetNewNode(data);
	struct Node* temp=head;
	if(n==1){
		Insert(data);
		return;
	}
	for(int i=1;i<n-2;i++){
		temp=temp->next;
	}
	new_node->next=temp->next;
	temp->next=new_node;
}
void Print(struct Node* head){
	if (head==NULL)
		return;
	struct Node* temp=head->next;
	do
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}while(temp!=head->next);
}
int main(){
	head=NULL;
	for(int i=1;i<=10;i++){
		if(i==3)
			continue;
		Insert(i);
	}
	printf("\nThe initial list is -> ");
	Print(head);
	printf("\n\nInserting element 3 ... \n");
	InsertAtNth(3+2,3);
	printf("\nThe list is -> ");
	Print(head);
}

