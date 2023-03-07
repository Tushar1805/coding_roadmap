//         *
//       * * *
//     * * * * * 
//   * * * * * * *
// * * * * * * * * *

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int rows, i, j, k, l;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);

	// Taking l = rows * 2, because when we take rows 5, we print "* "
	// That means we are printing 2 spaces at a time (including *) 
	// so, for full pyramid of 5 rows we need to print first star at 9, i.e "* ",
	// And if you see it includes one more space so, it goes to 10
	// if rows = 5, l = rows * 2, l = 10 
	
	l = rows * 2; 
	printf("\n");
	for (i = rows; i > 0 ; --i)
	{
		for (k = 0; k < l-2; ++k)
		{
			printf(" ");
		}
		for (j = k + 1; j < rows * 28; ++j)
		{
			printf("* ");
		}
		printf("\n");
		l-=2;
	}
	return 0;
}