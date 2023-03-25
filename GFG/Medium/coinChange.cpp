// https://practice.geeksforgeeks.org/problems/coin-change2448/1?page=1&difficulty[]=1&category[]=Arrays&sortBy=submissions

// Coin Change

// Given an integer array coins[ ] of size N representing different 
// denominations of currency and an integer sum, find the number of ways you can make 
// sum by using different combinations from coins[ ].  
// Note: Assume that you have an infinite supply of each type of coin. 

// Example 1:

// Input:
// sum = 4 , 
// N = 3
// coins[] = {1,2,3}
// Output: 4
// Explanation: Four Possible ways are:
// {1,1,1,1},{1,1,2},{2,2},{1,3}.
// Example 2:

// Input:
// Sum = 10 , 
// N = 4
// coins[] ={2,5,3,6}
// Output: 5
// Explanation: Five Possible ways are:
// {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} 
// and {5,5}.

// Your Task:
// You don't need to read input or print anything. 
// Your task is to complete the function count() which accepts 
// an array coins[ ] its size N and sum as input parameters and 
// returns the number of ways to make change for given sum of money. 

// Expected Time Complexity: O(sum*N)
// Expected Auxiliary Space: O(sum)

// Constraints:
// 1 <= sum, N <= 103

#include<bits/stdc++.h>
using namespace std;

long long dp[1000][1000];
long long solve(int a[], int n, int sum){
    if(n == -1 and sum > 0){
        return 0;
    }
    if(sum==0)
        return 1;
    if(sum<0)
        return 0;
    if(dp[n][sum] != -1)
        return dp[n][sum];
    return dp[n][sum] = solve(a, n, sum - a[n]) + solve(a, n-1, sum);
}
long long int count(int coins[], int N, int sum) {

    dp[N][sum+1];
    for(int i=0;i<N;i++){
        for(int j=0;j<=sum;j++ ){
            dp[i][j] = -1;
        }
    }
    return solve(coins, N-1, sum);
}

int main(int argc, char const *argv[])
{
	int n, sum;
	long long int res;
	cout<<"Enter the size of array: ";
	cin>>n;
	int coins[n];
	cout<<"\nEnter the coins in the array: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>coins[i];
	}
	cout<<"\nEnter the sum of rupees you have: ";
	cin>>sum;
	res = count(coins, n, sum);
	cout<<"\nThere are "<< res<<" such possible ways that the sum can be derived \nfrom the given couns in the array";
	return 0;
}