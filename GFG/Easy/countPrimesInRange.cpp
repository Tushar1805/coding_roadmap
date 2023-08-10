//! Count Primes In Range

// Given two numbers L and R(L<R). Count all the prime numbers in the range [L, R].

// Example 1:

// Input:
// L=1,R=10
// Output:
// 4
// Explanation:
// There are 4 primes in this range,
// which are 2,3,5 and 7.
// Example 2:

// Input:
// L=5,R=10
// Output:
// 2
// Explanation:
// There are 2 primes in this range,
// which are 5 and 7.

// Your Task:
// You don't need to read input or print anything.
// Your task is to complete the function countPrimes()
// which takes the two integers L and R as input parameters
// and returns the number of prime numbers in the range [L, R].


// Expected Time Complexity:O(RLogLog(R))
// Expected Auxillary Space:O(R)


// Constraints:
// 1<=L<R<=2*105

#include<bits/stdc++.h>
using namespace std;

int countPrimes(int L, int R) {
	vector<bool> prime(R + 1, true);
	int cnt = 0;
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= R; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= R; j = j + i) {
				prime[j] = 0;
			}
		}
	}
	for (int i = L; i <= R; i++) {
		if (prime[i]) cnt++;
	}
	return cnt;
}

int main(int argc, char const *argv[])
{
	int l, r;
	cout << "Enter the range from L to R: ";
	cin >> l >> r;
	int ans = countPrimes(l, r);
	cout << "There are " << ans << " prime numbers in the range " << l << " to " << r;
	return 0;
}