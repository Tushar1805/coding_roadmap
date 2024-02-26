// Print name 5 times

#include<bits/stdc++.h>
using namespace std;

// TC - O(n), SC - O(n) - stack space for storing the function calls

void printName(int i, int n) {
	if (i > n)
		return;
	cout << "Tushar" << endl;
	printName(i + 1, n);
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter how many times you want to print the name: ";
	cin >> n;
	printName(1, n);
	return 0;
}