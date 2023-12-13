#include<bits/stdc++.h>
using namespace std;

bool bruteForce(vector<int> arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[i]) return false;
		}
	}
	return true;
}

bool optimal(vector<int> arr, int n) {
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) return false;
	}
	return true;
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

	//! Bruete Force approach
	// Traverse for every element and check if it is smaller or not
	// than its all future element

	// if(bruteForce(arr, n)){
	// 	cout<<"Array is sorted";
	// }else{
	// 	cout<<"Array is not sorted";
	// }

	//! Optimal approach
	// Traverse the array and just check the previous element is smaller
	// than the current element

	if (optimal(arr, n)) {
		cout << "Array is sorted";
	} else {
		cout << "Array is not sorted";
	}

	return 0;
}