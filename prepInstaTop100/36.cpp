// 36. Decimal to Hexadecimal Conversion

// Numbers between (0 - 9) are represented as is. 
// There is special system for (10 - 15): 
// A - 10
// B - 11
// C - 12
// D - 13
// E - 14
// F - 16

#include<iostream>
using namespace std;

void convertHexadecimal(int dec){
	char hex[100];
	int pos = 0, rem;

	while(dec != 0){
		rem = dec % 16;

		if(rem < 10){
			// Whenever rem < 10 : we will have [0 - 9] as values in place
			// Note ASCII of 0 is 48
			hex[pos] = rem + 48;
			pos++;
		}else{
			// else whenever remainder >= 10 we will have [A - F] 
			// rem value will be > 10, adding 55 will result : A - F 
			// Note: ASCII A -> 65, B -> 66 ........ F -> 70
			hex[pos] = rem + 55;
			pos++;
		}
		
		dec /= 16;
	}

	for (int i = pos -1; i >= 0; --i)
	{
		cout<<hex[i];
	}

}

int main(int argc, char const *argv[])
{
	int dec;
	cout<<"Enter the decimal number: ";
	cin>>dec;
	cout<<"\nConversion of "<<dec<<" in Hexadecimal is: ";
	convertHexadecimal(dec);

	return 0;
}