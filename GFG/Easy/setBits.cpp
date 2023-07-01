// Number of 1 Bits

// Given a positive integer N, print count of set bits in it.

// Example 1:

// Input:
// N = 6

// Output:
// 2

// Explanation:
// Binary representation is '110'
// So the count of the set bit is 2.
// Example 2:

// Input:
// 8

// Output:
// 1

// Explanation:
// Binary representation is '1000'
// So the count of the set bit is 1.
// Your Task:
// You don't need to read input or print anything.
// Your task is to complete the function setBits() which takes
// an Integer N and returns the count of number of set bits.

// Expected Time Complexity: O(LogN)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 109

#include<iostream>
using namespace std;

int setBits(int n) {
	int binary[100];
	int res = 0, index = 0;

	while (n != 0) {
		binary[index] = n % 2;
		if (n % 2)
		{
			res++;
		}
		n /= 2;
		index++;
	}
	cout << "\nBinary Representation: ";
	for (int i = index - 1; i >= 0; i--) {
		cout << binary[i];
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the number: ";
	cin >> n;
	int res = setBits(n);
	cout << "\nNumber of set bits: " << res;
	return 0;
}