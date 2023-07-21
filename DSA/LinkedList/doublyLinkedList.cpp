//! Doubly linked List

#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* prev;
	Node* next;

	Node(int data) {
		this -> data = data;
		this -> prev = NULL;
		this -> next = NULL;
	}

	~Node() {
		int val = this -> data;
		cout << "Memory free for node with data " << data << endl;
	}
};

//! Linked List traversal
void print(Node* head) {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

//! Get the length of the linked list
int getLength(Node* head) {
	int len = 0;
	Node* temp = head;
	while (temp != NULL) {
		len++;
		temp = temp -> next;
	}
	return len;
}

//! Insert node at head
// Need to pass the reference of the head else it will create new node each time
// and will not update the existing linked list
void insertAtHead(Node* &head, Node* &tail, int d) {
	if (head == NULL) {
		Node* temp = new Node(d);
		head = temp;
		tail = temp;
	} else {
		Node* temp = new Node(d);
		temp-> next = head;
		head -> prev = temp;
		head = temp;
	}
}

//! Insert node at tail
void insertAtTail(Node* &head, Node* &tail, int d) {
	if (tail == NULL) {
		Node* temp = new Node(d);
		head = temp;
		tail = temp;
	} else {
		Node* temp = new Node(d);
		tail -> next = temp;
		temp -> prev = tail;
		tail = temp;
	}
}

//! Insert at any position
void insertAtPostion(Node* &head, Node* &tail, int pos, int d) {
	if (pos == 1) {
		insertAtHead(head, tail, d);
		return;
	}
	Node* temp = head;
	int cnt = 1;
	while (cnt < pos - 1) {
		temp = temp -> next;
		cnt++;
	}
	if (temp -> next == NULL) {
		insertAtTail(head, tail, d);
		return;
	}
	Node* insert = new Node(d);
	insert -> next = temp -> next;
	insert -> prev = temp -> next -> prev;
	temp-> next -> prev = insert;
	temp -> next = insert;
}

//! Delete node in DLL
void deleteNode(Node* &head, Node* &tail, int pos) {
	Node* temp = head;
	if (pos == 1) {
		temp -> next -> prev = NULL;
		head = temp -> next;
		temp -> next = NULL;
		delete temp;
		return;
	} else {
		int cnt = 1;
		while (cnt < pos) {
			temp = temp->next;
			cnt++;
		}
		if (temp -> next == NULL) {
			temp -> prev -> next = NULL;
			tail = temp -> prev;
			temp -> prev = NULL;
			delete temp;
			return;
		}
		temp -> prev -> next = temp -> next;
		temp -> next -> prev = temp -> prev;
		temp -> next = NULL;
		temp -> prev = NULL;
		delete temp;
	}
}

int main(int argc, char const *argv[])
{
	// Node* node1 = new Node(5);
	// Node* head = node1;
	// Node* tail = node1;
	Node* head = NULL;
	Node* tail = NULL;
	print(head);
	insertAtHead(head, tail, 10);
	print(head);
	insertAtHead(head, tail, 13);
	print(head);

	insertAtHead(head, tail, 18);
	print(head);

	insertAtTail(head, tail, 25);
	print(head);

	insertAtPostion(head, tail, 2, 15);
	print(head);

	// deleteNode(head, tail, 1);
	// print(head);

	// deleteNode(head, tail, 2);
	// print(head);

	deleteNode(head, tail, 5);
	print(head);
	cout << "Length: " << getLength(head);
	return 0;
}