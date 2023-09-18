// 27. C program to print all prime numbers between 1 to n

#include<stdio.h>
#include<vector>
using namespace std;

//! Sieve of Eractosthenas theorem

//! TC - O(n logn)
void sieve(vector<bool>& primes) {
	int n = primes.size();
	for (int i = 2; i * i < n; i++) {
		if (primes[i]) {
			for (int j = i * i; j < n; j = j + i) {
				if (primes[j]) primes[j] = false;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int n, prime;
	printf("Enter any number: ");
	scanf("%d", &n);

	std::vector<bool> primes(n + 1, true);
	primes[0] = primes[1] = false;
	sieve(primes);
	printf("\nAll prime numbers between 1 to %d", n);

	//! TC - O(n^2)
	// for (int i = 2; i <= n; ++i)
	// {
	// 	prime = 0;
	// 	for (int j = 2; j <= i/2; ++j)
	// 	{
	// 		if (i%j==0)
	// 		{
	// 			prime = 1;
	// 			break;
	// 		}
	// 	}
	// 	prime == 0 ? printf("\n%d", i) : printf("");
	// }

	for (int i = 0; i < primes.size(); ++i)
	{
		if (primes[i]) printf("\n%d", i);
	}
	return 0;
}