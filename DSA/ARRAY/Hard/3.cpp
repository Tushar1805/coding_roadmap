// 3Sum Problem
#include<bits/stdc++.h>
using namespace std;

// Brute Force: Tc - O(n^3 * log(no. of unique triplets)), SC - O(2 * no. of unique triplets)
vector<vector<int>> solution1(vector<int> arr, int n) {
	set<vector<int>> st;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (arr[i] + arr[j] + arr[k] == 0) {
					vector<int> temp = {arr[i], arr[j], arr[k]};
					sort(temp.begin(), temp.end());
					st.insert(temp);
				}
			}
		}
	}
	vector<vector<int>> ans(st.begin(), st.end());
	return ans;
}

// Better Approach: Using two loops and hashing
vector<vector<int>> solution2(vector<int> arr, int n) {
	set<vector<int>> st;
	for (int i = 0; i < n; i++) {
		set<int> hashset;
		for (int j = i + 1; j < n; j++) {
			int k = -(arr[i] + arr[j]);
			if (hashset.find(k) != hashset.end()) {
				vector<int> temp = {arr[i], arr[j], k};
				sort(temp.begin(), temp.end());
				st.insert(temp);
			}
			hashset.insert(arr[j]);
		}
	}
	vector<vector<int>> ans(st.begin(), st.end());
	return ans;
}

// Optimal Approach: Two pointer approach
// TC - O(n logn) + O(n^2), SC - O(no. of unique elements)
vector<vector<int>> solution3(vector<int> arr, int n) {
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		if (i > 0 && arr[i] == arr[i - 1]) continue;
		int j = i + 1;
		int k = n - 1;
		while (j < k) {
			int sum = arr[i] + arr[j] + arr[k];
			if (sum < 0) j++;
			else if (sum > 0) k--;
			else {
				vector<int> temp = {arr[i], arr[j], arr[k]};
				ans.push_back(temp);
				j++;
				k--;
				while (j < k && arr[j] == arr[j - 1]) j++;
				while (j < k && arr[k] == arr[k + 1]) k--;
			}
		}
	}
	return ans;
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

	// vector<vector<int>> ans = solution1(arr, n);

	// Better Approach
	// vector<vector<int>> ans = solution2(arr, n);

	// Optimal Approach
	vector<vector<int>> ans = solution3(arr, n);

	cout << "3 Sum triplets: \n";
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}