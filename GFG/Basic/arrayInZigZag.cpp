// https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1?page=1&curated[]=1&sortBy=submissions

// Convert array into Zig-Zag fashion

// Given an array arr of distinct elements of size N, 
// the task is to rearrange the elements of the array in a zig-zag fashion so that 
// the converted array should be in the below form: 

// arr[0] < arr[1]  > arr[2] < arr[3] > arr[4] < . . . . arr[n-2] < arr[n-1] > arr[n]. 

// NOTE: If your transformation is correct, the output will be 1 else the output will be 0. 

// Example 1:

// Input:
// N = 7
// Arr[] = {4, 3, 7, 8, 6, 2, 1}
// Output: 3 7 4 8 2 6 1
// Explanation: 3 < 7 > 4 < 8 > 2 < 6 > 1
// Example 2:

// Input:
// N = 4
// Arr[] = {1, 4, 3, 2}
// Output: 1 4 2 3
// Explanation: 1 < 4 > 2 < 3
// Your Task:
// You don't need to read input or print anything. 
// Your task is to complete the function zigZag() 
// which takes the array of integers arr and n as parameters and returns void. 
// You need to modify the array itself.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 106
// 0 <= Arri <= 109

#include <iostream>
using  namespace std;

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter the array elements: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	for (int i = 0; i < n; i = i+2)
	{
		
		if(i<n-1 && a[i]>a[i+1])
			swap(&a[i], &a[i+1]);
		if(i > 0 && a[i]>a[i-1])
			swap(&a[i], &a[i-1]);
	}

	cout<<"\nArray in zig zag form: ";
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}