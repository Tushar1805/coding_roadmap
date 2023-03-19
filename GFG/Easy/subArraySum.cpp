// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?page=1&sortBy=submissions

// Subarray with given sum

// Given an unsorted array A of size N that contains only non-negative integers, 
// find a continuous sub-array that adds to a given number S and 
// return the left and right index(1-based indexing) of that subarray.

// In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.

// Note:- You have to return an ArrayList consisting of two elements left and right. 
// In case no such subarray exists return an array consisting of element -1.

// Example 1:

// Input:
// N = 5, S = 12
// A[] = {1,2,3,7,5}
// Output: 2 4
// Explanation: The sum of elements 
// from 2nd position to 4th position 
// is 12.
 
// Example 2:

// Input:
// N = 10, S = 15
// A[] = {1,2,3,4,5,6,7,8,9,10}
// Output: 1 5
// Explanation: The sum of elements 
// from 1st position to 5th position
// is 15.

// Your Task:
// You don't need to read input or print anything. 
// The task is to complete the function subarraySum() 
// which takes arr, N, and S as input parameters and returns an 
// ArrayList containing the starting and ending positions 
// of the first such occurring subarray from the left where sum equals to S. 
// The two indexes in the array should be according to 1-based indexing. 
// If no such subarray is found, return an array consisting of only one element that is -1.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// 1 <= Ai <= 109
// 0<= S <= 1014

#include<bits/stdc++.h>
using namespace std;

//Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s){
        int l = 0, r=0;
        vector<int> ans;
        bool isFound = false;
        long long int currentSum = arr[0];
        if(s == 0){
            ans.push_back(-1);
            return ans;
        }
        while(r<n){
            if(s == currentSum){
                isFound = true;
                break;
            }else if(currentSum < s) {
                 r++;
                if(r<n)
                    currentSum += arr[r]; 
            }else{
                currentSum -= arr[l];
                l++;
            }
        }
        if(isFound){
            ans.push_back(l+1); // only l will return index, but we have to return position
            ans.push_back(r+1);
        }else{
            ans.push_back(-1);
        }
        return ans;
   }

int main(int argc, char const *argv[])
{
	int n; 
	long long int s;
	vector<int> a, res;
	cout<<"Enter the size of the array: ";
	cin>>n;
	cout<<"\nEnter the elements of the array: ";
	for (int i = 0; i < n; ++i)
	{
		int value;
		cin>>value;
		a.push_back(value);
	}
	cout<<"\nEnter the sum to check for the sub array: ";
	cin>>s;
	res = subarraySum(a, n, s);
	if(res[0] != -1)
		cout<<"\nThe sum "<<s<<" found from position "<<res[0]<<" to "<<res[1]<<" in the given array";
	else
		cout<<"\nThe sum not found in the array";
	return 0;
}