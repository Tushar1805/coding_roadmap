//! Search in a Rotated Array

// Given a sorted and rotated array A of N distinct elements which is rotated at some point,
// and given an element key. The task is to find the index of the given element key in the array A.
// The whole array A is given as the range to search.

// Example 1:

// Input:
// N = 9
// A[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}
// key = 10
// l = 0 , h = 8
// Output:
// 5
// Explanation: 10 is found at index 5.
// Example 2:

// Input:
// N = 4
// A[] = {3, 5, 1, 2}
// key = 6
// l = 0 , h = 3
// Output:
// -1
// Explanation: There is no element that has value 6.
// Your Task:
// Complete the function search() which takes an array arr[] and start,
// end index of the array and the K as input parameters, and returns the answer.

// Can you solve it in expected time complexity?

// Expected Time Complexity: O(log N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ N ≤ 107
// 0 ≤ A[i] ≤ 108
// 1 ≤ key ≤ 108

#include<bits/stdc++.h>
using namespace std;

int findPivot(int a[], int l, int h) {
	int mid;
	int s = l, e = h;
	while (s < e) {
		mid = s + (e - s) / 2;
		if (a[mid] >= a[0]) {
			s = mid + 1;
		} else {
			e = mid;
		}
	}
	return s;
}

int binarySearch(int a[], int l, int h, int key) {
	int mid;
	int s = l, e = h;

	while (s <= e) {
		mid = s + (e - s) / 2;
		if (a[mid] == key) {
			return mid;
		}
		if (a[mid] < key) {
			s = mid + 1;
		} else {
			e = mid - 1;
		}
	}
	return -1;
}

int search(int A[], int l, int h, int key) {
	// l: The starting index
	// h: The ending index, you have to search the key in this range
	int pivot = findPivot(A, l, h);
	cout << "Value of Pivot: " << pivot;
	if (key == A[pivot]) {
		return pivot;
	}
	if (key >= A[pivot] && key < A[h]) {
		return binarySearch(A, pivot, h, key);
	} else {
		return binarySearch(A, l, pivot - 1, key);
	}
}

int main(int argc, char const *argv[])
{
	int n, key;
	cout << "Enter the size of the array: ";
	cin >> n;
	int a[n];
	cout << "\nEnter the " << n << " sorted rotaed elements of the array: ";
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cout << "\nEnter the key to search in array: ";
	cin >> key;
	int index = search(a, 0, n - 1, key);
	cout << endl << key << " found at position " << index + 1;
	return 0;
}