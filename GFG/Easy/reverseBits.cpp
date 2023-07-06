//! Reverse Bits

// Given a 32 bit number X, reverse its binary form and print the answer in decimal.

// Example 1:

// Input:
// X = 1
// Output:
// 2147483648
// Explanation:
// Binary of 1 in 32 bits representation-
// 00000000000000000000000000000001
// Reversing the binary form we get,
// 10000000000000000000000000000000,
// whose decimal value is 2147483648.
// Example 2:

// Input:
// X = 5
// Output:
// 2684354560
// Explanation:
// Binary of 5 in 32 bits representation-
// 00000000000000000000000000000101
// Reversing the binary form we get,
// 10100000000000000000000000000000,
// whose decimal value is 2684354560.
// Your Task:
// You don't need to read input or print anything.
// Your task is to complete the function reversedBits()
// which takes an Integer X as input and returns the answer.

// Expected Time Complexity: O(log(X))
// Expected Auxiliary Space: O(1)

// Constraints:
// 0 <= X < 232

#include<iostream>
using namespace std;

long long reversedBits(long long X) {
	long long int result = 0;
	for (int i = 1; i <= 32; i++) {
		// Calculating the LSB
		// Taking & with 1 will give the set lsb bit
		long long int lsb = X & 1;

		// Now 31 times shifting left to get the reverse of lsb
		// It will be decresed by i as i is decreasing
		long long int reverseLsb = lsb << (32 - i);

		// Now taking or of result with the reverse LSB
		// will give the result
		result |= reverseLsb;

		// Now shifting the number right by one bit to get the next bit
		X >>= 1;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	long long int n;
	cout << "Enter a number: ";
	cin >> n;
	cout << "\nReversed Number after reversing its binary bits: " << reversedBits(n);
	return 0;
}