//! Rearrange an array with O(1) extra space

// Given an array arr[] of size N where every element is in the range from 0 to n-1.
// Rearrange the given array so that the transformed array arrT[i] becomes arr[arr[i]].

// NOTE: arr and arrT are both same variables, representing the array before and after transformation respectively.

// Example 1:

// Input:
// N = 2
// arr[] = {1,0}
// Output: 0 1
// Explanation:
// arr[arr[0]] = arr[1] = 0
// arr[arr[1]] = arr[0] = 1
// So, arrT becomes {0, 1}
// Example 2:

// Input:
// N = 5
// arr[] = {4,0,2,1,3}
// Output: 3 4 2 0 1
// Explanation:
// arr[arr[0]] = arr[4] = 3
// arr[arr[1]] = arr[0] = 4
// arr[arr[2]] = arr[2] = 2
// arr[arr[3]] = arr[1] = 0
// arr[arr[4]] = arr[3] = 1
// and so on
// So, arrT becomes {3, 4, 2, 0, 1}
// Your Task:
// You don't need to read input or print anything.
// The task is to complete the function arrange() which takes arr
// and N as input parameters and rearranges the elements in the array in-place.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// 0 <= Arr[i] < N

#include<bits/stdc++.h>
using namespace std;

void arrange(long long arr[], int n) {
	// Your code here

	//Sc - O(n)
	// long long temp[n];
	// for(int i=0;i<n;i++)
	//     temp[i] = arr[i];
	// for(int i=0;i<n;i++)
	//     arr[i] = temp[arr[i]];
	int max = n + 1;
	for (int i = 0; i < n; i++)
		arr[i] += (arr[arr[i]] % n) * n;
	for (int i = 0; i < n; i++)
		arr[i] /= n;

}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "\nEnter " << n << " elements of array: ";
	long long int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	arrange(a, n);
	cout << "\nArray after rearranging according to given criteria: ";
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	return 0;
}