//! Number of Unique Paths

// Given a A X B matrix with your initial position at the top-left cell,
// find the number of possible unique paths to reach the bottom-right cell
// of the matrix from the initial position.

// Note: Possible moves can be either down or right at any point in time,
// i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].

// Example 1:

// Input:
// A = 2, B = 2
// Output: 2
// Explanation: There are only two unique
// paths to reach the end of the matrix of
// size two from the starting cell of the
// matrix.
// Example 2:

// Input:
// A = 3, B = 4
// Output: 10
// Explanation: There are only 10 unique
// paths to reach the end of the matrix of
// size two from the starting cell of the
// matrix.
// Your Task:
// Complete NumberOfPath() function which takes 2 arguments(A and B) and
// returns the number of unique paths from top-left to the bottom-right cell.

// Expected Time Complexity: O(A*B).
// Expected Auxiliary Space: O(A*B).

// Constraints:
// 1 ≤ A ≤ 16
// 1 ≤ B ≤ 16

#include<bits/stdc++.h>
using namespace std;

// TC - O(m) || SC - O(1)
int  NumberOfPaths(int m, int n)
{
	// Code Here
	// 1st observation
	// we will move m-1 step right and n-1 step down to reach at the end
	// So total steps are m-1 + n-1 == m + n -2

	int total = m + n - 2;

	// 2nd observation
	// Now to get all possible combinations we can take either m-1 step or n-1 step to calculate
	int r = m - 1;

	// we have the formula of nCr = n! / r! * (n-r)!
	// we have the simplified formula for this as
	// r number of numbers starting from n in decreasing order divided by
	// r number of numbers starting from 1 in increasing order
	// eg. for 4C2 = 4*3 / 1 * 2

	long long int ans = 1;
	for (int i = 1; i <= r; i++) {
		ans = ans * (total - r + i) / i;
	}
	return ans;
}

// TC - O(m * n) || SC - O(m*n)
int NumberOfPath(int a, int b)
{
	int dp[a][b];
	dp[0][0] = 1;

	for (int i = 0; i < a; i++) {
		int up = 0, left = 0;
		for (int j = 0; j < b; j++) {
			if (i == 0 && j == 0) dp[i][j] = 1;
			else {
				if (i > 0) up = dp[i - 1][j];
				if (j > 0) left = dp[i][j - 1];

				dp[i][j] = up + left;
			}
		}
	}
	return dp[a - 1][b - 1];
}

int main(int argc, char const *argv[])
{
	int a, b;
	cout << "Enter the size of the grid: (a * b): ";
	cin >> a >> b;
	int ans = NumberOfPath(a, b);
	cout << "Number of Paths: " << ans;
	return 0;
}

