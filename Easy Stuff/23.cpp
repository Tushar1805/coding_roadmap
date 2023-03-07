// 23. calculate factorial of a number

#include<stdio.h>
long long int factorial(int n){
	if (n >= 1)
	{
		return n * factorial(n-1); 
	}else{
		return 1;
	}
}
int main(int argc, char const *argv[])
{
	int n;
	long long int fact = 1;
	printf("Enter any number: ");
	scanf("%d", &n);
	// for (int i = 1; i <= n; ++i)
	// {
	// 	fact = fact * i;
	// }
	fact = factorial(n); // Using recursion
	printf("The Factorial of %d = %lld", n, fact);
	return 0;
}