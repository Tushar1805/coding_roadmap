// https://practice.geeksforgeeks.org/problems/ncr1019/1?page=2&difficulty[]=1&sortBy=submissions

// nCr

// Given two integers n and r, find nCr. 
// Since the answer may be very large, calculate the answer modulo 109+7.

// Example 1:

// Input: n = 3, r = 2
// Output: 3
// Explaination: 3C2 = 3. 

// Example 2:

// Input: n = 2, r = 4
// Output: 0
// Explaination: r is greater than n.

// Your Task:
// You do not need to take input or print anything. 
// Your task is to complete the function nCr() which takes n and r as 
// input parameters and returns nCr modulo 109+7..

// Expected Time Complexity: O(n*r)
// Expected Auxiliary Space: O(r)

// Constraints:
// 1 ≤ n ≤ 1000
// 1 ≤ r ≤ 800

#include<bits/stdc++.h>
using namespace std;

int nCr(int n, int r){
    if(r>n)
        return 0;
    if((n-r) < r)
        r = n-r;
    int mod = 1000000007;
    int dp[r+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1;i<=n;i++){
        for(int j = min(i, r); j>0;j--){
            dp[j] = (dp[j] + dp[j-1]) % mod;
        }
    }
    return dp[r];
}

int main(int argc, char const *argv[])
{
	int n, r;
	cout<<"Enter the value of n and r: ";
	cin>>n>>r;
	cout<<"\nResult: "<<nCr(n, r);
	return 0;
}