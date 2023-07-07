//! Merge Without Extra Space

// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order.
// Merge them in sorted order without using any extra space.
// Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

// Example 1:

// Input:
// n = 4, arr1[] = [1 3 5 7]
// m = 5, arr2[] = [0 2 6 8 9]
// Output:
// arr1[] = [0 1 2 3]
// arr2[] = [5 6 7 8 9]
// Explanation:
// After merging the two
// non-decreasing arrays, we get,
// 0 1 2 3 5 6 7 8 9.
// Example 2:

// Input:
// n = 2, arr1[] = [10 12]
// m = 3, arr2[] = [5 18 20]
// Output:
// arr1[] = [5 10]
// arr2[] = [12 18 20]
// Explanation:
// After merging two sorted arrays
// we get 5 10 12 18 20.
// Your Task:
// You don't need to read input or print anything.
// You only need to complete the function merge() that takes arr1, arr2, n and m
// as input parameters and modifies them in-place so that they look like the sorted merged array when concatenated.

// Expected Time Complexity:  O((n+m) log(n+m))
// Expected Auxilliary Space: O(1)

// Constraints:
// 1 <= n, m <= 105
// 0 <= arr1i, arr2i <= 107

#include<bits/stdc++.h>
using namespace std;

void merge(long long int a1[], long long int a2[], int n, int m) {

	// TC - O((n+m) log(n+m)) SC - O(n+m)
	// long long int merge[n + m];
	// int k = 0;
	// for (int i = 0; i < n; i++) {
	// 	merge[k++] = a1[i];
	// }
	// for (int i = 0; i < m; ++i)
	// {
	// 	merge[k++] = a2[i];
	// }
	// int size = sizeof(merge) / sizeof(merge[0]);
	// sort(merge, merge + size);
	// k = 0;
	// for (int i = 0; i < n; ++i)
	// {
	// 	a1[i] = merge[i];
	// }
	// for (int i = 0; i < m; ++i)
	// {
	// 	a2[i] = merge[n + i];
	// }

	// TC - O(nlogn +mlogm) SC - O(1)
	int i = n - 1, j = 0;
	while (i >= 0 && j < m) {
		if (a1[i] <= a2[j]) {
			break;
		} else {
			int temp = a2[j];
			a2[j] = a1[i];
			a1[i] = temp;
			i--; j++;
		}
	}
	sort(a1, a1 + n);
	sort(a2, a2 + m);

}

int main(int argc, char const *argv[])
{
	int  n, m;
	cout << "Enter the range of first and second array respectively: ";
	cin >> n >> m;
	long long int a1[n], a2[m];
	cout << "\nEnter the elements of first array in sorted order: ";
	for (int i = 0; i < n; ++i)
	{
		cin >> a1[i];
	}
	cout << "\nEnter the elements of the second array in sorted order: ";
	for (int i = 0; i < m; ++i)
	{
		cin >> a2[i];
	}
	merge(a1, a2, n, m);
	cout << "\nArray after merging: ";
	for (int i = 0; i < n; ++i)
	{
		cout << a1[i] << " ";
	}
	for (int i = 0; i < m; ++i)
	{
		cout << a2[i] << " ";
	}
	return 0;
}