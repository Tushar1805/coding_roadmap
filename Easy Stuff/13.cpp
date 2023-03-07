// 13. swap first and last digits of a number 

#include<stdio.h>
#include<math.h>
int main(int argc, char const *argv[])
{
	// let n = 1234
	int n, c, f, l, swapped, divide;
	printf("Enter any number: ");
	scanf("%d", &n);
	int org = n;
	c = log10(n); // it will give the count of total digits - 1, here it will give 3 for 1234, c=3
	divide = pow(10, c); // it will give the power of 10 i.e. if pow(10, 3) then it will give 1000, divide = 1000
	f = n / divide; // f = 1
	n = n % divide; // n = 234
	l = n % 10; // l = 4
	n/=10; // n = 23
	swapped = l * divide + n * 10 + f;
	printf("The swapped first and last digits of %d = %d", org, swapped);
	return 0;
}