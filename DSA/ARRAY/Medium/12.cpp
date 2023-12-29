// Rotate matrix by 90 degrees

#include<bits/stdc++.h>
using namespace std;

// Enter value of n: 3
// Enter the 9 elements of the matrix: 1 2 3 4 5 6 7 8 9
// Elements after the operation: 7 4 1 8 5 2 9 6 3

// Example 1:
// Input: [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]
// Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix.

// Example 2:
// Input: [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output:[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
// Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix

void display(vector<vector<int>> matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
	}
}

// Brute Force Approach: TC - O(n^2), SC - O(n^2)
vector<vector<int>> solution1(vector<vector<int>> mat, int n) {
	vector<vector<int>> ans(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++ ) {
			ans[j][n - 1 - i] = mat[i][j];
		}
	}
	return ans;
}

// Optimal approach, reducing space complexity
// TC - O(n^2), SC - O(1)
void solution2(vector<vector<int>> &mat, int n) {
	// Step 1: find the transpose of matrix
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++ ) {
			swap(mat[i][j], mat[j][i]);
		}
	}

	// Step 2: Reverse the rows
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n / 2; j++ ) {
			swap(mat[i][j], mat[i][n - 1 - j]);
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter value of n: ";
	cin >> n;
	vector<vector<int>> matrix;
	cout << "Enter the " << n*n << " elements of the matrix: ";
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < n; j++) {
			int data;
			cin >> data;
			temp.push_back(data);
		}
		matrix.push_back(temp);
	}

	// matrix = solution1(matrix, n);
	solution2(matrix, n);
	// solution3(matrix, n);
	cout << "Elements after the operation: ";
	display(matrix, n);
	return 0;
}