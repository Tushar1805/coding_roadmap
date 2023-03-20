// https://practice.geeksforgeeks.org/problems/7366ce450d84b55391fc787a681c4d60de359e72/1

// Shortest XY distance in Grid

// Give a N*M grid of characters 'O', 'X', and 'Y'. 
// Find the minimum Manhattan distance between a X and a Y.

// Manhattan Distance :
// | row_index_x - row_index_y | + | column_index_x - column_index_y |


// Example 1:

// Input:
// N = 4, M = 4
// grid  = {{X, O, O, O}
//          {O, Y, O, Y}
//          {X, X, O, O}
//          {O, Y, O, O}}
// Output:
// 1
// Explanation:
// {{X, O, O, O}
// {O, Y, O, Y}
// {X, X, O, O}
// {O, Y, O, O}}
// The shortest X-Y distance in the grid is 1.
// One possible such X and Y are marked in bold
// in the above grid.
// Example 2:

// Input:
// N = 3, M = 3
// grid = {{X, X, O}
//         {O, O, Y}
//         {Y, O, O}}
// Output :
// 2
// Explanation:
// {{X, X, O}
//  {O, O, Y}
//  {Y, O, O}}
// The shortest X-Y distance in the grid is 2.
// One possible such X and Y are marked in bold
// in the above grid.
// Your Task:  
// You don't need to read input or print anything. 
// Your task is to complete the function shortestXYDist() which takes two integers N, 
// and M and an 2D list of size N*M as input and returns the shortest Manhattan Distance between a X and a Y.

// Expected Time Complexity: O(N*M)
// Expected Auxiliary Space: O(N*M)


// Constraints:
// 1 ≤ N*M ≤ 105 

// There exists at least one 'X' and at least one 'Y' in the grid.

#include<bits/stdc++.h>
using namespace std;

int shortestXYDist(vector<vector<char>> grid, int N, int M) {
     queue<pair<pair<int, int>, int>>q;
     vector<vector<int>>vis(N, vector<int>(M,0));
     
     for(int i=0;i<N;i++){
         for(int j =0; j<M;j++){
             if(grid[i][j] == 'X'){
                 q.push({{i, j}, 0});
                 vis[i][j] = 1;
             }
         }
     }
     
     int ans = 0;
     vector<int>row={1, 0, -1, 0};
     vector<int>col={0, 1, 0, -1};
     
     // Simple BFS
     while(!q.empty()){
         auto curr = q.front();
         q.pop();
         int i = curr.first.first;
         int j = curr.first.second;
         int dis = curr.second;
         if(grid[i][j] == 'Y'){
             ans = dis;
             break;
         }
         for(int k=0;k<4;k++){
             int m = i+row[k];
             int n = j+col[k];
             if(m>=0 and n>=0 and m<N and n<M and !vis[m][n]){
                 q.push({{m, n}, dis+1});
                 vis[m][n]=1;
             }
         }
     }
     return ans;
}

int main(int argc, char const *argv[])
{
	int m, n, dis;
	cout<<"Enter the number of rows and columns: ";
	cin>>m>>n;
	vector<vector<char>> grid;
	cout<<"\nEnter "<<m*n<<" characters i.e in the form of 'X', 'Y' & 'O': ";
	for (int i = 0; i < m; ++i)
	{
		vector<char> col;
		for (int j = 0; j < n; ++j)
		{
			char c;
			cin>>c;
			col.push_back(toupper(c));
		}
		grid.push_back(col);
	}
	cout<<"\nGrid Entered\n";
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
	dis = shortestXYDist(grid, m, n);
	cout<<"\nThe shortest XY distance found is: "<<dis;
	return 0;
}