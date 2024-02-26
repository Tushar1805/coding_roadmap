// Print linearly from 1 to N

#include<bits/stdc++.h>
using namespace std;

void print(int i, int n) {
	if (i > n)
		return;
	cout << i << endl;
	print(i + 1, n);
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter how many times you want to print the numbers: ";
	cin >> n;
	print(1, n);
	return 0;
}