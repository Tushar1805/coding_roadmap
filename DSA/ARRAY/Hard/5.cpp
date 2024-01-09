// Longest subarray with zero sum
#include<bits/stdc++.h>
using namespace std;

int solution1(vector<int> arr, int n){
	int sum = 0;
	int maxLen = 0;
	unordered_map<int, int> m;
	for (int i = 0; i < n ; i++) {
		sum += arr[i];
		if (sum == 0) {
			maxLen = max(maxLen, i + 1);
		} else if (m.find(sum) != m.end()) {
			maxLen = max(maxLen, i - m[sum]);
		} else {
			m[sum] = i;
		}
	}
	return maxLen;
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
	// Optimal Approach
	int ans = solution1(arr, n);
	cout << "Length of longest subarray with zero sum: " << ans;
	return 0;
}