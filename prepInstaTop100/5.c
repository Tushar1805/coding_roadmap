// https://prepinsta.com/c-program/greatest-of-two-numbers/

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int a, b;
	printf("Enter the two numbers: ");
	scanf("%d %d", &a, &b);

	// Using else if statement
	if(a>b)
		printf("\n%d is greater number", a);
	else
		printf("\n%d is greater number",b);

	// Using ternary operator
	(a>b) ? printf("\n%d is greater number", a) : printf("\n%d is greater number",b);
	return 0;
}