// https://practice.geeksforgeeks.org/problems/5551749efa02ae36b6fdb3034a7810e84bd4c1a4/1

// Frogs and Jumps

// N frogs are positioned at one end of the pond. 
// All frogs want to reach the other end of the pond as soon as possible. 
// The pond has some leaves arranged in a straight line. 
// Each frog has the strength to jump exactly K leaves. 
// For example, a  frog having strength 2 will visit the leaves 2, 4, 6, ...  etc. while crossing the pond.

// Given the strength of each frog and the number of leaves, 
// your task is to find the number of leaves that not be visited by any of the frogs 
// when all frogs have reached the other end of the pond. 

// Example 1:

// Input:
// N = 3
// leaves = 4
// frogs[] = {3, 2, 4} 
// Output: 1
// Explanation:
// Leaf 1 will not be visited by any frog.
// Example 2:

// Input: 
// N = 3
// leaves = 6
// frogs[] = {1, 3, 5} 
// Output: 0
// Explanation: 
// First frog will visit all the leaves so no 
// leaf is left unvisited.
// Your Task:
// Complete the function unvisitedLeaves() which takes the integers N, 
// leaves and the array frogs as the input parameters, and returns the number of unvisited leaves.

// Expected Time Complexity: O(N*log(leaves))
// Expected Auxiliary Space: O(leaves)

// Constraints:
// 1 ≤ N, leaves, frogs[i] ≤ 105

#include<bits/stdc++.h>
using namespace std;

int unvisitedLeaves(int N, int leaves, int frogs[]) {
    vector<int> vis(leaves+1, -1);
    for(int i=0;i<N;i++){
        int pos = frogs[i];
        int temp = pos;
        if(pos<=leaves && vis[pos] == -1){
            while(temp <= leaves){
               if(vis[temp] == -1)
                    vis[temp] = 1;
                temp += pos; 
            }
        }
    }
    int count = 0;
    for(int i=1;i<leaves+1;i++){
        if(vis[i] == -1)
           count++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
	int n, leaves;
	cout<<"Enter the number of frogs: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter the number of leaves to cross: ";
	cin>>leaves;
	cout<<"\nEnter the strength to jump for each frog: ";
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<"\nThe leaves which are not visited: "<<unvisitedLeaves(n, leaves, a);
	return 0;
}