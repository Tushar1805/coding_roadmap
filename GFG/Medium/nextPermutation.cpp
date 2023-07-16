//! Next Permutation

// Implement the next permutation, which rearranges the list of numbers
// into Lexicographically next greater permutation of list of numbers.
// If such arrangement is not possible, it must be rearranged to the lowest possible order
// i.e. sorted in an ascending order. You are given an list of numbers arr[ ] of size N.

// Example 1:

// Input: N = 6
// arr = {1, 2, 3, 6, 5, 4}
// Output: {1, 2, 4, 3, 5, 6}
// Explaination: The next permutation of the
// given array is {1, 2, 4, 3, 5, 6}.
// Example 2:

// Input: N = 3
// arr = {3, 2, 1}
// Output: {1, 2, 3}
// Explaination: As arr[] is the last
// permutation. So, the next permutation
// is the lowest one.
// Your Task:
// You do not need to read input or print anything.
// Your task is to complete the function nextPermutation()
// which takes N and arr[ ] as input parameters and returns a
// list of numbers containing the next permutation.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 10000

#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(int N, vector<int> arr) {
	// Using STL, TC - O(N), SC - O(1)
	// next_permutation(arr.begin(), arr.end());
	// return arr;

	// Using logic, TC - O(N), SC - O(1)
	int ind = -1;
	for (int i = N - 2; i >= 0; i--) {
		if (arr[i] < arr[i + 1]) {
			ind = i;
			break;
		}
	}
	if (ind == -1) {
		reverse(arr.begin(), arr.end());
		return arr;
	}
	for (int i = N - 1; i >= ind; i--) {
		if (arr[i] > arr[ind]) {
			swap(arr[i], arr[ind]);
			break;
		}
	}
	reverse(arr.begin() + ind + 1, arr.end());
	return arr;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the Size of the array: ";
	cin >> n;
	cout << "\nEnter the " << n << " elements of the array: ";
	vector<int> arr;
	for (int i = 0; i < n; ++i)
	{
		int data;
		cin >> data;
		arr.push_back(data);
	}
	vector<int> ans = nextPermutation(n, arr);
	cout << "\nNext Permitation: ";
	for (int i = 0; i < n; ++i)
	{
		cout << ans[i] << " ";
	}
	return 0;
}