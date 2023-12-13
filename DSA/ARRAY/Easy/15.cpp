// https://prepinsta.com/cpp-program/array-rotation/

#include <iostream>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, r, i, j;
	char c;
	cout << "Enter the size of array: ";
	cin >> n;
	int a[n];
	cout << "\nEnter the " << n << " elements of array: ";
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cout << "\nEnter how many times you want to perform the rotations: ";
	cin >> r;
	cout << "Enter which rotation you want to perform [for left: L, right: R]: ";
	cin >> c;
	if (tolower(c) == 'l') {
		for (i = 0; i < r; ++i)
		{
			int first = a[0];
			for (j = 0; j < n - 1; ++j)
			{
				a[j] = a[j + 1];
			}
			a[j] = first;
		}
		cout << "\nArray After " << r << " Rotations to the left: ";
		for (i = 0; i < n; ++i)
		{
			cout << a[i] << " ";
		}
	} else {
		for (i = 0; i < r; ++i)
		{
			int last = a[n - 1];
			for (j = n - 1; j > 0 ; --j)
			{
				a[j] = a[j - 1];
			}
			a[j] = last;
		}
		cout << "\nArray After " << r << " Rotations to the right: ";
		for (i = 0; i < n; ++i)
		{
			cout << a[i] << " ";
		}
	}
	return 0;
}