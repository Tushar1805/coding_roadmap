#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter a number: ";
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			printf(" ");
		}
		for (int j = 0; j < i * 2 + 1; ++j)
		{
			printf("*");
		}
		printf("\n");
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			printf(" ");
		}
		for (int j = 0; j < (n - i) * 2 - 1; ++j)
		{
			printf("*");
		}
		printf("\n");
	}

}