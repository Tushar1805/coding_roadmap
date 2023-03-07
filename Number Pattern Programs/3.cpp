//         1
//       2 1
//     3 2 1
//   4 3 2 1
// 5 4 3 2 1

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int rows, i, j, k, l;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	l = rows * 2;
	for ( i = 1; i <= rows; ++i)
	{
		for ( k = 0; k < l - 2; ++k)
		{
			printf(" ");
		}
		for ( j = i; j >= 1; --j)
		{
			printf("%d ", j);
		}
		l -= 2;
		printf("\n");
	}
	return 0;
}