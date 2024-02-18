// Check if one string is rotation of second string

#include<bits/stdc++.h>
using namespace std;

// Brute force: TC - O(N^2), SC - O(1)
bool solution1(string s, string t) {
	if (s.length() != t.length()) return false;
	int n = t.length();
	bool ans = true;
	for (int i = 0; i < n; i++) {
		ans = true;
		for (int j = 0; j < n; j++) {
			if (t[(i + j) % n] != s[j]) {
				ans = false;
			}
		}
		if (ans) return true;
	}
	return false;
}

// Optimized: TC - O(n), SC - O(1)
bool solution2(string s, string t) {
	string temp = s + s;
	return ((s.length() == t.length()) && temp.find(t) != -1);
}

int main(int argc, char const *argv[])
{
	string s, t;
	cout << "Enter the string 1: ";
	cin >> s;
	cout << "Enter the string 2: ";
	cin >> t;

	// bool ans = solution1(s, t);
	bool ans = solution2(s, t);

	if (ans) {
		cout << t << " is the rotation of " << s << endl;
	} else {
		cout << "Invalid";
	}
	return 0;
}