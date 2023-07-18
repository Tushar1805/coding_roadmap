//! Longest Common Subsequence

// Given two strings, find the length of longest subsequence present in both of them.
// Both the strings are in uppercase latin alphabets.

// Example 1:

// Input:
// A = 6, B = 6
// str1 = ABCDGH
// str2 = AEDFHR
// Output: 3
// Explanation: LCS for input strings “ABCDGH” and “AEDFHR” is “ADH” of length 3.
// Example 2:

// Input:
// A = 3, B = 2
// str1 = ABC
// str2 = AC
// Output: 2
// Explanation: LCS of "ABC" and "AC" is "AC" of length 2.
// Your Task:
// Complete the function lcs() which takes the length of two strings respectively
// and two strings as input parameters and returns the length of the longest
// subsequence present in both of them.

// Expected Time Complexity : O(|str1|*|str2|)
// Expected Auxiliary Space: O(|str1|*|str2|)

// Constraints:
// 1<=size(str1),size(str2)<=103

#include<bits/stdc++.h>
using namespace std;

//! Using Recursion
// int solve (int i, int j, string s1, string s2) {
// 	if (i == s1.size() or j == s2.size())
// 		return 0;
// 	if (s1[i] == s2[j]) {
// 		return 1 + solve(i + 1, j + 1, s1, s2);
// 	}
// 	return max(solve(i, j + 1, s1, s2), solve(i + 1, j, s1, s2));
// }

//! Using Memoization Top - Down Approach
int solve (int i, int j, string s1, string s2, vector<vector<int>>& dp) {
	if (i == s1.size() or j == s2.size()) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if (s1[i] == s2[j]) {
		return dp[i][j] = 1 + solve(i + 1, j + 1, s1, s2, dp);
	}
	return dp[i][j] = max(solve(i, j + 1, s1, s2, dp), solve(i + 1, j, s1, s2, dp));
}

//! Using DP - Tabulation Bottom - Up approach
int lcs(int n, int m, string s1, string s2)
{
	//! Recursion TC - O(2^(m*n))
	// int ans = solve(0, 0, s1, s2);
	// return ans

	//! Memoization TC - O(n*m) SC - O(n*m)
	// vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
	// int ans = solve(0, 0, s1, s2, dp);
	// return ans;

	//! Tabulation TC - O(n*m) SC - O(n * m)
	int dp[n + 1][m + 1];
	for (int i = n; i >= 0; i--) {
		for (int j = m; j >= 0; j--) {
			if (i == n or j == m) {
				dp[i][j] = 0;
			} else if (s1[i] == s2[j]) {
				dp[i][j] = 1 + dp[i + 1][j + 1];
			} else {
				dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
	return dp[0][0];
}

int main(int argc, char const *argv[])
{
	string s1, s2;
	cout << "Enter first string: ";
	cin >> s1;
	cout << "Enter second string: ";
	cin >> s2;
	int ans = lcs(s1.length(), s2.length(), s1, s2);
	cout << "Longest Common Subsequence: " << ans;
	return 0;
}