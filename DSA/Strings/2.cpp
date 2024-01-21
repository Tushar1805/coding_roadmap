// Valid Parentheses

#include<bits/stdc++.h>
using namespace std;

bool find(string s, char ch, int i, int n) {
	int cnt = 0;
	bool found = false;
	for (int j = i; j < n; j++) {
		if (s[j] == '(' || s[j] == '{' || s[j] == '[') {
			cnt++;
			continue;
		}
		if (s[j] == ch && cnt == 0) {
			found = true;
			break;
		}
		cnt--;
	}
	return found;
}
bool solution1(string s) {
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			if (!find(s, ')', i + 1, n)) return false;
		}
		if (s[i] == '[') {
			if (!find(s, ']', i + 1, n)) return false;
		}
		if (s[i] == '{') {
			if (!find(s, '}', i + 1, n)) return false;
		}
	}
	return true;
}

bool solution2(string s) {
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			st.push(s[i]);
		} else {
			if (st.empty() ||
			        (s[i] == ')' && st.top() != '(') ||
			        (s[i] == ']' && st.top() != '[') ||
			        (s[i] == '}' && st.top() != '{')) {
				return false;
			}
			st.pop();
		}
	}
	return st.empty();
}

int main(int argc, char const *argv[])
{
	string s;
	cout << "Enter the string: ";
	cin >> s;

	bool ans;
	// Brute Force
	// TC - O(n^2), SC - O(1)
	// ans = solution1(s);

	// Optimal Approach: Use of stack data structure
	// TC - O(N), SC - O(N)
	ans = solution2(s);

	if (ans) {
		cout << "The given string " << s << " is a valid parentheses\n";
	} else {
		cout << "The given string " << s << " is NOT a valid parentheses\n";
	}

	return 0;
}