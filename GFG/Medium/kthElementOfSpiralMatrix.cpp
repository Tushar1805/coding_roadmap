//! Spiral Matrix

// Given a matrix of size N x M.
// You have to find the Kth element which will obtain
// while traversing the matrix spirally starting from the top-left corner of the matrix.

// Example 1:

// Input:
// N = 3, M = 3, K = 4
// A[] = {{1, 2, 3},
//        {4, 5, 6},
//        {7, 8, 9}}
// Output:
// 6
// Explanation: Spiral traversal of matrix:
// {1, 2, 3, 6, 9, 8, 7, 4, 5}. Fourth element
// is 6.
// Example 2:

// Input:
// N = 2, M = 2, K = 2
// A[] = {{1, 2},
//        {3, 4}}
// Output:
// 2
// Explanation: Spiral traversal of matrix:
// {1, 2, 4, 3}. Second element is 2.
// Your Task:
// You don't need to read input or print anything.
// Complete the function findK() which takes the matrix A[ ][ ],
// number of rows N, number of columns M, and integer K as input parameters
// and returns the Kth element in the spiral traversal of the matrix.

// Expected Time Complexity: O(N*M)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ K ≤ N*M ≤ 106

#include<bits/stdc++.h>
using namespace std;

int findK(vector<vector<int>> &matrix, int n, int m, int k)
{
	int left = 0, top = 0, right = m - 1, bottom = n - 1;
	vector<int> ans;
	while (top <= bottom && left <= right) {
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
	}
	return ans[k - 1];
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
	int k;
	cout << "\nEnter the position of element you want: ";
	cin >> k;
	int ans = findK(matrix, m, n, k);
	cout << "\nResultant element: " << ans;
	return 0;
}