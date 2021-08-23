/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-29 11:04:56  (IST)
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
		node* temp2 = head;
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = temp;
	}
}

node* merge(node* a, node* b) {
	if (a == NULL)
		return b;
	if (b == NULL)
		return a;
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

// Runner Technique
node* midPoint(node* head) {
	node* slow = head;
	node* fast = head->next;
	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

node* mergeSort(node* head) {
	// base case
	if (head == NULL or head->next == NULL)
		return head;

	// rec case

	node* mid = midPoint(head);

	// break at the mid
	node* a = head;
	node* b = mid->next;
	mid->next = NULL;

	// Recursive sort
	a = mergeSort(a);
	b = mergeSort(b);

	// Merge
	return merge(a, b);
}



void print(node* head) {
	if (head == NULL)
		return;
	cout << head->data << " ";
	print(head->next);
}

int main()
{
	node* a = NULL; // empty list
	for (int i = 10; i >= 0; i--)
		insert(a, i);
	print(a);
	cout << ln;
	a = mergeSort(a);
	print(a);
	cout << ln;
}





