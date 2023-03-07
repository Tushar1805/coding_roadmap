// * * * * * * * * * 
// * * * *   * * * *
// * * *       * * *
// * *           * *
// *               *

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int rows, i, j, k, l, m, n, c = 0;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	l = -1;
	n = rows;
	for (int i = rows; i > 0; --i)
	{
		for (j = 0; j < i; ++j)
		{
			printf("* ");
		}
		for (k = 0; k < l-1; ++k)
		{
			printf(" ");
		}
		if (c == 0)
		{
			for (m = k+1; m <= n - c -1 ; ++m)
			{
				printf("* ");
			}
		}else{
			for (m = k+1; m < n - c -1; ++m)
			{
				printf("* ");
			}
		}
		printf("\n");
		l += 4;	
		// printf("L=%d",l);
		n = n + 4;
		c++;
	}
	return 0;
}