// Decimal to Binary conversion

#include<iostream>
#include<math.h>
using namespace std;

void convertBinary(int dec) {
	// int binary[32];
	int result = 0;
	int i = 0;

	// Bruete Force
	// while (dec != 0) {
	// 	binary[i] = dec % 2;
	// 	dec /= 2;
	// 	i++;
	// }

	// Optimized
	while (dec != 0) {
		int digit = dec & 1;
		result += pow(10, i) * digit;
		dec = dec >> 1;
		i++;
	}
	cout << result;
	// for (int j = i-1; j >= 0; j--)
	// 	cout<<binary[j];
}

int main(int argc, char const *argv[])
{
	int dec;
	cout << "Enter the Decimal number: ";
	cin >> dec;
	cout << "\nBinary Conversion of " << dec << " is: ";
	convertBinary(dec);
	return 0;
}