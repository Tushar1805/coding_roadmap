//! 326. Power of Three

// Given an integer n, return true if it is a power of three. Otherwise, return false.

// An integer n is a power of three, if there exists an integer x such that n == 3x.

// Example 1:

// Input: n = 27
// Output: true
// Explanation: 27 = 33
// Example 2:

// Input: n = 0
// Output: false
// Explanation: There is no x where 3x = 0.
// Example 3:

// Input: n = -1
// Output: false
// Explanation: There is no x where 3x = (-1).

// Constraints:

// -2^31 <= n <= 2^31 - 1
//! Follow up: Could you solve it without loops/recursion?


#include<bits/stdc++.h>
using namespace std;

bool isPowerOfThree(int n) {

	// TC - O(logN to base 3) , base 3 becaus finding the power of 3
	// while (n >= 3) {
	// 	if (n % 3 != 0) return false;
	// 	n /= 3;
	// }
	// return (n == 1);

	// Similarly we can find power of any number

	//! Follow up

	// log has a property where log b to the base a = log b/log a
	// Therefore, power can be calculated as power(p) = log b/log a
	// If P is not an integer B is not a power of A.
	int a = 3; // because we have to find the power of 3 for every number
	double p = log10(n) / log10(a);
	return (p  - (int)p == 0);
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter a number to whether it is a power of 3 or not: ";
	cin >> n;
	bool check = isPowerOfThree(n);
	if (check) {
		cout << endl << n << " is the power of 3";
	} else {
		cout << endl << n << " is not a power of 3";
	}
	return 0;
}