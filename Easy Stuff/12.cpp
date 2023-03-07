// 12. find sum of first and last digit of a number 

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
    printf("\n\n The sum of first and last digits of %d = %d ", org, f+l);
	return 0;
}