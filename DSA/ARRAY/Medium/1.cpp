#include<bits/stdc++.h>
using namespace std;

vector<int> solution1(vector<int> arr, int n, int target) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] + arr[j] == target) {
				return {i, j};
			}
		}
	}
	// Pair not found
	return { -1, -1};
}

vector<int> solution2(vector<int> arr, int n, int target) {
	unordered_map<int, int> mpp;
	for (int i = 0; i < n; i++) {
		if (mpp.find(target - arr[i]) == mpp.end()) {
			mpp[arr[i]] = i;
		} else {
			return {mpp[target - arr[i]], i};
		}
	}
	return { -1, -1};
}

int solution3(vector<int> arr, int n, int target){
	sort(arr.begin(), arr.end());
	int left = 0;
	int right = n - 1;
	while (left < right) {
		if (arr[left] + arr[right] == target) {
			return 1;
		} else if ((arr[left] + arr[right]) > target) {
			right--;
		} else {
			left++;
		}
	}
	return -1;
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
	cout << "Enter the sum for which you have to find 2 sum: ";
	cin >> target;
	// Bruete force approch: for every element check the sum for every other element in the array
	// vector<int> ans = solution1(arr, n, target);

	// Better Approach: using Hashmap
	vector<int> ans = solution2(arr, n, target);

	// Optimized solution only in case of where we don't have to
	// return the indexes of the pair
	int val = solution3(arr, n, target);
	if (val == 1) cout << "Pair with target exits" << endl;
	else cout << "Not found" << endl;
	if (ans[0] == -1) {
		cout << "No pair Found" << endl;
	} else {
		cout << "Pair found at indexes: " << ans[0] << " and " << ans[1];
	}
	return 0;
}