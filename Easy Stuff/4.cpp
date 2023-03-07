// 4. print all even number between 1 to 100

#include<stdio.h>

int main(int argc, char const *argv[])
{
	int n, c;
	printf("Enter how many numbers you want: ");
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		if (i % 2 == 0)
		{
			c++;
			printf("%d\n",i);
		}
	}
	printf("There are %d even numbers between 1 to %d numbers", c, n);
	return 0;
}