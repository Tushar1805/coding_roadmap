// Binary number to decimal number

// Given a Binary Number B, find its decimal equivalent.

// Example 1:

// Input: B = 10001000
// Output: 136
// Example 2:

// Input: B = 101100
// Output: 44

// Your Task:
// You don't need to read or print anything.
// Your task is to complete the function binary_to_decimal()
// which takes the binary number as string input parameter and returns its decimal equivalent.

// Expected Time Complexity: O(K * Log(K)) where K is number of bits in binary number.
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= number of bits in binary number  <= 16

#include<bits/stdc++.h>
using namespace std;

int binary_to_decimal(string str) {
	int ans = 0;
	int len = str.length();
	int factor = 0;
	for (int i = len - 1; i >= 0; --i)
	{
		int digit = str[i] - '0';
		ans += digit * pow(2, factor);
		factor++;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	string binary;
	cout << "Enter a binary number: ";
	cin >> binary;
	cout << "\nBinary to Decimal of " << binary << " is: " << binary_to_decimal(binary);
	return 0;
}