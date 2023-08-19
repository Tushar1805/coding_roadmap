//! Minimum element in a sorted and rotated array

// A sorted(in ascending order) array A[ ] with distinct elements is rotated at some unknown point,
// the task is to find the minimum element in it.

// Example 1

// Input:
// N = 5
// arr[] = {4 ,5 ,1 ,2 ,3}
// Output: 1
// Explanation: 1 is the minimum element inthe array.
// Example 2

// Input:
// N = 7
// arr[] = {10, 20, 30, 40, 50, 5, 7}
// Output: 5
// Explanation: Here 5 is the minimum element.

// Your Task:
// Complete the function findMin() which takes an array arr[] and n,
// size of the array as input parameters, and returns the minimum element of the array.

// Expected Time Complexity: O(log N).
// Expected Auxiliary Space: O(log N).

// Constraints:
// 1 ≤ N ≤ 100000
// 1 ≤ A[i] ≤ 1000000

#include<bits/stdc++.h>
using namespace std;

int findMin(int arr[], int n) {
	//complete the function here
	int l = 0;
	int r = n - 1;
	int mid;
	int ans = INT_MAX;

	while (l <= r) {
		mid = (l + r) / 2;
		if (arr[l] <= arr[r]) {
			ans = min(ans, arr[l]);
			break;
		}

		// Left Side is sorted
		if (arr[l] <= arr[mid]) {
			ans = min(ans, arr[l]);
			l =  mid + 1;
		}
		// Right side
		else {
			ans = min(ans, arr[mid]);
			r = mid - 1;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter " << n << " rotated elements: ";
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int ans = findMin(a, n);
	cout << "Minimum element in a sorted and rotated array: " << ans;
	return 0;
}