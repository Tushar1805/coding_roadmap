#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
	int ans = INT_MAX;
	int low = 0, high = nums.size() - 1;
	while (low <= high) {
		int mid = (low + high) / 2;

		// Optimized here
		if (nums[low] <= nums[high]) {
			ans = min(ans, nums[low]);
			break;
		}

		// left half is sorted
		if (nums[low] <= nums[mid]) {

			ans = min(ans, nums[low]);
			low = mid + 1;
		}
		else {
			ans = min(ans, nums[mid]);
			high = mid - 1;
		}
	}
	return ans;
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
	int ans = findMin(arr);

	cout << endl << "Minimum element in the array is " << ans;

	return 0;
}