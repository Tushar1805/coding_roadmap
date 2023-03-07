// 28. C program to find sum of all prime numbers between 1 to n

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n, prime, sum = 0;
	printf("Enter any number: ");
	scanf("%d", &n);
	printf("\nSum of All prime numbers between 1 to %d = ", n);
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
		prime == 0 ? sum+=i : printf("");
	}
	printf("%d", sum);
	return 0;
}