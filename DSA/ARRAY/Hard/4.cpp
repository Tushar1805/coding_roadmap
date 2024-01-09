// 4 Sum problem
#include<bits/stdc++.h>
using namespace std;

// 1 0 -1 0 -2 2

// Brute Force: Tc - O(n^4 * log(no. of unique quads)), SC - O(no. of unique quads)
vector<vector<int>> solution1(vector<int> arr, int n, int target) {
	set<vector<int>> st;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				for (int l = k + 1; l < n; l++) {
					long long sum = arr[i] + arr[j];
					sum += arr[k];
					sum += arr[l];
					if (sum == target) {
						vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
						sort(temp.begin(), temp.end());
						st.insert(temp);
					}
				}
			}
		}
	}
	vector<vector<int>> ans(st.begin(), st.end());
	return ans;
}

// Better Approach: Using 3 loops and hashing
// TC - O(n^3) O(log m) where m - no. of variables in set(can varry)
// SC - O(n) + O(2 * no. of quads)
vector<vector<int>> solution2(vector<int> arr, int n, int target) {
	set<vector<int>> st;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			set<long long> hashset;
			for (int k = j + 1; k < n; k++) {
				long long sum = arr[i];
				sum += arr[j];
				sum += arr[k];
				long long l = target - (sum);
				if (hashset.find(l) != hashset.end()) {
					vector<int> temp = {arr[i], arr[j], arr[k], (int) l};
					sort(temp.begin(), temp.end());
					st.insert(temp);
				}
				hashset.insert(arr[k]);
			}
		}
	}
	vector<vector<int>> ans(st.begin(), st.end());
	return ans;
}

// Optimal Approach: Two pointer approach
// TC - O(n logn) + O(n^3), SC - O(no. of unique elements) - to store answer
vector<vector<int>> solution3(vector<int> arr, int n) {
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		if (i > 0 && arr[i] == arr[i - 1]) continue;
		for (int j = i + 1; j < n; j++) {
			if (j > i + 1 && arr[j] == arr[j - 1]) continue;
			int k = j + 1;
			int l = n - 1;
			while (j < k) {
				long long sum = arr[i];
				sum += arr[j];
				sum += arr[k];
				sum += arr[l];
				if (sum < 0) k++;
				else if (sum > 0) l--;
				else {
					vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
					ans.push_back(temp);
					k++;
					l--;
					while (k < l && arr[k] == arr[k - 1]) k++;
					while (k < l && arr[l] == arr[l + 1]) l--;
				}
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
	int target;
	cout << "Enter the target sum to find: ";
	cin >> target;

	// Brute Force
	// vector<vector<int>> ans = solution1(arr, n, target);

	// Better Approach
	vector<vector<int>> ans = solution2(arr, n, target);

	// Optimal Approach
	// vector<vector<int>> ans = solution3(arr, n);

	cout << "4 Sum quadruplets: \n";
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}