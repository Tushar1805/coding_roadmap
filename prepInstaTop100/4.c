// https://prepinsta.com/c-program/sum-of-numbers-in-a-given-range/

#include<stdio.h>
int getSum(int sum, int a, int b){
	if (a>b)
		return sum;
	return a + getSum(sum, a+1, b); 
}
int main(int argc, char const *argv[])
{
	int a,b, sum = 0;
	printf("Enter the range of the numbers: ");
	scanf("%d %d", &a, &b);

	// Iterative Method
	for(int i = a; i<=b; i++){
		sum = sum + i;
	}
	printf("\nSum: %d", sum);

	// Direct Formula Method
	sum = b * (b+1) / 2 - a*(a+1)/2 + a;
	printf("\nSum: %d", sum);

	// Recursive Method
	sum = getSum(sum = 0, a, b);
	printf("\nSum: %d", sum);
	return 0;
}