// 3. print all alphabets from a to z.

#include<stdio.h>
int main(int argc, char const *argv[])
{
	printf("Alphabets from a to z\n");
	for (int i = 97; i <=122; ++i)
	{
		printf("%c ", i);
	}
	printf("\nAlphabets from A to Z\n");
	for (int i = 65; i <=90; ++i)
	{
		printf("%c ", i);
	}
	return 0;
}