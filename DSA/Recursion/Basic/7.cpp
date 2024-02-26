#include<iostream>
using namespace std;

int factorial(int n) {
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter a number to find the factorial of: ";
	cin >> n;

	cout << "Factorial of " << n << " is: " << factorial(n);
	return 0;
}