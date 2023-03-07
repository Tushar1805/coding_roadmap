// 30. Check whether a number is armstrong number of not
// Program for Narcissistic number

// An Armstrong number of three digits is an integer, 
// such that the sum of the cubes of its digits is equal to the number itself. 
// For example, 371 is an Armstrong number since 3**3 + 7**3 + 1**3 = 371.

#include<stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
	int n, digits, arm = 0;
	printf("Enter any positive integer: ");
	scanf("%d", &n);
	int org = n;
    digits = log10(n);

    while(n!=0){
    	arm = arm + pow(n%10, digits+1);
    	n /= 10;
    }

    if (arm == org)
    {
    	printf("\n%d is an armstrong number", org);
    }else{
    	printf("\n%d is not an armstrong number", org);
    }
	return 0;
}