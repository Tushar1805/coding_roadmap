//! Longest Repeating Subsequence

// Given string str, find the length of the longest repeating subsequence
// such that it can be found twice in the given string.

// The two identified subsequences A and B can use the same ith character
// from string str if and only if that ith character has different indices
// in A and B. For example, A = "xax" and B = "xax" then the index of first "x"
// must be different in the original string for A and B.

// Example 1:

// Input:
// str = "axxzxy"
// Output: 2
// Explanation:
// The given array with indexes looks like
// a x x z x y
// 0 1 2 3 4 5

// The longest subsequence is "xx".
// It appears twice as explained below.

// subsequence A
// x x
// 0 1  <-- index of subsequence A
// ------
// 1 2  <-- index of str

// subsequence B
// x x
// 0 1  <-- index of subsequence B
// ------
// 2 4  <-- index of str

// We are able to use character 'x'
// (at index 2 in str) in both subsequences
// as it appears on index 1 in subsequence A
// and index 0 in subsequence B.
// Example 2:

// Input:
// str = "axxxy"
// Output: 2
// Explanation:
// The given array with indexes looks like
// a x x x y
// 0 1 2 3 4

// The longest subsequence is "xx".
// It appears twice as explained below.

// subsequence A
// x x
// 0 1  <-- index of subsequence A
// ------
// 1 2  <-- index of str

// subsequence B
// x x
// 0 1  <-- index of subsequence B
// ------
// 2 3  <-- index of str

// We are able to use character 'x'
// (at index 2 in str) in both subsequences
// as it appears on index 1 in subsequence A
// and index 0 in subsequence B.

// Your Task:
// You don't need to read or print anything.
// Your task is to complete the LongestRepeatingSubsequence()
// which takes str as input parameter and returns the length of the longest repeating subsequnece.

// Expected Time Complexity: O(n2)
// Expected Space Complexity: O(n2)

// Constraints:
// 1 <= |str| <= 103

#include<bits/stdc++.h>
using namespace std;

//! DP - Memoization
// 	int solve(int i, int j, string str1, string str2, int n, vector<vector<int>>& dp){
// 	    if(i==n or j ==n)
// 	        return 0;
// 	    if(dp[i][j] != -1)
// 	        return dp[i][j];
// 	    if(str1[i] == str2[j] and j != i)
// 	        return dp[i][j] = 1 + solve(i+1, j+1, str1, str2, n, dp);
// 	    int a = solve(i+1, j, str1, str2, n, dp);
// 	    int b = solve(i, j+1, str1, str2, n, dp);
// 	    return dp[i][j] = max(a, b);
// 	}

int LongestRepeatingSubsequence(string str) {
	//  int n = str.size();
	//  vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
	//  int ans = solve(0, 0, str, str, n, dp);
	//  return ans;

	//! DP - Tabulation Approach
	int n = str.size();
	int dp[n + 1][n + 1];
	for (int i = n; i >= 0; i--) {
		for (int j = n; j >= 0; j--) {
			if (i == n or j == n)
				dp[i][j] = 0;
			else if (str[i] == str[j] and i != j)
				dp[i][j] = 1 + dp[i + 1][j + 1];
			else
				dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
		}
	}
	return dp[0][0];
}

int main(int argc, char const *argv[])
{
	string str;
	cout << "Enter the string: ";
	cin >> str;
	int ans = LongestRepeatingSubsequence(str);
	cout << "Longest Repeating Subsequence: " << ans;
	return 0;
}