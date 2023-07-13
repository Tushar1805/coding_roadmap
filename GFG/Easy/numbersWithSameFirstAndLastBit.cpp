//! Numbers with same first and last digit

// Given a range of numbers starting with integer L and ending at R,
// the task is to count the numbers which have same first and last digits.

// Example 1:

// Input:
// L = 7
// R = 68
// Output:9
// Explanation:
// Number with the same
// first and last digits
// in the given range is:
// [7, 8, 9, 11, 22, 33, 44 ,55, 66].
// Example 2:

// Input:
// L = 5
// R = 40
// Output:8
// Explanation:
// Number with the same
// first and last digits
// in the given range is:
// [5, 6, 7, 8, 9, 11, 22, 33, 44].

// Your Task:
// You don't need to read input or print anything.
// Your task is to complete the function numbersInRange()
// which takes integers L and R and returns the count of numbers if L>R return 0.

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

#include<bits/stdc++.h>
using namespace std;

int numbersInRange(int L, int R) {
	int count = 0;
	for (int i = L; i <= R; i++) {
		int c = log10(i);
		int divide = pow (10, c);
		int f = i / divide;
		int l = i % 10;
		if (f == l) {
			count++;
		}
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int l, r;
	cout << "Enter the range L to R: ";
	cin >> l >> r;
	int count = numbersInRange(l, r);
	cout << "\nThre are " << count << " numbers who pass the criteria";
	return 0;
}
