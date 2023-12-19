#include<bits/stdc++.h>
using namespace std;

// Input: {-2 -3 4 -1 -2 1 5 -3}
// Output: 7

// Extream Brute Force: O(N^3)
int solution1(vector<int> arr, int n) {
	int maxi = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int sum = 0;
			for (int k = i; k < j; k++) {
				sum += arr[k];
			}
			maxi = max(maxi, sum);
		}
	}
	return maxi;
}

// Better Approach: O(N^2)
int solution2(vector<int> arr, int n) {
	int maxi = INT_MIN;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += arr[j];
			maxi = max(maxi, sum);
		}
	}
	return maxi;
}

// Optimized Approach: O(N)
int solution3(vector<int> arr, int n) {
	int maxi = INT_MIN;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		maxi = max(sum, maxi);
		if (sum < 0) {
			sum = 0;
		}
	}
	if (maxi < 0) return 0;
	return maxi;
}

// Follow Up: Find the elements of the maximum subarray sum
vector<int> solution(vector<int> arr, int n) {
	vector<int> subarray;
	int maxi = INT_MIN, sum = 0;
	int arrStart = -1, arrEnd = -1;
	int start = -1;
	for (int i = 0; i < n; i++) {
		if (sum == 0) start = i;

		sum += arr[i];
		maxi = max(maxi, sum);
		arrStart = start;
		arrEnd = i;

		if (sum < 0) sum = 0;
	}

	for (int i = arrStart; i < arrEnd; i++) {
		subarray.push_back(arr[i]);
	}
	return subarray;
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
	vector<int> subarray = solution(arr, n);

	cout << "Maximum subarray sum: " << ans << endl;
	cout << "Sub array elements: ";
	for (int i = 0; i < subarray.size(); i++) {
		cout << subarray[i] << " ";
	}

	return 0;
}