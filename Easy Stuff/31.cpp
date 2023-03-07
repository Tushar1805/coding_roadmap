// 31. print all armstrong numbers between 1 to n

#include<stdio.h>
#include <math.h>

int checkArmstrong(int n){
	int arm = 0, digits;
	int org = n;
	int temp = n;
    digits = log10(temp);
    while(temp!=0){
    	arm = arm + pow(temp%10, digits+1);
    	temp /= 10;
    }
    if (arm == org)
    {
    	return 1;
    }
    return 0;
}
int main(int argc, char const *argv[])
{
	int n;
	printf("Enter any positive integer: ");
	scanf("%d", &n);
	printf("\nAll the armstrong numbers between 1 to %d = ", n);
	for (int i = 1; i <= n; ++i)
	{
		int check = checkArmstrong(i);
		if (check == 1)
		{
			printf("%d ", i);
		}
	}
	return 0;
}