// https://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1?page=1&curated[]=8&sortBy=submissions

// Bitonic Point 

// Given an array arr of n elements that is first strictly increasing and then maybe strictly decreasing, 
// find the maximum element in the array.
// Note: If the array is increasing then just print the last element will be the maximum value.

// Example 1:

// Input: 
// n = 9
// arr[] = {1,15,25,45,42,21,17,12,11}
// Output: 45
// Explanation: Maximum element is 45.
// Example 2:

// Input: 
// n = 5
// arr[] = {1, 45, 47, 50, 5}
// Output: 50
// Explanation: Maximum element is 50.
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function findMaximum() 
// which takes the array arr[], and n as parameters and returns an integer denoting the answer.

// Expected Time Complexity: O(logn)
// Expected Auxiliary Space: O(1)

// Constraints:
// 3 ≤ n ≤ 106
// 1 ≤ arri ≤ 106

#include<iostream>
using namespace std;

int findMaximum(int arr[], int n) {
    int l = 0, r = n-1, mid;
    int max = 0;
    while(l<=r){
        mid = (l+r) / 2;
        if(arr[mid] > arr[mid-1] && arr[mid]>arr[mid+1]){
            return arr[mid];
        }else if(arr[mid] < arr[mid-1]){
            r = mid - 1;
        }else{
            l = mid+1;
        }
    }
    return n;
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter the "<<n<<" elements of the array: ";
	for (int i = 0; i < n; ++i)
	 {
	 	cin>>a[i];
	 } 
	 cout<<"\nMaximum value: "<<findMaximum(a,n);
	return 0;
}
