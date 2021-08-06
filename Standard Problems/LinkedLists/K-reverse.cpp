/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-29 10:30:34  (IST)
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
		node* temp = new node(data);
		temp->next = head;
		head = temp;
	}
}


node* KReverse(node* head, int k) {
	if (head == NULL)
		return NULL;
	// reverse the first k nodes
	node *current = head, *temp, *prev = NULL;
	int cnt = 1;
	while (current != NULL and cnt <= k) {
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
		cnt++;
	}
	if (temp != NULL) {
		head->next = KReverse(temp, k);
	}

	return prev;
}


void print(node* head) {
	if (head == NULL)
		return;
	cout << head->data << " ";
	print(head->next);
}

int main()
{
	node* head = NULL; // empty list
	for (int i = 10; i >= 0; i--)
		insert(head, i);
	print(head);
	cout << ln;
	head = KReverse(head, 3);
	print(head);
	cout << ln;
}





