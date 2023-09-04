//! Flood fill Algorithm

// An image is represented by a 2-D array of integers,
// each integer representing the pixel value of the image.

// Given a coordinate (sr, sc) representing the starting
// pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

// To perform a "flood fill", consider the starting pixel,
// plus any pixels connected 4-directionally to the starting
// pixel of the same color as the starting pixel, plus any
// pixels connected 4-directionally to those pixels
// (also with the same color as the starting pixel), and so on.
// Replace the color of all of the aforementioned pixels with the newColor.

// Example 1:

// Input: image = {{1,1,1},{1,1,0},{1,0,1}},
// sr = 1, sc = 1, newColor = 2.
// Output: {{2,2,2},{2,2,0},{2,0,1}}
// Explanation: From the center of the image
// (with position (sr, sc) = (1, 1)), all
// pixels connected by a path of the same color
// as the starting pixel are colored with the new
// color.Note the bottom corner is not colored 2,
// because it is not 4-directionally connected to
// the starting pixel.

// Your Task:
// You don't need to read or print anyhting.
// Your task is to complete the function floodFill() which takes image,
// sr, sc and newColor as input paramater and returns the image after flood filling.

// Expected Time Compelxity: O(n*m)
// Expected Space Complexity: O(n*m)

// Constraints:
// 1 <= n <= m <= 100
// 0 <= pixel values <= 10
// 0 <= sr <= (n-1)
// 0 <= sc <= (m-1)

#include<bits/stdc++.h>
using namespace std;

void dfs(int x, int y, vector<vector<int>>& image, int prevC, int newColor, int n, int m) {
	if (x < 0 || y < 0 || x >= n || y >= m || image[x][y] != prevC) return;
	image[x][y] = '-';
	dfs(x, y + 1, image, prevC, newColor, n, m);
	dfs(x + 1, y, image, prevC, newColor, n, m);
	dfs(x, y - 1, image, prevC, newColor, n, m);
	dfs(x - 1, y, image, prevC, newColor, n, m);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	int n = image.size(); // rows
	if (n == 0) return image;
	int m = image[0].size(); // columns
	dfs(sr, sc, image, image[sr][sc], newColor, n, m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (image[i][j] == image[sr][sc])
				image[i][j] = newColor;
			else if (image[i][j] == '-')
				image[i][j] = image[sr][sc];
		}
	}
	return image;
}

int main(int argc, char const *argv[])
{
	int n, m;
	cout << "Enter the number of rows and columns: ";
	cin >> n >> m;
	cout << "Enter " << n*m << " pixels of the image: ";
	vector<vector<int>> image;
	int newColor;

	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < m; j++) {
			int data;
			cin >> data;
			temp.push_back(data);
		}
		image.push_back(temp);
	}
	cout << "Enter the value of new color to flood fill: ";
	cin >> newColor;
	int sr, sc;
	cout << "Enter the starting and ending position of the pixel to floodFill: ";
	cin >> sr >> sc;

	vector<vector<int>> ans = floodFill(image, sr, sc, newColor);
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