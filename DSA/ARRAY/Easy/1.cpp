#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter the " << n << " elements of the array: ";
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		arr.push_back(data);
	}

	// Bruete force to find the largest element in the array
	// Sort the array and the return the last element

	sort(arr.begin(), arr.end());
	cout << "Largest element of the array: " << arr[n - 1] << endl;

	// Optimized approach to find the largest element
	// Traverse the array with the max variable and update whenever found
	// greater than max

	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	cout << "Largest element of the array: " << max << endl;
	return 0;
}