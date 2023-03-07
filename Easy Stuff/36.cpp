// 36. print fibonacci series up to n terms

// a series of numbers in which each number ( Fibonacci number ) is the sum of the two preceding numbers. 
// The simplest is the series 1, 1, 2, 3, 5, 8, etc.

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n, f0 = 0, f1 = 1, f2;
	printf("Enter any positive integer (less than 25): ");
	scanf("%d", &n);
	printf("\nFibonacci series: ");
	printf("%d ", f1);
	for (int i = 0; i < n; ++i)
	{
		f2 = f0 + f1;
    	printf("%d ", f2);
    	f0 = f1;
    	f1 = f2;
	}
	return 0;
}