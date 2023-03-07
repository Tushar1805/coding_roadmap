// 29. Find all prime factors of a number

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n, prime;
	printf("Enter any positive integer: ");
	scanf("%d", &n);
	printf("All prime factors of %d = ", n);

	// Wrong logic, only gets the numbers which are prime and are factors of given number
	// but don't give the numbers which are repeated

	// for (int i = 2; i <= n ; ++i)
	// {
	// 	if (n%i ==0)
	// 	{
	// 		prime = 0;
	// 		for (int j = 2; j < i/2; ++j)
	// 		{
	// 			if (i%j == 0)
	// 			{
	// 				prime = 1;
	// 				break;
	// 			}
	// 		}
	// 		if (prime == 0)
	// 		{
	// 			printf("\nPrime factor of %d = %d", n, i);
	// 		}
	// 	}
	// }

	// Correct Logic

	// It works as follows
	// if n = 24, 
	// i = 2, n(24) > 1
	// iteration 1: 24 % 2 = 0, output: 2 , n = 24 / i(2), n = 12

	// iteration 2: 12 % 2 = 0, output: 2 2 , n = 12 / i(2), n = 6

	// iteration 3: 6 % 2 = 0, output: 2 2 2 , n = 6 / i(2), n = 3

	// iteration 4: 3 % 2 != 0, n(3) > 1, condtion true, i++, i = 3, 
	//              3 % 3 = 0, output: 2 2 2 3, n = 3 / i(3), n = 1
	
	// iteration 5: 1 % 3 !=0, n(1) > 1, condition false, loop breaks 

	for (int i = 2; n > 1; ++i)
	{
		while(n % i == 0){
			printf("%d ", i);
			n = n / i;
		}
	}
	return 0;
}