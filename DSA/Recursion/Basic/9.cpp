#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

// Using two pointers
void reverseArray(int l, int r, vector<int>&arr) {
	if (l >= r) return;
	swap(arr[l], arr[r]);
	reverseArray(l + 1, r - 1, arr);
}

// Using only one variable
int i = 0;
void reverseArray(int n, vector<int>&arr) {
	if (i == n / 2)
		return;
	swap(arr[i], arr[n - i - 1]);
	i++;
	reverseArray(n, arr);
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	vector<int> arr;
	cout << "Enter " << n << " elements of the array: ";
	for (int i = 0; i < n; ++i)
	{
		int data;
		cin >> data;
		arr.push_back(data);
	}
	reverseArray(n, arr);
	cout << "\nReversed Array: ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	return 0;
}