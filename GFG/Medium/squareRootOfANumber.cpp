//! Square root of a number

// Given an integer x, find the square root of x.
// If x is not a perfect square, then return floor(√x).

// Example 1:

// Input:
// x = 5
// Output: 2
// Explanation: Since, 5 is not a perfect
// square, floor of square_root of 5 is 2.
// Example 2:

// Input:
// x = 4
// Output: 2
// Explanation: Since, 4 is a perfect
// square, so its square root is 2.

// Your Task:
// You don't need to read input or print anything.
// The task is to complete the function floorSqrt()
// which takes x as the input parameter and return its square root.
// Note: Try Solving the question without using the sqrt function. The value of x>=0.

// Expected Time Complexity: O(log N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ x ≤ 107

#include<bits/stdc++.h>
using namespace std;

double squareRootPrecision(long long int n, int upto, long long int tempSol) {
	double factor = 1;
	double ans = tempSol;
	for (int i = 1; i <= upto; ++i)
	{
		factor /= 10;
		for (double j = ans; j * j < n; j = factor + j)
		{
			ans = j;
		}
	}
	return ans;
}

long long int squareRoot(long long int l, long long int h, long long int x) {
	long long int mid;
	long long int s = l, e = h;
	long long int ans = 1;
	while (s <= e) {
		mid = (s + e) / 2;
		long long sq = mid * mid;
		if (sq <= x) {
			ans = mid;
			s = mid + 1;
		} else {
			e = mid - 1;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	long long int x;
	cout << "Enter the Number: ";
	cin >> x;
	if (x == 0) {
		cout << "Square root of " << x << " is: 0";
	} else {
		long long tempSol = squareRoot(1, x - 1, x);
		cout << "\nSquare root of " << x << " without precision is: " << tempSol;
		cout << "\nSquare root of " << x << " with precision of 3 is: " << squareRootPrecision(x, 3, tempSol);
	}
	return 0;
}