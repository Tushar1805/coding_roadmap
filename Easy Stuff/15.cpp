// 15. calculate product of digits of a number 

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n, product = 1, rem;
	printf("Enter any number: ");
	scanf("%d", &n);
	int org = n;
	while(n!=0){
		rem = n%10;
		product = product * rem;
		n/=10;
	}
	printf("\nProduct of digits of %d = %d", org, product);
	return 0;
}