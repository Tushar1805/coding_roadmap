// https://prepinsta.com/c-program/to-find-the-largest-number-among-three-numbers/

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int num1, num2, num3;
	printf("Enter the three numbers: ");
	scanf("%d %d %d", &num1, &num2, &num3);

	// Using if - else statements
	if ((num1 > num2) && (num1> num3))
		printf("\nNumber %d is greater", num1);
	else if ((num2> num1) && (num2> num3))
		printf("\nNumber %d is greater", num2);
	else
		printf("\nNumber %d is greater", num3);
	
	// Using ternary operators
	(num1>num3) 
		? (num1> num2) 
			? printf("\nNumber %d is greater", num1) 
			: printf("\nNumber %d is greater", num2) 
		: (num3>num2) 
		? printf("\nNumber %d is greater", num3)
		: printf("\nNumber %d is greater", num2);
	return 0;
}