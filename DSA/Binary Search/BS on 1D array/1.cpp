#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int target) {
	int n = arr.size();
	int l = 0, r = n - 1, mid;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (arr[mid] == target) {
			return mid;
		} else if (arr[mid] < target) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;

	vector<int> arr;
	cout << "Enter elements of the array: ";
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		arr.push_back(data);
	}

	int target;
	cout << "Enter the target to be searched: ";
	cin >> target;

	cout << endl << "Given array" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	int ans = binarySearch(arr, target);
	cout << endl << target << " found at index " << ans;

	return 0;
}