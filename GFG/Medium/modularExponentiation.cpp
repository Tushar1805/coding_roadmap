//! Modular Exponentiation for large numbers

// Implement pow(x, n) % M.
// In other words, given x, n and M, find (xn) % M.

// Example 1:

// Input:
// x = 3, n = 2, m = 4
// Output:
// 1
// Explanation:
// 32 = 9. 9 % 4 = 1.
// Example 2:

// Input:
// x = 2, n = 6, m = 10
// Output:
// 4
// Explanation:
// 26 = 64. 64 % 10 = 4.

// Your Task:
// You don't need to read or print anything.
// Your task is to complete the function PowMod()
// which takes integers x, n and M as input parameters and returns xn % M.

// Expected Time Complexity: O(log(n))
// Expected Space Complexity: O(1)

// Constraints:
// 1 ≤ x, n, M ≤ 109

#include<bits/stdc++.h>
using namespace std;

long long int PowMod(long long int x, long long int n, long long int M)
{
	// Code here
	long long res = 1;
	while (n > 0) {
		// odd
		if (n & 1) {
			res = (res * x) % M;
		}
		x = (x * x) % M;
		n = n >> 1;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	long long int x, n, m;
	cout << "Enter the value of x: ";
	cin >> x;
	cout << "Enter the value of n: ";
	cin >> n;
	cout << "Enter the value of m: ";
	cin >> m;
	long long int ans = PowMod(x, n, m);
	cout << x << " raised to the power " << n << " with mod " << m << " is: " << ans;
	return 0;
}