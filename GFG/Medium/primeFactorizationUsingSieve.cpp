//! Prime Factorization using Sieve

// You are given a positive number N. Using the concept of Sieve, compute its prime factorisation.

// Example:

// Input:
// N = 12246
// Output:
// 2 3 13 157
// Explanation:
// 2*3*13*157 = 12246 = N.
// Your Task:

// Comple the function findPrimeFactors(), which takes a positive number
// N as input and returns a vector consisting of prime factors.
// You should implement Sieve algorithm to solve this problem.

// Expected Time Complexity: O(Nlog(log(N)).

// Expected Auxiliary Space: O(N).

// Constraints:

// 1<=N<=2*105

#include<bits/stdc++.h>
using namespace std;

void mySieve(vector<int>&prime, int n) {
	for (int i = 1; i <= n; i++) {
		prime[i] = i;
	}
	for (int i = 2; i * i <= n; i++) {
		if (prime[i] == i) {
			for (int j = i * i; j <= n; j += i) {
				if (prime[j] == j)
					prime[j] = i;
			}
		}
	}
}

vector<int> findPrimeFactors(int N) {

	vector<int> prime(N + 1);
	mySieve(prime, N);
	vector<int> ans;

	while (N != 1) {
		ans.push_back(prime[N]);
		N = N / prime[N];
	}

	return ans;
}
int main(int argc, char const *argv[])
{
	cout << "Enter number of testcases: ";
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << "Prime Factors of " << n << " : ";
		vector<int> ans = findPrimeFactors(n);
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}