// Decimal to Binary conversion

#include<iostream>
using namespace std;

void convertBinary(int dec){
	int binary[32];
	int i = 0;

	while(dec != 0){
		binary[i] = dec % 2;
		dec /= 2;
		i++; 
	} 

	for (int j = i-1; j >= 0; j--)
		cout<<binary[j];
}

int main(int argc, char const *argv[])
{
	int dec;
	cout<<"Enter the Decimal number: ";
	cin>>dec;
	cout<<"\nBinary Conversion of "<<dec<<" is: ";
	convertBinary(dec);
	return 0;
}