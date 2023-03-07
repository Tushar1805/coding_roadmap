// 20. print all ASCII character with their values

#include<stdio.h>
int main(int argc, char const *argv[])
{
	printf("****** ASCII Table *******");
	for (int i = 0; i < 255; ++i)
	{
		printf("\n%d value = %c", i, i);
	}
	return 0;
}