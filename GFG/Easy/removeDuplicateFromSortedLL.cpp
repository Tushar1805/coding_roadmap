//! Remove duplicate element from sorted Linked List

// Given a singly linked list consisting of N nodes.
// The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
// Note: Try not to use extra space. Expected time complexity is O(N).
// The nodes are arranged in a sorted way.

// Example 1:

// Input:
// LinkedList: 2->2->4->5
// Output: 2 4 5
// Explanation: In the given linked list
// 2 ->2 -> 4-> 5, only 2 occurs more
// than 1 time.
// Example 2:

// Input:
// LinkedList: 2->2->2->2->2
// Output: 2
// Explanation: In the given linked list
// 2 ->2 ->2 ->2 ->2, 2 is the only element
// and is repeated 5 times.
// Your Task:
// The task is to complete the function removeDuplicates() which should remove the duplicates
// from linked list and return the head of the linkedlist.

// Expected Time Complexity : O(N)
// Expected Auxilliary Space : O(1)

// Constraints:
// 1 <= Number of nodes <= 104

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
// your code goes here
	if (head == NULL)
		return NULL;

	Node* curr = head;
	while (curr != NULL) {
		if ((curr -> next != NULL) && curr -> data == curr -> next -> data) {
			curr -> next = curr ->next->next;
		} else {
			curr = curr -> next;
		}
	}
	return head;
}

void print(Node *root)
{
	Node *temp = root;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main() {
	int K;
	cout << "Enter the size of linked list: ";
	cin >> K;
	Node *head = NULL;
	Node *temp = head;
	cout << "Enter value of " << K << " nodes: ";
	for (int i = 0; i < K; i++) {
		int data;
		cin >> data;
		if (head == NULL)
			head = temp = new Node(data);
		else
		{
			temp->next = new Node(data);
			temp = temp->next;
		}
	}

	Node *result  = removeDuplicates(head);
	cout << "\nResult after deleting duplicates: ";
	print(result);
	cout << endl;

	return 0;
}