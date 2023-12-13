#include<bits/stdc++.h>
using namespace std;

int bruteForce(vector<int> &arr, int n) {
	set<int> s;
	for (int i = 0; i < n; i++) {
		s.insert(arr[i]);
	}
	int j = 0;
	for (int i : s) {
		arr[j++] = i;
	}
	return s.size();
}

int optimal(vector<int>& arr, int n) {
	int i = 0;
	for (int j = 1; j < n; j++) {
		if (arr[i] != arr[j]) {
			i++;
			arr[i] = arr[j];
		}
	}
	return i + 1;
}

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

	//! Brute force approach
	// To return the duplicates we can use the hash_set property of
	// Storing only the unique elements

	// int k = bruteForce(arr, n);

	//! Optimal Approach
	// Use two pointer approach
	int k = optimal(arr, n);
	cout << "Ther are " << k << " unique elements in the array" << endl;
	cout << "Elements: ";
	for (int i = 0; i < k; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}