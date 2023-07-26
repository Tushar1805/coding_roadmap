#include<iostream>
using namespace std;

// Node of linked list

class Node {
public:
	int data;
	Node* next;

	// Constructor
	Node(int data) {
		this -> data = data;
		this -> next = NULL;
	}

	// Destructor
	~Node() {
		int value  = this -> data;
		// if (this -> next != NULL) {
		// 	delete next;
		// 	this -> next = NULL;
		// }
		cout << " Memory is free for node with data " << value << endl;
	}
};

// Insert at start
// Need to pass the reference of the head else it will create new node each time
// and will not update the existing linked list
void insertAtHead(Node* &head, Node* &tail, int d) {
	if (head == NULL) {
		Node* temp = new Node(d);
		head = temp;
		tail = temp;
	} else {
		// Create new node
		Node* temp = new Node(d);
		temp -> next = head; // Address of new node points to head
		head = temp; // Now head points to new node
	}
}

// Insert at last
void insertAtTail(Node* &head, Node* &tail, int d) {
	if (tail == NULL) {
		Node* temp = new Node(d);
		head = temp;
		tail = temp;
	} else {
		Node* temp = new Node(d);
		tail -> next = temp;
		tail = temp;
	}
}

// Insert at Middle
void insertAtMiddle(Node* &head, Node* &tail, int pos, int d) {
	Node* temp = head;
	int cnt = 1;

	// Insert at start
	if (pos == 1) {
		insertAtHead(head, tail, d);
		return;
	}
	while (cnt < pos - 1) {
		temp = temp-> next;
		cnt++;
	}
	// Insert at tail
	if (temp -> next == NULL) {
		insertAtTail(head, tail, d);
		return;
	}

	// creating node for d
	Node* insert = new Node(d);
	insert -> next = temp -> next;
	temp -> next = insert;
}

// Delete at position
void deleteNode(int pos, Node* &head) {
	if (pos == 1) {
		Node* temp = head;
		head  = head -> next;
		// Memory free start node
		temp -> next = NULL;
		delete temp;
	} else {
		int cnt = 1;
		Node *curr = head;
		Node *prev = NULL;
		while (cnt < pos) {
			prev = curr;
			curr = curr -> next;
			cnt++;
		}
		if (curr -> next == NULL) {
			prev -> next = NULL;
			curr -> next = NULL;
			delete curr;
			return;
		}
		prev -> next = curr -> next;
		curr -> next = NULL;
		delete curr;
	}
}

void print(Node* &head) {
	Node *temp = head;
	while (temp != NULL) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

Node* reverseList( Node *head)
{
	// code here
	// return head of reversed list
	Node* curr = head;
	Node* nxt = NULL;
	Node* prev = NULL;

	while (curr != NULL) {
		nxt = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = nxt;
	}
	head = prev;
	return head;
}

int main(int argc, char const *argv[])
{
	Node* node1 = new Node(10);
	// cout << node1 -> data << endl;
	// cout << node1 -> next << endl;

	// Head points to node1
	Node* head = node1;
	Node* tail = node1;
	// Node* head = NULL;
	// Node* tail = NULL;
	print(head);

	insertAtTail(head, tail, 12);
	print(head);

	insertAtTail(head, tail, 15);
	print(head);

	insertAtMiddle(head, tail, 3, 40);
	print(head);
	insertAtMiddle(head, tail, 4, 50);
	print(head);

	deleteNode(5, head);
	print(head);

	cout << "Reverse the Linked list: ";
	head = reverseList(head);
	print(head);
	return 0;
}