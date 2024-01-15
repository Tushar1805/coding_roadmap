// Reverse Pairs
#include<bits/stdc++.h>
using namespace std;

// Brute Force: TC - O(n^2), SC - O(1)
int solution1(vector<int> arr, int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > 2 * 1LL * arr[j]) cnt++;

	return cnt;
}

// Optimal Approach: Merge Sort
// TC - O(log n + n 2n log n), SC - O(n)
int cnt = 0;
void merge(vector<int> &arr, int low, int mid, int high) {

	int j = mid + 1;
	for (int i = low; i <= mid; i++) {
		while (j <= high && arr[i] > 2 * 1LL * arr[j])
			j++;
		cnt += j - (mid + 1);
	}
	vector<int> temp; // temporary array
	int left = low;      // starting index of left half of arr
	int right = mid + 1;   // starting index of right half of arr

	//storing elements in the temporary array in a sorted manner//
	while (left <= mid && right <= high) {

		if (arr[left] <= arr[right]) {
			temp.push_back(arr[left]);
			left++;
		}
		else {
			temp.push_back(arr[right]);
			right++;
		}
	}

	// if elements on the left half are still left //

	while (left <= mid) {
		temp.push_back(arr[left]);
		left++;
	}

	//  if elements on the right half are still left //
	while (right <= high) {
		temp.push_back(arr[right]);
		right++;
	}

	// transfering all elements from temporary to arr //
	for (int i = low; i <= high; i++) {
		arr[i] = temp[i - low];
	}
}

void mergeSort(vector<int> &arr, int low, int high) {
	if (low >= high) return;
	int mid = (low + high) / 2 ;
	mergeSort(arr, low, mid);  // left half
	mergeSort(arr, mid + 1, high); // right half
	merge(arr, low, mid, high);  // merging sorted halves
}

int solution2(vector<int> arr, int n) {
	mergeSort(arr, 0, n - 1);
	return cnt;
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
	int ans;
	// ans = solution1(arr, n);

	// Optimal Approach: Merge sort
	ans = solution2(arr, n);

	cout << "Number of Reverse Pairs: " << ans << endl;
	return 0;
}