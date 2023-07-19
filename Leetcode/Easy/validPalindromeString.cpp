//! 125. Valid Palindrome

// A phrase is a palindrome if, after converting all uppercase letters
// into lowercase letters and removing all non-alphanumeric characters,
// it reads the same forward and backward. Alphanumeric characters include letters and numbers.

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

// Constraints:

// 1 <= s.length <= 2 * 105
// s consists only of printable ASCII characters.

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
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
	cout << "Enter a string: ";
	cin >> s;
	bool ans = isPalindrome(s);
	if (ans) {
		cout << endl << s << " is a palindrome string";
	} else {
		cout << "\nNot a palindrome";
	}
	return 0;
}