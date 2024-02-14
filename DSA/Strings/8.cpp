// Isomorphic String

#include<bits/stdc++.h>
using namespace std;

bool solution(string s, string t) {
	if (s.length() != t.length()) return false;

	unordered_map<char, char> m1;
	unordered_map<char, char> m2;
	for (int i = 0; i < s.length(); i++) {
		if (m1.find(s[i]) == m1.end() && m2.find(t[i]) == m2.end()) {
			m1[s[i]] = t[i];
			m2[t[i]] = s[i];
		} else if (m1[s[i]] != t[i]) return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	string s, t;
	cout << "Enter the first string: ";
	cin >> s;
	cout << "Enter the seconde string: ";
	cin >> t;

	bool ans = solution(s, t);
	if (ans) {
		cout << "Strings are isomorphic" << endl;
	} else {
		cout << "Strings are not isomorphic" << endl;
	}
	return 0;
}