#include<iostream>
using namespace std;

int pow(int n, int m) {
	if (m == 0)
		return 1;
	m--;
	return n * pow(n, m);
}

int main(int argc, char const *argv[])
{
	int n, m;
	cout << "Enter the number to find the power of: ";
	cin >> n;
	cout << "Enter the number to find the power to: ";
	cin >> m;
	cout << m << " to the power of " << n << " is: " << pow(n, m);
	return 0;
}