// 18. find frequency of each digit in a given integer

#include<stdio.h>
#include <math.h>
#define MAX 10
int main(int argc, char const *argv[])
{
	long long int n;
	int digit;
	int freq[MAX];
	printf("Enter any number: ");
	scanf("%lld", &n);
	for (int i = 0; i < MAX; ++i)
	{
		freq[i] = 0;
	}

	while(n != 0){
       digit = n % 10;
       n/=10;
       freq[digit]++;
	}
	/* Print frequency of each digit */
    printf("Frequency of each digit in %lld is: \n", n);
	for (int i = 0; i < MAX; ++i)
	{
		printf("\nFrequency of %d = %d", i , freq[i]);
	}
    // digits = log10(n);
    // divide = pow(10, digits);
    // printf("%d\n", digits);
    // for (int i = 0; i < digits + 1; ++i)
    // {
    // 	divide = pow(10, digits - i);
    // 	digit = org / divide;
    // 	org = n % divide;
    // 	n = org;
    // 	while(n!=0){
    // 		next = n % 10;
    // 		if (digit == next)
    // 		{
    // 			c++;
    // 		}
    // 		n = n/10;
    // 	}
    // 	printf("\n%d occurred %d times", digit, c);
    // }
	return 0;
}