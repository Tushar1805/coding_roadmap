#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach: TC - O(N^2), SC - O(1)
int solution1(vector<int> arr, int n, int k) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += arr[j];
			if (sum == k)
				cnt++;
		}
	}
	return cnt;
}

// Better Approach: Works for both +ve & -ve elements
// TC - O(N), SC - O(N)
int solution2(vector<int> arr, int n, int k) {
	int cnt = 0;
	unordered_map<int, int> mpp;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum == k) cnt++;
		int rem = sum - k;
		if (mpp.find(rem) != mpp.end())
			cnt++;
		mpp[sum] = i;
	}
	return cnt;
}

// Optimal approach: Works for only positive elements
// TC - O(N), SC - O(1)
int solution3(vector<int> arr, int n, int k) {
	int left = 0, right = 0, cnt = 0;
	int  sum = arr[right];
	while (right < n) {
		while (sum > k) {
			sum -= arr[left];
			left++;
		}
		if (left <= right && sum == k) cnt++;
		right++;
		if (right < n) sum += arr[right];
	}
	return cnt;
}

int main(int argc, char const * argv[])
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
	int k;
	cout << "Enter the sum to find: ";
	cin >> k;

	// int ans = solution1(arr, n, k);
	// int ans = solution2(arr, n, k);
	int ans = solution3(arr, n, k);
	cout << "There are " << ans << " subarrays of given sum " << k << endl;
	return 0;
}