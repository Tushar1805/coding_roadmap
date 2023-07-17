//! Largest subarray with 0 sum

// Given an array having both positive and negative integers.
// The task is to compute the length of the largest subarray with sum 0.

// Example 1:

// Input:
// N = 8
// A[] = {15,-2,2,-8,1,7,10,23}
// Output: 5
// Explanation: The largest subarray with
// sum 0 will be -2 2 -8 1 7.
// Your Task:
// You just have to complete the function maxLen() which takes two arguments
// an array A and n, where n is the size of the array A and returns the
// length of the largest subarray with 0 sum.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 105
// -1000 <= A[i] <= 1000, for each valid i

#include<bits/stdc++.h>
using namespace std;

//! bruete Force
// int maxLen(vector<int>&a, int n)
// {
// 	int len = 0;
// 	for (int i = 0; i < n; ++i)
// 	{
// 		long long int sum = 0;
// 		for (int j = i; j < n; ++j)
// 		{
// 			sum += a[j];
// 			if (sum == 0) {
// 				len = max(j - i + 1, len);
// 			}
// 		}
// 	}
// 	return len;
// }

//! Optimized approach
int maxLen(vector<int>&a, int n)
{
	map<int, int> preSumMap;
	int len = 0;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum == 0) {
			len = max(len, i + 1);
		}
		long long rem = sum - 0;
		if (preSumMap.find(sum) != preSumMap.end()) {
			int l = i - preSumMap[rem];
			len = max(len, l);
		}
		if (preSumMap.find(sum) == preSumMap.end()) {
			preSumMap[sum] = i;
		}
	}
	return len;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	vector<int> a;
	cout << "\nEnter the elements of array: ";
	for (int i = 0; i < n; ++i)
	{
		int data;
		cin >> data;
		a.push_back(data);
	}
	int ans = maxLen(a, n);
	cout << "Subarray count: " << ans;
	return 0;
}