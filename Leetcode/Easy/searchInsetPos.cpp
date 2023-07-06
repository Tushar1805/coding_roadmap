//! 35. Search Insert Position

// Given a sorted array of distinct integers and a target value,
// return the index if the target is found. If not, return the index where
// it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4

// Constraints:

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums contains distinct values sorted in ascending order.
// -104 <= target <= 104

#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
	int mid, ans;
	int l = 0;
	int r = nums.size();
	if (target > nums[r - 1]) return r;
	while (l <= r) {
		mid = (l + r) / 2;
		if (nums[mid] == target) {
			return mid;
		} else if (nums[mid] < target) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return l;
}

int main(int argc, char const *argv[])
{
	vector<int> a;
	int target, n;
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "\nEnter the " << n << " element of array in sorted order: ";
	for (int i = 0; i < n; ++i)
	{
		int data;
		cin >> data;
		a.push_back(data);
	}
	cout << "\nEnter the target value to find in array: ";
	cin >> target;
	int pos = searchInsert(a, target);
	cout << "\nTarget found at position " << pos + 1;
	return 0;
}