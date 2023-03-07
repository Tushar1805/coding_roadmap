// 7. find sum of all even numbers between 1 to n

#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n, sum = 0; 
	printf("Enter how many numbers you want: ");
	scanf("%d", &n);
	for(int i = 1; i<= n; i++){
		if (i % 2 ==0)
		{
			sum+=i;
		}
	}
	printf("The sum of all even natural numbers between 1 to %d = %d\n",n, sum );
	return 0;
}