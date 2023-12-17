#include<bits/stdc++.h>
using namespace std;

// Naive Approach is to sort the array with any of the sorting algorithm

vector<int> solution1(vector<int> arr, int n) {
	vector<int> ans;
	int cnt0 = 0, cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) cnt0++;
		else if (arr[i] == 1) cnt1++;
		else  cnt2++;
	}
	for (int i = 0; i < cnt0; i++)
		ans.push_back(0);

	for (int i = 0; i < cnt1; i++)
		ans.push_back(1);

	for (int i = 0; i < cnt2; i++)
		ans.push_back(2);

	return ans;
}

void solution2(vector<int> &arr, int n) {
	int low = 0;
	int mid = 0;
	int high = n - 1;

	while (mid <= high) {
		if (arr[mid] == 0) {
			swap(arr[mid], arr[low]);
			low++;
			mid++;
		} else if (arr[mid] == 2) {
			swap(arr[mid], arr[high]);
			high--;
		} else {
			mid++;
		}
	}
}

void display(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
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

	// Bruete Force approach: TC - O(2N), SC - O(N)
	// vector<int> ans = solution1(arr, n);

	// Optimal approach: Dutch National Flag Algorithm
	// TC - O(N) SC - O(1)
	solution2(arr, n);
	cout << "Sorted Array: ";
	display(arr);
	return 0;
}