#include<bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int low = 0, high = n - 1, mid = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (a[mid] == x) return {a[mid], a[mid]};
		else if (x > a[mid]) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	int f = (high >= 0) ? a[high] : -1;
	int c = (low < n) ? a[low] : -1;
	return {f, c};
}

int main(int argc, char const *argv[])
{
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

	int target;
	cout << "Enter the target to be searched: ";
	cin >> target;

	cout << endl << "Given array" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	pair<int, int> ans = getFloorAndCeil(arr, n, target);

	cout << endl << "Floor = " << ans.first << " " << "Ceil = " << ans.second;

	return 0;
}