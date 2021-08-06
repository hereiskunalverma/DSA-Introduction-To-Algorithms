/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-29 10:05:47  (IST)
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

void insert(node* &head, int data) {
	node* temp = new node(data);
	if (head == NULL)
		head = temp;
	else {
		temp->next = head;
		head = temp;
	}
}


void print(node* head) {
	if (head == NULL)
		return;
	cout << head->data << " ";
	print(head->next);
}

node* recReverse(node* head) {
	if (head == NULL or head->next == NULL)
		return head;
	node* temp = recReverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return temp;
}

void iterReverse(node* &head) {
	node *temp, *prev = NULL, *current = head;
	while (current != NULL) {
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}

	head = prev;

	return;
}


int main()
{
	node* head = NULL; // empty list
	for (int i = 5; i >= 1; i--)
		insert(head, i);
	iterReverse(head);
	print(head);
}
