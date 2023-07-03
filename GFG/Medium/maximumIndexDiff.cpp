// https://practice.geeksforgeeks.org/problems/maximum-index3307/1

// Maximum Index

// Given an array arr[] of n positive integers.
// The task is to find the maximum of j - i subjected to the constraint of arr[i] <= arr[j].

// Example 1:

// Input:
// n = 9
// arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
// Output:
// 6
// Explanation:
// In the given array arr[1] < arr[7]  satisfying
// the required condition (arr[i] <= arr[j])  thus
// giving the maximum difference of j - i which is
// 6(7-1).
// Example 2:

// Input:
// N = 2
// arr[] = {18, 17}
// Output:
// 0
// Explanation:
// We can either take i and j as 0 and 0
// or we cantake 1 and 1 both give the same result 0.
// Your Task:
// Complete the function maxIndexDiff() which takes array arr and size n,
// as input parameters and returns an integer representing the answer.
// You don't to print answer or take inputs.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 106
// 0 ≤ Arr[i] ≤ 109

#include<bits/stdc++.h>
using namespace std;

int maxIndexDiff(int arr[], int n) {
	int prefix[n], suffix[n];
	prefix[0] = arr[0];
	suffix[n - 1] = arr[n - 1];

	for (int i = 1; i < n; i++) {
		prefix[i] = min(prefix[i - 1], arr[i]);
		suffix[n - i - 1] = max(suffix[n - i], arr[n - i - 1]);
	}

	int i, j, ans;
	i = j = ans = 0;

	while (j < n) {
		if (prefix[i] <= suffix[j]) {
			ans = max(ans, j - i);
			j++;
		} else {
			i++;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	int a[n];
	cout << "\nEnter the " << n << " elements of the array: ";
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cout << "\nMaximum Index Difference: " << maxIndexDiff(a, n);
	return 0;
}
