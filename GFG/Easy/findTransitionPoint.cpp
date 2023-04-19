//! Find Transition Point
// Given a sorted array containing only 0s and 1s, find the transition point.

// Example 1:

// Input:
// N = 5
// arr[] = {0,0,0,1,1}
// Output: 3
// Explanation: index 3 is the transition
// point where 1 begins.

// Example 2:

// Input:
// N = 4
// arr[] = {0,0,0,0}
// Output: -1
// Explanation: Since, there is no "1",
// the answer is -1.

// Your Task:
// You don't need to read input or print anything.
// The task is to complete the function transitionPoint()
// that takes array and N as input parameters and
// returns the 0 based index of the position where "0" ends and "1" begins.
// If array does not have any 1s, return -1. If array does not have any 0s, return 0.

// Expected Time Complexity: O(LogN)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 500000
// 0 ≤ arr[i] ≤ 1

#include<bits/stdc++.h>
using namespace std;

int transitionPoint(int a[], int n) {
	int res = -1 ;
	int l = 0, r = n - 1;
	int mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] == 1) {
			res = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	int a[n];
	cout << "\nEnter the " << n << " elements only 1's and 0's:  ";
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int res = transitionPoint(a, n);
	cout << "\nFirst Transition: " << res;
	return 0;
}