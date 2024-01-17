// Maximum product subarray

#include<bits/stdc++.h>
using namespace std;

// Brute Force: Generate all subarrays
// TC - Nearly O(n^3), SC - O(1);
int solution1(vector<int> arr, int n) {
	int ans = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int pro = 1;
			for (int k = i; k <= j; k++) {
				pro *= arr[k];
			}
			ans = max(ans, pro);
		}
	}
	return ans;
}

// Better Approach: Using Two loops only
// TC - O(n^2), SC - O(1)
int solution2(vector<int> arr, int n) {
	int ans = INT_MIN;
	for (int i = 0; i < n; i++) {
		int pro = 1;
		for (int j = i; j < n; j++) {
			pro *= arr[j];
			ans = max(ans, pro);
		}
	}
	return ans;
}

// Optimal Approach
// TC - O(n), SC - O(1)
int solution3(vector<int> arr, int n) {
	int ans = INT_MIN;
	int pre = 1, suff = 1;
	for (int i = 0; i < n; i++) {
		if (pre == 0) pre = 1;
		if (suff == 0) suff = 1;
		pre *= arr[i];
		suff *= arr[n - i - 1];
		ans = max(ans, max(pre, suff));
	}
	return ans;
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
	int ans;
	// ans = solution1(arr, n);

	// Better Approach
	// ans = solution2(arr, n);

	// Optimal Approach
	ans = solution3(arr, n);

	cout << "Maximum Subarray product: " << ans << endl;
	return 0;
}