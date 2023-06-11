//! 1009. Complement of Base 10 Integer

// The complement of an integer is the integer you get
// when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer n, return its complement.

// Example 1:

// Input: n = 5
// Output: 2
// Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
// Example 2:

// Input: n = 7
// Output: 0
// Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.
// Example 3:

// Input: n = 10
// Output: 5
// Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.

// Constraints:

// 0 <= n < 109

#include<bits/stdc++.h>
using namespace std;

int bitwiseComplement(int n) {
	// Edge Case
	if (n == 0) return 1;

	int m = n;
	int mask = 0; // to find out the number of 1's that will be AND'ed with not of number
	while (m != 0) {
		mask = (mask << 1) | 1; // Left shift mask by 1 and or it with 1 will give no. of 1's till m!=0
		m >>= 1; // right shifting the m bit to find how many bits left
	}
	int ans = (~n) & mask;
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter a number: ";
	cin >> n;
	cout << "\nBitwise Complement of " << n << " is: " << bitwiseComplement(n);
	return 0;
}