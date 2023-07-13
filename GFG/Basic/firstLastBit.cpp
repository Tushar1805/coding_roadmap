//! First and last Bit

// Given a positive integer n. The problem is to check whether only the first
// and last bits are set in the binary representation of n.
// The answer is 1 if the first and last bit is set else 0.

// Example 1:

// Input: N = 9
// Output: 1
// Explanation: (9)10 = (1001)2, only
// the first and last bits are set.
// â€‹Example 2:

// Input: N = 15
// Output: 0
// Explanation: (15)10 = (1111)2, except
// first and last there are other bits also
// which are set.
// Your Task:
// Your task is to complete the function onlyFirstAndLastAreSet()
// which takes the N as inputs and returns the answer.

// Expected Time Complexity: O(log N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 109

#include<bits/stdc++.h>
using namespace std;

int onlyFirstAndLastAreSet(long long int n) {
	if (n == 1) return 1;
	if (n == 2) return 0;
	int i = (n - 1) & (n - 2);
	if (i == 0) {
		return 1;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter a number: ";
	cin >> n;
	int ans = onlyFirstAndLastAreSet(n);
	if (ans == 1) {
		cout << endl << n << " has first and last bits set";
	} else {
		cout << "\nNot set";
	}
	return 0;
}