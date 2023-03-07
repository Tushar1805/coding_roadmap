//         1
//       2 1 2
//     3 2 1 2 3
//   4 3 2 1 2 3 4
// 5 4 3 2 1 2 3 4 5

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int rows, i, j , k, l, m;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	l = rows * 2;
	for(i = 1; i <= rows; i++){
		for (k = 0; k < l -2; ++k)
		{
			printf(" ");
		}
		for(j = i; j >= 1; --j){
			printf("%d ", j);
		}
		for (m = 2; m <= i; ++m)
		{
			printf("%d ", m);
		}
		printf("\n");
		l -= 2;
	}
	return 0;
}