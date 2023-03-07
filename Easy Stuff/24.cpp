// 24. C program to find HCF (GCD) of two numbers
// HCF - Highest Common Factor
// GCD - Greatest Common Divisor

#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n1, n2, fact;
	printf("Enter two numbers: ");
	scanf("%d %d", &n1, &n2);

	for (int i = 1; i <= n1 && i <= n2; ++i)
	{
		if (n1 % i == 0 && n2 % i == 0)
		{
			fact = i;
		}
	}

	printf("\nHCF of %d & %d = %d", n1, n2, fact);

	return 0;
}