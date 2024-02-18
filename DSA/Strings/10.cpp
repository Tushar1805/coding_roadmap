// Check if one string is anagram of each other

#include<bits/stdc++.h>
using namespace std;

bool solution1(string s1, string s2) {
	if (s1.length() != s2.length()) return false;

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i])return false;
	}
	return true;
}

bool solution2(string s1, string s2) {
	if (s1.length() != s2.length()) return false;

	unordered_map<char, int> mp;
	int n = s1.length();
	for (int i = 0; i < n; i++) {
		mp[s1[i]]++;
	}
	for (int i = 0; i < n; i++) {
		mp[s2[i]]--;
	}
	for (auto i : mp) {
		if (i.second != 0) return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	string s1, s2;
	cout << "Enter the string 1: ";
	cin >> s1;
	cout << "Enter the string 2: ";
	cin >> s2;

	// bool ans = solution1(s1, s2);
	bool ans = solution2(s1, s2);

	if (ans) {
		cout << "Two string are anagram of each other";
	} else {
		cout << "Not Anagrams";
	}
	return 0;
}