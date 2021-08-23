/*
* @Author: Kunal Verma
* @Date:   2021-01-04 09:04:26
* @Last Modified on:   HP
* @Last Modified time: 2021-07-15 13:28:01
*/

// Building expression tree from prefix expression
#include<stdio.h>
#include<stdlib.h>
#define and &&
#define or ||
#include<math.h>
#define take_array(a,n) for(int i=0; i<n;i++)scanf("%d",&a[i]);
#define print_array(a,n) for(int i=0; i<n;i++){printf("%d ",a[i]);}printf("\n");

typedef struct node {
	char data;
	struct node *left, *right;
} node;


// build the expression tree
char* add(node** p, char *a) {
	// if end of the expression
	if (*a == '\0')
		return '\0';
	while (1) {
		char *q = NULL;
		if (*p == NULL) {
			// make a node *a as the data with
			// both the children as null
			node* new_node = (node*)malloc(sizeof(node));
			new_node->data = *a;
			new_node->left = NULL;
			new_node->right = NULL;
			*p = new_node;
		}
		else {
			// if the character is an operand
			if (*a >= 'a' and * a <= 'z')
				return a;
			// build the left sub-tree
			q = add(&(*p)->left, a + 1);

			// build the right sub-tree
			q = add(&(*p)->right, q + 1);
			return q;
		}
	}
}
// print the infix expression
void infix(node*p) {
	if (p == NULL)
		return;
	infix(p->left);
	printf("%c ", p->data);
	infix(p->right);
}

// print the postfix expression
void postfix(node* p) {
	if (p == NULL)
		return;
	postfix(p->left);
	postfix(p->right);
	printf("%c ", p->data);
}
int main() {
	node* s = NULL;
	char a[] = "*+ab-cd";
	add(&s, a);
	printf("The Infix expression is : \n");
	infix(s);
	printf("\n");
	printf("The Postfix expression is : \n");
	postfix(s);
	return 0;
}
