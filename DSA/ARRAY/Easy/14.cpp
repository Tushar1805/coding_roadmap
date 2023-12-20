#include<bits/stdc++.h>
using namespace std;

// Naive approach
int solution1(vector<int> arr, int n, int s) {
	int len = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int sum = 0;
			for (int k = i; k <= j; k++) {
				sum += arr[k];
			}
			if (sum == s) {
				len = max((j - i + 1), len);
			}
		}
	}
	return len;
}

// Optimized brute force
int solution2(vector<int> arr, int n, int s) {
	int len = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += arr[j];
			if (sum == s) {
				len = max(len, j - i + 1);
			}
		}
	}
	return len;
}
// Better solution: Using Prefix sum hashmap
// This is the is the optimal solution for the array consisting negative and positive elementss
int solution3(vector<int> arr, int n, int s) {
	unordered_map<int, int> mpp;
	int len = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum == s) {
			len = max(len, i + 1);
		}
		int rem = sum - s;
		if (mpp.find(rem) != mpp.end()) {
			len = max(len, i - mpp[rem]);
		}
		if (mpp.find(rem) == mpp.end()) {
			mpp[sum] = i;
		}
	}
	return len;
}

// Optimized approach: Greedy or two pointe
int solution4(vector<int> arr, int n, int s) {
	int left = 0, right = 0;
	int len = 0;
	int sum = 0;
	while (right < n) {
		while (left <= right && sum > s) {
			sum -= arr[left];
			left++;
		}
		if (sum == s) {
			len = max(len, right - left + 1);
		}
		right++;
		if (right < n) sum += arr[right];
	}
	return len;
}

int main(int argc, char const *argv[])
{
	int n, sum;
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "Enter the " << n << "Elements of the array: ";
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		arr.push_back(data);
	}
	cout << "Enter the sum of the subarray you want to find: ";
	cin >> sum;
	// int ans = solution1(arr, n, sum);
	// int ans = solution2(arr, n, sum);
	// int ans = solution3(arr, n, sum);
	int ans = solution3(arr, n, sum);

	cout << "\nMaximum length of Subarray of sum " << sum << " is " << ans;
	return 0;
}