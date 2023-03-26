// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/0

// Row with max 1s

// Given a boolean 2D array of n x m dimensions where each row is sorted. 
// Find the 0-based index of the first row that has the maximum number of 1's.

// Example 1:

// Input: 
// N = 4 , M = 4
// Arr[][] = {{0, 1, 1, 1},
//            {0, 0, 1, 1},
//            {1, 1, 1, 1},
//            {0, 0, 0, 0}}
// Output: 2
// Explanation: Row 2 contains 4 1's (0-based
// indexing).

// Example 2:

// Input: 
// N = 2, M = 2
// Arr[][] = {{0, 0}, {1, 1}}
// Output: 1
// Explanation: Row 1 contains 2 1's (0-based
// indexing).

// Your Task:  
// You don't need to read input or print anything. 
// Your task is to complete the function rowWithMax1s() which takes the array of booleans arr[][], 
// n and m as input parameters and returns the 0-based index of the first row that has the most number of 1s. 
// If no such row exists, return -1.
 
// Expected Time Complexity: O(Nlog(M))
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N, M ≤ 103
// 0 ≤ Arr[i][j] ≤ 1 

#include<bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int> > a, int n, int m) {
    int count, res = -1;
    int max = 0;
    for(int i=0;i<n;i++){
        count = 0;
        for(int j =0;j<m;j++){
            if(a[i][j] == 1)
                count++;
        }
        if(count > max){
            max = count;
            res = i;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
	int n, m;
	vector<vector<int>> a;
	cout<<"Enter the number of rows and column: ";
	cin>>m>>n;

	cout<<"\nEnter the elements 2D array: ";
	for (int i = 0; i < n; ++i)
	{
		vector<int> temp;
		for(int j=0;j<m;j++){
			int value;
			cin>>value;
			temp.push_back(value);
		}
		a.push_back(temp);
	}

	cout<<"\nRow with maximum 1s: "<<rowWithMax1s(a, n, m);
	return 0;
}