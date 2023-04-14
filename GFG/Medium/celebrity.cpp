// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1?page=3&difficulty[]=1&sortBy=submissions

// The Celebrity Problem

// A celebrity is a person who is known to all but does not know anyone at a party. 
// If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that 
// if an element of row i and column j  is set to 1 it means ith person knows jth person. 
// Here M[i][i] will always be 0.
// Note: Follow 0 based indexing.
// Follow Up: Can you optimize it to O(N)
 
// Example 1:

// Input:
// N = 3
// M[][] = {{0 1 0},
//          {0 0 0}, 
//          {0 1 0}}
// Output: 1
// Explanation: 0th and 2nd person both
// know 1. Therefore, 1 is the celebrity. 

// Example 2:

// Input:
// N = 2
// M[][] = {{0 1},
//          {1 0}}
// Output: -1
// Explanation: The two people at the party both
// know each other. None of them is a celebrity.

// Your Task:
// You don't need to read input or print anything. 
// Complete the function celebrity() which takes the matrix M and its size N as input parameters 
// and returns the index of the celebrity. If no such celebrity is present, return -1.

// Expected Time Complexity: O(N^2)
// Expected Auxiliary Space: O(1)

// Constraints:
// 2 <= N <= 3000
// 0 <= M[][] <= 1

#include<bits/stdc++.h>
using namespace std;

//Function to find if there is a celebrity in the party or not.
int celebrity(vector<vector<int> >& M, int n) 
{
    
    // O(N^2) complexity
    // int in[n] = {0};
    // int out[n] = {0};
    
    // for(int i=0 ;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(M[i][j] == 1){
    //             in[j]++;
    //             out[i]++;
    //         }
    //     }
    // }
    
    // for(int i=0;i<n;i++){
    //     if(in[i] == n-1 && out[i] == 0){
    //         return i;
    //     }
    // }
    // return -1;
    
    // O(N) complexity
    
    int c=0;
    for(int i=1;i<n;i++){
        if(M[c][i] == 1)
            c=i;
    }
    for(int i =0;i<n;i++){
        if(i != c && (M[c][i] == 1 or M[i][c] == 0))
            return -1;
    }
    return c;
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the number of people in the party: ";
	cin>>n;
	vector<vector<int>> a;
	for (int i = 0; i < n; ++i)
	{
		vector<int> p;
		for(int j = 0; j< n;j++){
			if(i != j){
				cout<<"\nEnter 1 if Person "<<i+1<<" knows Person "<< j+1<<" : ";
				int val;
				cin>>val;
				p.push_back(val);
			}else{
				p.push_back(0);
			}
		}
		a.push_back(p);
	}

	int res = celebrity(a, n);
	if(res != -1){
		cout<<"\nCelebrity in the party is Person "<<res+1;
	}else{
		cout<<"\nNo Celebrity present in the party";
	}
	
	return 0;
}