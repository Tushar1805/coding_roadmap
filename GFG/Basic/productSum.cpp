//! Product Sum

// Given two integers a and b. Write a program to find the number of digits in the product of these two integers.

// Example 1:

// Input: a = 12, b = 4
// Output: 2
// Explanation: 12*4 = 48
// Hence its a 2 digit number.

// Example 2:

// Input: a = -24, b = 33
// Output: 3
// Explanation: -24*33 = -792
// Hence its a 3 digit number.

// Your Task:
// You dont need to read input or print anything. Complete the function countDigits() which takes a and b as input parameter and returns the number of digits in the product of the two numbers.

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

// Constraints:
// -108<= a,b <=108

#include<iostream>
using namespace std;

long long int countDigits(long long int a, long long int b) {
	long long int product = a * b;
	long long count = 0;
	while (product != 0) {
		product /= 10;
		count++;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	long long int a, b;
	cout << "Enter two numbers: ";
	cin >> a >> b;
	cout << "\nCount of digits: " << countDigits(a, b);
	return 0;
}