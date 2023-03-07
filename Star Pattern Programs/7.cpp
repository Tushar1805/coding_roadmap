// *               *
// * *           * *
// * * *       * * *
// * * * *   * * * *
// * * * * * * * * *

#include<stdio.h>

int main(int argc, char const *argv[])
{
	int rows, i, j, k, l, m, n;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	l = rows * 4;
	n = l-4;
	for (i = 0; i < rows; ++i)
	{
		for (j = 0; j <= i ; ++j)
		{
			printf("* ");
		}
		for (k = 0; k < (l-4) - 2; ++k)
		{
			printf(" ");
		}
		if (i == rows -1)
		{
			for (m = k+1; m <= n - i; ++m)
			{
				printf("* ");
			}
		}else{
			for (m = k+1; m <= n - i - 1; ++m)
			{
					printf("* ");
			}
		}
		printf("\n");
		l -= 4;	
		n = n-2;	
	}
	return 0;
}