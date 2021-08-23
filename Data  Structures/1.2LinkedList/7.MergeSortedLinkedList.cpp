/*

R E X


* @Author: Kunal Verma

		CodeForces - kunalverma19
		CodeChef   - kunalverma_19
		AtCoder    - TLKunalVermaRX

* @Last Modified by:   Kunal Verma
* @Modified Time: 2021-07-03 09:49:17  (IST)
*/

#include<bits/stdc++.h>
#define ll long long
#define ln "\n"
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* Insert(Node* head, int data) {
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = NULL;
	if (head == NULL)
		head = new_node;
	else {
		Node* temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
	return head;
}
Node* merge(Node* head1, Node* head2) {
	Node* result = NULL;
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	// take any of the node
	if (head1->data <= head2->data) {
		result = head1;
		result->next = merge(head1->next, head2);
	}
	else {
		result = head2;
		result->next = merge(head1, head2->next);
	}
	return result;
}
void Print(Node* head) {
	if (head == NULL)
		return;
	cout << head->data << " ";
	Print(head->next);
}
int main()
{
	Node *head1 = NULL, *head2 = NULL; // empty lists
	Node* merged_list = NULL;
	for (int i = 1; i <= 5; i++)
		head1 = Insert(head1, i);
	for (int i = 5; i <= 10; i++)
		head2 = Insert(head2, i);
	cout << "First list is -> ";
	Print(head1);
	cout << ln;
	cout << "Second list is -> ";
	Print(head2);
	cout << ln;
	merged_list = merge(head1, head2);
	cout << "Merged List -> ";
	Print(merged_list);
}
