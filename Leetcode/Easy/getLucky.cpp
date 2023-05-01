//! 1945. Sum of Digits of String After Convert

// You are given a string s consisting of lowercase English letters, and an integer k.

// First, convert s into an integer by replacing each letter with
// its position in the alphabet (i.e., replace 'a' with 1, 'b' with 2, ..., 'z' with 26).
// Then, transform the integer by replacing it with the sum of its digits.
// Repeat the transform operation k times in total.

// For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:

// Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
// Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
// Transform #2: 17 ➝ 1 + 7 ➝ 8
// Return the resulting integer after performing the operations described above.

// Example 1:

// Input: s = "iiii", k = 1
// Output: 36
// Explanation: The operations are as follows:
// - Convert: "iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
// - Transform #1: 9999 ➝ 9 + 9 + 9 + 9 ➝ 36
// Thus the resulting integer is 36.
// Example 2:

// Input: s = "leetcode", k = 2
// Output: 6
// Explanation: The operations are as follows:
// - Convert: "leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝ 12552031545
// - Transform #1: 12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
// - Transform #2: 33 ➝ 3 + 3 ➝ 6
// Thus the resulting integer is 6.
// Example 3:

// Input: s = "zbax", k = 2
// Output: 8

// Constraints:

// 1 <= s.length <= 100
// 1 <= k <= 10
// s consists of lowercase English letters.

// Testcase - hvmhoasabaymnmsd k =1

#include<bits/stdc++.h>
using namespace std;

int getLucky(string s, int k) {
	int count = 0;
	for (int i = 0; i < s.length(); i++)
	{
		int m = s[i] - 96;
		if (m > 9)
		{
			while (m > 0)
			{
				int l = m % 10;
				count = count + l;
				m = m / 10;
			}
		}
		else
		{
			count = count + (s[i] - 96);
		}
	}
	if (k == 1)
	{
		return count;
	}
	else
	{
		for (int i = 0; i < k - 1; i++)
		{
			int j = 0;
			while (count > 0)
			{
				j = j + count % 10;
				count = count / 10;
			}
			count = j;
		}
	}
	return count;
}

int main(int argc, char const *argv[])
{
	string s;
	cout << "Enter the string: ";
	cin >> s;
	int k;
	cout << "\nEnter the value of transform times: ";
	cin >> k;
	cout << "Result: " << getLucky(s, k);

	return 0;
}