// 6. find sum of all natural numbers between 1 to n

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n, sum=0;
	printf("Enter how many numbers you want: ");
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		sum+=i;
	}
	printf("\n\nThe sum of 1 to %d natural numbers = %d", n, sum);
	return 0;
}