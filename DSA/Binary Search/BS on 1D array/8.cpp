#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
	int n = nums.size();
	int l = 0;
	int r = n - 1;
	int mid;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (nums[mid] == target) return mid;
		else if (nums[l] <= nums[mid]) {
			// left is sorted
			if (nums[l] <= target && target <= nums[mid]) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		} else {
			// right is sorted
			if (nums[mid] <= target && target <= nums[r]) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
	}
	return -1;
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
	int ans = search(arr, target);

	cout << endl << "Target " << target << " found at index " << ans;

	return 0;
}