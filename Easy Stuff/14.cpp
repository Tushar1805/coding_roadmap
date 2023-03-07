// 14. calculate sum of digits of a nubmber 

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n, sum = 0;
	printf("Enter any number: ");
	scanf("%d", &n);
	int org = n;
	while(n!=0){
		sum = sum + n%10;
		n/=10;
	}
	printf("\nSum of digits of %d = %d", org, sum);
	return 0;
}