// 21. find the power of a number using for loop

#include<stdio.h>
#include<math.h>
int power(int base, int exponent){
	if (exponent !=0)
	{
		return base*power(base, exponent-1);
	}else{
		return 1;
	}
}
int main(int argc, char const *argv[])
{
	int base, exponent, p = 1;
	printf("Enter value of base and exponent: ");
	scanf("%d %d", &base, &exponent);
	// Using for loop
	for (int i = 1; i <= exponent; ++i)
	{
		p = p * base;
	}
	// p = power(base, exponent); // Using recursion
	// p = pow(base, exponent); // using power function
	printf("\n%d to the power of %d = %d", base, exponent, p);
	return 0;
}