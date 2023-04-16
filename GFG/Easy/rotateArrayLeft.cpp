// https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1?page=1&difficulty[]=0&category[]=Arrays&sortBy=submissions

// Rotate Array

// Given an unsorted array arr[] of size N. 
// Rotate the array to the left (counter-clockwise direction) by D steps, where D is a positive integer. 

// Example 1:

// Input:
// N = 5, D = 2
// arr[] = {1,2,3,4,5}
// Output: 3 4 5 1 2
// Explanation: 1 2 3 4 5  when rotated
// by 2 elements, it becomes 3 4 5 1 2.
// Example 2:

// Input:
// N = 10, D = 3
// arr[] = {2,4,6,8,10,12,14,16,18,20}
// Output: 8 10 12 14 16 18 20 2 4 6
// Explanation: 2 4 6 8 10 12 14 16 18 20 
// when rotated by 3 elements, it becomes 
// 8 10 12 14 16 18 20 2 4 6.
 
// Your Task:
// Complete the function rotateArr() which takes the array, 
// D and N as input parameters and rotates the array by D elements. 
// The array must be modified in-place without using extra space. 

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 106
// 1 <= D <= 106
// 0 <= arr[i] <= 105

#include<bits/stdc++.h>
using namespace std;

//Function to rotate an array by d elements in counter-clockwise direction.
void reverse(int a[], int low, int high){
    while(low<high){
        swap(a[low], a[high]);
        low++;
        high--;
    }
}
void rotateArr(int a[], int d, int n){
    // int temp[n];
    // int k = 0;
    // for (int i = d; i < n; i++) {
    //     temp[k] = arr[i];
    //     k++;
    // }
    // for (int i = 0; i < d; i++) {
    //     temp[k] = arr[i];
    //     k++;
    // }
    // for (int i = 0; i < n; i++) {
    //     arr[i] = temp[i];
    // }
    
    d = d % n;
    
    reverse(a, 0, d-1);
    reverse(a, d, n-1);
    reverse(a, 0, n-1);
}

int main(int argc, char const *argv[])
{
	int n,d;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter the "<<n<<" elements of the array: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	} 
	cout<<"\nEnter the value from where you want to rotate the array to left: ";
	cin>>d;
	rotateArr(a, d, n);
	cout<<"\nArray after rotation: ";
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	} 
	return 0;
}