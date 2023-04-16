// https://practice.geeksforgeeks.org/problems/4db2fcd97400456c4914d5a3e8ad932cc21e3e9d/1

// Unequal Arrays

// You are given two arrays A and B each of length N. 
// You can perform the following operation on array A zero or more times. 

// Select any two indices i and j, 1 <= i , j <= N and i != j
// Set A[i] = A[i] + 2 and A[j] = A[j]-2
// Find the minimum number of operations required to make A and B equal.

// Note :

// Two arrays are said to be equal if the frequency of each element is equal in both of them.
// Arrays may contain duplicate elements.
// Example 1:

// Input:
// N = 3
// A[] = {2, 5, 6}
// B[] = {1, 2, 10}
// Output: 2
// Explanation: 
// Select i = 3, j = 2, A[3] = 6 + 2 = 8 and A[2] = 5 - 2 = 3
// Select i = 3, j = 2, A[3] = 8 + 2 = 10 and A[2] = 3 - 2 = 1
// Now A = {2, 1, 10} and B = {1, 2, 10}
// Example 2:

// Input:
// N = 2
// A[] = {3, 3}
// B[] = {9, 8}
// Output: -1
// Explanation: 
// It can be shown that A cannot be made equal to B.
// Your Task: 
// You don't need to read input or print anything. 
// Your task is to complete the function solve() 
// which takes the 2 arrays A[], B[] and their size N as input parameters 
// and returns the minimum number of moves to make A and B equal if possible else return -1.

// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 105
// -109 <= A[i] <= 109
// -109 <= B[i] <= 109

#include<bits/stdc++.h>
using namespace std;

long long solve(int N, vector<int> &A, vector<int> &B) {
    long long sum = 0, ans=0;
    vector<int> a,b,c,d;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int i=0;i<N;i++){
        sum += A[i] - B[i];
        if(A[i] % 2 != 0) a.push_back(A[i]);
        else b.push_back(A[i]);
        if(B[i] % 2 != 0) c.push_back(B[i]);
        else d.push_back(B[i]);
    }
    if(sum != 0 || a.size() != c.size()) return -1;
    for(int i=0;i<a.size();i++){
        ans += (abs(a[i] - c[i]) / 2);
    }
    for(int i=0;i<b.size();i++){
        ans += (abs(b[i] - d[i]) / 2);
    }
    return ans/2;
}

int main(int argc, char const *argv[])
{
	int n;
	long long res;
	cout<<"Enter the size of the array: ";
	cin>>n;
	vector<int> a, b;
	cout<<"\nEnter the "<<n<<" elements of array A: ";
	for (int i = 0; i < n; ++i)
	{
		int value;
		cin>>value;
		a.push_back(value);
	}
	cout<<"\nEnter the "<<n<<" elements of array B: ";
	for (int i = 0; i < n; ++i)
	{
		int value;
		cin>>value;
		b.push_back(value);
	}
	res = solve(n, a, b);
	if(res != -1)
		cout<<"\nMinimum operations to make both array same are: "<<res;
	else
		cout<<"\nBoth arrays can't be equal";
	return 0;
}