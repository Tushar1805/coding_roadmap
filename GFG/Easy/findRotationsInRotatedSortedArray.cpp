//! Rotation

// Given an ascending sorted rotated array Arr of distinct integers of size N.
// The array is right rotated K times. Find the value of K.

// Example 1:

// Input:
// N = 5
// Arr[] = {5, 1, 2, 3, 4}
// Output: 1
// Explanation: The given array is 5 1 2 3 4.
// The original sorted array is 1 2 3 4 5.
// We can see that the array was rotated
// 1 times to the right.
// Example 2:

// Input:
// N = 5
// Arr[] = {1, 2, 3, 4, 5}
// Output: 0
// Explanation: The given array is not rotated.
// Your Task:
// Complete the function findKRotation() which takes array arr and size n,
// as input parameters and returns an integer representing the answer.
// You don't to print answer or take inputs.

// Expected Time Complexity: O(log(N))
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <=105
// 1 <= Arri <= 107

#include<bits/stdc++.h>
using namespace std;

int findKRotation(int arr[], int n) {
	// Binary search Approach | Optimal

	// int l = 0, r = n-1;
	// int mid;
	// if(arr[0] <= arr[r]){
	//     return 0;
	// }
	// while(l<=r){
	//     mid = (l+r) /2;
	//     if (arr[mid] <= arr[n - 1]) {
	//             r = mid - 1;
	//             continue;
	//         }
	//         if (mid + 1 < n && arr[mid] > arr[n - 1] && arr[mid] <= arr[mid + 1]) {
	//             l = mid + 1;
	//             continue;
	//         }
	//         if (mid + 1 < n && arr[mid] > arr[mid + 1]) {
	//             break;
	//         }
	// }
	//return mid+1;

	// Bruete Force Approach
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[n - 1] < arr[i]) {
			ans++;
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
	int ans = findKRotation(a, n);
	cout << "Array rotated " << ans << " times to the right";
	return 0;
}