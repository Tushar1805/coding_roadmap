
// Algorithm :
// 1. Iterate through the array from the beginning to the end.
// 2. For each element in the array:
// 		If the count is 0, set the current element as the candidate.
// 		If the current element is the same as the candidate, increment the count.
// 		If the current element is different from the candidate, decrement the count.
// 3. After the first pass, the candidate is the potential majority element.
// 4. Reset the count to 0.
// 5. Iterate through the array again.
// 6. Count the occurrences of the candidate element.
// 7. If the candidate occurs more than half of the time, it is the majority element.
// 8. If the candidate occurs more than half of the time, return it as the majority element.
// 9. If the candidate occurs less than or equal to half of the time, there is no majority element.

#include<bits/stdc++.h>
using namespace std;

// Bruete Force Approach: TC - O(n^2)
int solution1(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j] == arr[i]) cnt++;
		}
		if (cnt > n / 2) return arr[i];
	}
	return -1;
}

// Better Approach: TC - O(N log N) + O(N), SC - O(N) in case of all unique elements
int solution2(int arr[], int n) {
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		m[arr[i]]++;
	}
	for (auto i : m) {
		if (i.second > n / 2) return i.first;
	}
	return -1;
}

// Optimized Solution: TC - O(N), SC - O(1) || Moore's Voting Algorithm
int solution3(int arr[], int n) {
	int candidate = 0;
	int count = 0;

	// Step 1 - Traverse all elements to find the candidate
	for (int i = 0; i < n; i++) {
		if (count == 0) {
			candidate = arr[i];
		}
		count += (candidate == arr[i]) ? 1 : -1;
	}

	// Step 2 - verify the candidate
	count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == candidate) {
			count++;
		}
	}

	// Step 3 - return majority element

	if (count > n / 2) {
		return candidate;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	int arr[n];
	cout << "Enter the " << n << " elements of array: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// int ans = solution1(arr, n);
	// int ans = solution2(arr, n);
	int ans = solution3(arr, n);

	cout << "Majority Element: " << ans;
	return 0;
}