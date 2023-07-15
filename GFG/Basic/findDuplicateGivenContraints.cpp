//! Find duplicates under given constraints

// Given a sorted array A[] having 10 elements which contain 6 different numbers
// in which only 1 number is repeated five times.
// Your task is to find the duplicate number using two comparisons only.

// Example 1:

// Input:
// A[] = {1, 1, 1, 1, 1, 5, 7, 10, 20, 30}
// Output: 1
// Example 2:

// Input:
// A[] = {1, 2, 3, 3, 3, 3, 3, 5, 9, 10}
// Output: 3

// Your Task:
// You don't need to read input or print anything.
// Your task is to complete the function findDuplicate() which takes the array A[],
// as inputs and returns the required duplicate element.

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

// Constraints:

// Size of the array A[] = 10
// 1 ≤ A[] ≤ 105

#include<bits/stdc++.h>
using namespace std;

int findDuplicate(int A[])
{
	if (A[4] == A[3]) {
		return A[4];
	} else {
		return A[5];
	}
}

int main(int argc, char const *argv[])
{
	int A[] = {1, 1, 1, 1, 1, 5, 7, 10, 20, 30};
	int ans = findDuplicate(A);
	cout << "Duplicate element: " << ans;
	return 0;
}