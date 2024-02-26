// 5. Print Linearly from 1 to N(but by backtrack)

#include<bits/stdc++.h>
using namespace std;

void print(int i) {
	if (i < 1)
		return;
	print(i - 1);
	cout << i << endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter how many times you want to print the numbers: ";
	cin >> n;
	print( n);
	return 0;
}