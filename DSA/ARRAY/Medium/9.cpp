#include<bits/stdc++.h>
using namespace std;

// Input:
//  arr = [10, 22, 12, 3, 0, 6]
// Output:
//  22 12 6


// Brute force approach: TC - O(N^N), SC - O(N)
vector<int> solution1(vector<int> arr, int n) {
	vector<int> leaders;
	for (int i = 0; i < n; i++) {
		int flag = 1;
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) {
				flag = -1;
				break;
			}
		}
		if (flag == 1) {
			leaders.push_back(arr[i]);
		}
	}
	return leaders;
}

// Optimized approach
vector<int> solution2(vector<int> arr, int n) {
	vector<int> leaders;
	leaders.push_back(arr[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		if (leaders.back() < arr[i]) leaders.push_back(arr[i]);

	}
	return leaders;
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

	// vector<int> ans = solution1(arr, n);
	// cout << "Leaders in array: ";
	// for (int i = 0; i < ans.size(); ++i)
	// {
	// 	cout << ans[i] << " ";
	// }

	vector<int> ans = solution2(arr, n);
	// For solution 2 print elements in reverse order
	cout << "Leaders in array: ";
	for (int i = ans.size() - 1; i >= 0; --i)
	{
		cout << ans[i] << " ";
	}
	return 0;
}