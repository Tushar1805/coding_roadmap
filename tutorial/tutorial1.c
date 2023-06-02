#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(){
	// int n;
	// It gets the input
//	scanf("%d", &n);
//	printf("Hello World \nyour number is:");
 	char ch = 'a';
 	int a = 10;  //
 	float b = 5.3;
 	double c = 5.5;
 	bool d = true;
 	string e = "tushar";

 	for (int i = 0; i<5; i++){
 		for(int j=5;j>i;j--){
 			printf("* ");
 		}
 		printf("\n");
 	}
 	
 	// printf("ASCII: %.2f", b);

 	printf("Size: %d", sizeof(e));
 	return 0;
}
