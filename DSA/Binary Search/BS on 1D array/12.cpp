#include<bits/stdc++.h>
using namespace std;

int singleElement(vector<int> &nums) {
	// int n = arr.size();
	// int ans = 0;
	// Using XOR property
	// for (int i = 0; i < n; i++) {
	// 	ans ^= arr[i];
	// }
	// return ans;

	int n = nums.size();
	if (n == 1) return nums[0];
	if (nums[1] != nums[0]) return nums[0];
	if (nums[n - 1] != nums[n - 2]) return nums[n - 1];
	int l = 1, r = n - 2, mid;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid]) {
			return nums[mid];
		} else if ( ((mid % 2 == 1) && nums[mid - 1] == nums[mid]) || ((mid % 2 == 0) && nums[mid] == nums[mid + 1])) {
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
	int ans = singleElement(arr);

	cout << endl << "Single element in sorted array is " << ans;

	return 0;
}