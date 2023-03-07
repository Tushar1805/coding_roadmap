// 22. find all factors of a number

#include<stdio.h>
int main(int argc, char const *argv[])
{
	long long int n;
	int fact;
	printf("Enter any number: ");
	scanf("%lld", &n);

	// logic to get factors in pairs

	// for (int i = 1; i <= n; ++i)
	// {
	// 	for (int j = i; j <= n; ++j)
	// 	{
	// 		fact = i * j;
	// 		if (fact == n)
	// 		{
	// 			printf("\nFactors of %d = %d * %d", n, i, j);
	// 		}else if(fact > n){
	// 			break;
	// 		}
	// 	}
	// }

	// To find all factors
	printf("\nFactors of %d = ", n);
	for (int i = 1; i <= n; ++i)
	{
		if (n%i==0)
		{
			printf("%d ", i);
		}
	}

	return 0;
}