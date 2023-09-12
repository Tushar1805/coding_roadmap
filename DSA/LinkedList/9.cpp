//! Find the first node of loop in linked list

// Given a singly linked list of N nodes.
// Find the first node of the loop if the linked list has a loop.
// If a loop is present return the node data of the first node of the loop else return -1.

// Example 1:

// Input:

// Output: 3
// Explanation:
// We can see that there exists a loop
// in the given linked list and the first
// node of the loop is 3.
// Example 2:
// Input:
// Output: -1
// Explanation: No loop exists in the above
// linked list.So the output is -1.
// Your Task:
// The task is to complete the function findFirstNode()
// which contains reference to the head as only argument.
// This function should return the value of the first node of
// the loop if the linked list contains a loop, else return -1.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// 1 <= Data on Node <= 106
// 0 <= pos <= N


#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int val)
	{
		data = val;
		next = NULL;
	}
};

void loopHere(Node* head, Node* tail, int position)
{
	if (position == 0) return;

	Node* walk = head;
	for (int i = 1; i < position; i++)
		walk = walk->next;
	tail->next = walk;
}

int findFirstNode(Node* head)
{
	Node* slow = head;
	Node* fast = head;

	while (fast && fast -> next) {
		slow = slow -> next;
		fast = fast -> next -> next;
		if (slow == fast) break;
	}
	if (slow != fast) return -1;
	slow = head;
	while (slow != fast) {
		slow = slow -> next;
		fast = fast -> next;
	}
	return slow -> data;
}

int main()
{
	int t;
	cout << "Enter number of test cases: ";
	cin >> t;
	while (t--)
	{
		int n, num;
		cout << "Enter the length of linked list: ";
		cin >> n;

		Node *head, *tail;
		cout << "Enter first element of linked list: ";
		cin >> num;
		head = tail = new Node(num);
		cout << "Enter remaining element of linked list: ";
		for (int i = 0 ; i < n - 1 ; i++)
		{
			cin >> num;
			tail->next = new Node(num);
			tail = tail->next;
		}

		int pos;
		cout << "Enter position where loop need to be attached: ";
		cin >> pos;
		loopHere(head, tail, pos);

		int ans = findFirstNode(head);
		cout << "First Node of the loop: " << ans << "\n";
	}
	return 0;
}