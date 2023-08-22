//! Add Two Numbers

// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]
// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

// Constraints:

// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* ansHead = new ListNode(0);
	ListNode* ansTail = ansHead;
	int ansDigit;
	int digit1;
	int digit2;
	int carry = 0;

	while (l1 != NULL || l2 != NULL || carry != 0) {
		digit1 = (l1 != NULL) ? l1->val : 0;
		digit2 = (l2 != NULL) ? l2->val : 0;

		int sum = carry + digit1 + digit2;
		ansDigit = sum % 10;
		carry = sum / 10;

		ListNode* newNode = new ListNode(ansDigit);
		ansTail -> next = newNode;
		ansTail = ansTail -> next;

		l1 = (l1 != NULL) ? l1 -> next : NULL;
		l2 = (l2 != NULL) ? l2 -> next : NULL;
	}
	return ansHead -> next;
}

void insertAtTail(ListNode* &head, ListNode* &tail, int d) {
	if (tail == NULL) {
		ListNode* temp = new ListNode(d);
		head = temp;
		tail = temp;
	} else {
		ListNode* temp = new ListNode(d);
		tail -> next = temp;
		tail = temp;
	}
}

void print(ListNode* &head) {
	ListNode *temp = head;
	while (temp != NULL) {
		cout << temp -> val << " ";
		temp = temp -> next;
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	ListNode* l1 = new ListNode(2);
	ListNode* l1Tail = l1;
	insertAtTail(l1, l1Tail, 4);
	insertAtTail(l1, l1Tail, 3);
	ListNode* l2 = new ListNode(5);
	ListNode* l2Tail = l2;
	insertAtTail(l2, l2Tail, 6);
	insertAtTail(l2, l2Tail, 4);

	ListNode* ans = addTwoNumbers(l1, l2);
	print(ans);

	return 0;
}

