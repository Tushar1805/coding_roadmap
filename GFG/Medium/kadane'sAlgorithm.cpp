// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1?page=1&difficulty[]=1&sortBy=submissions

// Kadane's Algorithm

// Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) 
// which has the maximum sum and return its sum.

// Example 1:

// Input:
// N = 5
// Arr[] = {1,2,3,-2,5}
// Output:
// 9
// Explanation:
// Max subarray sum is 9
// of elements (1, 2, 3, -2, 5) which 
// is a contiguous subarray.
// Example 2:

// Input:
// N = 4
// Arr[] = {-1,-2,-3,-4}
// Output:
// -1
// Explanation:
// Max subarray sum is -1 
// of element (-1)

// Your Task:
// You don't need to read input or print anything. 
// The task is to complete the function maxSubarraySum() which takes Arr[] and N as 
// input parameters and returns the sum of subarray with maximum sum.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 106
// -107 ≤ A[i] ≤ 107

#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n){
        
    long long int sum = 0, max = LONG_MIN;
    int ans_start = -1, ans_end = -1, start = 0;
    for(int i=0;i<n;i++){
    	if(sum ==0)
    		start = i;
        sum += arr[i];
        if(max < sum){
            max = sum;
            ans_start = start; ans_end = i; // this will give the subarray which has the maximum sum
        }
        if(sum<0){
            sum = 0;
        }
       
    }
    cout<<"\nsubarray with maximum sum: ";
    for (int i = ans_start; i <= ans_end ; ++i)
    {
    	cout<<arr[i]<<" + ";
    }
    return max;
}

int main(int argc, char const *argv[])
{
	int n;
	long long int res;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter the elements of the array: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	res = maxSubarraySum(a, n);
	cout<<"\nMaximum sum found in the subarray is: "<<res;
	return 0;
}