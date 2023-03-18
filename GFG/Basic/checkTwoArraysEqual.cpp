// https://practice.geeksforgeeks.org/problems/check-if-two-arrays-are-equal-or-not3847/1?page=1&curated[]=1&sortBy=submissions

// Given two arrays A and B of equal size N, the task is to find if given arrays are equal or not. 
// Two arrays are said to be equal if both of them contain same set of elements, 
// arrangements (or permutation) of elements may be different though.
// Note : If there are repetitions, then counts of repeated elements must also be same for two array to be equal.

// Example 1:

// Input:
// N = 5
// A[] = {1,2,5,4,0}
// B[] = {2,4,5,0,1}
// Output: 1
// Explanation: Both the array can be 
// rearranged to {0,1,2,4,5}
// Example 2:

// Input:
// N = 3
// A[] = {1,2,5}
// B[] = {2,4,15}
// Output: 0
// Explanation: A[] and B[] have only 
// one common value.
// Your Task:
// Complete check() function which takes both the given array and 
// their size as function arguments and returns true if the arrays are equal else returns false.
// The 0 and 1 printing is done by the driver code.

// Expected Time Complexity : O(N)
// Expected Auxilliary Space : O(N)

// Constraints:
// 1<=N<=107
// 1<=A[],B[]<=1018


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	vector<int> a, b;
	cout<<"Enter the size of the two array: ";
	cin>>n;
	cout<<"\nEnter the elements of array 1: ";
	for (int i = 0; i < n; ++i)
	{
		int value;
		cin>>value;
		a.push_back(value);
	}
	cout<<"\nEnter the elements of array 2: ";
	for (int i = 0; i < n; ++i)
	{
		int value;
		cin>>value;
		b.push_back(value);
	}

	sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0;
        bool equal = true;
        while(i<n){
            if(a[i] != a[i]){
                equal = false;
                break;
            } 
            i++;
        }
      equal ? cout<<"\nBoth the array are equal" : cout<<"\nArrays not equal";
	return 0;
}