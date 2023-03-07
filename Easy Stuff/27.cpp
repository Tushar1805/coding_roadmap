// 27. C program to print all prime numbers between 1 to n

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n, prime;
	printf("Enter any number: ");
	scanf("%d", &n);
	printf("\nAll prime numbers between 1 to %d", n);
	for (int i = 2; i <= n; ++i)
	{
		prime = 0;
		for (int j = 2; j <= i/2; ++j)
		{
			if (i%j==0)
			{
				prime = 1;
				break;
			}
		}
		prime == 0 ? printf("\n%d", i) : printf("");
	}
	return 0;
}