//! Remove duplicates from an unsorted linked list

// Given an unsorted linked list of N nodes.
// The task is to remove duplicate elements from this unsorted Linked List.
// When a value appears in multiple nodes, the node which appeared first should be kept,
// all others duplicates are to be removed.

// Example 1:

// Input:
// N = 4
// value[] = {5,2,2,4}
// Output: 5 2 4
// Explanation:Given linked list elements are
// 5->2->2->4, in which 2 is repeated only.
// So, we will delete the extra repeated
// elements 2 from the linked list and the
// resultant linked list will contain 5->2->4
// Example 2:

// Input:
// N = 5
// value[] = {2,2,2,2,2}
// Output: 2
// Explanation:Given linked list elements are
// 2->2->2->2->2, in which 2 is repeated. So,
// we will delete the extra repeated elements
// 2 from the linked list and the resultant
// linked list will contain only 2.
// Your Task:
// You have to complete the method removeDuplicates()
// which takes 1 argument: the head of the linked list.
// Your function should return a pointer to a linked list with no duplicate element.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= size of linked lists <= 106
// 0 <= numbers in list <= 104

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

void print(Node *root)
{
	Node *temp = root;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

Node * removeDuplicates( Node *head)
{
	// your code goes here
	unordered_map<int, int> m;
	if (head == NULL)
		return NULL;

	Node* curr = head;
	Node* prev = NULL, *temp = NULL;

	while (curr != NULL) {
		int val = curr -> data;
		if (m[val] < 1) {
			m[val]++;
			prev = curr;
			curr = curr->next;
			temp = curr;
		}
		else {
			temp = curr->next;
			prev->next = temp;
			curr->next = NULL;
			curr = temp;
		}
	}
	return head;
}


int main() {
	int K;
	cout << "Enter the size of the linked list: ";
	cin >> K;
	struct Node *head = NULL;
	struct Node *temp = head;
	cout << "\nEnter " << K << " node of linked list: ";
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
	cout << "Result after deleting duplicates: ";
	print(result);
	cout << endl;
	return 0;
}
