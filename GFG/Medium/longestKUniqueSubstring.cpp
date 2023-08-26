//! Longest K unique characters substring

// Given a string you need to print the size of the longest possible
// substring that has exactly K unique characters. If there is no possible substring then print -1.

// Example 1:

// Input:
// S = "aabacbebebe", K = 3
// Output:
// 7
// Explanation:
// "cbebebe" is the longest substring with 3 distinct characters.
// Example 2:

// Input:
// S = "aaaa", K = 2
// Output: -1
// Explanation:
// There's no substring with 2 distinct characters.
// Your Task:
// You don't need to read input or print anything. Your task is
// to complete the function longestKSubstr() which takes the string
// S and an integer K as input and returns the length of the longest
// substring with exactly K distinct characters. If there is no
// substring with exactly K distinct characters then return -1.

// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(|S|).

// Constraints:
// 1 ≤ |S| ≤ 105
// 1 ≤ K ≤ 26
// All characters are lowercase latin characters.

#include<bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k) {

	int ans = -1;
	int j = 0;
	unordered_map<char, int> m;

	for (int i = 0; i < s.length(); i++) {
		m[s[i]]++;
		if (m.size() == k)
			ans = max(ans, i - j + 1);
		else if (m.size() > k) {
			while (m.size() != k) {
				m[s[j]]--;
				if (m[s[j]] == 0)
					m.erase(s[j]);
				j++;
			}
		}
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	string str;
	cout << "Enter the string: ";
	cin >> str;
	int k;
	cout << "Enter number  of unique characters you want in substring: ";
	cin >> k;
	int ans = longestKSubstr(str, k);
	cout << "Length of longest " << k << " substring: " << ans;
	return 0;
}