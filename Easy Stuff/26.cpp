// 26. C program to check whether a number is prime or not

// Prime Number - a whole number greater than 1 that cannot be exactly divided by any whole number other than itself and 1

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n, flag = 0;
	printf("Enter any number: ");
	scanf("%d", &n);

	if (n == 0 || n == 1)
	{
		flag = 1;
	}else{
		for (int i = 2; i <= n/2; ++i)
		{
			if (n%i == 0)
			{
				flag = 1;
				break;
			}
		}
	}

	flag == 0 ? printf("\n%d is a prime number", n) : printf("\n%d is not a prime number", n);
	return 0;
}