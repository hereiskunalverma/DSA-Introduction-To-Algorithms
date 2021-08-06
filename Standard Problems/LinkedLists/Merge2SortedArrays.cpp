/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-29 10:45:42  (IST)
*/

// Revese every k-nodes of the given linked list



#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;

class node {
public:
	int data;
	node* next;
	node(int data) {
		this->data = data;
		next = NULL;
	}
};


void insert(node* &head, int data) {
	if (head == NULL)
		head = new node(data);
	else {
		node* temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		node* new_node = new node(data);
		temp->next = new_node;
	}
}


node* merge(node* a, node* b) {
	if (a == NULL)
		return b;
	if (b == NULL)
		return a;
	// rec case
	node* c;
	if (a->data < b->data) {
		c = a;
		c->next = merge(a->next, b);
	}
	else {
		c = b;
		c->next = merge(a, b->next);
	}
	return c;
}


void print(node* head) {
	if (head == NULL)
		return;
	cout << head->data << " ";
	print(head->next);
}

int main()
{
	node *a = NULL, *b = NULL;
	insert(a, 1);
	insert(a, 5);
	insert(a, 7);
	insert(a, 10);
	insert(b, 2);
	insert(b, 3);
	insert(b, 6);
	cout << " first ll is : ";
	print(a);
	cout << ln;
	cout << " second ll is : ";
	print(b);
	cout << ln;

	node *head = merge(a, b);
	cout << " LinkedList sorted : ";
	print(head);
}





