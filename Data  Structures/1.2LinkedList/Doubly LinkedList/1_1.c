// Creation of Doubly LinkedList
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
struct Node* head; // 
struct Node* GetNewNode(int data){
	struct Node* new_node=(struct Node*)(malloc(sizeof(struct Node*)));
	new_node->data=data;
	new_node->prev=NULL;
	new_node->next=NULL;
	return new_node;
}
void Insert(int data){
	struct Node* temp=GetNewNode(data);
	if(head==NULL){
		head=temp;
		return;
	}
	head->prev=temp;
	temp->next=head;
	head=temp;
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
	// list should be - 10 9 8 7 6 ... 3 2 1
	printf("\nThe initial list is \n");
	Print(head);
	
}
