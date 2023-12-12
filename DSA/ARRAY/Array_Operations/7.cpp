//! Swap Alternate elements in array

#include<bits/stdc++.h>
using namespace std;

void swapElements(int a[], int n) {
	for (int i = 0; i < n; i = i + 2 )
	{
		if (i + 1 < n) {
			int temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	int a[n];
	cout << "\nEnter " << n << " elements of array: ";
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	swapElements(a, n);
	cout << "\nResulting array: ";
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	return 0;
}