// Count the subsequences with sum equal to k

#include<bits/stdc++.h>
using namespace std;

int countSub(int i, vector<int> &arr, int k, int sum) {
	if (i == arr.size()) {
		if (sum == k) {
			return 1;
		}
		return 0;
	}

	return (countSub(i + 1, arr, k, sum + arr[i]) + countSub(i + 1, arr, k, sum));
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
	int k;
	cout << "Enter the target sum: ";
	cin >> k;
	int ans = countSub(0, arr, k, 0);
	cout << "There are " << ans << " subseequences with the given sum " << k;
	return 0;
}