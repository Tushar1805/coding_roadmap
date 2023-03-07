// 1 1
// 1 2 2 1
// 1 2 3 3 2 1
// 1 2 3 4 4 3 2 1
// 1 2 3 4 5 5 4 3 2 1

#include <stdio.h>
int main(int argc, char const *argv[])
{
	int rows, i, j, k;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	for (i = 1; i <= rows; ++i)
	{
		for (j = 1; j <= i; ++j)
		{
		  printf("%d ", j);
		}
		for(k = i; k>=1; k--){
			printf("%d ", k);
		}
		printf("\n");
	}
	return 0;
}