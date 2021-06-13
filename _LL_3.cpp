#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* next;
	node( int d ) {
		this->data = d;
		next = NULL;
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

void insertAtHead(node*&head, int val) {

	if (head == NULL) {
		head = new node(val);
		return;
	}

	node*temp = head;
	head = new node(val);
	head->next = temp;

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
	return;
}

void search(node*head , int val) {
	node*temp = head;
	int i = 1;
	while (temp != NULL) {
		if (temp->data == val) {
			cout << "found data position " << i << endl;
			return;
		}
		temp = temp->next;
		i++;
	}

	cout << "did not find data " << endl;
	return;

}

void deleteNode(node*&head, int val) {
	if (head == NULL )return;

	if (head->data == val) {
		node*temp2 = head;
		head = temp2->next;
		delete temp2;
		return;
	}


	node*temp = head;

	bool ispresent = 0;
	while ( temp->next != NULL ) {

		if (temp->next->data == val) {
			ispresent = 1;
			break;
		}
		temp = temp->next;
	}
	if (!ispresent)return;

	node*toDelete = temp ->next;
	temp->next = toDelete->next;

	delete toDelete;

	return;
}

node* reverseIterative(node*head) {

	node*prevPointer = NULL;
	node*currPointer = head;
	node*nextPointer;

	while (currPointer != NULL) {

		nextPointer = currPointer->next;

		currPointer->next = prevPointer;

		prevPointer = currPointer;
		currPointer = nextPointer;

	}
	return prevPointer;
}

node* reverseRecursive(node* &head) {

	if (head == NULL || head->next == NULL)
		return head;

	node*newHead = reverseRecursive(head->next);
	head->next->next = head;
	head->next = NULL;

	return newHead;
}

node* reverseRecursiveK(node*head, int k) {

	if (head == NULL)return head;

	node* currPointer = head;
	node* prevPointer = NULL;
	node* nextPointer;
	int i = 0;

	while (currPointer != NULL && i < k) {

		nextPointer = currPointer->next;
		currPointer->next = prevPointer;
		i++;
		prevPointer = currPointer;
		currPointer = nextPointer;
	}

	if (nextPointer != NULL)
		head->next = reverseRecursiveK(nextPointer, k);

	return prevPointer;
}

void createCycle(node*&head, int d) {
	node*temp = head;
	node*startNode ;

	while (temp->next != NULL) {
		if (d == 1)startNode = temp;
		temp = temp->next;
		d--;
	}
	temp->next = startNode;
	return;
}

void detectCycle(node*head) {

	node *fast , *slow;
	slow = head;
	fast = head;
	int cycle = 0;
	while (fast != NULL && fast->next != NULL) {
		if (fast == slow) {
			cycle = 1;
			break;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	if (cycle)cout << "yes cycle is present " << endl;
	else cout << "no cycle is not present " << endl;

	return;
}

void removeCycle(node*&head) {

	node *slow  , *fast ;
	fast = head ;
	slow = head;

	int ispresent = 0;

	while ( fast != slow ) {

		if (fast == slow) {
			ispresent = 1;
			break;
		}
		fast = fast -> next -> next;
		slow = slow -> next;
	}
	slow = head;

	while (slow->next != fast->next) {
		slow = slow->next;
		fast = fast->next;
	}
	fast->next = NULL;

	return;
}


int main(int argc, char const *argv[]) {

	node*head1 = NULL;
	node*head2 = NULL;

	insertAtTail(head1, 11);
	insertAtTail(head1, 22);
	insertAtTail(head1, 33);
	insertAtTail(head1, 44);
	insertAtTail(head1, 55);
	insertAtTail(head1, 66);
	insertAtHead(head1, 77);
	insertAtHead(head1, 88);


	insertAtTail(head2, 11);
	insertAtTail(head2, 22);
	insertAtTail(head2, 33);
	insertAtTail(head2, 44);
	insertAtTail(head2, 55);
	insertAtTail(head2, 66);
	insertAtHead(head2, 77);
	insertAtHead(head2, 88);

	printLL(head1);
	search(head1, 22);
	deleteNode(head1, 11);
	printLL(head1);

	head1 = reverseIterative(head1);
	printLL(head1);

	deleteNode(head1, 22);
	head1 = reverseRecursive(head1);
	printLL(head1);

	head1 = reverseRecursiveK(head1, 4);
	printLL(head1);

	createCycle(head1, 4);
	// detectCycle(head1);
	printLL(head1);

	// removeCycle(head1);
	// detectCycle(head1);

	return 0;
}