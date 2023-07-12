//! Power Of Numbers

// Given a number and its reverse. Find that number raised to the power of its own reverse.
// Note: As answers can be very large, print the result modulo 109 + 7.

// Example 1:

// Input:
// N = 2
// Output: 4
// Explanation: The reverse of 2 is 2 and after raising power of 2 by 2 we get 4
// which gives remainder as 4 when divided by 1000000007.
// Example 2:

// Input:
// N = 12
// Output: 864354781
// Explanation: The reverse of 12 is 21and 1221 when divided by 1000000007 gives remainder as 864354781.
// Your Task:
// You don't need to read input or print anything.
// You just need to complete the function pow()
// that takes two parameters N and R denoting the
// input number and its reverse and returns power of (N to R)mod(109 + 7).

// Expected Time Complexity: O(LogN).
// Expected Auxiliary Space: O(LogN).

// Constraints:
// 1 <= N <= 109

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long power(int N, int R)
{
	long long int ans = 0;
	// Brute Force, TC - O(1)
	// for(int i=1; i<=R; i++){
	//       power *= N;
	// }

	// Optimal approach, Tc - O(log N)
	if (R == 0)
		return 1;

	if (R % 2 == 0) {
		ans = power(N, R / 2);
		ans *= ans;
	} else {
		ans = N;
		ans = ans * power(N, R - 1);
	}
	return ans % mod;
}

int main(int argc, char const *argv[])
{
	int n, r = 0;
	cout << "Enter the number to find the power of: ";
	cin >> n;
	int org = n;
	while (org != 0) {
		int rem = org % 10;
		r = r * 10 + rem;
		org /= 10;
	}
	long long int ans = power(n, r);
	cout << "\n" << n << " Raised to " << r << " = " << ans;
	return 0;
}