//! Make Zeroes

// Given a matrix of  size n x m. Your task is to make Zeroes,
// that means in whole matrix when you find a zero, convert its upper, lower, left,
// and right value to zero and make that element the sum of the upper, lower, left and right value.
// Do the following tasks according to the initial matrix.

// Example 1:

// Input: matrix = {{1, 2, 3, 4},
//                  {5, 6, 0, 7},
//                  {8, 9, 4, 6},
//                  {8, 4, 5, 2}}
// Output: {{1, 2, 0, 4},
//          {5, 0, 20, 0},
//          {8, 9, 0, 6},
//          {8, 4, 5, 2}}
// Explanation: As matrix[1][2] = 0, we will
// perform the operation here. Then matrix[1][2]
// = matrix[0][2] + matrix[2][2] + matrix[1][1]
// + matrix[1][3] and matrix[0][2] = matrix[2][2]
// = matrix[1][1] = matrix[1][3] = 0.
// Example 2:

// Input: matrix = {{1, 2},
//                  {3, 4}}
// output: {{1, 2},
//          {3, 4}}

// Your Task:
// You don't need to read or print anything. Your task is to complete the function MakeZeros()
// which takes the matrix as input parameter and does the given task according to initial matrix.
// You don't need to return anything. The driver code prints the modified matrix itself in the output.

// Expected Time Complexity: O(n * m)
// Expected Space Complexity: O(n * m)

// Constraints:
// 1 ≤ n, m ≤ 100
// 0 ≤ matrix[i][j] ≤ 100, where 0 ≤ i ≤ n and 0 ≤ j ≤ m

#include<bits/stdc++.h>
using namespace std;

void MakeZeros(vector<vector<int>>& matrix) {
	vector<int> pos;
	int n = matrix.size();
	int m = matrix[0].size();
	vector<vector<int>> temp = matrix;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) {
				if (i - 1 >= 0) {
					matrix[i][j] += temp[i - 1][j];
					matrix[i - 1][j] = 0;
				}
				if (j + 1 < m) {
					matrix[i][j] += temp[i][j + 1];
					matrix[i][j + 1] = 0;
				}
				if (j - 1 >= 0) {
					matrix[i][j] += temp[i][j - 1];
					matrix[i][j - 1] = 0;
				}
				if (i + 1 < n) {
					matrix[i][j] += temp[i + 1][j];
					matrix[i + 1][j] = 0;
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int n, m;
	cout << "Enter the number of rows and column: ";
	cin >> n >> m;
	vector<vector<int>> matrix;
	cout << endl << "Enter " << n*m << " elements of the matrix: ";
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
	MakeZeros(matrix);
	cout << "\nResultant matrix: \n";
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}