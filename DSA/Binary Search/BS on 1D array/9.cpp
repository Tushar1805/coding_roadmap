#include<bits/stdc++.h>
using namespace std;

//* Search in rotated sorted array with duplicate elements
//* only state whether the target present or not

bool search(vector<int>& nums, int target) {
	int l = 0;
	int r = nums.size() - 1;
	int mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (nums[mid] == target)
			return true;
		if ((nums[l] == nums[mid]) && (nums[r] == nums[mid])) {
			l++;
			r--;
		} else if (nums[l] <= nums[mid]) {
			if (nums[l] <= target && nums[mid] > target)
				r = mid - 1;
			else
				l = mid + 1;
		} else {
			if (nums[mid] <= target && nums[r] >= target)
				l = mid + 1;
			else
				r = mid - 1;
		}
	}
	return false;
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
	bool ans = search(arr, target);

	ans ? cout << endl << "Target " << target << " present in the array" : cout << endl << "NOT FOUND";

	return 0;
}