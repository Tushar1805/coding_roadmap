//! Copy Set Bits in Range

// Given two numbers X and Y, and a range [L, R] where 1 <= L <= R <= 31.
// You have to copy the set bits of 'Y' in the range L to R in 'X'. Return this modified X.

// Note: Range count will be from Right to Left & start from 1.

// Example 1:

// Input:
// X = 44, Y = 3
// L = 1,  R = 5
// Output:
// 47
// Explaination:
// Binary represenation of 44 and 3 is 101100 and 000011.
// So in the range 1 to 5 there are two set bits of 3 (1st & 2nd position).
// If those are set in 44 it will become 101111 which is 47.
// Example 2:

// Input:
// X = 16, Y = 2
// L = 1,  R = 3
// Output: 18
// Explaination: Binary represenation of 16 and 2 is 10000 and 10.
// If the mentioned conditions are applied then 16 will become 10010 which is 18.
// Your Task:
// You do not need to read input or print anything.
// Your task is to complete the function setSetBit()
// which takes the numbers X, Y, L and R as input parameters and returns the modified value of X.

// Expected Time Complexity: O(R - L)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ X, Y ≤ 109
// 1 ≤ L ≤ R ≤ 32

#include<bits/stdc++.h>
using namespace std;

//* Brute Force Approach
// int setSetBits(int x, int y, int l, int r) {
// 	int binX[32], binY[32], indexArra[32];
// 	int xi = 0, yj = 0;
// 	while (x != 0) {
// 		binX[xi] = x % 2;
// 		x /= 2;
// 		xi++;
// 	}
// 	while (y != 0) {
// 		binY[yj]  = y % 2;
// 		y /= 2;
// 		yj++;
// 	}
// 	for (int i = l - 1; i < r; ++i)
// 	{
// 		if (binY[i] == 1) {
// 			binX[i] = binY[i];
// 		}
// 	}
// 	int res  = 0;
// 	for (int i = xi - 1; i >= 0; --i)
// 	{
// 		res += binX[i] * pow(2, i);
// 	}
// 	return res;
// }


//* Optimized approach - O{R-L}
int setSetBits(int x, int y, int l, int r) {
	for (int i = l; i <= r; ++i)
	{
		if ((y & (1 << (i - 1))) != 0) {
			x = x | (1 << (i - 1));
		}
	}
	return x;
}

int main(int argc, char const *argv[])
{
	int x, y, r, l;
	cout << "Enter the value of X & Y: ";
	cin >> x >> y;
	cout << "\nEnter the Range L to R to copy the set bits of Y in: ";
	cin >> l >> r;
	int res = setSetBits(x, y, l, r);
	cout << "\nModified Result: " << res;
	return 0;
}