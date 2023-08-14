//! Non Repeating Numbers


// Given an array A containing 2*N+2 positive numbers,
// out of which 2*N numbers exist in pairs whereas the other two number occur exactly
// once and are distinct. Find the other two numbers. Return in increasing order.

// Example 1:

// Input:
// N = 2
// arr[] = {1, 2, 3, 2, 1, 4}
// Output:
// 3 4
// Explanation:
// 3 and 4 occur exactly once.
// Example 2:

// Input:
// N = 1
// arr[] = {2, 1, 3, 2}
// Output:
// 1 3
// Explanation:
// 1 3 occur exactly once.
// Your Task:
// You do not need to read or print anything. Your task is to complete
// the function singleNumber() which takes the array as input parameter
// and returns a list of two numbers which occur exactly once in the array.
// The list must be in ascending order.

// Expected Time Complexity: O(N)
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= length of array <= 106
// 1 <= Elements in array <= 5 * 106

#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> nums)
{
	// Code here.
	int n = nums.size();
	int x = 0;

	// Step 1: XOR all the elements in the array
	for (int i = 0; i < n; i++) {
		x ^= nums[i];
	}

	// Step 2: find the and op of x and 2s compliment of x
	int y = x & -x;
	int g1 = 0, g2 = 0;

	// Strp 3: Two groups of 0 and 1
	for (int i = 0; i < n; i++) {
		if ( (y & nums[i]) == 0) {
			g1 ^= nums[i];
		} else {
			g2 ^= nums[i];
		}
	}
	vector<int> ans(2, 0);
	if (g1 < g2) {
		ans[0] = g1; ans[1] = g2;
	} else {
		ans[0] = g2; ans[1] = g1;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	vector<int> arr;
	cout << "Enter the " << n << " elements of the array: ";
	for (int i = 0; i < n; ++i)
	{
		int data;
		cin >> data;
		arr.push_back(data);
	}
	vector<int> ans = singleNumber(arr);
	cout << "First Non Repeating: " << ans[0] << endl;
	cout << "Second Non Repeating: " << ans[1] << endl;
	return 0;
}