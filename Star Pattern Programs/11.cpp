// * * * * *
// * *   * *
// *   *   *
// * *   * *
// * * * * *

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n, i, j, k, l;
	printf("Enter any number: ");
	scanf("%d", &n);
	l = (n * 2) - 1;
	for (int i = 1; i <= l; ++i)
	{
		for (int j = 1; j <= l; ++j)
		{
			if (i == j || j == (l - i + 1) || i == 1 || j == 1 || i == l || j == l)
			{
				printf("* ");
			}else{
				printf("  ");
			}
			
		}
		printf("\n");
	}
	return 0;
}