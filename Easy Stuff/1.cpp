// 1. print all natural numbers from 1 to n

#include<stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter how many numbers you want to print: ");
	scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
    	printf("%d\n", i);
    }
	return 0;
}