/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-29 09:44:14  (IST)
*/
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

void insertAtHead(node* &head, int data) {
	node* temp = new node(data);
	if (head == NULL) {
		head = temp;
		return;
	}
	temp->next = head;
	head = temp;
}


void insertInMiddle(node* &head, int data, int pos) {
	if (pos == 0)
		insertAtHead(head, data);
	else {
		node* temp = head;
		for (int i = 1; i <= pos - 1; i++) {
			temp = temp->next;
		}
		node* temp2 = new node(data);
		temp2->next = temp->next;
		temp->next = temp2;
	}
}

void InsertAtEnd(node* head, int data) {
	if (head == NULL)
		return;
	node* temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	node* new_node = new node(data);
	temp->next = new_node;
}


void print(node* head) {
	if (head == NULL)
		return;
	cout << head->data << " ";
	print(head->next);
}
int main()
{
	node* head = NULL; // empty list;
	for (int i = 4; i >= 0; i--)
		insertAtHead(head, i);
	insertInMiddle(head, 100, 2);
	InsertAtEnd(head, 200);
	print(head);
}
