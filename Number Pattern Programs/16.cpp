//         1
//       1 2 3
//     1 2 3 4 5 
//   1 2 3 4 5 6 7 
// 1 2 3 4 5 6 7 8 9

#include <stdio.h>
int main(int argc, char const *argv[])
{
	int rows, i, j, k, l, m = 1;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	l = rows * 2;
	for (i = 1; i <= rows; ++i)
	{
		for(k = 0; k < l -2; k++){
			printf(" ");
		}
		for (j = 1; j <= m ; ++j)
		{
			printf("%d ", j);
		}
		m += 2;
		l -= 2;
		printf("\n");
	}
	return 0;
}
