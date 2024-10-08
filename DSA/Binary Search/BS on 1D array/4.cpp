#include<bits/stdc++.h>
using namespace std;

int searchInsertPos(vector<long long> &arr, long long n, long long x) {
	int l = 0, r = n - 1, mid;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (arr[mid] >= x) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return l;
}


int main(int argc, char const *argv[])
{
	long long n;
	cout << "Enter the size of the array: ";
	cin >> n;

	vector<long long> arr;
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
	int ans = searchInsertPos(arr, n, target);

	cout << endl << "Element " << target << " can be inserted at index " << ans;

	return 0;
}