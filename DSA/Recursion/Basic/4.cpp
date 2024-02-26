// Print linearly from N to 1

#include<bits/stdc++.h>
using namespace std;

void print(int i) {
	if (i < 1)
		return;
	cout << i << endl;
	print(i - 1);
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter how many times you want to print the numbers: ";
	cin >> n;
	print( n);
	return 0;
}