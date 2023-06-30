// Is Binary Number Multiple of 3

// Given a number in its binary form find if the given binary number is a multiple of 3.
// It is recommended to finish the task using one traversal of input binary number.

// Example 1:

// Input: S = "0011"
// Output: 1
// Explanation: "0011" is 3, which is divisible by 3.
// Example 2:

// Input: S = "100"
// Output: 0
// Explanation: "100"'s decimal equivalent is 4, which is not divisible by 3.
// Your Task:
// You don't need to read input or print anything.
// Your task is to complete the function isDivisible() which takes the string s as inputs
// and returns 1 if the given number is divisible by 3 otherwise 0.

// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ |S| ≤ 105

#include<bits/stdc++.h>
using namespace std;

int isDivisible(string s) {
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {

		if (s[i] == '1') {
			if (i % 2 == 0) {
				sum += 2;
			} else {
				sum += 1;
			}
		}
	}
	return (sum % 3 == 0) ? 1 : 0;
}

int main(int argc, char const *argv[])
{
	string s;
	cout << "Enter a binary number: ";
	cin >> s;
	int ans = isDivisible(s);
	cout << "\n Divisible: " << ans;
	return 0;
}