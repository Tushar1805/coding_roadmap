// Hexadecimal to Decimal conversion

// Hexadecimal Range - (0, 15)

// With numbers (0 - 9) represented as is

// And 10 - A, 11 - B, 12 - C, 13 - D, 14 - E, 15 - F 

#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

int getDecimal(string hex){
	int len = hex.size();
	int dec = 0;
	int index = 0;
	
	for (int i = len-1; i>=0; i--)
	{

		if(hex[i]>= '0' && hex[i] <= '9'){
			int digit = int (hex[i]) - 48;
			dec += digit * pow(16, index);
			index++;
		}else if(toupper(hex[i]) >= 'A' && toupper(hex[i]) <= 'F'){
			int digit = int (toupper(hex[i])) - 55;
			dec += digit * pow(16, index);
			index++;
		}
	}
	return dec;
}

int main(int argc, char const *argv[])
{
	string hex;
	cout<<"Enter the Hexadecimal number: ";
	cin>>hex;
	cout<<"\nConversion of "<<hex<<" into Decimal is: "<<getDecimal(hex);
	return 0;
}