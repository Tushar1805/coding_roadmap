// Merge overlapping subintervals

#include<bits/stdc++.h>
using namespace std;

// Brute Force Solution
// TC - O(n log n) + o(2n), SC - O(n)
vector<vector<int>> solution1(vector<vector<int>> arr, int n) {
	vector<vector<int>> ans;
	// Sort the array first
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		int start = arr[i][0];
		int end = arr[i][1];
		if (!ans.empty() && end <= ans.back()[1]) continue;
		for (int j = i + 1; j < n; j++) {
			if (arr[j][0] <= end) {
				end = max(end, arr[j][1]);
			} else {
				break;
			}
		}
		ans.push_back({start, end});
	}
	return ans;
}

// Better Approach
// TC - O(n logn) + O(n) , SC - O(n)
vector<vector<int>> solution2(vector<vector<int>> arr, int n) {
	vector<vector<int>> ans;
	// Sort the array first
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		if (ans.empty() || arr[i][0] > ans.back()[1]) {
			ans.push_back(arr[i]);
		} else {
			ans.back()[1] = max(ans.back()[1], arr[i][1]);
		}
	}
	return ans;
}


int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the number of intervals present: ";
	cin >> n;
	vector<vector<int>> arr;
	cout << "Enter the " << n << " intervals " << endl;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		cout << i + 1 << " Interval: ";
		for (int j = 0; j < 2; j++) {
			int data;
			cin >> data;
			temp.push_back(data);
		}
		arr.push_back(temp);
	}

	// Brute Force
	// vector<vector<int>> ans = solution1(arr, n);

	// Optimal Approach
	vector<vector<int>> ans = solution2(arr, n);
	cout << "Merged Intervals: " << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << "Interval " << i + 1 << ": ";
		for (int j = 0; j < 2; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}