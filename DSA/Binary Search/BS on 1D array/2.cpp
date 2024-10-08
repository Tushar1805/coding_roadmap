// Given a sorted array arr[] of size n without duplicates, and given a value x.
// Floor of x is defined as the largest element k in arr[]
// such that k is smaller than or equal to x. Find the index of k(0-based indexing).

#include<bits/stdc++.h>
using namespace std;

int findCeil(vector<long long> &arr, long long n, long long x) {
	int l = 0, r = n - 1, mid;
	int ans = -1;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (arr[mid] >= x) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return ans;
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

	// traditional method
	int ans = findCeil(arr, n, target);

	// short cut method
	int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

	cout << endl << "floor of " << target << " found at index " << ans;

	return 0;
}