// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 

#include<iostream>
#include <conio.h>
using namespace std;

class floydsTriangle{
	public:
	floydsTriangle(int row){
		int n = 1;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				printf("%d ", n);
				n++;
			}
			printf("\n");
		}
	}	
};

int main(int argc, char const *argv[])
{
	int rows;
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	floydsTriangle f1(rows);
	getch();
	return 0;
}