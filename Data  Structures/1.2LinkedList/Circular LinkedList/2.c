// Creation and Traversal of Circular Linked List
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
void Insert(int data){ // insertion at end
	struct Node* new_node=GetNewNode(data);
	struct Node* temp=head;
	if(head==NULL){
		head=new_node;
		new_node->next=head;
	}
	else{
		while(temp->next!=head){
			temp=temp->next;
		}
		temp->next=new_node;
		new_node->next=head;
	}
}
void Print(struct Node* head){
	struct Node* first=head;
	if(head!=NULL){
	do{
		printf("%d ", first->data);
		first=first->next;
	}while(first!=head);
}
}
int main(){
	head=NULL; // empty list
	for(int i=1;i<=10;i++)
		Insert(i);
	printf("\nThe initial Circular Linked List is -> ");
	Print(head);
}
