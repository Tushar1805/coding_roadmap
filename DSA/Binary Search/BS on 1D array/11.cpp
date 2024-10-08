#include<bits/stdc++.h>
using namespace std;

// Simple logic is find the minimum
// element in the array and return it's index

int countRotation(vector<int> &arr) {
	int n = arr.size();
	int l = 0, r = n - 1, mid;
	int ans = INT_MAX;
	int index = -1;

	while (l <= r) {
		mid = l + (r - l) / 2;

		if (arr[l] <= arr[r]) {
			if (arr[l] < ans) {
				ans = arr[l];
				index = l;
			}
			break;
		}

		if (arr[l] <= arr[mid]) {
			// left is sorted
			if (arr[l] < ans) {
				ans = arr[l];
				index = l;
			}
			l = mid + 1;
		} else {
			if (arr[mid] < ans) {
				ans = arr[mid];
				index = mid;
			}
			r = mid - 1;
		}
	}
	return index;
}

int main() {
	long long n;
	cout << "Enter the size of the array: ";
	cin >> n;

	vector<int> arr;
	cout << "Enter elements of the array: ";
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		arr.push_back(data);
	}

	cout << endl << "Given array" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	int ans = countRotation(arr);

	cout << endl << "No. of times array rotated is " << ans;

	return 0;
}