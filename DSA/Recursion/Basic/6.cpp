// 5. Print Linearly from N to 1 (but by backtrack)

#include<bits/stdc++.h>
using namespace std;

void print(int i, int n) {
	if (i > n)
		return;
	print(i + 1, n);
	cout << i << endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter how many times you want to print the numbers: ";
	cin >> n;
	print(1, n);
	return 0;
}