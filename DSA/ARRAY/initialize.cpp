#include<stdio.h>
int main(int argc, char const *argv[])
{
	int a[10];
	printf("Enter the 10 elements of array: ");
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &a[i]);
	}
	printf("\nElements of array are: ");
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}