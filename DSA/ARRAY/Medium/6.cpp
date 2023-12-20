// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and
// sell on day 5 (price = 6), profit = 6-1 = 5.

// Note: That buying on day 2 and selling on day 1
// is not allowed because you must buy before
// you sell.

#include<bits/stdc++.h>
using namespace std;

// Bruete Force Approach: O(N^2)
int solution1(vector<int> arr, int n) {
	int maxi = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] > arr[i]) {
				int profit = arr[j] - arr[i];
				maxi = max(maxi, profit);
			}
		}
	}
	return maxi;
}

// Optimized Approach: O(N)
int solution2(vector<int> arr, int n) {
	int profit = 0;
	int mini = arr[0];
	int cost;
	for (int i = 1; i < n; i++) {
		cost = arr[i] - mini;
		profit = max(profit, cost);
		mini = min(mini, arr[i]);
	}
	return profit;
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

	// int ans = solution1(arr, n);
	int ans = solution2(arr, n);

	cout << "Maximum Profit: " << ans << endl;

	return 0;
}