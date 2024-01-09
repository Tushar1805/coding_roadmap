// count number of subarray with given XOR k
#include<bits/stdc++.h>
using namespace std;
// 4 2 2 6 4

// Naive Brute Force: Form all the subarrays and check for the XOR
// TC - O(n^3), SC - O(1)
int solution1(vector<int> arr, int n, int k) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int xr = 0;
			for (int l = i; l <= j; l++) {
				xr ^= arr[l];
			}
			if (xr == k) cnt++;
		}
	}
	return cnt;
}

// Better Approach: Reduce the above complexity and use only two loops
// TC - O(n^2), SC - O(1)
int solution2(vector<int> arr, int n, int k) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int xr = 0;
		for (int j = i; j < n; j++) {
			xr ^= arr[j];
			if (xr == k) cnt++;
		}
	}
	return cnt;
}

// Optimal Approach: Use Reverse engineering
// If total xor is (xr) and we need to find k from xr
// x = xr ^ k - like the presum problem
// TC - O(n), SC - O(n)
int solution3(vector<int> arr, int n, int k) {
	int cnt = 0;
	int xr = 0;
	int x = 0;
	unordered_map<int, int> mp;
	mp[0]++;
	for (int i = 0; i < n; i++) {
		xr ^= arr[i];
		x = xr ^ k;
		cnt += mp[x];
		mp[xr]++;
	}
	return cnt;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	vector<int> arr;
	cout << "Enter the " << n << " elements of the array: ";
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		arr.push_back(data);
	}
	int k;
	cout << "Enter the value to check for the XOR: ";
	cin >> k;

	// Brute Force
	// int ans = solution1(arr, n, k);

	// Better Approach
	// int ans = solution2(arr, n, k);

	// Optimal Approach
	int ans = solution3(arr, n, k);
	cout << "Number of subarray with given XOR " << k << ": " << ans;
	return 0;
}