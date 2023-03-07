// 1
// 0 0
// 1 1 1
// 0 0 0 0
// 1 1 1 1 1

#include <stdio.h>
int main(int argc, char const *argv[])
{
	int rows, i, j;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	for (i = 1; i <= rows; ++i)
	{
		for(j = 1; j<=i; j++){
			if (i%2==0)
			{
				printf("0 ");
			}else{
				printf("1 ");
			}
		}
		printf("\n");
	}
	return 0;
}