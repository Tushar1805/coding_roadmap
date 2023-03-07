// 16. enter a number and print its reverse

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n, rev = 0, rem;
	printf("Enter any number: ");
	scanf ("%d", &n);
	int org = n;
	while(n != 0){
		rem = n%10;
		rev = rev *10 + rem;
		n/=10;
	}
	printf("Reverse of the %d = %d", org, rev);
	return 0;
}