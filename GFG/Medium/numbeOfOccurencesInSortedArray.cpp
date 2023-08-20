//! Number of occurrence

// Given a sorted array Arr of size N and a number X,
// you need to find the number of occurrences of X in Arr.

// Example 1:

// Input:
// N = 7, X = 2
// Arr[] = {1, 1, 2, 2, 2, 2, 3}
// Output: 4
// Explanation: 2 occurs 4 times in the
// given array.
// Example 2:

// Input:
// N = 7, X = 4
// Arr[] = {1, 1, 2, 2, 2, 2, 3}
// Output: 0
// Explanation: 4 is not present in the
// given array.
// Your Task:
// You don't need to read input or print anything.
// Your task is to complete the function count() which takes
// the array of integers arr, n, and x as parameters and returns an integer denoting the answer.
// If x is not present in the array (arr) then return 0.

// Expected Time Complexity: O(logN)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ Arr[i] ≤ 106
// 1 ≤ X ≤ 106

#include<bits/stdc++.h>
using namespace std;

int count(int arr[], int n, int x) {
	// code here
	int cnt = 0;
	int l = 0, r = n - 1;
	int mid;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (arr[mid] == x) {
			if (arr[l] == x && arr[r] == x) {
				cnt = (r - l) + 1;
				break;
			}
			if (arr[l] != x)
				l++;
			if (arr[r] != x)
				r--;
		} else if (arr[mid] < x) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return cnt;
}

int main(int argc, char const *argv[])
{
	int n, x;
	cout << "Enter the size of the array: ";
	cin >> n;
	int arr[n];
	cout << "\nEnter the " << n << " sorted elements of the array: ";
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << "\nEnter the value to find the count of in array: ";
	cin >> x;
	int cnt = count(arr, n, x);
	cout << endl << x << " found " << cnt << " times in the array";
	return 0;
}

