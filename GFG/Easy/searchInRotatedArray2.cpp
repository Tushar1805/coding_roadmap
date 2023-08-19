//! Search in Rotated Array 2

// Given a sorted and rotated array A of N elements which is rotated at some point,
// and may contain duplicates and given an element key.
// Check whether the key exist in the array A or not.

// Example 1:

// Input:
// N = 7
// A[] = {2,5,6,0,0,1,2}
// key = 0
// Output:
// 1
// Explanation:
// 0 is found at index 3.
// Example 2:

// Input:
// N = 7
// A[] = {2,5,6,0,0,1,2}
// key = 3
// Output:
// 0
// Explanation:
// There is no element that has value 3.
// Your Task:
// Complete the function search() which takes a integer N and
// an array A and the Key as input parameters, and returns the answer.

// Expected Time Complexity: O(log N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ N ≤ 5000
// 0 ≤ A[i] ≤ 108
// 1 ≤ key ≤ 108

#include<bits/stdc++.h>
using namespace std;

bool Search(int N, vector<int>& arr, int k) {
	int mid;
	int l = 0, r = N - 1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (arr[mid] == k)
			return true;
		if (arr[l] <= arr[mid]) {
			if (arr[l] <= k && arr[mid] >= k)
				r = r - 1;
			else
				l = l + 1;
		} else {
			if (arr[r] >= k && arr[mid] <= k) {
				l = l + 1;
			} else {
				r = r - 1;
			}
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int n, key;
	cout << "Enter the size of the array: ";
	cin >> n;
	vector<int> arr;
	cout << "\nEnter the " << n << " sorted rotaed elements of the array: ";
	for (int i = 0; i < n; ++i)
	{
		int data;
		cin >> data;
		arr.push_back(data);
	}
	cout << "\nEnter the key to search in array: ";
	cin >> key;
	int index = Search(n, arr, key);
	cout << endl << key << " found at position " << index + 1;
	return 0;
}