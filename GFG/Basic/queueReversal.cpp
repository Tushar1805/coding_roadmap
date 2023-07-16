//! Queue Reversal

// Given a Queue Q containing N elements. The task is to reverse the Queue.
// Your task is to complete the function rev(), that reverses the N elements of the queue.

// Example 1:

// Input:
// 6
// 4 3 1 10 2 6
// Output:
// 6 2 10 1 3 4
// Explanation:
// After reversing the given elements of the queue ,
// the resultant queue will be 6 2 10 1 3 4.
// Example 2:

// Input:
// 4
// 4 3 2 1
// Output:
// 1 2 3 4
// Explanation:
// After reversing the given elements of the queue , the resultant queue will be 1 2 3 4.
// Your Task: You need to complete the function rev that takes a queue as parameter
// and returns the reversed queue. The printing is done automatically by the driver code.

// Expected Time Complexity : O(n)
// Expected Auxilliary Space : O(n)

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ elements of Queue ≤ 105

#include<bits/stdc++.h>
using namespace std;

queue<int> rev(queue<int> q)
{
	// add code here.
	stack<int> s;
	while (!q.empty()) {
		s.push(q.front());
		q.pop();
	}
	while (!s.empty()) {
		int data = s.top();
		q.push(data);
		s.pop();
	}

	return q;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the queue: ";
	cin >> n;
	queue<int> q;
	cout << "\nEnter the " << n << " elements of the queue: ";
	for (int i = 0; i < n; ++i)
	{
		int data;
		cin >> data;
		q.push(data);
	}
	queue<int> reversed = rev(q);
	cout << "\nReversed elements of the queue: ";
	while (!reversed.empty()) {
		cout << reversed.front() << " ";
		reversed.pop();
	}
	return 0;
}