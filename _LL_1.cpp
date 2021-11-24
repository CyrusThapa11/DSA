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

	// do not init nextPtr
	node*prevPointer = NULL;
	node*currPointer = head;
	node*nextPointer;

	while (currPointer != NULL) {
		// thing to be noted
		nextPointer = currPointer->next;
		// reverse
		currPointer->next = prevPointer;
		// change few pointers
		prevPointer = currPointer;
		currPointer = nextPointer;
	}
	return prevPointer;
}

node* reverseRecursive(node* &head) {

	//pornhub.com

	if (head == NULL || head->next == NULL)
		return head;

	// have faith and assume we got the rev.LL
	node*newHead = reverseRecursive(head->next);
	// reverse here
	head->next->next = head;
	// thing to be noted
	head->next = NULL;

	return newHead;
}

node* reverseRecursiveK(node*head, int k) {

	if (head == NULL)return head;

	// do not init nextPtr
	node* currPointer = head;
	node* prevPointer = NULL;
	node* nextPointer;
	int i = 0;

	while (currPointer != NULL && i < k) {
		// note
		nextPointer = currPointer->next;
		// reverse
		currPointer->next = prevPointer;
		i++;
		// few changes
		prevPointer = currPointer;
		currPointer = nextPointer;
	}
	// edge case if th pointer i is less than k / null comes first
	if (nextPointer != NULL)
		head->next = reverseRecursiveK(nextPointer, k);
	// return prevPtr
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
	// init both to head
	slow = head;
	fast = head;
	int cycle = 0;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		if (fast == slow) {
			cycle = 1;
			break;
		}
	}

	if (cycle)cout << "yes cycle is present " << endl;
	else cout << "no cycle is not present " << endl;

	return;
}

void removeCycle(node*&head) {

	node *slow  , *fast ;
	fast = head ;
	slow = head ;

	int ispresent = 0;

	// DO THIS OR ....
	fast = fast -> next -> next;
	slow = slow -> next;

	while ( fast != slow ) {
		fast = fast -> next -> next;
		slow = slow -> next;
		if (fast == slow) {
			ispresent = 1;
			break;
		}
	}

	// .... DO THIS
	// do {
	// 	fast = fast -> next -> next;
	// 	slow = slow -> next;
	// } while (fast != slow);

	// we can use fast here but then
	// we have to do slow->next = null in line 240
	slow = head;

	while (slow->next != fast->next) {
		slow = slow->next;
		fast = fast->next;
	}
	fast->next = NULL;
	cout << " null at " << fast->data << " ";

	return;
}

int lengthh(node*head) {
	int len = 1;
	node*temp = head;
	while (temp->next != NULL) {
		len++;
		temp = temp->next;
		// cout << temp->data << " ";
	}
	return len;
}

node* reverseRecursiveKNodes(node*&head, int no) {
	if (head == NULL)return head;

	int len = 1;
	node*temp = head;
	while (temp->next != NULL) {
		len++;
		temp = temp->next;
	}

	no = no % len;
	node*tail = temp;
	temp = head;

	while ( len - no) {
		len--;
		temp = temp->next;
	}

	node*newHead = temp->next;
	tail->next = head;
	temp->next = NULL;

	return newHead;
}

node* intersectLL(node*&head1, node*&head2, int d) {

	node * temp1 = head1;
	d--;
	while (d--) temp1 = temp1->next;

	node*temp2 = head2;
	while (temp2->next != NULL)temp2 = temp2->next;

	temp2->next = temp1;

	return head1;
}

int findIntersection(node*head1, node*head2) {
	if (head1 == NULL || head2 == NULL)return 0;

	int len1, len2;
	len1 = lengthh(head1);
	len2 = lengthh(head2);

	int d;
	node*longer, *shorter;

	if (len1 > len2) {
		longer = head1;
		shorter = head2;
		d = len1 - len2 ;
	} else {
		longer = head2;
		shorter = head1;
		d = len2 - len1 ;
	}

	while (d--)longer = longer->next;

	while (longer->next != shorter->next) {
		longer = longer->next;
		shorter = shorter->next;
	}
	return shorter->next->data;
}

node* mergeIterative(node*&head1, node*&head2) {

	node*newHead = new node(-1);
	node* helperPointer = newHead;
	node* temp1 = head1, * temp2 = head2;

	while (temp1 != NULL && temp2 != NULL) {
		if (temp1->data < temp2->data) {
			helperPointer->next = temp1;
			temp1 = temp1->next;
		} else {
			helperPointer->next = temp2;
			temp2 = temp2->next;
		}
		helperPointer = helperPointer ->next;
	}

	// if (temp1 != NULL) {
	while (temp1 != NULL) {
		helperPointer->next = temp1;
		temp1 = temp1->next;
		helperPointer = helperPointer->next;
	}
	// } else {
	while (temp2 != NULL) {
		helperPointer->next = temp2;
		temp2 = temp2->next;
		helperPointer = helperPointer->next;
	}
	// }

	return newHead ->next;
}

void evenAfterOddLL(node* &head) {

	node*evenHead = head , *even = head, *odd = head->next;
	node*temp = head;

	if (head->data & 1) {
		evenHead = head->next;
		odd = head;
		even = head->next;
		cout << " yes ";
	}


	while (odd->next != NULL && even->next != NULL) {
		odd->next = even->next;
		even->next = odd->next->next;
		odd = odd->next;
		even = even->next;
	}

	odd->next = evenHead;
	if (even->next != NULL)
		even->next = NULL;
	return ;
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

	printLL(head1);

	// insertAtTail(head2, 101);
	// insertAtTail(head2, 202);
	// insertAtTail(head2, 303);
	// insertAtTail(head2, 404);
	// insertAtTail(head2, 505);
	// insertAtTail(head2, 606);
	// insertAtHead(head2, 707);
	// insertAtHead(head2, 808);

	// printLL(head1);
	// search(head1, 22);
	// deleteNode(head1, 11);
	// printLL(head1);

	// head1 = reverseIterative(head1);
	// printLL(head1);

	// deleteNode(head1, 22);
	// head1 = reverseRecursive(head1);
	// printLL(head1);

	head1 = reverseRecursiveK(head1, 3);
	printLL(head1);

	// createCycle(head1, 4);
	// detectCycle(head1);
	// // printLL(head1);
	// removeCycle(head1);
	// // printLL(head1);
	// detectCycle(head1);

	// printLL(head1);

	// node*head3 = intersectLL(head1, head2, 5);

	// cout << findIntersection(head1, head2) << endl;


	// node*head4 = NULL;
	// node*head5 = NULL;

	// insertAtTail(head4, 111);
	// insertAtTail(head4, 202);
	// insertAtTail(head4, 333);
	// insertAtTail(head4, 404);
	// insertAtTail(head4, 555);
	// insertAtTail(head4, 606);


	// insertAtTail(head5, 101);
	// insertAtTail(head5, 202);
	// insertAtTail(head5, 303);
	// insertAtTail(head5, 404);
	// insertAtTail(head5, 505);
	// insertAtTail(head5, 606);

	// printLL(head4);
	// printLL(head5);
	// node*head6 = mergeIterative(head4, head5);
	// printLL(head6);
	// cout << endl;

	// node*head7 = NULL;
	// insertAtTail(head7, 101);
	// insertAtTail(head7, 202);
	// insertAtTail(head7, 303);
	// insertAtTail(head7, 404);
	// insertAtTail(head7, 505);
	// insertAtTail(head7, 606);
	// insertAtTail(head7, 607);
	// printLL(head7);
	// evenAfterOddLL(head7);
	// cout << endl;
	// printLL(head7);

	return 0;
}