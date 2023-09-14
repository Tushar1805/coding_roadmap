//! Perfect Sum Problem

// Given an array arr[] of non-negative integers and an integer sum,
// the task is to count all subsets of the given array with a sum equal to a given sum.

// Note: Answer can be very large, so, output answer modulo 109+7

// Example 1:

// Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
//        sum = 10
// Output: 3
// Explanation: {2, 3, 5}, {2, 8}, {10} are
// possible subsets.
// Example 2:
// Input: N = 5, arr[] = {1, 2, 3, 4, 5}
//        sum = 10
// Output: 3
// Explanation: {1, 2, 3, 4}, {1, 4, 5},
// {2, 3, 5} are possible subsets.
// Your Task:
// You don't need to read input or print anything.
// Complete the function perfectSum() which takes N,
// array arr[] and sum as input parameters and returns an integer value

// Expected Time Complexity: O(N*sum)
// Expected Auxiliary Space: O(N*sum)

// Constraints:
// 1 ≤ N*sum ≤ 106
// 0<=arr[I]<=106

#include<bits/stdc++.h>
using namespace std;

int mod = 1000000007;

// Recursion
int solve(int pos, int arr[], int n, int sum) {
	// Base case if sum is negative
	if (sum < 0) return 0;
	// Base case if sum is equal to 0
	if (pos == n) return (sum == 0 ? 1 : 0);
	// Not take + take
	return (solve(pos + 1, arr, n, sum) % mod + solve(pos + 1, arr, n, sum - arr[pos]) % mod) % mod;
}

// Recursion With Memoization
int solve(int pos, int arr[], int n, int sum, vector<vector<int>> &dp) {
	// Base case if sum is negative
	if (sum < 0) return 0;
	// Base case if sum is equal to 0
	if (pos == n) return (sum == 0 ? 1 : 0);
	if (dp[pos][sum] != -1) return dp[pos][sum];
	// Not take + take
	return dp[pos][sum] = (solve(pos + 1, arr, n, sum) % mod + solve(pos + 1, arr, n, sum - arr[pos]) % mod) % mod;
}

int perfectSum(int arr[], int n, int sum) {
	// Approach 1: Recursion TC & SC - O(2^n)
	// return solve(0, arr, n, sum);

	// Approach 2: Recursion with Memoization TC & SC - O(n*sum)
	// vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
	// return solve(0, arr, n, sum, dp);

	// Approach 3: DP Tabular approach TC & SC - O(n*sum)
	vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= sum; i++) {
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j < arr[i - 1]) {
				// copy previous state
				dp[i][j] = (dp[i - 1][j]) % mod;
			} else {
				// current state = previous state + and state of remained sum
				dp[i][j] = ((dp[i - 1][j]) % mod + (dp[i - 1][j - arr[i - 1]]) % mod) % mod;
			}
		}
	}
	return dp[n][sum];
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
	int sum;
	cout << "Enter the sum for which you want to find the perfect sum: ";
	cin >> sum;
	int ans = perfectSum(arr, n, sum);
	cout << "There are " << ans << " subsets with given sum";
	return 0;
}