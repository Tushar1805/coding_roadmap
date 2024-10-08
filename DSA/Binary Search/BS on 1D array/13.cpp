#include<bits/stdc++.h>
using namespace std;

//* Problem Statement
// A peak element is an element that is strictly greater than its neighbors.

// Given a 0-indexed integer array nums, find a peak element, and return its index.
// If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞. In other words,
// an element is always considered to be strictly greater than a neighbor that is outside the array.

// You must write an algorithm that runs in O(log n) time.

int findPeakElement(vector<int>& nums) {
	int n = nums.size();
	if (n == 1)
		return 0;

	//These conditions written to eliminate below if condition
	// if((mid-1>=0 && nums[mid] > nums[mid-1]) && (mid+1 < nums.size() && nums[mid]>nums[mid+1]))
	if (nums[0] > nums[1]) return 0;
	if (nums[n - 1] > nums[n - 2]) return n - 1;


	//* Brute Force, TC - O(N)
	// for (int i = 1; i < n - 1; i++) {
	// 	if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
	// 		return i;
	// }

	//* Optimal, TC - O(log N)
	int l = 1, r = n - 2;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
		else if (nums[mid] < nums[mid - 1]) {
			r = mid - 1;
		} else if (nums[mid] < nums[mid + 1]) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return -1;
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
	int ans = findPeakElement(arr);

	cout << endl << "Peak element in the array is " << ans;

	return 0;
}