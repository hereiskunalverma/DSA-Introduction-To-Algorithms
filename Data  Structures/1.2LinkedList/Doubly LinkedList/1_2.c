// Searching a given element
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
void Insert(int data){ // appending item at head
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
struct Node* head;
int Search(struct Node* head, int data){
	if(head==NULL)
		return 0;
	if (head->data==data)
		return 1;
	return Search(head->next, data);
}
int main(){
	head=NULL; // empty list
	for(int i=1;i<=10;i++)
		Insert(i);
	// list should be - 10 9 8 ... 3 2 1
	printf("\nThe initial list is ...\n");
	Print(head);
	int item;
	printf("\nEnter the element to search\n");
	scanf("%d",&item);
	printf("\nSearching element %d ...\n",item);
	if(Search(head, item))
		printf("\nElement Found!\n");
	else
		printf("\nElement not present!\n");

}
