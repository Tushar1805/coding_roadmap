// Spiral traversal of the matrix

#include<bits/stdc++.h>
using namespace std;

// Example 1:
// Input: Matrix[][] = { { 1, 2, 3, 4 },
// 	      			{ 5, 6, 7, 8 },
// 	      			{ 9, 10, 11, 12 },
//               		{ 13, 14, 15, 16 } }

// Output: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
// Explanation: The output of matrix in spiral form.

// Example 2:
// Input: Matrix[][] = { { 1, 2, 3 },
// 	              	{ 4, 5, 6 },
// 		      		{ 7, 8, 9 } }

// Output: 1, 2, 3, 6, 9, 8, 7, 4, 5.
// Explanation: The output of matrix in spiral form.

// Optimal Solution: TC- O(R*C), SC - O(R*C)
vector<int> solution(vector<vector<int>> matrix, int r, int c) {
	int left = 0;
	int right = c - 1;
	int top = 0;
	int bottom = r - 1;
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
	return  ans;
}

void display(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
}

int main(int argc, char const *argv[])
{
	int r, c;
	cout << "Enter number of rows and columns: ";
	cin >> r >> c;
	vector<vector<int>> matrix;
	cout << "Enter the " << r*c << " elements of the matrix: ";
	for (int i = 0; i < r; i++) {
		vector<int> temp;
		for (int j = 0; j < c; j++) {
			int data;
			cin >> data;
			temp.push_back(data);
		}
		matrix.push_back(temp);
	}

	vector<int> ans = solution(matrix, r, c);
	cout << "Spiral traversal of matrix: ";
	display(ans);
	return 0;
}