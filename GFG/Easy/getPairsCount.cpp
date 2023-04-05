// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1?page=1&difficulty[]=0&sortBy=submissions

// Count pairs with given sum

// Given an array of N integers, and an integer K, 
// find the number of pairs of elements in the array whose sum is equal to K.

// Example 1:

// Input:
// N = 4, K = 6
// arr[] = {1, 5, 7, 1}
// Output: 2
// Explanation: 
// arr[0] + arr[1] = 1 + 5 = 6 
// and arr[1] + arr[3] = 5 + 1 = 6.

// Example 2:

// Input:
// N = 4, K = 2
// arr[] = {1, 1, 1, 1}
// Output: 6
// Explanation: 
// Each 1 will produce sum 2 with any 1.

// Your Task:
// You don't need to read input or print anything. 
// Your task is to complete the function getPairsCount() which takes arr[], 
// n and k as input parameters and returns the number of pairs that have sum K.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 105
// 1 <= K <= 108
// 1 <= Arr[i] <= 106

#include<bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int k) {
    int count = 0;
    unordered_map<int, int> mm;
    
    // Brute force method O(N^2)
    // for(int i=0; i<n;i++){
    //     for(int j=i; j<n; j++){
    //         if(i!=j && (arr[i] + arr[j] == k))
    //             count++;
    //     }
    // }
    
    for(int i=0; i<n; i++){
        int b = k - arr[i];
        if(mm[b]){
            count += mm[b];
        }
        mm[arr[i]]++;
    }
    
    
    return count;
}

int main(int argc, char const *argv[])
{
	int n, k;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter the "<<n<<" elements of the array: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<"\nEnter the positive integer sum of two numbers that should be present in array: ";
	cin>>k;
	cout<<"\nThere are "<<getPairsCount(a, n, k)<<" such pairs of sum "<<k;
	return 0;
}
