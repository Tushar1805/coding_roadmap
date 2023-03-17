// https://practice.geeksforgeeks.org/problems/reverse-array-in-groups0255/1?page=1&status[]=solved&sortBy=submissions

// Reverse array in groups 

// Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.

// Note: If at any instance, there are no more subarrays of size greater than or equal to K, 
// then reverse the last subarray (irrespective of its size). 
// You shouldn't return any array, modify the given array in-place.

// Example 1:

// Input:
// N = 5, K = 3
// arr[] = {1,2,3,4,5}
// Output: 3 2 1 5 4
// Explanation: First group consists of elements
// 1, 2, 3. Second group consists of 4,5.
 

// Example 2:

// Input:
// N = 4, K = 3
// arr[] = {5,6,8,9}
// Output: 8 6 5 9
 

// Your Task:
// You don't need to read input or print anything. The task is to complete the function reverseInGroups() which takes the array, N and K as input parameters and modifies the array in-place. 

 

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

 

// Constraints:
// 1 ≤ N, K ≤ 107
// 1 ≤ A[i] ≤ 101

#include<iostream>
#include<vector>
using namespace std;

 void reverseInGroups(vector<long long>& arr, int n, int k){
        int start, end;
        for(int i=0;i<n; i = i+k){
            start = i;
            end = (i+k-1 > n-1) ? n-1 : i+k-1;
            while(start<=end){
                int temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
                start++;
                end--;
            }
        }
    }

    int main(int argc, char const *argv[])
    {
        int n, k;
        vector<long long> a;
        cout<<"Enter the size of the array: ";
        cin>>n;
        cout<<"Enter the "<<n<<" elements of array: ";
        for(int i = 0;i<n;i++){
            long long value;
            cin>>value;
            a.push_back(value);
        }
        cout<<"Enter sub-array group size: ";
        cin>>k;
        reverseInGroups(a,n,k);
        cout<<"Reversed in groups array: ";
        for(int i = 0;i<n;i++){
            cout<<a[i]<<" ";
        }
        return 0;
    }