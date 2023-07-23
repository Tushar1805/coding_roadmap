//! Given a linked list of 0s, 1s and 2s, sort it

// Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only.
// The task is to segregate 0s, 1s, and 2s linked list such that
// all zeros segregate to head side, 2s at the end of the linked list,
// and 1s in the mid of 0s and 2s.

// Example 1:

// Input:
// N = 8
// value[] = {1,2,2,1,2,0,2,2}
// Output: 0 1 1 2 2 2 2 2
// Explanation: All the 0s are segregated
// to the left end of the linked list,
// 2s to the right end of the list, and
// 1s in between.
// Example 2:

// Input:
// N = 4
// value[] = {2,2,0,1}
// Output: 0 1 2 2
// Explanation: After arranging all the
// 0s,1s and 2s in the given format,
// the output will be 0 1 2 2.
// Your Task:
// The task is to complete the function segregate()
// which segregates the nodes in the linked list as asked
// in the problem statement and returns the head of the modified linked list.
// The printing is done automatically by the driver code.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 106

#include <bits/stdc++.h>
using namespace std;
/* Link list Node */

struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

struct Node *start = NULL;

void printList(struct Node *Node) {
	while (Node != NULL) {
		printf("%d ", Node->data);
		Node = Node->next;
	}
	printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
	int n, value, i;
	// scanf("%d",&n);
	n = n1;
	struct Node *temp;
	cout << "Enter the " << n << " node of the linked list: ";
	for (i = 0; i < n; i++) {
		scanf("%d", &value);

		if (i == 0) {
			start = new Node(value);
			temp = start;
			continue;
		} else {
			temp->next = new Node(value);
			temp = temp->next;
			temp->next = NULL;
		}
	}
}

//! Approach 1: TC - O(n) SC - O(1)
// Node* segregate(Node *head) {

// 	// Add code here
// 	Node* temp = head;
// 	if (head == NULL)
// 		return NULL;

// 	int zeroCount = 0;
// 	int oneCount = 0;
// 	int twoCount = 0;

// 	while (temp != NULL) {
// 		if (temp -> data == 0) {
// 			zeroCount++;
// 		} else if (temp -> data == 1) {
// 			oneCount++;
// 		} else {
// 			twoCount++;
// 		}
// 		temp = temp ->next;
// 	}
// 	temp = head;
// 	while (temp != NULL) {
// 		if (zeroCount != 0) {
// 			temp -> data = 0;
// 			zeroCount--;
// 		} else if (oneCount != 0) {
// 			temp -> data = 1;
// 			oneCount--;
// 		} else {
// 			temp -> data = 2;
// 			twoCount--;
// 		}
// 		temp = temp -> next;
// 	}
// 	return head;
// }

void insertAtTail(Node* &tail, Node* &curr) {
	tail -> next = curr;
	tail = curr;
}

//! Approach 2: TC - O(n) SC - O(N)
Node* segregate(Node *head) {

	// Add code here
	Node* zeroHead = new Node(-1);
	Node* zeroTail = zeroHead;
	Node* oneHead = new Node(-1);
	Node* oneTail = oneHead;
	Node* twoHead = new Node(-1);
	Node* twoTail = twoHead;

	Node* curr = head;
	//! Created seperated list of 0s, 1s and 2s
	while (curr != NULL) {
		int value = curr -> data;
		if (value == 0) {
			insertAtTail(zeroTail, curr);
		} else if (value == 1) {
			insertAtTail(oneTail, curr);
		} else {
			insertAtTail(twoTail, curr);
		}
		curr = curr -> next;
	}

	// Merge 3 sorted list

	// 1s list is not empty
	if (oneHead -> next != NULL) {
		zeroTail -> next = oneHead -> next;
	} else {
		zeroTail -> next = twoHead-> next;
	}
	oneTail -> next = twoHead -> next;
	twoTail -> next = NULL;

	head = zeroHead -> next;

	// Delete dummy Nodes
	delete oneHead;
	delete zeroHead;
	delete twoHead;
	return head;
}

int main()
{
	int n;
	cout << "Enter the size of the linked list: ";
	scanf("%d", &n);

	insert(n);
	struct Node *newHead = segregate(start);
	cout << "Updated list: ";
	printList(newHead);
	return 0;
}