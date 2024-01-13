// Find the repeating and missing number

#include<bits/stdc++.h>
using namespace std;

// Brute force: TC - O(n^2), SC - O(1)
vector<int> solution1(vector<int> arr, int n) {
	int repeating = -1, missing = -1;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j] == i) cnt++;
		}
		if (cnt == 2) repeating = i;
		else if (cnt == 0) missing = i;
		if (repeating != -1 && missing != -1) break;
	}
	return {repeating, missing};
}

// Better Approach: Hashing
// TC - O(2n), SC - O(n)
vector<int> solution2(vector<int> arr, int n) {
	vector<int> hash(n + 1, 0);
	for (int i = 0; i < n; i++) {
		hash[arr[i]]++;
	}
	int repeating = -1, missing = -1;
	for (int i = 1; i <= n; i++) {
		if (hash[i] == 0) missing = i;
		else if (hash[i] == 2) repeating = i;
		if (repeating != -1 && missing != -1) break;
	}
	return {repeating, missing};
}

// Optimal Approach: Mathematical approach
// TC - O(n), SC - O(1)
vector<int> solution3(vector<int> arr, int n) {
	long long s = 0; // sum of all numbers in array
	long long s2 = 0; // sum of all numbser's square in array
	long long sn = (n * (n + 1)) / 2; // Sum of n natural numbers
	long long sn2 = (n * (n + 1) * (2 * n + 1)) / 6; // sum of squares of n natural number
	for (int i = 0; i < n; i++) {
		s += arr[i];
		s2 += ((long long)arr[i] * (long long)arr[i]);
	}
	long long val1 = s - sn; // x - y
	long long val2 = s2 - sn2;
	val2 = val2 / val1; // x + y
	long long x = (val1 + val2) / 2;
	long long y = x - val1;
	return {(int)x, (int)y};
}

// Optimal Approach 2: Using XOR operation
// TC - O(3n), SC - O(1)
vector<int> solution4(vector<int> arr, int n) {
	int xr = 0;
	for (int i = 0; i < n; i++) {
		xr ^= arr[i];
		xr ^= i + 1;
	}
	// We need to find the differentiating bit
	// int number =  xr & ~(xr-1) // Short cut method
	int bitNo = 0;
	while (1) {
		if ((xr & (1 << bitNo)) != 0) {
			break;
		}
		bitNo++;
	}

	// club and xor the array elements
	int one = 0;
	int zero = 0;
	for (int i = 0; i < n; i++) {
		if ((arr[i] & (1 << bitNo)) != 0) one ^= arr[i]; // oneth club
		else zero ^= arr[i]; // zeroth club
		if ((i + 1 & (1 << bitNo)) != 0) one ^= i + 1;
		else zero ^= i + 1;
	}

	// verify which one is repeating and missing
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == zero) cnt++;
	}
	if (cnt == 2) return {zero, one};
	return {one, zero};
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

	// Naive Brute Force
	// vector<int> ans = solution1(arr, n);

	// Better Approach
	// vector<int> ans = solution2(arr, n);

	// Optimal Approach
	// vector<int> ans = solution3(arr, n);

	// Optimal Approach: Using XOR
	vector<int> ans = solution4(arr, n);

	cout << "Repeating Number: " << ans[0] << endl;
	cout << "Missing Number: " << ans[1] << endl;
	return 0;
}
