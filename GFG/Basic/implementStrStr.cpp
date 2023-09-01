//! Implement strstr

// Your task is to implement the function strstr.
// The function takes two strings as arguments (s,x) and
// locates the occurrence of the string x in the string s.
// The function returns an integer denoting the first occurrence of the string x in s (0 based indexing).

// Note: You are not allowed to use inbuilt function.

// Example 1:

// Input:
// s = GeeksForGeeks, x = Fr
// Output: -1
// Explanation: Fr is not present in the
// string GeeksForGeeks as substring.

// Example 2:

// Input:
// s = GeeksForGeeks, x = For
// Output: 5
// Explanation: For is present as substring
// in GeeksForGeeks from index 5 (0 based
// indexing).

// Your Task:
// You don't have to take any input. Just complete the strstr()
// function which takes two strings str, target as an input parameter.
// The function returns -1 if no match if found else it returns an integer
// denoting the first occurrence of the x in the string s.

// Expected Time Complexity: O(|s|*|x|)
// Expected Auxiliary Space: O(1)

// Note : Try to solve the question in constant space complexity.

// Constraints:
// 1 <= |s|,|x| <= 100

#include<bits/stdc++.h>
using namespace std;

int strstr(string s1, string s2) {
	for (int i = 0; i < s1.length(); i++) {
		int ind = i;
		bool check = true;
		for (int j = 0 ; j < s2.length(); j++) {
			if (s1[i] != s2[j]) {
				check = false;
				break;
			} else {
				check = true;
				i++;
			}
		}
		if (check)
			return ind;
		else
			i = ind;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	string str1, str2;
	cout << "Enter string 1: ";
	cin >> str1;
	cout << "Enter string 2: ";
	cin >> str2;
	int ans = strstr(str1, str2);
	cout << "Answer: " << ans;
	return 0;
}
