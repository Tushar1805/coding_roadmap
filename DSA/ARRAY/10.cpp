//! Boyer Moore's votting algorith || Majority element

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

int majorityElement(int n, int arr[]) {
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

	if (count >= n / 2) {
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
	int ans = majorityElement(n, arr);
	cout << "Majority Element: " << ans;
	return 0;
}