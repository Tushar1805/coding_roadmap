// 9 8 7 6 5 4 3 2 1
//   7 6 5 4 3 2 1
//     5 4 3 2 1
//       3 2 1 
//         1

#include <stdio.h>
int main(int argc, char const *argv[])
{
	int rows, i, j, k, l;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	l = 0;
	for (i = 1; i <= rows; ++i)
	{
		for(k = 0; k < l; k++){
			printf(" ");
		}
		for (j = (rows * 2) - (k + 1); j >= 1 ; --j)
		{
			printf("%d ", j);
		}
		l += 2;
		printf("\n");
	}
	return 0;
}