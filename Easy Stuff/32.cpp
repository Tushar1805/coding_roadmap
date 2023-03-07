// 32. Check whether a number is perfect number or not

// perfect number, a positive integer that is equal to the sum of its proper divisors. 
// The smallest perfect number is 6, which is the sum of 1, 2, and 3. Other perfect numbers are 28, 496, and 8,128.

#include<stdio.h>

int main(int argc, char const *argv[])
{
	int n, count = 1, sum = 0;
	printf("Enter any positive integer: ");
	scanf("%d", &n);
	int org = n;
	for (int i = 1; i <= org/2; ++i)
	{
		if (n % i == 0)
		{
			sum += i;
		}
	}
	if (org == sum)
	{
		printf("\n%d is the perfect number", org);
	}else{
		printf("\n%d is not the perfect number", org);
	}
	return 0;
}