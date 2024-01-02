// Pascal's Triangle
#include<bits/stdc++.h>
using namespace std;

// Function to calculate the nCr value
int nCr(int r, int c) {
	int res = 1;
	for (int i = 0; i < c; i++) {
		res = res * (r - i);
		res = res / (i + 1);
	}
	return res;
}

// Varient 1: Given the row number r and column number c
// find the element ar (r, c) in pascal's triangle
void variation1() {
	int r, c;
	cout << "Enter the row number: ";
	cin >> r;
	cout << "Enter the column number: ";
	cin >> c;
	int res = nCr(r - 1, c - 1);
	cout << "Element at position (" << r << ", " << c << ") is: " << res << endl;
}

// Variation 2: Given the row number r print the row
// TC - O(r), row number
void variation2() {
	int r;
	cout << "Enter the row number: ";
	cin >> r;
	int ans = 1;
	cout << ans << " ";
	for (int i = 1; i < r; i++) {
		ans = ans * (r - i);
		ans = ans / i;
		cout << ans << " ";
	}

}

void display(vector<vector<long long int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

// Variation 3: Given the number of rown n, print the first n rows of pascal's triangle
void variation3() {
	int n;
	cout << "Enter the number of rows: ";
	cin >> n;

	// Naive approach use of nCr function, TC - approx O(n^3)
	vector<vector<long long int>> pascal;
	// for (int i = 1; i <= n; i++) {
	// 	vector<int> temp;
	// 	for (int j = 1; j <= i; j++) {
	// 		temp.push_back(nCr(i - 1, j - 1));
	// 	}
	// 	pascal.push_back(temp);
	// }

	// cout << "Pascal's triangle" << endl;
	// display(pascal);

	// Optimal Approach, TC -O(n * r)
	for (int row = 1; row <= n; row++) {
		long long int ans = 1;
		vector<long long int> temp;
		temp.push_back(ans);
		for (int col = 1; col < row; col++) {
			ans = ans * (row - col);
			ans = ans / col;
			temp.push_back(ans);
		}
		pascal.push_back(temp);
	}

	cout << "Pascal's triangle" << endl;
	display(pascal);
}

int main(int argc, char const *argv[])
{
	int ch;
	cout << "Enter 1 for variation 1\nEnter 2 for variation 2\nEnter 3 for variation 3\n";
	cout << "Enter your choice: ";
	cin >> ch;
	switch (ch) {
	case 1:
		variation1();
		break;
	case 2:
		variation2();
	case 3:
		variation3();
		break;
	default:
		cout << "Invalid Choice!" << endl;
	}

	return 0;
}