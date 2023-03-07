// 5
// 4 5
// 3 4 5
// 2 3 4 5
// 1 2 3 4 5

#include <stdio.h>
int main(int argc, char const *argv[])
{
	int rows, i, j;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	for (i = rows; i >= 1; --i)
	{
		for(j = i; j <= rows ; j++){
			printf("%d ", j);
		}
		printf("\n");
	}
	return 0;
}