//! Count the subarrays having product less than k

// Given an array of positive numbers,
// the task is to find the number of possible contiguous subarrays having product less than a given number k.

// Example 1:

// Input :
// n = 4, k = 10
// a[] = {1, 2, 3, 4}
// Output :
// 7
// Explanation:
// The contiguous subarrays are {1}, {2}, {3}, {4}
// {1, 2}, {1, 2, 3} and {2, 3} whose count is 7.
// Example 2:

// Input:
// n = 7 , k = 100
// a[] = {1, 9, 2, 8, 6, 4, 3}
// Output:
// 16
// Your Task:
// You don't need to read input or print anything.
// Your task is to complete the function countSubArrayProductLessThanK()
// which takes the array a[], its size n and an integer k as inputs and returns the count of required subarrays.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<=n<=106
// 1<=k<=1015
// 1<=a[i]<=105

#include<bits/stdc++.h>
using namespace std;

//! Brute Force Method TC = O[n^2] SC = O[1]
// int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
// 	int ans = 0;
// 	long long int mul;
// 	for (int i = 0; i < n; i++) {
// 		mul = a[i];
// 		for (int j = i + 1; j < n; j++) {
// 			mul *= a[j];
// 			cout << mul << endl;
// 			if (mul < k) {
// 				ans++;
// 			}
// 		}
// 		if (a[i] < k) {
// 			ans++;
// 		}
// 	}
// 	return ans;
// }

//! Optimized approach TC = O[n] SC = O[1]
int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
	if (k <= 1) return 0;
	int count = 0, left = 0, right = 0;
	long long int mul = 1;
	while (right < n) {
		mul *= a[right];
		while (mul >= k) {
			mul /= a[left];
			left++;
		}
		count += (right - left) + 1;
		right++;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int n, k;
	vector<int> a;
	cout << "Enter the size of the array: ";
	cin >> n;
	cout << "\nEnter the " << n << " elements of the array: ";
	for (int i = 0; i < n; ++i)
	{
		int data;
		cin >> data;
		a.push_back(data);
	}
	cout << "\nEnter the value of prokuct k: ";
	cin >> k;
	int result = countSubArrayProductLessThanK(a, n, k);
	cout << "\nSub array count for the given input " << k << " is: " << result;
	return 0;
}