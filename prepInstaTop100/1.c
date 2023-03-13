// https://prepinsta.com/c-program/a-number-is-positive-or-negative/
#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n;
	printf("Enter any number: ");
	scanf("%d", &n);

	//Bruete force Method
	if (n>0)
		printf("\nNumber is Positive");
	else if(n<0)
		printf("\nNumber is Negative");
	else
		printf("\nNumber is Zero");
	return 0;
}