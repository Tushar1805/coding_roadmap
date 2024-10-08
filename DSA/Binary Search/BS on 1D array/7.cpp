#include<bits/stdc++.h>
using namespace std;

int countOccurence(vector<int> &arr, int n, int x) {
	int l = 0, r = n - 1;
	int mid;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (arr[mid] == x) {
			if (arr[l] == x && arr[r] == x) {
				return (r - l) + 1;
			}
			if (arr[l] != x)
				l++;
			if (arr[r] != x)
				r--;
		} else if (arr[mid] < x) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	long long n;
	cout << "Enter the size of the array: ";
	cin >> n;

	vector<int> arr;
	cout << "Enter elements of the array: ";
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		arr.push_back(data);
	}

	int target;
	cout << "Enter the target to be searched: ";
	cin >> target;

	cout << endl << "Given array" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	int ans = countOccurence(arr, n, target);

	cout << endl << "count occurence = " <<  ans;

	return 0;
}