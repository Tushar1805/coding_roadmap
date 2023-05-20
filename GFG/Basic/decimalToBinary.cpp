//! Decimal to binary

// Given a decimal number N, compute its binary equivalent.

// Example 1:

// Input: N = 7
// Output: 111

// Example 2:

// Input: N = 33
// Output: 100001
// Your Task:
// You don't need to read input or print anything.
// Complete the function toBinary() which takes the decimal number N as the input parameter
// and prints its binary equivalent.
// Note: Print the output in a single line, the next line character is printed by the Driver Code.

#include<bits/stdc++.h>
using namespace std;

void toBinary(int n)
{
	int org = n;
	string ans = "";
	while (n != 0) {
		int digit = n % 2;
		ans += digit + '0';
		n /= 2;
	}

	cout << "\nDecimal to Binary of " << org << " is: ";
	for (int i = ans.length() - 1; i >= 0; --i)
	{
		cout << ans[i];
	}

}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter a number: ";
	cin >> n;
	toBinary(n);
	return 0;
}