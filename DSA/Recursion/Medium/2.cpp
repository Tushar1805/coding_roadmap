// Printing subsequences whose sum is k

#include<bits/stdc++.h>
using namespace std;

void printSubK(int i, vector<int>&arr, int sum, int k, vector<int>sub,  vector<vector<int>> &ans) {
	if (i == arr.size()) {
		if (sum == k) {
			ans.push_back(sub);
		}
		return;
	}
	sub.push_back(arr[i]);
	sum += arr[i];
	// Take
	printSubK(i + 1, arr, sum, k, sub, ans);
	sub.pop_back();
	sum -= arr[i];
	// Not Take
	printSubK(i + 1, arr, sum, k, sub, ans);
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
	vector<vector<int>> ans;
	vector<int> temp;
	printSubK(0, arr, 0, k, temp, ans);
	cout << "All subsequences with the given sum " << k << " are: \n";
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}