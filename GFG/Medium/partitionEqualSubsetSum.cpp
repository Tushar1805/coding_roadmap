//! Partition Equal Subset Sum

// Given an array arr[] of size N, check if it can be partitioned into two parts
// such that the sum of elements in both parts is the same.

// Example 1:

// Input: N = 4
// arr = {1, 5, 11, 5}
// Output: YES
// Explanation:
// The two parts are {1, 5, 5} and {11}.
// Example 2:

// Input: N = 3
// arr = {1, 3, 5}
// Output: NO
// Explanation: This array can never be
// partitioned into two such parts.
// Your Task:
// You do not need to read input or print anything.
// Your task is to complete the function equalPartition()
// which takes the value N and the array as input parameters and
// returns 1 if the partition is possible. Otherwise, returns 0.

// Expected Time Complexity: O(N*sum of elements)
// Expected Auxiliary Space: O(N*sum of elements)

// Constraints:
// 1 ≤ N ≤ 100
// 1 ≤ arr[i] ≤ 1000
// N*sum of elements ≤ 5*106

#include<bits/stdc++.h>
using namespace std;

// Recursion
int solve(int pos, int arr[], int n, int sum) {
	// Base case if sum is negative
	if (sum < 0) return 0;
	// Base case if sum is equal to 0
	if (pos == n) return (sum == 0 ? 1 : 0);
	// Not take || take (if we found subset in any of the path return true)
	return (solve(pos + 1, arr, n, sum) || solve(pos + 1, arr, n, sum - arr[pos])) ;
}

// Recursion With Memoization
int solve(int pos, int arr[], int n, int sum, vector<vector<int>> &dp) {
	// Base case if sum is negative
	if (sum < 0) return 0;
	// Base case if sum is equal to 0
	if (pos == n) return (sum == 0 ? 1 : 0);
	if (dp[pos][sum] != -1) return dp[pos][sum];
	// Not take + take
	return dp[pos][sum] = (solve(pos + 1, arr, n, sum) || solve(pos + 1, arr, n, sum - arr[pos]));
}

int equalPartition(int arr[], int n) {
	int totalSum = 0;
	for (int i = 0; i < n; i++) totalSum += arr[i];

	// If total sum  is not even then there's no way that there will two equal partitions
	if (totalSum % 2 != 0) return 0;
	int targetSum = totalSum / 2;

	// Approach 1: Recursion TC & SC - O(2^n)
	// return solve(0, arr, n, targetSum);

	// Approach 2: Recursion with Memoization TC & SC - O(n*sum)
	// vector<vector<int>> dp(n + 1, vector<int>(targetSum + 1, -1));
	// return solve(0, arr, n, targetSum, dp);

	// Approach 3: DP Tabular approach TC & SC - O(n*sum)
	vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1));
	dp[0][0] = true;
	for (int i = 1; i <= targetSum; i++) {
		dp[0][i] = false;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= targetSum; j++) {
			if (j < arr[i - 1]) {
				// copy previous state
				dp[i][j] = dp[i - 1][j];
			} else {
				// current state = previous state + and state of remained sum
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
			}
		}
	}
	return dp[n][targetSum];
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	int arr[n];
	cout << "Enter the " << n << " elements of the array: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = equalPartition(arr, n);
	if (ans) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	return 0;
}