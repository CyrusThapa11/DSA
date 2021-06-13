#include <bits/stdc++.h>
using namespace std;

// DOUBLY LINKED LIST !

class node {
public:
	int data;
	node *next , *previous;

	node( int d ) {
		this->data = d;
		next = NULL;
		previous = NULL;
	}

};

void printLL(node*head) {
	if (head == NULL)return;

	node*temp = head;

	while (temp->next != NULL) {
		cout << temp->data << " -> ";
		temp =  temp ->next;
	}

	cout << temp->data << " -> ";
	cout << "NULL";
	cout << endl;
	return;
}

void printLLFromTail(node*tail1) {
	node*temp = tail1;

	while (temp->previous != NULL) {
		cout << temp->data << " <- ";
		temp = temp->previous;
	}
	cout << temp->data << endl;
	return;
}

void insertAtHead(node*&head, int val) {

	if (head == NULL) {
		head = new node(val);
		return;
	}

	node*temp = head;
	head = new node(val);
	head->next = temp;
	temp->previous = head;

	return;
}

void insertAtTail(node*&head, int val) {
	if (head == NULL) {
		head = new node(val);
		return;
	}

	node*temp = head;
	while (temp->next != NULL)
		temp =  temp ->next;

	temp->next = new node(val);
	temp ->next-> previous = temp;

	return;
}

node* getTail(node*head) {

	node*temp = head;

	while ( temp->next != NULL )
		temp = temp->next;

	return temp;
}

void deleteNode(node*&head, int val) {
	if (head == NULL )return;

	if (head->data == val) {
		node*temp2 = head;
		temp2->next->previous = NULL;

		head = temp2->next;
		delete temp2;
		return;
	}

	node*temp = head;
	bool ispresent = 0;

	while ( temp != NULL ) {

		if (temp->data == val) {
			ispresent = 1;
			break;
		}
		temp = temp->next;
	}
	if (!ispresent)return;

	node*toDelete = temp ;

	if (temp->next == NULL) {
		toDelete->previous->next = NULL;
		delete toDelete;
		return;
	}

	toDelete = temp ;

	temp->previous->next = toDelete->next;
	toDelete->next->previous = temp->previous;

	delete toDelete;
	return;
}


int main(int argc, char const * argv[]) {

	node*head1 = NULL;
	node*head2 = NULL;

	insertAtTail(head1, 11);
	insertAtTail(head1, 44);
	insertAtTail(head1, 55);
	insertAtTail(head1, 66);

	insertAtHead(head1, 77);
	insertAtHead(head1, 88);

	insertAtTail(head1, 22);
	insertAtTail(head1, 33);

	insertAtTail(head2, 11);
	insertAtTail(head2, 22);
	insertAtTail(head2, 33);
	insertAtTail(head2, 44);
	insertAtTail(head2, 55);
	insertAtTail(head2, 66);
	insertAtHead(head2, 77);
	insertAtHead(head2, 88);

	printLL(head1);
	// search(head1, 22);
	deleteNode(head1, 88);
	printLL(head1);

	node* tail1 = getTail(head1);
	printLLFromTail(tail1);

	// head1 = reverseIterative(head1);
	// printLL(head1);

	// deleteNode(head1, 22);
	// head1 = reverseRecursive(head1);
	// printLL(head1);

	// head1 = reverseRecursiveK(head1, 4);
	// printLL(head1);

	// createCycle(head1, 4);
	// detectCycle(head1);
	// printLL( head1);

	// removeCycle(head1);
	// detectCycle(head1);

	return 0;
}