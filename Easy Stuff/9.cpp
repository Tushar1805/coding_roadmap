// 9. print multiplication table of any number.

#include <stdio.h>
int main(int argc, char const *argv[])
{
	int  n;
	printf("Enter the number of which you want to print the multiplication table of: ");
	scanf("%d", &n);
	for (int i = 1; i <= 10; ++i)
	{
		printf("%d * %d = %d\n", n, i, n*i);
	}
	return 0;
}