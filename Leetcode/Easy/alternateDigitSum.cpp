// 2544. Alternating Digit Sum

// You are given a positive integer n. Each digit of n has a sign according to the following rules:

// The most significant digit is assigned a positive sign.
// Each other digit has an opposite sign to its adjacent digits.
// Return the sum of all digits with their corresponding sign.

// Example 1:

// Input: n = 521
// Output: 4
// Explanation: (+5) + (-2) + (+1) = 4.
// Example 2:

// Input: n = 111
// Output: 1
// Explanation: (+1) + (-1) + (+1) = 1.
// Example 3:

// Input: n = 886996
// Output: 0
// Explanation: (+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0.

// Constraints:

// 1 <= n <= 109

#include<bits/stdc++.h>
using namespace std;

int alternateDigitSum(int n) {
	string s = to_string(n);
	int sum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (i % 2 == 0)
			sum = sum + (s[i] - '0');
		else
			sum = sum - (s[i] - '0');
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter a number: ";
	cin >> n;
	cout << "\nAlternate Digit Sum according to the rules: " << alternateDigitSum(n);
	return 0;
}