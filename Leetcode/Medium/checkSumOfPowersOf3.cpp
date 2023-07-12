//! 1780. Check if Number is a Sum of Powers of Three

// Given an integer n, return true if it is possible to represent n as
// the sum of distinct powers of three. Otherwise, return false.

// An integer y is a power of three if there exists an integer x such that y == 3x.

// Example 1:

// Input: n = 12
// Output: true
// Explanation: 12 = 31 + 32
// Example 2:

// Input: n = 91
// Output: true
// Explanation: 91 = 30 + 32 + 34
// Example 3:

// Input: n = 21
// Output: false

// Constraints: 1 <= n <= 107

#include<bits/stdc++.h>
using namespace std;

bool checkPowersOfThree(int n) {

	//! My approach
	for (int i = 15; i >= 0; i--) {
		long long int x = pow(3, i);
		if (x <= n) n -= x;
		if (n == 0) return 1;
	}
	return 0;

	//! Another approach
	// bool oneChance = true;
	// while(n>1){
	//     if(n%3==0){
	//         n/=3;
	//         oneChance = true;
	//     } else if(oneChance && n%3==1) {
	//         n--;
	//         oneChance = false;
	//     } else {
	//         return false;
	//     }
	// }
	// return true;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the number: ";
	cin >> n;
	bool ans = checkPowersOfThree(n);
	cout << "\nGiven number " << n << " is sum of powers of three: " << ans;
	return 0;
}
