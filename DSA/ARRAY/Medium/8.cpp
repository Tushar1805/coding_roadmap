#include<bits/stdc++.h>
using namespace std;

// Input: arr[] = {2, 1, 5, 4, 3, 0, 0}
// output: 2 3 0 0 1 4 5


//! Brute Force approach: TC - O(N! * N)
void solution1(vector<int>& arr, int n) {
	// Step 1 - Generate all the permutations in sorted order
	// Step 2 - Linearlly search in the array for the given permutation
	// Step 3 - Return the next index of the found permutation
}

//! Better Approach: Use STL function next_permutation
// TC - worst case O(n)
void solution2(vector<int> &arr, int n) {
	next_permutation(arr.begin(), arr.end());
}

//! Optimized splution: Withoud using STL
// TC - O(3N)
void solution3(vector<int> &arr, int n) {
	int ind = -1;
	// Step 1: Find the break point
	// where arr[i] < arr[i+1] from end of the array

	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] < arr[i + 1]) {
			ind = i;
			break;
		}
	}

	// Step 2: Now if the ind = -1 means no break point and
	// We just have to return the reverse of the arr given

	if (ind == -1) {
		reverse(arr.begin(), arr.end());
	} else {
		// Step 3: if we have a break point we  need to find just greater
		// element than the arr[ind] from right of the array

		for (int i = n - 1; i >= ind; i--) {
			if (arr[ind] < arr[i]) {
				swap(arr[ind], arr[i]);
				break;
			}
		}

		// Step 4: Now we need smallest elments from the remaining array
		// so just reverse the remaining elements we will get the smallest elements
		reverse(arr.begin() + ind + 1, arr.end());
	}
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

	solution3(arr, n);
	cout << "Next Permitation: ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	return 0;
}