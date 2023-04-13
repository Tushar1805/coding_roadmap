// https://practice.geeksforgeeks.org/problems/searching-a-number0324/1?page=2&difficulty[]=-1&sortBy=submissions

// Searching a number

// Given an array Arr of N elements and a integer K. 
// Your task is to return the position of first occurence of K in the given array.
// Note: Position of first element is considered as 1.

// Example 1:

// Input:
// N = 5, K = 16
// Arr[] = {9, 7, 2, 16, 4}
// Output: 4
// Explanation: K = 16 is found in the
// given array at position 4.
// Example 2:

// Input:
// N = 7, K = 98
// Arr[] = {1, 22, 57, 47, 34, 18, 66}
// Output: -1
// Explanation: K = 98 isn't found in
// the given array.
// Your Task:
// Complete the function search() which takes an array arr, two integers n and k, 
// as input parameters and returns an integer denoting the answer. 
// Return -1 if the number is not found in array. You don't to print answer or take inputs.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 106
// 1 <= K <= 106
// 1 <= Arr[i] <= 106

#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int k) {
    int pos = -1;
    for(int i=0;i<n;i++){
        if(arr[i] == k){
            pos = i+1;
            break;
        }
    }
    return pos;
}

int main(int argc, char const *argv[])
{
	int n, k, pos;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter the "<<n<<" elements of the array: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<"\nEneter the number to find in the array: ";
	cin>>k;
	pos = search(a, n, k);
	if(pos != -1)
		cout<<endl<<k<<" found at position "<<pos;
	else
		cout<<endl<<k<< " Not found";
	return 0;
}