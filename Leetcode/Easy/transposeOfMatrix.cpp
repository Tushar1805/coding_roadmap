//! Transpose of Matrix (m*n)

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	vector<vector<int>> ans(m, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans[j][i] = matrix[i][j];
		}
	}
	return ans;
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
	vector<vector<int>> ans;
	ans = transpose(matrix);
	cout << "\nTranspose of matrix: " << endl;
	int row = ans.size();
	int column = ans[0].size();
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}