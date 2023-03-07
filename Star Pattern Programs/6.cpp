// * * * * * * * * *
//   * * * * * * *
//     * * * * *
//       * * *
//         *

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int rows, i, j, k, l = 0, m;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);

	// Taking m = rows * 2, because when we take rows 5, we print "* "
	// That means we are printing 2 spaces at a time (including *) 
	// so, for full pyramid of 5 rows we need to print first star at 9, i.e "* ",
	// And if you see it includes one more space so, it goes to 10
	// if rows = 5, m = rows * 2, m = 10 

	m = rows * 2;
	for (i = 0; i < rows; ++i)
	{
		for (int k = 0; k < l; ++k)
		{
			printf(" ");
		}
		for (int j = k; j <= m; ++j)
		{
			printf("* ");
		}
		printf("\n");
		l+=2;
		m-=2;
	}
	return 0;
}