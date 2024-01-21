// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters
// and removing all non-alphanumeric characters, it reads the same forward and backward.
// Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.

#include<bits/stdc++.h>
using namespace std;


bool solution1(string s) {
	int start = 0;
	int end = s.size() - 1;
	while (start <= end) {
		if (!isalnum(s[start])) {start++; continue;}
		if (!isalnum(s[end])) {end--; continue;}
		if (tolower(s[start]) != tolower(s[end]))return false;
		else {
			start++;
			end--;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	string s;
	cout << "Enter the string: ";
	getline(cin, s);

	bool ans;

	// Optimal Approach: Two pointer approach
	// TC - O(N), SC - O(1)
	ans = solution1(s);

	if (ans) {
		cout << "The given string " << s << " is a valid Palindrome\n";
	} else {
		cout << "The given string " << s << " is NOT a valid Palindrome\n";
	}

	return 0;
}