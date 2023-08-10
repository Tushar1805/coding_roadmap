//! Count Prime Numbers in Range
//! Sieve of Eratosthenes Theorem
//! Segemented sieve

#include<iostream>
#include<vector>
using namespace std;
int size = 1000000;
vector<bool> sieve(size + 1, true);

void createSieve() {
	for (int i = 2; i <= size; ++i)
	{
		sieve[i] = 1;
	}
	for (int i = 2; i <= size; ++i)
	{
		if (sieve[i]) {
			for (int j = i * i; j <= size; j++) {
				sieve[j] = 0;
			}
		}
	}
}

vector<int> generatePrimes(int n) {
	vector<int> p;
	for (int i = 2; i <= n; i++) {
		if (sieve[i])
			p.push_back(i);
	}
	return p;
}

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
	int t;
	cin >> t;
	while (t--) {
		// int n;
		int l, r;
		// cout << "Enter the range n: ";
		cout << "Enter Range L to R: ";
		// cin>>n;
		cin >> l >> r;
		// int ans = primeCount(n);
		// cout << "There are " << ans << " number of prime numbers between 1 to " << n << endl;

		// Step 1: Generate all the primes in range, sqrt(R)
		vector<int> primes = generatePrimes(r);

		// Step 2: Create a dummy array of size r - l + 1 and make everyone as 1
		int dummy[r - l + 1];
		for (int i = 0; i < r - l + 1; i++) {
			dummy[i] = 1;
		}

		// Step 3: for all prime number mark its multiple as 0
		for (auto pr : primes) {
			int firstMultiple = (l / pr) * pr;
			if (firstMultiple < l) firstMultiple += pr;

			for (int j = max(pr * pr, firstMultiple); j <= r; j += pr) {
				dummy[j - l] = 0;
			}
		}

		// Step 4: Get all the primes
		for (int i = l; i <= r; i++) {
			if (dummy[i - l]) {
				cout << i << " ";
			}
		}
	}
	return 0;
}