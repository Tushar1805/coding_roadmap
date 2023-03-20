// Missing number in array

// https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1?page=1&sortBy=submissions

// Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.

// Example 1:

// Input:
// N = 5
// A[] = {1,2,3,5}
// Output: 4
// Example 2:

// Input:
// N = 10
// A[] = {6,1,2,8,3,4,7,10,5}
// Output: 9

// Your Task :
// You don't need to read input or print anything. 
// Complete the function MissingNumber() that takes array and N as input  
// parameters and returns the value of the missing number.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)


// Constraints:
// 1 ≤ N ≤ 106
// 1 ≤ A[i] ≤ 106

#include<bits/stdc++.h>
using namespace std;

// My Solution
// int MissingNumber(vector<int>& array, int n) {
//         sort(array.begin(), array.end());
//         int distinct = n;
//         // if(n==2)
//         //   return 2;
//         for(int i = 1; i<=n; i++){
//             if(array[i-1] != i ){
//                 distinct = i;
//                 break;
//             }
//         }
//         return distinct;
//     }

	// Using sum formula
	// This will work for the small sums but will cause overflow errors for large ints
    // int MissingNumber(vector<int>& array, int n) {
    //   	int sumN = n*(n+1) / 2;
    //   	int s = 0;
    //     for (int i = 0; i < n-1; ++i)
    //     {
    //     	s += array[i];
    //     }
    //     return sumN-s;
    // }

	int MissingNumber(vector<int>& array, int n) {
      	int x1 = 0 , x2 = 0;
        for (int i = 0; i <n - 1; ++i)
        {
        	x1 ^= array[i]; 
        }
        for (int i = 1; i <=n; ++i)
        {
        	x2 ^= i;
        }
        return x1 ^ x2;
    }

int main(int argc, char const *argv[])
{
	int n, res;
	vector<int> a;
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"\nEnter the distinct elements from 1 to "<<n-1<<": ";
	for (int i = 0; i < n-1; ++i)
	{
		int value;
		cin>>value;
		a.push_back(value);
	}

	res = MissingNumber(a, n);
	cout<<"\nMissing Number: "<<res;
	return 0;
}