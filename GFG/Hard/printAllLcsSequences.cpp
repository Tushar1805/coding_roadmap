//! Print all LCS sequences

// You are given two strings s and t.
// Now your task is to print all longest common sub-sequences in lexicographical order.

// Example 1:

// Input: s = abaaa, t = baabaca
// Output: aaaa abaa baaa
// Example 2:

// Input: s = aaa, t = a
// Output: a
// Your Task:
// You do not need to read or print anything. Y
// our task is to complete the function all_longest_common_subsequences()
// which takes string a and b as first and second parameter respectively
// and returns a list of strings which contains
// all possible longest common subsequences in lexicographical order.

// Expected Time Complexity: O(n4)
// Expected Space Complexity: O(K * n) where K is a constant less than n.

// Constraints:
// 1 ≤ Length of both strings ≤ 50

#include<bits/stdc++.h>
using namespace std;

set<string> st;
void helper_print(string s, string t, int i, int j, string &temp, vector<string> & ans, int cnt) {
	if (cnt == 0) {
		if (st.find(temp) == st.end()) {
			st.insert(temp);
			ans.push_back(temp);
		}
		return;
	}

	if (i >= s.size() || j >= t.size()) return;

	for (int row = i; row < s.size(); row++) {
		for (int col = j; col < t.size(); col++) {
			if (s[row] == t[col]) {
				temp.push_back(s[row]);
				helper_print(s, t, row + 1, col + 1, temp, ans, cnt - 1);
				temp.pop_back();
			}
		}
	}
}

vector<string> all_longest_common_subsequences(string s, string t)
{
	int n = s.length();
	int m = t.length();
	//  int dp[n][m];
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 0 ; i <= n; i++) dp[i][0] = 0;
	for (int j = 0; j <= m; j++) dp[0][j] = 0;
	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int len = dp[n][m];
	vector<string> ans;
	string temp = "";
	unordered_set<string> st;
	helper_print(s, t, 0, 0, temp, ans, len);
	sort(ans.begin(), ans.end());

	return ans;
}

int main(int argc, char const *argv[])
{
	string s1, s2;
	cout << "Enter first string: ";
	cin >> s1;
	cout << "Enter second string: ";
	cin >> s2;
	vector<string> ans = all_longest_common_subsequences(s1, s2);
	cout << "\nAll Longest Common Subsequences are: " ;
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
	return 0;
}