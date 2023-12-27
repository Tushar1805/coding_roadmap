#include<bits/stdc++.h>
using namespace std;

// Example 1:
// Input: [100, 200, 1, 3, 2, 4]
// Output: 4
// Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.

// Input: [3, 8, 5, 7, 6]
// Output: 4
// Explanation: The longest consecutive subsequence is 5, 6, 7, and 8.

// Brute Force Approach: TC - O(N^2), SC - O(1)
bool search (int x, vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		if (x == arr[i]) return true;
	}
	return false;
}

int solution1(vector<int> &arr, int n) {
	int longest = INT_MIN;
	int cnt = 0;
	int x;
	for (int i = 0; i < n; i++) {
		x = arr[i];
		cnt = 1;
		while (search(x + 1, arr)) {
			x = x + 1;
			cnt++;
		}
		longest = max(longest, cnt);
	}
	return longest;
}

// Better Approach: Using sorting, TC - O(n logn) + O(n) , SC - O(1)
int solution2(vector<int> nums, int n) {
	if (n == 0) return 0;
	int longest = 1;
	int last_smaller = INT_MIN;
	int cnt = 0;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n; i++) {
		if (nums[i] - 1 == last_smaller) {
			cnt++;
			last_smaller = nums[i];
		} else if (last_smaller != nums[i]) {
			cnt = 1;
			last_smaller = nums[i];
		}
		longest = max(longest, cnt);
	}
	return longest;
}

// Optimal Approach: TC - O(3N), SC - O(N)(worst- unique elements)
int solution3(vector<int> arr, int n) {
	if (n == 0) return 0;
	int longest = 1;
	int cnt = 0;
	unordered_set<int> st;
	for (int i = 0; i < n; i++) {
		st.insert(arr[i]);
	}
	for (auto i : st) {
		if (st.find(i - 1) == st.end()) {
			cnt = 1;
			int x = i;
			while (st.find(x + 1) != st.end()) {
				cnt++;
				x += 1;
			}
			longest = max(longest, cnt);
		}
	}
	return longest;
}



int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter the " << n << " elements of the array: ";
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		arr.push_back(data);
	}

	// int ans = solution1(arr, n);
	// int ans = solution2(arr, n);
	int ans = solution3(arr, n);

	cout << "Longest Subsequence: " << ans;
	return 0;
}