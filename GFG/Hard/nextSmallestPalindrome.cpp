//! Next Smallest Palindrome

// Given a number, in the form of an array Num[] of size N containing digits from 1 to 9(inclusive).
// The task is to find the next smallest palindrome strictly larger than the given number.

// Example 1:

// Input:
// N = 11
// Num[] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2}
// Output: 9 4 1 8 8 0 8 8 1 4 9
// Explanation: Next smallest palindrome is
// 94188088149.
// Example 2:

// Input:
// N = 5
// Num[] = {2, 3, 5, 4, 5}
// Output: 2 3 6 3 2
// Explanation: Next smallest palindrome is
// 23632.
// Your Task:
// Complete the function generateNextPalindrome() which takes an array num,
// and an single integer n, as input parameters and returns an array of integers
// denoting the answer. You don't to print answer or take inputs.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// 1 <= Num[i] <= 9

#include<bits/stdc++.h>
using namespace std;

vector<int> generateNextPalindrome(int num[], int n) {
	// code here
	vector<int> ans;
	int solved = 0, carry;
	// Incremental Case
	for (int i = n / 2; i < n; i++) {
		if (num[i] < num[n - i - 1]) {
			num[i] = num[n - i - 1];
			for (int j = i + 1; j < n; j++) {
				num[j] = num[n - j - 1];
			}
			solved = 1;
			break;
		} else if (num[i] > num[n - i - 1])
			break;
	}

	if (solved == 1) {
		for (int i = 0; i < n; i++)
			ans.push_back(num[i]);
		return ans;
	} else {
		// Decremental case
		carry = 1;
		for (int i = (n - 1) / 2; i >= 0; i--) {
			if (num[i] + carry == 10) {
				num[i] = 0;
				carry = 1;
			} else {
				num[i]++;
				carry = 0;
				break;
			}
		}

		if (carry == 1)
			ans.push_back(1);

		for (int i = 0; i < n; i++)
			ans.push_back(num[i]);

		if (carry == 1)
			n++;

		for (int i = (n + 1) / 2; i < n; i++)
			ans[i] = ans[n - i - 1];

		return ans;
	}

}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter " << n << " elements of the array: ";
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	vector<int> ans = generateNextPalindrome(a, n);
	cout << "Next Smallest Palindrome: ";
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
	return 0;
}

