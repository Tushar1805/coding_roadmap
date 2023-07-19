//! Longest Palindromic Subsequence

// Given a String, find the longest palindromic subsequence.

// Example 1:

// Input:
// S = "bbabcbcab"
// Output: 7
// Explanation: Subsequence "babcbab" is the
// longest subsequence which is also a palindrome.
// Example 2:

// Input:
// S = "abcd"
// Output: 1
// Explanation: "a", "b", "c" and "d" are
// palindromic and all have a length 1.

// Your Task:
// You don't need to read input or print anything.
// Your task is to complete the function longestPalinSubseq()
// which takes the string S as input and returns an integer denoting
// the length of the longest palindromic subsequence of S.

// Expected Time Complexity: O(|S|*|S|).
// Expected Auxiliary Space: O(|S|*|S|).

// Constraints:
// 1 ≤ |S| ≤ 1000

#include<bits/stdc++.h>
using namespace std;

int longestPalinSubseq(string A) {
	//code here
	string s1 = A;
	string s2 = A;
	reverse(s2.begin(), s2.end());
	int n = A.size();

	int dp[n + 1][n + 1];
	for (int i = n; i >= 0; i--) {
		for (int j = n; j >= 0; j--) {
			if (i == n or j == n) {
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
	string str;
	cout << "Enter a string: ";
	cin >> str;
	int ans = longestPalinSubseq(str);
	cout << "\nLongest Palindromic Subsequences length is: " << ans;
	return 0;
}