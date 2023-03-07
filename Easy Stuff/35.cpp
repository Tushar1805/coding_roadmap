// 35. print all strong numbers between 1 to n

#include<stdio.h>

int factorial(int n){
	int fact = 1;
	for (int i = 2; i <= n; ++i)
	{
		fact = fact * i;
	}
	return fact;
}

int checkStrongNo(int n){
	int org = n, sum = 0, rem;
	while(n!=0){
		rem = n % 10;
		sum += factorial(rem);
		n /= 10;
	}
	if (sum == org)
	{
		return 1;
	}else{
		return 0;
	}
}
int main(int argc, char const *argv[])
{
	int n, check;
	printf("Enter any positive integer: ");
	scanf("%d", &n);
	printf("All the strong numbers between to %d: ", n);
	for (int i = 1; i <= n; ++i)
	{
		check = checkStrongNo(i);
		(check == 1) ? printf("%d ", i) : printf("");
	}
	
	return 0;
}