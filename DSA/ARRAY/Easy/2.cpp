#include<bits/stdc++.h>
using namespace std;


vector<int> betterApproach(vector<int> arr, int n) {
	int small = INT_MAX, large = INT_MIN;
	int seconde_small = INT_MAX, second_large = INT_MIN;

	// First loop to find the largest and smallest
	for (int i = 0; i < n; i++) {
		if (arr[i] > large) {
			large = arr[i];
		}
		if (arr[i] < small) {
			small = arr[i];
		}
	}

	// Second loop to find the second largest and the second smallest element in the array
	for (int i = 0; i < n; i++) {
		if (arr[i] >= second_large && arr[i] < large) {
			second_large = arr[i];
		}
		if (arr[i] <= seconde_small && arr[i] > small) {
			seconde_small = arr[i];
		}
	}
	return {seconde_small, second_large};
}

vector<int> optimalApproach(vector<int> arr, int n) {
	int small = INT_MAX, large = INT_MIN;
	int seconde_small = INT_MAX, second_large = INT_MIN;

	// Second largest
	for (int i = 0; i < n; i++) {
		// Logic for the second largest
		if (arr[i] > large) {
			second_large = large;
			large = arr[i];
		} else if (arr[i] > second_large && arr[i] != large) {
			second_large = arr[i];
		}

		// Logic for the second smallest element in the array
		if (arr[i] < small) {
			seconde_small = small;
			small = arr[i];
		} else if (arr[i] < seconde_small && arr[i] != small) {
			seconde_small = arr[i];
		}
	}
	return {seconde_small, second_large};
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	if (n < 2) return 0;
	cout << "Enter the " << n << " elements of the array: ";
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		arr.push_back(data);
	}

	//! Bruete force to find the second largest element in the array
	// Sort the array and the return the second last element for second largest
	// return second element for second smallest

	//! Work only for non duplicate elements
	// sort(arr.begin(), arr.end());
	// cout << "Second Largest element of the array: " << arr[n - 2] << endl;
	// cout << "Second Smallest element of the array: " << arr[1] << endl;

	//! Better approach
	// Traverse and found largest and smallest
	// Then again traverse and found element which is just smaller than the largest
	// And element which is just greater than the smallest

	// vector<int> ans = betterApproach(arr, n);

	//! Optimal approach
	// Traverse and update in single loop using better logic

	vector<int> ans = optimalApproach(arr, n);

	cout << "Second Largest element of the array: " << ans[1] << endl;
	cout << "Second Smallest element of the array: " << ans[0] << endl;

	return 0;
}