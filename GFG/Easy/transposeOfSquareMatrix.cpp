//! Transpose of Square Matrix

// Write a program to find the transpose of a square matrix of size N*N.
// Transpose of a matrix is obtained by changing rows to columns and columns to rows.

// Example 1:

// Input:
// N = 4
// mat[][] = {{1, 1, 1, 1},
//            {2, 2, 2, 2}
//            {3, 3, 3, 3}
//            {4, 4, 4, 4}}
// Output:
// {{1, 2, 3, 4},
//  {1, 2, 3, 4}
//  {1, 2, 3, 4}
//  {1, 2, 3, 4}}
// Example 2:

// Input:
// N = 2
// mat[][] = {{1, 2},
//            {-9, -2}}
// Output:
// {{1, -9},
//  {2, -2}}

// Your Task:
// You dont need to read input or print anything.
// Complete the function transpose() which takes matrix[][] and N as input parameter
//  and finds the transpose of the input matrix. You need to do this in-place.
//  That is you need to update the original matrix with the transpose.

// Expected Time Complexity: O(N * N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 103
// -109 <= mat[i][j] <= 109

#include<bits/stdc++.h>
using namespace std;
void transpose(vector<vector<int> >& matrix, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
}

int main(int argc, char const *argv[])
{
	int m, n;
	cout << "Enter the number of rows and columns present in the matrix: ";
	cin >> m >> n;
	vector<vector<int>> matrix;
	for (int i = 0; i < m; ++i)
	{
		cout << "\nEnter " << n << " elements of row " << i + 1 << ": ";
		vector<int> row;
		for (int j = 0; j < n; ++j)
		{
			int data;
			cin >> data;
			row.push_back(data);
		}
		matrix.push_back(row);
	}
	transpose(matrix, n);
	cout << "\nTranspose of matrix: " << endl;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}