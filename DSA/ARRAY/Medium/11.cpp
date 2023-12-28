// Set matrix zero

#include<bits/stdc++.h>
using namespace std;

// Input: 0 1 2 0 3 4 5 2 1 3 1 5
// output: 0 0 0 0 0 4 5 0 0 3 1 0

// Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.

// Input: matrix=[[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output:[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
// Explanation:Since matrix[0][0]=0 and matrix[0][3]=0. Therefore 1st row, 1st column and 4th column will be set to 0

void display(vector<vector<int>> matrix, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << " ";
		}
	}
}

// Brute Force: TC - O((N*M) * (N+M) + (N*M)), SC - O(1)
void solution1(vector<vector<int>>& matrix, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				// Mark col as -1
				for (int k = 0; k < n; k++) {
					if (matrix[k][j] != 0) {
						matrix[k][j] = -1;
					}
				}
				// Mark row as -1
				for (int l = 0; l < m; l++) {
					if (matrix[i][l] != 0) {
						matrix[i][l] = -1;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == -1) {
				matrix[i][j] = 0;
			}
		}
	}
}

// My approach uses a lot of space
void myApproach(vector<vector<int>>& matrix, int n, int m) {
	unordered_set<int> r_zero;
	unordered_set<int> c_zero;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				r_zero.insert(i);
				c_zero.insert(j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (r_zero.find(i) != r_zero.end() || c_zero.find(j) != c_zero.end()) {
				matrix[i][j] = 0;
			}
		}
	}

}

// Better Approach: TC - O(2 * N * M),  SC - O(N) + O(M)
void solution2(vector<vector<int>> &matrix, int n, int m) {

	vector<int> row(n, 0); // row array
	vector<int> col(m, 0); // col array
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (row[i] || col[j]) {
				matrix[i][j] = 0;
			}
		}
	}
}

// Optimal Approach: TC - O(2*N*M), SC - O(1)
void solution3(vector<vector<int>> &matrix, int n, int m) {
	// vector<int> row(n, 0); -> matrix[...][0]
	// vector<int> col(m, 0); -> matrix[0][...]
	int col0 = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				// mark row as 0
				matrix[i][0] = 0;

				// mark col as 0
				if (j != 0) {
					matrix[0][j] = 0;
				} else {
					col0 = 0;
				}

			}
		}
	}
	// mark matrix elements from i = 1, j =1;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
		}
	}

	// Now check the top row
	if (matrix[0][0] == 0) {
		for (int j = 0; j < m; j++) {
			if (matrix[0][j] != 0) matrix[0][j] = 0;
		}
	}

	// Now check the first column
	if (col0 == 0) {
		for (int i = 0; i < n; i++) {
			if (matrix[i][0] != 0) matrix[i][0] = 0;
		}
	}
}


int main(int argc, char const *argv[])
{
	int n, m;
	cout << "Enter number of rows & columns: ";
	cin >> n >> m;
	vector<vector<int>> matrix;
	cout << "Enter the " << n*m << " elements of the matrix: ";
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < m; j++) {
			int data;
			cin >> data;
			temp.push_back(data);
		}
		matrix.push_back(temp);
	}

	// solution1(matrix, n, m);
	// solution2(matrix, n, m);
	solution3(matrix, n, m);
	cout << "Elements after the operation: ";
	display(matrix, n, m);
	return 0;
}