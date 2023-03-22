// https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1?page=1&category[]=Arrays&sortBy=submissions

// Find duplicates in an array

// Given an array a[] of size N which contains elements from 0 to N-1, 
// you need to find all the elements occurring more than once in the given array.

// Note: The extra space is only for the array to be returned.
// Try and perform all operations within the provided array. 

// Example 1:

// Input:
// N = 4
// a[] = {0,3,1,2}
// Output: -1
// Explanation: N=4 and all elements from 0
// to (N-1 = 3) are present in the given
// array. Therefore output is -1.
// Example 2:

// Input:
// N = 5
// a[] = {2,3,1,2,3}
// Output: 2 3 
// Explanation: 2 and 3 occur more than once
// in the given array.
// Your Task:
// Complete the function duplicates() which takes array a[] and n as input as parameters 
// and returns a list of elements that occur more than once in the given array in a sorted manner. 
// If no such element is found, return list containing [-1]. 

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(n).

// Constraints:
// 1 <= N <= 105
// 0 <= A[i] <= N-1, for each valid i

#include<bits/stdc++.h>
using namespace std;

// My solution uses O(n) space complexity
// vector<int> duplicates(int arr[], int n) {
//     unordered_map<int, int> mm;
//     vector<int> res;
//     bool check = false;
//     for(int i=0;i<n;i++){
//         mm[arr[i]]++;
//         if(mm[arr[i]] == 2 ){
//             res.push_back(arr[i]);
//             check = true;
//         }   
//     }
//     if(!check)
//         res.push_back(-1);
//     sort(res.begin(), res.end());
//     return res;
// }

// Uses O(1) space complexity, by manupulating the given array only
vector<int> duplicates(int arr[], int n) {
    // unordered_map<int, int> mm;
    vector<int> res;
    bool check = false;
    for(int i=0;i<n;i++){
        arr[arr[i] % n] = arr[arr[i] %n] +n;
    }
    for(int i = 0; i<n; i++){
        if(arr[i]/n > 1){
             res.push_back(i);
            check = true;
        }
    }
    // for(int i=0;i<n;i++){
    //     mm[arr[i]]++;
    //     if(mm[arr[i]] == 2 ){
    //         res.push_back(arr[i]);
    //         check = true;
    //     }   
    // }
    if(!check)
        res.push_back(-1);
    sort(res.begin(), res.end());
    return res;
}

int main(int argc, char const *argv[])
{
	int n;
	vector<int> res;
	cout<<"Enter the size of array: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter the elements of array: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	res = duplicates(a, n);
	cout<<"\nDuplicate elements in array are: ";
	for (int i = 0; i < res.size(); ++i)
	{
		cout<<res[i]<<" ";
	}
	return 0;
}

