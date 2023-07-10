//! Spirally traversing a matrix

// Given a matrix of size r*c. Traverse the matrix in spiral form.

// Example 1:

// Input:
// r = 4, c = 4
// matrix[][] = {{1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {9, 10, 11, 12},
//            {13, 14, 15,16}}
// Output:
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
// Explanation:

// Example 2:

// Input:
// r = 3, c = 4
// matrix[][] = {{1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {9, 10, 11, 12}}
// Output:
// 1 2 3 4 8 12 11 10 9 5 6 7
// Explanation:
// Applying same technique as shown above,
// output for the 2nd testcase will be
// 1 2 3 4 8 12 11 10 9 5 6 7.

// Your Task:
// You dont need to read input or print anything.
// Complete the function spirallyTraverse() that takes matrix, r and c as input parameters and returns a list of integers denoting the spiral traversal of matrix.

// Expected Time Complexity: O(r*c)
// Expected Auxiliary Space: O(r*c), for returning the answer only.

// Constraints:
// 1 <= r, c <= 100
// 0 <= matrixi <= 100


#include<bits/stdc++.h>
using namespace std;

//Function to return a list of integers denoting spiral traversal of matrix.
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)
{
	int left = 0, top = 0, right = c - 1, bottom = r - 1;
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
	vector<int> ans = spirallyTraverse(matrix, m, n);
	cout << "\nSpirally traversed elements: " << endl;
	for (int i = 0; i < m * n; ++i)
	{
		cout << ans[i] << " ";
	}
	return 0;
}