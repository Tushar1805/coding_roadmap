// Octal to Decimal conversion

#include<iostream>
#include<math.h>
using namespace std;

int getOctal(long long int n){
	int i = 0;
	int result = 0;
	while(n != 0){
		int digit = n % 10;
		result += digit * pow(8, i);
		n /= 10;
		i++; 
	}
	return result;
}

int main(int argc, char const *argv[])
{
	long long int octal;
	cout<<"Enter the octal number: ";
	cin>>octal;

	cout<<"\n\nDecimal Conversion of "<<octal<<" is: "<<getOctal(octal);
	return 0;
}