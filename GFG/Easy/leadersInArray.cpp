// https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?page=1&sortBy=submissions

// Leaders in an array

// Given an array A of positive integers. 
// Your task is to find the leaders in the array. 
// An element of array is leader if it is greater than or equal to all the elements to its right side. 
// The rightmost element is always a leader. 

// Example 1:

// Input:
// n = 6
// A[] = {16,17,4,3,5,2}
// Output: 17 5 2
// Explanation: The first leader is 17 
// as it is greater than all the elements
// to its right.  Similarly, the next 
// leader is 5. The right most element 
// is always a leader so it is also 
// included.
 
// Example 2:

// Input:
// n = 5
// A[] = {1,2,3,4,0}
// Output: 4 0
 
// Your Task:
// You don't need to read input or print anything. 
// The task is to complete the function leader() which takes array A and n as input parameters 
// and returns an array of leaders in order of their appearance.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= n <= 107
// 0 <= Ai <= 107

#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(int a[], int n){
    vector<int> lead;
    int max = 0;
    for(int i=n-1; i>=0;i--){
        if(a[i] >= max){
            max = a[i];
            lead.push_back(max);
        }
    }
    reverse(lead.begin(), lead.end());
    return lead;
}

int main(int argc, char const *argv[])
{
	int n;
	vector<int> res;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter the elements of array: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	res = leaders(a, n);
	cout<<"\nLeaders of array: ";
	for(int i=0; i<res.size();i++){
		cout<<res[i]<<" ";
	}
	return 0;
}