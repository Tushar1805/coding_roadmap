// https://practice.geeksforgeeks.org/problems/1f05c7c12b1084f270c57566b2110967c046730d/1

// Make Array Elements Equal

// You are given an integer N. Consider an array arr having N elements where arr[i] = 2*i+1. 
// (The array is 0-indexed)

// You are allowed to perform the given operation on the array any number of times:

// 1) Select two indices i and j and increase arr[i] by 1 and decrease arr[j] by 1.

// Your task is to find the minimum number of such operations required 
// to make all the elements of the array equal.

// Example 1:

// Input:
// N = 3
// Output:
// 2
// Explanation:
// Initially the array is {1, 3, 5}. If we perform
// the operation once on the indices 0 and 2, the 
// resulting array will be {2, 3, 4}. If we again 
// perform the operation once on the indices 0
// and 2, the resulting array will be {3, 3, 3}.
// Hence, the minimum operations required is 2
// in this case. 
// Example 2:

// Input: 
// N = 2
// Output:
// 1
// Explanation: 
// The array initially is {1, 3}. After performing 
// an operation the array will be {2, 2}. Hence,
// the answer is 1 in this case.
// Your Task:
// Complete the function minOperations() which takes the integer N as the input parameter, 
// and returns the minimum operations required to make all the array elements equal.

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 109

#include<bits/stdc++.h>
using namespace std;

long long int minOperations(int N) {
        
    // Brute force approch O(N)
    // int i=1, j = 1;
    // long long int count = 0;
    // while(i<=N/2){
    //     count += N-j;
    //     j += 2;
    //     i++;
    // }
    // return count;
    
    // Optimized approach O(1)
    long long int last = 2 *(N-1) + 1;
    long long int mid = (last+1)/2;
    
    if(mid % 2 == 0)
        return mid*mid/4;
    return ((mid-1) * (mid+1))/4;
    
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the value of N: ";
	cin>>n;
	cout<<"\nMinimum operations required to equal the elements are: "<<minOperations(n);
	return 0;
}