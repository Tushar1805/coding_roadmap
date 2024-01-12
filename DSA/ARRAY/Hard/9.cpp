// Merge two sorted arrays without extra space

#include<bits/stdc++.h>
using namespace std;

// Brute Force: Using extra space
// TC - O(n+m) + O(n+m)
// SC - O(n+m)
void solution1(vector<int> &arr1, vector<int> &arr2, int n, int m) {
	vector<int> ans(n + m);
	int left = 0, right = 0, idx = 0;
	while (left < n && right < m) {
		if (arr1[left] <= arr2[right]) ans[idx++] = arr1[left++];
		else ans[idx++] = arr2[right++];
	}
	while (left < n) ans[idx++] = arr1[left++];
	while (right < m) ans[idx++] = arr2[right++];
	for (int i = 0; i < n + m; i++) {
		if (i < n) arr1[i] = ans[i];
		else arr2[i - n] = ans[i];
	}
}

// Optimal Approach 1: Two pointer approach
// TC - O(min(n, m)) + O(n log n) + O(m log m), SC - O(1s)
void solution2(vector<int> &arr1, vector<int> &arr2, int n, int m) {
	int i = n - 1, j = 0;
	while (i >= 0 && j < m) {
		if (arr1[i] > arr2[j]) swap(arr1[i--], arr2[j++]);
		else break;
	}
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
}

// Optimal Approach 2: Gap Method (shell sort technique)
// TC - O(log2(n+m)) + O(n+m)
void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int ind1, int ind2) {
	if (arr1[ind1] > arr2[ind2]) {
		swap(arr1[ind1], arr2[ind2]);
	}
}
void solution3(vector<int> &arr1, vector<int> &arr2, int n, int m) {
	int len = n + m;

	// Initial gap:
	int gap = (len / 2) + (len % 2);

	while (gap > 0) {
		// Place 2 pointers:
		int left = 0;
		int right = left + gap;
		while (right < len) {
			// case 1: left in arr1[]
			//and right in arr2[]:
			if (left < n && right >= n) {
				swapIfGreater(arr1, arr2, left, right - n);
			}
			// case 2: both pointers in arr2[]:
			else if (left >= n) {
				swapIfGreater(arr2, arr2, left - n, right - n);
			}
			// case 3: both pointers in arr1[]:
			else {
				swapIfGreater(arr1, arr1, left, right);
			}
			left++, right++;
		}
		// break if iteration gap=1 is completed:
		if (gap == 1) break;

		// Otherwise, calculate new gap:
		gap = (gap / 2) + (gap % 2);
	}
}

void display(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	int n, m;
	cout << "Enter the size of the array 1 & array 2: ";
	cin >> n >> m;
	vector<int> arr1, arr2;
	cout << "Enter the " << n << " elements of the array 1: ";
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		arr1.push_back(data);
	}
	cout << "Enter the " << m << " elements of the array 2: ";
	for (int i = 0; i < m; i++) {
		int data;
		cin >> data;
		arr2.push_back(data);
	}

	// Brute Force
	// solution1(arr1, arr2, n, m);

	// Optimal Approach 1
	// solution2(arr1, arr2, n, m);

	// Optimal Approach 2: Gap Method
	solution3(arr1, arr2, n, m);
	cout << "Merged Arrays \n";
	cout << "Array 1: ";
	display(arr1);
	cout << "Array 2: ";
	display(arr2);
	return 0;
}

