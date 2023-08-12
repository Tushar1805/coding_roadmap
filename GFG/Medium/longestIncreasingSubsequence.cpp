//! Longest Increasing Subsequence

// Given an array of integers, find the length of the longest (strictly)
// increasing subsequence from the given array.

// Example 1:

// Input:
// N = 16
// A = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
// Output:
// 6
// Explanation:
// There are more than one LIS in this array.
// One such Longest increasing subsequence is {0,2,6,9,13,15}.
// Example 2:

// Input:
// N = 6
// A[] = {5,8,3,7,9,1}
// Output:
// 3
// Explanation:
// There are more than one LIS in this array.  One such Longest increasing subsequence is {5,7,9}.
// Your Task:
// Complete the function longestSubsequence() which takes the input
// array and its size as input parameters and returns the length of the longest increasing subsequence.

// Expected Time Complexity : O( N*log(N) )
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 104
// 0 ≤ A[i] ≤ 106

#include<bits/stdc++.h>
using namespace std;

int fixPosition(int ans[], int l, int r, int x) {
	while (l < r) {
		int m = (l + r) / 2;
		if (ans[m] >= x) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	return r;
}

int longestSubsequence(int n, int a[])
{

	// TC = O(n^n)
	//   int dp[n];
	//   dp[0] = 1;
	//   int ans = dp[0];
	//   for(int i=1; i<n; i++){
	//       dp[i] = 1;
	//       for(int j = 0; j<i; j++){
	//           if(a[i]>a[j]){
	//               dp[i] = max(dp[i], dp[j] + 1);
	//           }
	//       }
	//       ans = max(ans, dp[i]);
	//   }

	// Optimised approach, TC = O(n log n)
	int ans[n];
	int len = 1;
	ans[0] = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > ans[len - 1]) {
			ans[len] = a[i];
			len++;
		} else {
			int p = fixPosition(ans, 0, len - 1, a[i]);
			ans[p] = a[i];
		}
	}
	return len;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = longestSubsequence(n, arr);
	cout << "Longest Subsequence: " << ans;
	return 0;
}