//! Smallest Positive missing number

// You are given an array arr[] of N integers including 0.
// The task is to find the smallest positive number missing from the array.

// Example 1:

// Input:
// N = 5
// arr[] = {1,2,3,4,5}
// Output: 6
// Explanation: Smallest positive missing
// number is 6.
// Example 2:

// Input:
// N = 5
// arr[] = {0,-10,1,3,-20}
// Output: 2
// Explanation: Smallest positive missing
// number is 2.
// Your Task:
// The task is to complete the function missingNumber()
// which returns the smallest positive missing number in the array.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 106
// -106 <= arr[i] <= 106

#include<bits/stdc++.h>
using namespace std;

int missingNumber(int a[], int n)
{
	//! Brute Forc, TC - O(n^2)
	// sort(a, a+n);
	// int k = 1;
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		if (a[j] == k) {
	// 			k++;
	// 		}
	// 	}
	// }
	// return k;

	//! Better approach, TC - O(n), SC - O(1)
	// unordered_map<int, int> m;
	// int k = 1;
	// for (int i = 0; i < n; ++i)
	// {
	// 	if (a[i] <= 0) continue;
	// 	// cout << a[i] << endl;
	// 	m[a[i]]++;
	// }

	// while (true) {
	// 	if (m[k] > 0) {
	// 		k++;
	// 	}
	// 	else {
	// 		break;
	// 	}
	// }
	// return k;

	//! Better Approach than previous TC- O(n), SC- O(1)
	for (int i = 0; i < n; ++i)
	{
		while (a[i] >= 1 && a[i] <= n && a[i] != a[a[i] - 1]) {
			int temp = a[a[i] - 1];
			a[a[i] - 1] = a[i];
			a[i] = temp;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (a[i] != i + 1)
			return i + 1;
	}
	return n + 1;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of array: ";
	cin >> n;
	int a[n];
	cout << endl << "Enter " << n << " elements of the array: ";
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int ans = missingNumber(a, n);
	cout << "\nMissing element from the array is: " << ans;
	return 0;
}