#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	// constructor
	Node(int data) {
		this -> data = data;
		this -> next = NULL;
	}
	~Node() {
		int val = this ->data;
		if (this->next != NULL) {
			delete next;
			this -> next = NULL;
		}
		cout << "Memory free for node with data " << val << endl;
	}
};

void insertNode(Node* &tail, int element, int d) {
	// Assuming that the element is present in the list
	if (tail == NULL) {
		Node* temp = new Node(d);
		tail = temp;
		temp -> next = temp;
		return;
	}
	Node* curr = tail;
	while (curr -> data != element) {
		curr = curr -> next;
	}
	Node* temp = new Node(d);
	// Node* nextCurr = curr -> next;
	// curr -> next = temp;
	// temp = nextCurr;

	// Optimized
	temp -> next = curr -> next;
	curr -> next = temp;
}

void deleteNode(Node* &tail, int element) {
	// Empth List
	if (tail == NULL) {
		cout << "List is empty, please check again\n";
		return;
	}
	// Assuming that the value is present in the linked list
	Node* prev = tail;
	Node* curr = prev -> next;
	while (curr -> data != element) {
		prev = curr;
		curr = curr -> next;
	}
	prev -> next = curr -> next;

	// 1 node Linked list
	if (curr == prev) {
		tail = NULL;
		return;
	}
	// >=2 Node Linked list
	else if (tail == curr) {
		tail = prev;
	}
	curr -> next = NULL;
	delete curr;
}

void print(Node* tail) {
	Node* temp = tail;
	if (tail == NULL) {
		cout << "List is Empty" << endl;
		return;
	}
	do {
		cout << temp -> data << " ";
		temp = temp->next;
	} while (tail != temp);
	cout << endl;
}
int main(int argc, char const *argv[])
{
	Node* tail = NULL;
	insertNode(tail, 5, 3);
	print(tail);

	insertNode(tail, 3, 15);
	print(tail);
	insertNode(tail, 3, 5);
	print(tail);
	/*insertNode(tail, 15, 7);
	print(tail);
	insertNode(tail, 5, 6);
	print(tail);
	*/
	deleteNode(tail, 3);
	print(tail);
	return 0;
}