//! Nth catalan number

// Given a number N. The task is to find the Nth catalan number.
// The first few Catalan numbers for N = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …

// Catalan Number for N is equal to the number of expressions containing
// N pairs of paranthesis that are correct matched, i.e.,
// for each of the N '(' there exist N ')' on there right and vice versa.

// Since answer can be huge return answer modulo 1e9+7.

// Note: Positions start from 0 as shown above.

// Example 1:

// Input:
// N = 5
// Output: 42
// Example 2:

// Input:
// N = 4
// Output: 14
// Your Task:
// Complete findCatalan() function that takes n as an argument and
// returns the Nth Catalan number. The output is printed by the driver code.

// Expected Time Complexity: O(N^2).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 103

#include<bits/stdc++.h>
using namespace std;

long long int m = 1000000007;
int findCatalan(int n)
{
	//code here
	int dp[n + 1];
	dp[0] = dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		long long int cat = 0;

		int k = 0, j = i - 1;
		while (k <= j) {
			if (k == j) {
				cat = ((cat % m) + ((dp[k] % m) * (dp[j] % m)) % m) % m ;
			} else {
				cat = ((cat % m) + (((dp[k] % m) * (dp[j] % m)) + ((dp[j] % m) * (dp[k] % m))) % m) % m;
			}
			k++;
			j--;
		}
		dp[i] = cat;
	}
	return dp[n];
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the value of n: ";
	cin >> n;
	int ans = findCatalan(n);
	cout << n << " th catalan number: " << ans;
	return 0;
}
