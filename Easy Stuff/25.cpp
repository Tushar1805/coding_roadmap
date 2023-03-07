// 25. C program to find LCM of two numbers
#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n1, n2, gcd, lcm, max;
	printf("Enter two numbers: ");
	scanf("%d %d", &n1, &n2);

	printf("\n******* Logic 1 **********\n");

	// ******* Logic 1 **********

	// n1>n2 ? max = n1 : max = n2; // this line can also be written as below
	max = (n1 > n2) ? n1 : n2;
	while(1){
		if ((max % n1) == 0 && (max % n2) == 0)
		{
			printf("\nLCM of %d & %d = %d", n1, n2, max);
			break;
		}
		max++;
	}

	// ******* Logic 2 **********
	printf("\n******* Logic 2 **********\n");

	for (int i = 1; i <= n1 && i <= n2; ++i)
	{
		if (n1 % i == 0 && n2 % i == 0)
		{
			gcd = i;
		}
	}
	
	lcm = (n1 * n2) / gcd;
	printf("\nLCM of %d & %d = %d", n1, n2, lcm);
	return 0;
}