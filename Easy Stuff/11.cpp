// 11. Find first and last digit of a number

#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n, f, l;
	printf("Enter any number: ");
	scanf("%d", &n);
	int org = n;
	l = n % 10;
    while(n != 0){
    	f = n % 10;
    	n/=10;
    }
    printf("\n\n The first and last digits of %d = %d %d respectively", org, f, l);
	return 0;
}