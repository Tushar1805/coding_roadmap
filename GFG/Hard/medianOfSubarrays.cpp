// https://practice.geeksforgeeks.org/problems/6f08220ca3b871be594f50f7f56a9ef2799cb485/1

// Given an array A[] of N integers and an integer M. 
// The task is to count the number of subarrays which have median M.
// Median of an array is defined as below:

// 1. If N is odd, the median value is the number that is in the middle after sorting the array.
// 2. if N is even, the median value is the left of the two middle numbers after sorting the array. 

// Example 1:

// Input:
// N = 5, M = 2
// A[] = {2, 1, 3, 5, 4}
// Output: 
// 3
// Explanation: 
// The subarrays which has median equal to M
// are [2], [2,1,3] and [2,1,3,5]

// Example 2:

// Input:
// N = 1, M = 1
// A[] = {1}
// Output: 
// 1
// Explanation: 
// The subarrays which has median equal to M
// is [1].

// Your Task: 
// You don't need to read input or print anything. 
// Complete the function countSubarray( ) 
// which takes the integer N , the array A[], and the integer M as input parameters and returns the number of subarays. 

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ A[] ≤ 105
// 1 ≤ M ≤ N

#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

long long int help(int n, vector<int> a, int m){
	unordered_map<int, int> mm;
	mm[0]++;
	int sum = 0;
	long long int ans = 0, currentElement = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] < m)
		{
			sum--;
			currentElement -= mm[sum];
		}else{
			currentElement += mm[sum];
			sum++;
		}
		ans += currentElement;
		mm[sum]++;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int m, n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	vector<int> arr;
	cout<<"\nEnter the elements of the array: ";
	for (int i = 0; i < n; ++i)
	{
		int value;
		cin>>value;
		arr.push_back(value);
	}
	cout<<"\nEnter the median of the sub arrays: ";
	cin>>m;

	// This gets the sub arrays whose median is m or grater than m
	// for the eg given sub arrays whose median is 2 or >2.
	long long int a = help(n, arr, m);

	// for the eg given sub arrays whose median is 3 or >3.
	long long int b = help(n, arr, m+1);
	// this two function call will elemenate the sub arrays contains 1

	cout<<"\nTotal number of sub arrays having median "<<m<<" are: "<<a-b;
	return 0;
}

