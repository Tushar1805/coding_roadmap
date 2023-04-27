// https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1?page=1&curated[]=2&sortBy=submissions

// First Repeating Element 

// Given an array arr[] of size n, find the first repeating element. 
// The element should occur more than once and the index of its first occurrence should be the smallest.

// Note:- The position you return should be according to 1-based indexing. 

// Example 1:

// Input:
// n = 7
// arr[] = {1, 5, 3, 4, 3, 5, 6}
// Output: 2
// Explanation: 
// 5 is appearing twice and 
// its first appearence is at index 2 
// which is less than 3 whose first 
// occuring index is 3.

// Example 2:

// Input:
// n = 4
// arr[] = {1, 2, 3, 4}
// Output: -1
// Explanation: 
// All elements appear only once so 
// answer is -1.

// Your Task:
// You don't need to read input or print anything. 
// Complete the function firstRepeated() which takes arr and n as input parameters 
// and returns the position of the first repeating element. If there is no such element, return -1.
 
// Expected Time Complexity: O(n)
// Expected Auxilliary Space: O(n)

// Constraints:
// 1 <= n <= 106
// 0 <= Ai<= 106

#include<bits/stdc++.h>
using namespace std;

int firstRepeated(int arr[], int n) {
    unordered_map<int, int> mm;
    int res = -1;
    for(int i=0;i<n;i++){
        mm[arr[i]]++; 
    }
    
    for(int i=0;i<n;i++){
        if(mm[arr[i]] > 1){
            res = i+1;
            break;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int a[n];
	int res;
	cout<<"\nEnter the elements of the array: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	res = firstRepeated(a, n);

	(res != -1)?
	cout<<"\nFirst repeated element found at position: "<<res : cout<<"\nFirst repeated element not found";
	return 0;
}