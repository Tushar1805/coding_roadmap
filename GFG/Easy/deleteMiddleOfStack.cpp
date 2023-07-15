//! Delete middle element of a stack

// Given a stack, delete the middle element of the stack without using any additional data structure.
// Middle element:- ceil((size_of_stack+1)/2) (1-based indexing) from bottom of the stack.

// Note: The output shown by the compiler is the stack from top to bottom.

// Example 1:

// Input:
// Stack = {10, 20, 30, 40, 50}
// Output:
// ModifiedStack = {10, 20, 40, 50}
// Explanation:
// If you print the stack the bottom-most element will be 10 and the top-most element will be 50.
// Middle element will be element at index 3 from bottom, which is 30. Deleting 30,
// stack will look like {10 20 40 50}.
// Example 2:

// Input:
// Stack = {10 20 30 40}
// Output:
// ModifiedStack = {10 30 40}
// Explanation:
// If you print the stack the bottom-most element will be 10 and the top-most element will be 40.
// Middle element will be element at index 2 from bottom, which is 20.
// Deleting 20, stack will look like {10 30 40}.
// Your Task:
// You don't need to read input or print anything.
// Complete the function deleteMid() which takes the stack and
// its size as input parameters and modifies the stack in-place.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 2 ≤ size of stack ≤ 105

#include<bits/stdc++.h>
using namespace std;

//Function to delete middle element of a stack.
void helper(stack<int>&s, int n, int i) {
	if (i == n / 2) {
		s.pop();
		return;
	}
	int data = s.top();
	s.pop();
	i++;
	helper(s, n, i);
	s.push(data);
}
void deleteMid(stack<int>&s, int sizeOfStack)
{
	//! Brute force uses extra space
	// stack<int> st;
	// int n = sizeOfStack/2;
	// int i=0;
	// while(!s.empty()){
	//     int data = s.top();
	//     st.push(data);
	//     s.pop();
	//     i++;

	//     if(i==n)
	//     s.pop();
	// }
	// while(!st.empty()){
	//     int data = st.top();
	//     s.push(data);
	//     st.pop();
	// }

	//! Optimized approach use recursion
	helper(s, sizeOfStack, 0);

}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the stack: ";
	cin >> n;
	stack<int> s;
	cout << "\nEnter " << n << " elements of stack: ";
	for (int i = 0; i < n; ++i)
	{
		int data;
		cin >> data;
		s.push(data);
	}

	// s.push(1);
	// s.push(2);
	// s.push(3);
	// s.push(4);
	// s.push(5);
	deleteMid(s, s.size());
	cout << "\nStack after delete operation: ";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}