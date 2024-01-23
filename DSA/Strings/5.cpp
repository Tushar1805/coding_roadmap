// Reverse words in a given string

#include<bits/stdc++.h>
using namespace std;

string solution1(string s) {
	stack<string> st;
	string temp = "";
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] != ' ') {
			temp += s[i];
		} else if (s[i] == ' ') {
			if (temp != "") st.push(temp);
			// st.push(" ");
			temp = "";
		}
	}
	if (temp != "") {
		st.push(temp);
	}
	string ans = "";
	while (!st.empty()) {
		ans += st.top();
		st.pop();
		if (!st.empty()) ans += " ";
	}
	return ans;
}

string solution2(string s) {
	int left = 0;
	int right = s.length() - 1;

	string temp = "";
	string ans = "";

	//Iterate the string and keep on adding to form a word
	//If empty space is encountered then add the current word to the result
	while (left <= right) {
		char ch = s[left];
		if (ch != ' ') {
			temp += ch;
		} else if (ch == ' ') {
			if (ans != "" && temp != "") ans = temp + " " + ans;
			else {
				ans += temp;
			}
			temp = "";
		}
		left++;
	}

	//If not empty string then add to the result(Last word is added)
	if (temp != "") {
		if (ans != "") ans = temp + " " + ans;
		else ans = temp;
	}

	return ans;
}

void reverse(string &s, int i, int j) {
	while (i < j) {
		char temp = s[i];
		s[i++] = s[j];
		s[j--] = temp;
	}
}
void solution3(string &s) {
	int i = 0, j = 0;
	int l = 0;
	int len = s.length();
	int wordcount = 0;
	while (true) {
		while (i < len && s[i] == ' ') i++;
		if (i == len) break;
		if (wordcount) s[j++] = ' ';
		l = j;
		while (i < len && s[i] != ' ') {s[j] = s[i]; j++; i++;}
		reverse(s, l, j - 1);
		wordcount++;
	}
	s.resize(j);
	reverse(s, 0, j - 1);
}

int main(int argc, char const *argv[])
{
	string s;
	cout << "Enter the string: ";
	getline(cin, s);

	string ans;

	// Brute Force approach
	// ans = solution1(s);

	// Optimal Approach: Two pointer approach
	// TC - O(N), SC - O(1)
	// ans = solution2(s);

	// Optimal Approach: In place
	// TC - O(N), SC - O(1)
	solution3(s);

	cout << "Reverse String: " << s;

	return 0;
}