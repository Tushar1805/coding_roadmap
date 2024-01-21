// Remove outermost parantheses

#include<bits/stdc++.h>
using namespace std;


string solution1(string s) {
	int count = 0;
	std::string str;
	for (char c : s) {
		if (c == '(') {
			if (count++) {
				str += '(';
			}
		} else {
			if (--count) {
				str += ')';
			}
		}
	}
	return str;
}

int main(int argc, char const *argv[])
{
	string s;
	cout << "Enter the string: ";
	getline(cin, s);

	string ans;

	// Optimal Approach: Two pointer approach
	// TC - O(N), SC - O(1)
	ans = solution1(s);

	cout << "Result: " << ans;

	return 0;
}