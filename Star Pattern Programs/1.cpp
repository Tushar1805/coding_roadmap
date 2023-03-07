// *
// * *
// * * *
// * * * *
// * * * * *

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int rows, i, j;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	printf("\n");
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}