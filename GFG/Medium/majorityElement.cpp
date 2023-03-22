// https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1?page=1&category[]=Arrays&sortBy=submissions

// Majority Element

// Given an array A of N elements. Find the majority element in the array. 
// A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 

// Example 1:

// Input:
// N = 3 
// A[] = {1,2,3} 
// Output:
// -1
// Explanation:
// Since, each element in 
// {1,2,3} appears only once so there 
// is no majority element.
// Example 2:

// Input:
// N = 5 
// A[] = {3,1,3,3,2} 
// Output:
// 3
// Explanation:
// Since, 3 is present more
// than N/2 times, so it is 
// the majority element.

// Your Task:
// The task is to complete the function majorityElement() 
// which returns the majority element in the array. If no majority exists, return -1.
 

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).
 

// Constraints:
// 1 ≤ N ≤ 107
// 0 ≤ Ai ≤ 106

#include<bits/stdc++.h>
using namespace std;

int majorityElement(int a[], int size)
{
    unordered_map<int, int> mm;
    int m = -1;
    for(int i=0;i<size;i++){
        mm[a[i]]++;
        if (mm[a[i]] > size/2)
            m = a[i];
    }
    return m;
}

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    cout<<"\nEnter the elements of array: ";
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    cout<<"\nMajority element in the array is: "<<majorityElement(a,n);
    return 0;
}

