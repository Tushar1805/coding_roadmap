// 2. print all natural numbers in reverse (from n to 1)

#include<stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter how many you want to print: ");
	scanf("%d", &n);
	for (int i = n; i>=1; i--)
	{
		printf("%d\n", i);
	}
	return 0;
}