// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5
// 1 2 3 4
// 1 2 3
// 1 2
// 1

#include <stdio.h>
int main(int argc, char const *argv[])
{
	int rows, i, j;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	for (i = 1; i <= rows; ++i)
	{
		for (j = 1; j <= i; ++j)
		{
			printf("%d ", j);
		}
		printf("\n");
	}
	for (i = rows -1; i >= 1; --i)
	{
		for (j = 1; j <= i; ++j)
		{
			printf("%d ", j);
		}
		printf("\n");
	}
	return 0;
}