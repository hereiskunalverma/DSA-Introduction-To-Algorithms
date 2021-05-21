// maximum value in doubly linked list
#include<stdio.h>
#include<stdlib.h>
#define and &&
#define or ||
#include<math.h>
#define take_array(a,n) for(int i=0; i<n;i++)scanf("%d",&a[i]);
#define print_array(a,n) for(int i=0; i<n;i++){printf("%d ",a[i]);}printf("\n");
void swap(int *a, int *b){
	int temp=*b;
	*b=*a;
	*a=temp;
}
struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};
struct Node* head;
struct Node* GetNewNode(int data){
	struct Node* new_node = (struct Node*)(malloc(sizeof(struct Node*)));
	new_node->data=data;
	new_node->next=NULL;
	new_node->prev=NULL;
	return new_node;
}
void Insert(int data){
	struct Node* new_node=GetNewNode(data);
	if(head==NULL){
		head=new_node;
		return;
	}
	struct Node* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=new_node;
	new_node->prev=temp;
	new_node->next=NULL;
}
void sort(struct Node* head){
	int flag,i;
	struct Node* temp;
	struct Node* temp1=NULL;
	if(head==NULL)
		return;
	do
	{
		flag=0;
		temp=head;
		while(temp->next!=temp1){
		if(temp->data < temp->next->data){
			swap(&temp->data,&temp->next->data);
			flag=1;
		}
		temp=temp->next;
	}
	temp1=temp;
	}while(flag);
}
void Print(struct Node* head){
	if(head==NULL)
		return;
	printf("%d ", head->data);
	Print(head->next);
}
int main(){
	head=NULL; // empty list
	Insert(2);
	Insert(5);
	Insert(1);
	Insert(3);
	Insert(2);
	Insert(0);
	printf("\nThe initial list is -> ");
	Print(head);
	printf("\n");
	printf("\n\n\t\tFinding maximum element...\n\n");
	sort(head);
	printf("The maximum is %d\n",head->data);
}
