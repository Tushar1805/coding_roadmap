// https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/0

// Union of two arrays

// Given two arrays a[] and b[] of size n and m respectively. 
// The task is to find the number of elements in the union between these two arrays.

// Union of the two arrays can be defined as the set containing distinct elements from both the arrays. 
// If there are repetitions, then only one occurrence of element should be printed in the union.

// Note : Elements are not necessarily distinct.

// Example 1:

// Input:
// 5 3
// 1 2 3 4 5
// 1 2 3
// Output: 
// 5
// Explanation: 
// 1, 2, 3, 4 and 5 are the
// elements which comes in the union set
// of both arrays. So count is 5.
// Example 2:

// Input:
// 6 2 
// 85 25 1 32 54 6
// 85 2 
// Output: 
// 7
// Explanation: 
// 85, 25, 1, 32, 54, 6, and
// 2 are the elements which comes in the
// union set of both arrays. So count is 7.
// Your Task:
// Complete doUnion funciton that takes a, n, b, m as parameters and returns the count of union elements of the two arrays. 
// The printing is done by the driver code.

// Constraints:
// 1 ≤ n, m ≤ 105
// 0 ≤ a[i], b[i] < 105

// Expected Time Complexity : O((n+m)log(n+m))
// Expected Auxilliary Space : O(n+m)

#include <bits/stdc++.h>
using namespace std;

int doUnion(int a[], int n, int b[], int m)  {
    int count = 0;
    unordered_map<int, int> mm;
    for(int i =0; i<n; i++){
         mm[a[i]]++;
        if(mm[a[i]]<2)
            count++;
    }
    for(int j =0; j<m;j++){
        mm[b[j]]++;
        if(mm[b[j]]<2)
          count++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
	int n, m, res;
	cout<<"Enter the size of array 1 and 2 respectively: ";
	cin>>n>>m;
	int a[n];
	int b[m];
	cout<<"\nEnter the "<< n<<" elements of array 1: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<"\nEnter the "<< m<<" elements of array 2: ";
	for (int i = 0; i < m; ++i)
	{
		cin>>b[i];
	}
	res = doUnion(a, n, b , m);
	if (res != 0)
	{
		cout<<"\nThere are "<<res<<" elements in the union of two arrays";
	}else{
		cout<<"\nNo union";
	}
	return 0;
}