// 19. enter a number and print it in words.

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n;
	printf("Enter any number: ");
	scanf("%d", &n);
	printf("%d in character = %c", n, n);
	return 0;
}