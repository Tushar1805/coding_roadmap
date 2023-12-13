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

	//! Linear search using single traversal
	int data;
	cout << "Enter a number to search in array: ";
	cin >> data;
	int found = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] == data) {
			found = i;
		}
	}
	if (found != -1) {
		cout << "Element found at index " << found;
	} else {
		cout << "Element not found";
	}
	return 0;

}