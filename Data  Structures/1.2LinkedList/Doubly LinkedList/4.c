// insert a element in sorted doubly linked list
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
void InsertNew(int data){
    struct Node* new_node=GetNewNode(data);
    struct Node *temp=head,*prevnode;
    while(1){
        prevnode=temp;
        if (temp->data>=data)
            break;
        temp=temp->next;
    }
    printf("prevnode %d\n", prevnode->prev->data);
    new_node->next=prevnode->prev->next;
    prevnode->prev->prev=new_node->next;
    prevnode->prev->next=new_node;
    new_node->prev=prevnode->prev;
}
void Print(struct Node* head){
    if(head==NULL)
        return;
    printf("%d ", head->data);
    Print(head->next);
}
int main(){
    head=NULL; // empty list
    for(int i=1;i<=10;i++){
        if(i==3)
            continue;
        Insert(i);
    }
    printf("\nThe initial list is -> ");
    Print(head);
    printf("\n\nInserting 3 in sorted linked list...\n");
    InsertNew(3);
    Print(head);
}
