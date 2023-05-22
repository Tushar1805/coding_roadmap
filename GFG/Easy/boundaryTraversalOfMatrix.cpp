//! Boundary traversal of matrix

// You are given a matrix of dimensions n x m.
// The task is to perform boundary traversal on the matrix in a clockwise manner.

// Example 1:

// Input:
// n = 4, m = 4
// matrix[][] = {{1, 2, 3, 4},
//          {5, 6, 7, 8},
//          {9, 10, 11, 12},
//          {13, 14, 15,16}}
// Output: 1 2 3 4 8 12 16 15 14 13 9 5
// Explanation:
// The matrix is:
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16
// The boundary traversal is:
// 1 2 3 4 8 12 16 15 14 13 9 5
// Example 2:

// Input:
// n = 3, m = 4
// matrrix[][] = {{12, 11, 10, 9},
//          {8, 7, 6, 5},
//          {4, 3, 2, 1}}
// Output: 12 11 10 9 5 1 2 3 4 8

// Your Task:
// Complete the function boundaryTraversal() that takes matrix,
// n and m as input parameters and returns the list of integers that
// form the boundary traversal of the matrix in a clockwise manner.

// Expected Time Complexity: O(N + M)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= n, m<= 100
// 0 <= matrixi <= 1000

#include<bits/stdc++.h>
using namespace std;

//Function to return list of integers that form the boundary
//traversal of the matrix in a clockwise manner.
vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m)
{
	int left = 0, top = 0, right = m - 1, bottom = n - 1;
	vector<int> ans;
	for (int i = left; i <= right; i++) {
		ans.push_back(matrix[top][i]);
	}
	top++;
	for (int i = top; i <= bottom; i++) {
		ans.push_back(matrix[i][right]);
	}
	right--;
	if (top <= bottom) {
		for (int i = right; i >= left; i--) {
			ans.push_back(matrix[bottom][i]);
		}
		bottom--;
	}
	if (left <= right) {
		for (int i = bottom; i >= top; i--) {
			ans.push_back(matrix[i][left]);
		}
		left++;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n, m;
	cout << "Enter the number of rows and column: ";
	cin >> n >> m;
	vector<vector<int>> matrix;
	cout << endl << "Enter " << n*m << " elements of the matrix only (0 & 1): ";
	for (int i = 0; i < n; ++i)
	{
		vector<int> temp;
		for (int j = 0; j < m; ++j)
		{
			int data;
			cin >> data;
			temp.push_back(data);
		}
		matrix.push_back(temp);
	}
	vector<int> ans = boundaryTraversal(matrix, n, m);
	cout << "\nResultant boundary traversal: \n";
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
	return 0;
}