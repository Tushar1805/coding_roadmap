//! Multiply two strings

// Given two numbers as strings s1 and s2. Calculate their Product.

// Note: The numbers can be negative and You are not allowed to use any built-in function
// or convert the strings to integers. There can be zeros in the begining of the numbers.

// Example 1:

// Input:
// s1 = "0033"
// s2 = "2"
// Output:
// 66
// Example 2:

// Input:
// s1 = "11"
// s2 = "23"
// Output:
// 253
// Your Task: You don't need to read input or print anything.
// Your task is to complete the function multiplyStrings()
// which takes two strings s1 and s2 as input and returns their product as a string.

// Expected Time Complexity: O(n1* n2)
// Expected Auxiliary Space: O(n1 + n2); where n1 and n2 are sizes of strings s1 and s2 respectively.

// Constraints:
// 1 ≤ length of s1 and s2 ≤ 103

#include<bits/stdc++.h>
using namespace std;

string multiplyStrings(string s1, string s2) {
	int n = s1.length();
	int m = s2.length();
	string ans(n + m , '0');

	bool isS1Negative = false;
	bool isS2Negative = false;

	if (s1[0] == '-') {
		isS1Negative = true;
		s1[0] = '0';
	}
	if (s2[0] == '-') {
		isS2Negative = true;
		s2[0] = '0';
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			int p = (s1[i] - '0') * (s2[j] - '0') + (ans[i + j + 1] - '0');
			ans[i + j + 1] = p % 10 + '0';
			ans[i + j] += p / 10;
		}
	}

	for (int i = 0; i < n + m; i++) {
		if (ans[i] != '0') {
			ans = ans.substr(i);
			break;
		}
	}

	if (isS1Negative && isS2Negative) {
		return ans;
	} else if (isS1Negative || isS2Negative) {
		reverse(ans.begin(), ans.end());
		ans += "-";
		reverse(ans.begin(), ans.end());
		return ans;
	} else if (!isS1Negative && !isS2Negative) {
		return ans;
	}
	return "0";
}

int main(int argc, char const *argv[])
{
	string s1, s2;
	cout << "Enter first number: ";
	cin >> s1;
	cout << "Enter second number: ";
	cin >> s2;

	string ans = multiplyStrings(s1, s2);
	cout << "Multiplication: " << ans;
	return 0;
}