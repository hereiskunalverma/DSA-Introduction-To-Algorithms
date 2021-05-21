// Size of Doubly LinkedList
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
        new_node->next=NULL;
    }
}
void Delete(int n){
    struct Node* temp=head;
    // deletion at head
    if(n==1){
        head=temp->next;
        free(temp);
        return;
    }
    for(int i=0;i<n-2;i++){
        temp=temp->next;
    }
    struct Node* temp1=temp->next;
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
    head=NULL; // empty list
    for(int i=1;i<=10;i++){
        Insert(i);
    }
    printf("\nThe list is -> ");
    Print(head);
    printf("\n\n\nDeleting element at position 4...\n");
    Delete(4);
    printf("\nThe list is -> ");
    Print(head);
}
