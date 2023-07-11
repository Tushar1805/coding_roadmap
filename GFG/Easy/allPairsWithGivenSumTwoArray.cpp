//! Find all pairs with a given sum

// Given two unsorted arrays A of size N and B of size M of distinct elements,
// the task is to find all pairs from both arrays whose sum is equal to X.

// Note: All pairs should be printed in increasing order of u.
// For eg. for two pairs (u1,v1) and (u2,v2), if u1 < u2 then
// (u1,v1) should be printed first else second.

// Example 1:

// Input:
// A[] = {1, 2, 4, 5, 7}
// B[] = {5, 6, 3, 4, 8}
// X = 9
// Output:
// 1 8
// 4 5
// 5 4
// Explanation:
// (1, 8), (4, 5), (5, 4) are the
// pairs which sum to 9.
// Example 2:
// Input:
// A[] = {-1, -2, 4, -6, 5, 7}
// B[] = {6, 3, 4, 0}
// X = 8
// Output:
// 4 4
// 5 3

// Your Task:
// You don't need to read input or print anything.
// Your task is to complete the function allPairs()
// which takes the array A[], B[], its size N and M respectively,
// and an integer X as inputs and returns the sorted vector pair values of
// all the pairs u,v where u belongs to array A and v belongs to array B.
// If no such pair exists return empty vector pair.

// Expected Time Complexity: O(NLog(N))
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N, M ≤ 106
// -106 ≤ X, A[i], B[i] ≤ 106

#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> allPairs(int A[], int B[], int N, int M, int X)
{
	vector<pair<int, int>> ans;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i] + B[j] == X) {
				pair<int, int> p;
				p.first = A[i];
				p.second = B[j];
				ans.push_back(p);
			}
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

int main(int argc, char const *argv[])
{
	int n, m;
	cout << "Enter the size of two Arrays: ";
	cin >> n >> m;
	int a[n], b[m];
	cout << "\nEnter " << n << " elements of first array: ";
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	cout << "\nEnter " << m << " elements of second array: ";
	for (int i = 0; i < m; ++i)
	{
		cin >> b[i];
	}
	int x;
	cout << "\nEnter the sum you want to find the pairs for: ";
	cin >> x;
	vector<pair<int, int>> ans = allPairs(a, b, n, m, x);
	cout << endl << "All Pairs: " << endl;
	for (int i = 0; i < ans.size(); ++i)
	{
		pair<int, int> p = ans[i];
		cout << endl << p.first << " " << p.second;
	}
	return 0;
}