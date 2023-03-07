// * * * * *
//   * * * *
//     * * *
//       * *
//         *

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int rows, i, j, k, l=0;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	printf("\n");
	for (int i = rows; i > 0; --i)
	{
		for (int k = 0; k < l; ++k)
		{
			printf(" ");
		}
		for (int j = 0; j < i; ++j)
		{
			printf("* ");
		}
		printf("\n");
		l+=2;
	}
	return 0;
}