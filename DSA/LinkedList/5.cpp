//! Double a Number Represented as a Linked List

//! Difficulty:Medium
// You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

// Return the head of the linked list after doubling it.

// Example 1:


// Input: head = [1,8,9]
// Output: [3,7,8]
// Explanation: The figure above corresponds to the given linked list which represents the number 189.
// Hence, the returned linked list represents the number 189 * 2 = 378.
// Example 2:


// Input: head = [9,9,9]
// Output: [1,9,9,8]
// Explanation: The figure above corresponds to the given linked list which represents the number 999.
// Hence, the returned linked list reprersents the number 999 * 2 = 1998.


// Constraints:

// The number of nodes in the list is in the range [1, 104]
// 0 <= Node.val <= 9
// The input is generated such that the list represents a number that does not have leading zeros,
// except the number 0 itself.

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

// Insert at last
void insert(Node* &head, Node* &tail, int d) {
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
void print(Node* &head) {
	Node *temp = head;
	while (temp != NULL) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

Node* doubleIt(Node* head) {
	Node* temp = head;
	Node* tail = NULL;
	int number = temp -> data;
	int place = 10;
	int c = 1;

	while (temp->next != NULL) {
		temp = temp -> next;
		number = (number * place) + temp->data;
	}
	number *= 2;
	int k = number == 0 ? 0 : log10(number) + 1;
	cout << k << endl;
	while (k > 1) {
		c *= 10;
		k--;
	}
	temp = head;
	while (c != 0) {
		int d = number / c;
		insert(head, tail, d);
		number %= c;
		c /= 10;
	}
	return head;
}

int main(int argc, char const *argv[])
{
	Node* head = NULL;
	Node* tail = NULL;
	int n;
	cout << "Enter the number of digits in the number: ";
	cin >> n;
	cout << "Enter the number of " << n << " digits: ";
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		insert(head, tail, data);
	}
	print(head);
	Node* ans = doubleIt(head);
	print(ans);
	return 0;
}