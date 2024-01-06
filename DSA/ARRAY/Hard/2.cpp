// Majority Element (n / 3)
#include<bits/stdc++.h>
using namespace std;

vector<int> solution1(vector<int> arr, int n) {
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (ans.size() == 0 || ans[0] != arr[i]) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (arr[j] == arr[i]) cnt++;
			}
			if (cnt > n / 3) ans.push_back(arr[i]);
		}
		if (ans.size() == 2) break;
	}
	return ans;
}

// Using Hashmap: TC - O(N), SC - O(N)
vector<int> solution2(vector<int> arr, int n) {
	vector<int> ans;
	unordered_map<int, int> m;
	int mini = (n / 3) + 1;
	for (int i = 0; i < n; i++) {
		m[arr[i]]++;
		if (m[arr[i]] == mini) ans.push_back(arr[i]);
		if (ans.size() == 2) break;
	}
	return ans;
}

// Using Moore's voting algorithm for 2 candidates
// TC - O(N), SC - O(1)
vector<int> solution3(vector<int> arr, int n) {
	int cnt1 = 0, cnt2 = 0, el1 = INT_MIN, el2 = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (cnt1 == 0 && el2 != arr[i]) {
			cnt1 = 1;
			el1 = arr[i];
		} else if (cnt2 == 0 && el1 != arr[i]) {
			cnt2 = 1;
			el2 = arr[i];
		} else if (arr[i] == el1) cnt1++;
		else if (arr[i] == el2) cnt2++;
	}

	int mini = (n / 3) + 1;
	vector<int> ans;
	// Verify the candidates to be majority elements
	cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == el1) cnt1++;
		else if (arr[i] == el2) cnt2++;
	}
	if (cnt1 >= mini) ans.push_back(el1);
	if (cnt2 >= mini) ans.push_back(el2);
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

	// Brute force: TC - O(N^2)
	// vector<int> ans = solution1(arr, n);

	// Better Approach
	// vector<int> ans = solution2(arr, n);

	// Optimal Approach
	vector<int> ans = solution3(arr, n);

	cout << "Majority Elements: ";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}