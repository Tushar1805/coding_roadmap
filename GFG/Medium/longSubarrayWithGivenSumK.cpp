//! Longest Sub-Array with Sum K

// Given an array containing N integers and an integer K.,
// Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

// Example 1:

// Input :
// A[] = {10, 5, 2, 7, 1, 9}
// K = 15
// Output : 4
// Explanation:
// The sub-array is {5, 2, 7, 1}.
// Example 2:

// Input :
// A[] = {-1, 2, 3}
// K = 6
// Output : 0
// Explanation:
// There is no such sub-array with sum 6.
// Your Task:
// This is a function problem. The input is already taken care of by the driver code.
// You only need to complete the function lenOfLongSubarr() that takes an array (A),
// sizeOfArray (n),  sum (K)and returns the required length of the longest Sub-Array.
// The driver code takes care of the printing.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1<=N<=105
// -105<=A[i], K<=105

#include<bits/stdc++.h>
using namespace std;

//! bruete Force
// lenOfLongSubarr(int nums[],  int n, int k)
// {
// 	int len = 0;
// 	for (int i = 0; i < n; ++i)
// 	{
// 		long long int sum = 0;
// 		for (int j = i; j < n; ++j)
// 		{
// 			sum += nums[j];
// 			if (sum == k) {
// 				len = max(j - i + 1, len);
// 			}
// 		}
// 	}
// 	return len;
// }

//! Better approach
// lenOfLongSubarr(int nums[],  int n, int k)
// {
// 	map<int, int> preSumMap;
// 	int len = 0;
// 	long long sum = 0;
// 	for (int i = 0; i < n; i++) {
// 		sum += nums[i];
// 		if (sum == 0) {
// 			len = max(len, i + 1);
// 		}
// 		long long rem = sum - 0;
// 		if (preSumMap.find(sum) != preSumMap.end()) {
// 			int l = i - preSumMap[rem];
// 			len = max(len, l);
// 		}
// 		if (preSumMap.find(sum) == preSumMap.end()) {
// 			preSumMap[sum] = i;
// 		}
// 	}
// 	return len;
// }

//! Optimized approach
int lenOfLongSubarr(int nums[],  int n, int k)
{
	map<long long, int> preSumMap;
	int len = 0;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += nums[i];
		if (sum == k) {
			len = max(i + 1, len);
		}
		long long rem = sum - k;
		if (preSumMap.find(rem) != preSumMap.end()) {
			len = max(i - preSumMap[rem], len);
		}
		if (preSumMap.find(sum) == preSumMap.end()) {
			preSumMap[sum] = i;
		}
	}
	return len;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	int a[n];
	cout << "\nEnter the elements of array: ";
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int k;
	cout << "\nEnter the sum to which you have to find the longest Subarray: ";
	cin >> k;
	int ans = lenOfLongSubarr(a, n, k);
	cout << "Subarray count: " << ans;
	return 0;
}