//! Count Prime Numbers in Range
//! Sieve and Eratosthenes Theorem

#include<iostream>
#include<vector>
using namespace std;

int primeCount(int n) {
	int cnt = 0;
	vector<bool> prime(n + 1, true);
	prime[0] = prime[1] = false;

	for (int i = 2; i <= n; i++) {
		if (prime[i])
			cnt++;
		for (int j = 2 * i; j <= n;  j = j + i)
		{
			prime[j] = 0;
		}
	}
	return cnt;
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the range n: ";
	cin >> n;
	int ans = primeCount(n);
	cout << "There are " << ans << " number of prime numbers between 1 to " << n;
	return 0;
}