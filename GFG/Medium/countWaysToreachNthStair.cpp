//! Count ways to reach the n'th stair

// There are n stairs, a person standing at the bottom wants to reach the top.
// The person can climb either 1 stair or 2 stairs at a time. Count the number
// of ways, the person can reach the top (order does matter).

// Example 1:

// Input:
// n = 4
// Output: 5
// Explanation:
// You can reach 4th stair in 5 ways.
// Way 1: Climb 2 stairs at a time.
// Way 2: Climb 1 stair at a time.
// Way 3: Climb 2 stairs, then 1 stair
// and then 1 stair.
// Way 4: Climb 1 stair, then 2 stairs
// then 1 stair.
// Way 5: Climb 1 stair, then 1 stair and
// then 2 stairs.
// Example 2:

// Input:
// n = 10
// Output: 89
// Explanation:
// There are 89 ways to reach the 10th stair.
// Your Task:
// Complete the function countWays() which takes the top stair
// number m as input parameters and returns the answer % 10^9+7.

// Expected Time Complexity : O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ n ≤ 104

#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

// Using DP TC & SC - O(N)
// int countWays(int n)
// {
// 	vector<int> dp(n + 1);
// 	dp[0] = dp[1] = 1;
// 	for (int i = 2; i <= n; i++) {
// 		dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod) % mod;
// 	}
// 	return dp[n];
// }

// Its a fibonacci sequence we can solve it using fibonacci logic
// Here space optimized

int countWays(int n)
{
	if (n == 0 || n == 1) return 1;
	int a = 1;
	int b = 1;
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		ans = (a % mod + b % mod) % mod;
		a = b;
		b = ans;
	}
	return ans;
}


int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the nth stair: ";
	cin >> n;
	int ans = countWays(n);
	cout << "Ways to reach the nth stair " << ans;
	return 0;
}