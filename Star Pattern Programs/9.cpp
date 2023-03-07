// * * * * *
// *       *         
// *       *
// *       *
// * * * * *

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int rows, i, j, k, l, c = 0;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < rows; ++j)
		{
			if (i == 0 || i == rows -1 || j == 0 || j == rows-1)
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