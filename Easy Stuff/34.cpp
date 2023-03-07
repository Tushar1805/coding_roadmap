// 34. check whether a number is strong number or not

// A number can be said as a strong number when the sum of the factorial of the individual digits is equal to the number.
// For example, 145 is a strong number.

#include<stdio.h>
int factorial(int n){
	int fact = 1;
	for (int i = 2; i <= n; ++i)
	{
		fact = fact * i;
	}
	return fact;
}
int main(int argc, char const *argv[])
{
	int n, rem, sum = 0;
	printf("Enter any positive integer: ");
	scanf("%d", &n);

	int org = n;

	while(n!=0){
		rem = n % 10;
		sum += factorial(rem);
		n /= 10;
	}
	if (sum == org)
	{
		printf("\n%d is strong number", org);
	}else{
		printf("\n%d is not strong number", org);
	}
	return 0;
}