//! Nth Natural Number

// Given a positive integer N. You have to find Nth natural number
// after removing all the numbers containing digit 9.

// Example 1:

// Input:
// N = 8
// Output:
// 8
// Explanation:
// After removing natural numbers which contains
// digit 9, first 8 numbers are 1,2,3,4,5,6,7,8
// and 8th number is 8.
// Example 2:

// Input:
// N = 9
// Output:
// 10
// Explanation:
// After removing natural numbers which contains
// digit 9, first 9 numbers are 1,2,3,4,5,6,7,8,10
// and 9th number is 10.

// Your Task:
// You don't need to read input or print anything.
// Complete the function findNth() which accepts an
// integer N as input parameter and return the Nth number after removing all the numbers containing digit 9.

// Expected Time Complexity: O(logN)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 1012

#include<bits/stdc++.h>
using namespace std;

long long findNth(long long N) {
	long long ans = 0, multiplier = 1;
	while (N) {
		ans += (N % 9) * multiplier;
		N /= 9;
		multiplier *= 10;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the value of N: ";
	cin >> n;
	long long  ans = findNth(n);
	cout << endl << n << "th natural number after skipping all numbers that have 9 digit in it is: " << ans;
	return 0;
}

