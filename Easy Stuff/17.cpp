// 17. check whether a number is palindrome or not

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
	if (rev == org)
	{
		printf("%d is a palindrome number", org);
	}else{
		printf("%d is not a palindrome number", org);
	}
	return 0;
}