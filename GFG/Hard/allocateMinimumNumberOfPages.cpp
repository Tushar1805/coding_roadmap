//! Allocate minimum number of pages

// You have N books, each with Ai number of pages.
// M students need to be allocated contiguous books,
// with each student getting at least one book. Out of all the permutations,
// the goal is to find the permutation where the student with
// the most books allocated to him gets the minimum number of pages,
// out of all possible permutations.

// Note: Return -1 if a valid assignment is not possible,
// and allotment should be in contiguous order (see the explanation for better understanding).

// Example 1:

// Input:
// N = 4
// A[] = {12,34,67,90}
// M = 2
// Output:113
// Explanation:Allocation can be done in
// following ways:
// {12} and {34, 67, 90} Maximum Pages = 191
// {12, 34} and {67, 90} Maximum Pages = 157
// {12, 34, 67} and {90} Maximum Pages =113.
// Therefore, the minimum of these cases is 113,
// which is selected as the output.

// Example 2:

// Input:
// N = 3
// A[] = {15,17,20}
// M = 2
// Output:32
// Explanation: Allocation is done as
// {15,17} and {20}
// Your Task:
// You don't need to read input or print anything.
// Your task is to complete the function findPages()
// which takes 2 Integers N, and m and an array A[]
// of length N as input and returns the expected answer.

// Expected Time Complexity: O(NlogN)
// Expected Auxilliary Space: O(1)

// Constraints:
// 1 <= N <= 105
// 1 <= A [ i ] <= 106
// 1 <= M <= 105

#include<bits/stdc++.h>
using namespace std;

bool getPossibleSol(int A[], int mid, int M, int N) {
	int pages = 0;
	int s = 1;
	for (int i = 0; i < N; i++) {
		if ((pages + A[i]) <= mid) {
			pages += A[i];
		} else {
			s++;
			if (s > M || A[i] > mid) {
				return false;
			}
			pages = A[i];
		}
	}
	return true;
}
int findPages(int A[], int N, int M)
{
	int ans = -1;
	long long int r = 0;
	if (M > N)
		return -1;
	for (int i = 0; i < N; i++) {
		r += A[i];
	}
	long long int l = 0;
	long long int mid;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (getPossibleSol(A, mid, M, N)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n, m;
	cout << "Enter the number of books: ";
	cin >> n;
	cout << "Enter the number of students: ";
	cin >> m;
	cout << "Enter the pages of " << n << " books: ";
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int ans = findPages(a, n, m);
	cout << "Minimum number of pages: " << ans;
	return 0;
}