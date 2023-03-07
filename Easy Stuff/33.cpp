// 33. print all perfect numbers between 1 to n

#include<stdio.h>
int checkPerfectNo(int n){
	int sum = 0;
	for (int i = 1; i <= n/2; ++i)
	{
		if(n % i == 0){
			sum += i;
		}
	}
	if(sum == n)  
		return 1; 
	return 0;
}
int main(int argc, char const *argv[])
{
	int n, perfNo;
	printf("Enter any positive integer: ");
	scanf("%d", &n);
	printf("All the perfect numbers between 1 to %d: ", n);
	for (int i = 1; i <= n; ++i)
	{
		perfNo = checkPerfectNo(i);
		if (perfNo == 1)
		{
			printf("%d ", i);
		}
	}
	return 0;
}