// https://practice.geeksforgeeks.org/problems/maximum-index-1587115620/0

// Maximum Index

// Given an array A[] of N positive integers. 
// The task is to find the maximum of j - i subjected to the constraint of A[i] < A[j] and i < j.
 
// Example 1:

// Input:
// N = 2
// A[] = {1, 10}
// Output:
// 1
// Explanation:
// A[0]<A[1] so (j-i) is 1-0 = 1.
// Example 2:

// Input:
// N = 9
// A[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
// Output:
// 6
// Explanation:
// In the given array A[1] < A[7]
// satisfying the required 
// condition(A[i] < A[j]) thus giving 
// the maximum difference of j - i 
// which is 6(7-1).
 
// Your Task:
// The task is to complete the function maxIndexDiff() which finds and 
// returns maximum index difference. Printing the output will be handled by driver code. 
// Return 0 in case no such index is found.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 107
// 0 ≤ A[i] ≤ 109

#include<bits/stdc++.h>
using namespace std;

int maxIndexDiff(int a[], int N) 
{ 
    vector<int> left(N);
    vector<int> right(N);
    left[0] = a[0];
    for(int i=1;i<N; i++){
        left[i] = min(left[i-1], a[i]);
    }
    right[N-1] = a[N-1];
    for(int i=N-2; i>=0; i--){
        right[i] = max(right[i+1], a[i]);
    }
    int x=0, y=0, ans = 0;
    while(x<N && y<N){
        if(right[y] >= left[x]){
            ans = max(ans, y-x);
            y++;
        }
        else x++;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter the elements of the array: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<"\nThe maximum of j - i: "<<maxIndexDiff(a, n);
	return 0;
}