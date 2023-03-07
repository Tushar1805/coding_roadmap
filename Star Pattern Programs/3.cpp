//         *
//       * *
//     * * *
//   * * * *
// * * * * *

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int rows, i, j, k;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	printf("\n");
	for (int i = rows; i > 0; --i)
	{
		for (int k = 0; k < (i * 2) - 2; ++k)
		{
			printf(" ");
		}
		for (int j = rows; j >= i; --j)
		{
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}