//! Pascal Triangle

// Given a positive integer N, return the Nth row of pascal's triangle.
// Pascal's triangle is a triangular array of the binomial coefficients formed
// by summing up the elements of previous row.

// Example :
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// For N = 3, return 3rd row i.e 1 2 1

// Example 1:

// Input:
// N = 4
// Output: 1 3 3 1
// Explanation: 4th row of pascal's triangle
// is 1 3 3 1.
// Example 2:

// Input:
// N = 5
// Output: 1 4 6 4 1
// Explanation: 5th row of pascal's triangle
// is 1 4 6 4 1.

// Your Task:
// Complete the function nthRowOfPascalTriangle() which takes n,
// as input parameters and returns an array representing the answer.
// The elements can be large so return it modulo 109 + 7. You don't to print answer or take inputs.

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N2)

// Constraints:
// 1 ≤ N ≤ 1000

#include<bits/stdc++.h>
using namespace std;
#define ll long long

//! Python Solution, Working
// def nthRowOfPascalTriangle(self,n):
//         # code here

//         mod = 10**9 + 7
//         ans = []

//         ans.append(1)
//         val = 1

//         for i in range(1, n):
//             val = val * (n - i)
//             val = val // i

//             ans.append(val % mod)

//         return ans

vector<ll> nthRowOfPascalTriangle(int n) {
	//! This logic is correct but gives overflow errors after 74
	// vector<ll> row;
	// ll int ans = 1;
	// row.push_back(ans);
	// ll int m = 1000000007;
	// for(ll int i=1;i<=n;i++){
	//     ans = (ans * (n-i)) ;
	//     ans = (ans / i)  ;
	//     if(ans != 0)
	//         row.push_back(ans % m);
	// }
	// return row;


	ll mod = 1e9 + 7;
	vector<vector<ll>>ans;

	ans.resize(n + 1);


	ans[1].push_back(1);

	for (int i = 2; i <= n; i++) {
		ans[i].resize(i);
		ans[i][0] = 1;
		ans[i][i - 1] = 1;
		for (int j = 1; j < i - 1; j++) {
			ans[i][j] = ((ans[i - 1][j - 1] + ans[i - 1][j])) % mod;
		}
	}

	return ans[n];
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the row number you want of the pascal triangle: ";
	cin >> n;
	vector<ll> ans = nthRowOfPascalTriangle(n);
	cout << n << "th row of pascal triangle: " << endl;
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << " ";
	}
	return 0;
}