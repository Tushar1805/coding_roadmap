//! Remove loop in Linked List

// Given a linked list of N nodes such that it may contain a loop.

// A loop here means that the last node of the link list is
// connected to the node at position X(1-based index).
// If the link list does not have any loop, X=0.

// Remove the loop from the linked list, if it is present, i.e.
// unlink the last node which is forming the loop.


// Example 1:

// Input:
// N = 3
// value[] = {1,3,4}
// X = 2
// Output: 1
// Explanation: The link list looks like
// 1 -> 3 -> 4
//      ^    |
//      |____|
// A loop is present. If you remove it
// successfully, the answer will be 1.

// Example 2:

// Input:
// N = 4
// value[] = {1,8,3,4}
// X = 0
// Output: 1
// Explanation: The Linked list does not
// contains any loop.

// Example 3:

// Input:
// N = 4
// value[] = {1,2,3,4}
// X = 1
// Output: 1
// Explanation: The link list looks like
// 1 -> 2 -> 3 -> 4
// ^              |
// |______________|
// A loop is present.
// If you remove it successfully,
// the answer will be 1.

// Your Task:
// You don't need to read input or print anything.
// Your task is to complete the function removeLoop()
// which takes the head of the linked list as the input parameter.
// Simply remove the loop in the list (if present) without disconnecting any nodes from the list.
// Note: The generated output will be 1 if your submitted code is correct.

// Expected time complexity: O(N)
// Expected auxiliary space: O(1)

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

bool isLoop(Node* head)
{
	if (!head) return false;

	Node* fast = head->next;
	Node* slow = head;

	while ( fast != slow)
	{
		if ( !fast || !fast->next ) return false;
		fast = fast->next->next;
		slow = slow->next;
	}

	return true;
}

int length(Node* head)
{
	int ret = 0;
	while (head)
	{
		ret++;
		head = head->next;
	}
	return ret;
}

void removeLoop(Node* head)
{
	// code here
	// just remove the loop without losing any nodes
	if (head -> next == head) {
		head->next = NULL;
		return;
	}
	Node* slow = head;
	Node* fast = head;
	while (fast && fast -> next) {
		slow = slow -> next;
		fast = fast -> next -> next;
		if (slow == fast) break;
	}
	if (slow != fast) return;
	slow = head;
	while (slow != fast) {
		slow = slow -> next;
		fast = fast -> next;
	}
	Node* temp = slow;
	while (temp -> next != slow) {
		temp = temp -> next;
	}
	temp -> next = NULL;
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

		removeLoop(head);
		if ( isLoop(head) || length(head) != n )
			cout << "0\n";
		else
			cout << "1\n";
	}
	return 0;
}