//! Replace O's with X's

// Given a matrix mat of size N x M where every element is either 'O' or 'X'.
// Replace all 'O' with 'X' that are surrounded by 'X'.

// A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X'
// at locations just below, just above, just left and just right of it.

// Example 1:

// Input:
// n = 5, m = 4
// mat = {{'X', 'X', 'X', 'X'},
//        {'X', 'O', 'X', 'X'},
//        {'X', 'O', 'O', 'X'},
//        {'X', 'O', 'X', 'X'},
//        {'X', 'X', 'O', 'O'}}
// Output:
// ans = {{'X', 'X', 'X', 'X'},
//        {'X', 'X', 'X', 'X'},
//        {'X', 'X', 'X', 'X'},
//        {'X', 'X', 'X', 'X'},
//        {'X', 'X', 'O', 'O'}}
// Explanation:
// Following the rule the above matrix is the resultant matrix.
// Example 2:

// Input:
// n = 5, m = 4
// mat = {{'X', 'O', 'X', 'X'},
//        {'X', 'O', 'X', 'X'},
//        {'X', 'O', 'O', 'X'},
//        {'X', 'O', 'X', 'X'},
//        {'X', 'X', 'O', 'O'}}
// Output:
// ans = {{'X', 'O', 'X', 'X'},
//        {'X', 'O', 'X', 'X'},
//        {'X', 'O', 'O', 'X'},
//        {'X', 'O', 'X', 'X'},
//        {'X', 'X', 'O', 'O'}}
// Explanation:
// Following the rule the above matrix is the resultant matrix.
// Your Task:
// You do not need to read input or print anything. Your task is to complete
// the function fill() which takes N, M and mat as input parameters ad returns a
// 2D array representing the resultant matrix.

// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n*m)

//! We are gonna solve this problem using flood fill algorithm

#include<bits/stdc++.h>
using namespace std;

void dfs(int x, int y, vector<vector<char>> &mat, int n, int m) {
	if (x<0 or y< 0 or x >= n or y >= m or mat[x][y] != 'O') return;
	mat[x][y] = 'T';
	dfs(x, y + 1, mat, n, m);
	dfs(x + 1, y, mat, n, m);
	dfs(x, y - 1, mat, n, m);
	dfs(x - 1, y, mat, n, m);
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
	if (n == 0)
		return mat;

	// Moving in first and last column
	for (int i = 0; i < n ; i++) {
		if (mat[i][0] == 'O')
			dfs(i, 0, mat, n, m);
		if (mat[i][m - 1] == 'O')
			dfs(i, m - 1, mat, n, m);
	}

	// Moving in first and last row
	for (int j = 0; j < m; j++) {
		if (mat[0][j] == 'O')
			dfs(0, j, mat, n, m);
		if (mat[n - 1][j] == 'O')
			dfs(n - 1, j, mat, n, m);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 'O')
				mat[i][j] = 'X';
			else if (mat[i][j] == 'T')
				mat[i][j] = 'O';
		}
	}
	return mat;
}

int main(int argc, char const *argv[])
{
	int n, m;
	cout << "Enter the number of rows and columns: ";
	cin >> n >> m;
	cout << "Enter " << n*m << " (X & O, only) characters of the matrix: ";
	vector<vector<char>> mat;
	for (int i = 0; i < n; i++) {
		vector<char> temp;
		for (int j = 0; j < m; j++) {
			char data;
			cin >> data;
			temp.push_back(data);
		}
		mat.push_back(temp);
	}

	vector<vector<char>> ans = fill(n, m, mat);
	cout << "Answer: " << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}