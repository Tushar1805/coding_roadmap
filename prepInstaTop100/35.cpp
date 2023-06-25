// Decimal to Octal Conversion

#include<iostream>
using namespace std;

void convertOctal(int dec){
	int octal[32];
	int i = 0;

	while(dec != 0){
		octal[i] = dec % 8;
		dec /= 8;
		i++; 
	} 

	for (int j = i-1; j >= 0; j--)
		cout<<octal[j];
}

int main(int argc, char const *argv[])
{
	int dec;
	cout<<"Enter the Decimal number: ";
	cin>>dec;
	cout<<"\nOctal Conversion of "<<dec<<" is: ";
	convertOctal(dec);
	return 0;
}