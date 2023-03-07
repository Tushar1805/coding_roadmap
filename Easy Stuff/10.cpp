// 10. count number of digits in a number.

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n, c=0;
	printf("Enter any number: ");
	scanf("%d", &n);
	int org = n;
	while( n != 0){
		n/=10;
		c++;
	}
	printf("\n\nThe number of digits in %d number = %d", org, c);
	return 0;
}