// https://prepinsta.com/c-program/to-find-the-sum-of-first-n-natural-numbers/

#include<stdio.h>

int getSum(int sum,int n)
{
    if(n==0) 
        return sum;
        
    return n+getSum(sum,n-1);
}
int main(int argc, char const *argv[])
{
	int n;
	printf("Enter number: ");
	scanf("%d", &n);
	int sum = 0;

	// Iterative method
	for (int i = 1; i <= n; ++i)
	{
		sum += i;
	}
	printf("\nSum: %d", sum);

	// Direct Formula method
	sum = n*(n+1)/2;
	printf("\nSum: %d", sum);

	// Recursive Method
	sum = getSum(sum = 0, n);
	printf("\nSum: %d", sum);
	return 0;
}