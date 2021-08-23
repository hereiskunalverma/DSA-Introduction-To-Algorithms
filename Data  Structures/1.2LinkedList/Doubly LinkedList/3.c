// sorting doubly linked list
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
    struct Node* new_node=(struct Node*)(malloc(sizeof(struct Node*)));
    new_node->data=data;
    new_node->next=NULL;
    new_node->prev=NULL;
    return new_node;
}
void Insert(int data){
    struct Node* temp=GetNewNode(data);
    if(head==NULL)
        head=temp;
    else{
        struct Node* temp1=head;
        while(temp1->next!=NULL)
            temp1=temp1->next;
        temp1->next=temp;
        temp->prev=temp1;
        temp->next=NULL;
    }
}
void Print(struct Node* head){
    if(head==NULL)
        return;
    printf("%d ", head->data);
    Print(head->next);
}
void bubblesort(struct Node* head){
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
            if(temp->data > temp->next->data){
                swap(&temp->data,&temp->next->data);
                flag=1;
            }
            temp=temp->next;
        }
        temp1=temp;
    }while(flag);
}
int main(){
    head=NULL; // empty list
    for(int i=10;i>0;i--)
        Insert(i);
    printf("\nThe initial list is - ");
    Print(head);
    printf("\n");
    bubblesort(head);
    printf("\nThe sorted list is - ");
    Print(head);
}
