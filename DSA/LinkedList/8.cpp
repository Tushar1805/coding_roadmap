//! Delete nodes having greater value on right

// Given a singly linked list, remove all the nodes in the list which have any node
// on their right whose value is greater. (Not just immidiate Right ,
// but entire List on the Right)

// Example 1:

// Input:
// LinkedList = 12->15->10->11->5->6->2->3
// Output: 15 11 6 3
// Explanation: Since, 12, 10, 5 and 2 are
// the elements which have greater elements
// on the following nodes. So, after deleting
// them, the linked list would like be 15,
// 11, 6, 3.
// Example 2:

// Input:
// LinkedList = 10->20->30->40->50->60
// Output: 60
// Explanation: All the nodes except the last
// node has a greater value node on its right,
// so all the nodes except the last node must
// be removed.
// Your Task:
// The task is to complete the function compute() which should modify
// the list as required and return the head of the modified linked list.
// The printing is done by the driver code,

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ size of linked list ≤ 105
// 1 ≤ element of linked list ≤ 105
// Note: Try to solve the problem without using any extra space.


#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;

	Node(int d) {
		data = d;
		next = NULL;
	}
};

void print(Node* head) {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp -> data << " -> ";
		temp = temp -> next;
	}
}

void insertNode(int data, Node* &head) {
	if (head == NULL) {
		Node* newNode = new Node(data);
		head = newNode;
	} else {
		Node* temp = head;
		while (temp -> next != NULL)
			temp = temp -> next;
		Node* newNode = new Node(data);
		temp -> next = newNode;
	}
}

Node* compute(Node* head) {
	Node* curr = head;
	Node* prev = head;

	while (curr && curr -> next) {
		Node* runner = curr -> next;
		bool removeCurrent = false;
		while (runner) {
			if (runner ->data > curr ->data) {
				removeCurrent = true;
				break;
			}
			runner = runner -> next;
		}
		if (removeCurrent) {
			Node* n2 = curr;
			if (curr == head) {
				head = curr -> next;
			}
			curr = curr -> next;
			prev -> next = curr;
			n2 -> next = NULL;
		} else {
			prev = curr;
			curr = curr -> next;
		}
	}
	return head;
}

int main(int argc, char const *argv[])
{
	Node* head = NULL;
	char ch;
	do {
		int val;
		cout << "Enter a value to insert in linked list: ";
		cin >> val;
		insertNode(val, head);
		cout << "Press Y to insert into linked list and any other key to exit: ";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');

	cout << "\nBefore Deletion: ";
	print(head);
	cout << "\nAfter Deletion: ";
	head = compute(head);
	print(head);
	return 0;
}