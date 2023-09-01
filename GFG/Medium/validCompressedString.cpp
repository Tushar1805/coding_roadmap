//! Valid Compressed String

// A special compression mechanism can arbitrarily delete 0 or more characters
// and replace them with the deleted character count.
// Given two strings, S and T where S is a normal string and T is a compressed string,
// determine if the compressed string  T is valid for the plaintext string S.
// Note: If T consists of multiple integers adjacently, consider all of them at a single number.
// For example T="12B32", consider T as "12" + "B" + "32".

// Example 1:

// Input:
// S = "GEEKSFORGEEKS"
// T = "G7G3S"
// Output:
// 1
// Explanation:
// We can clearly see that T is a valid
// compressed string for S.

// Example 2:

// Input:
// S = "DFS"
// T = "D1D"
// Output :
// 0
// Explanation:
// T is not a valid compressed string.

// Your Task:
// You don't need to read input or print anything.
// Your task is to complete the function checkCompressed()
// which takes 2 strings S and T as input parameters and returns
// integer 1 if T is a valid compression of S and 0 otherwise.

// Expected Time Complexity: O(|T|)
// Expected Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;

int validCompression(string s, string t) {
	int i = 0, j = 0;
	int n = s.length(), m = t.length();

	while (i < n && j < m) {
		if (s[i] == t[j]) {
			i++;
			j++;
		} else if (isdigit(t[j])) {
			string deleteCount = "";
			while (j < m && isdigit(t[j])) {
				deleteCount += t[j];
				j++;
			}
			i += stoi(deleteCount);
		} else {
			return 0;
		}
	}
	if (i == s.length() && j == t.length())
		return 1;
	return 0;
}

int main(int argc, char const *argv[])
{
	string s, t;
	cout << "Enter normal string: ";
	cin >> s;
	cout << "Enter compressed string: ";
	cin >> t;

	int ans = validCompression(s, t);
	if (ans == 1) {
		cout << t << " is valid compression of " << s;
	} else {
		cout << "Not Valid";
	}

	return 0;
}