// 1
// 0 1
// 1 0 1
// 0 1 0 1
// 1 0 1 0 1

#include <stdio.h>
int main(int argc, char const *argv[])
{
	int rows, i, j, x, y;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	for (i = 1; i <= rows; ++i)
	{
		if (i % 2 == 0)
		{
			x = 1;
			y = 0;
		}else{
			x = 0;
			y = 1;
		}
		for(j = 1; j <= i; j++){
			if (j%2 == 0)
			{
				printf("%d ", x);
			}else{
				printf("%d ", y);
			}
		}
		printf("\n");
	}
	return 0;
}