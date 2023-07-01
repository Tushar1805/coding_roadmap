// 38. Octal to Binary conversion

#include<iostream>
#include<math.h>
using namespace std;

// This approach has the worst time complexity but provides the accurate form of octal to binary conversion
void convertBinary(int octal) {
	int binary[100];
	int index = 0;

	while (octal != 0) {
		int digit = octal % 10;
		for (int j = 0; j < 3; ++j) {
			binary[index] = digit % 2;
			digit /= 2;
			index++;
		}
		octal /= 10;
	}
	for (int i = index - 1; i >= 0; --i)
	{
		cout << binary[i];
	}
}

// Method 2:
// Accept octal number
// Convert it into decimal Equivalent
// Convert this decimal value into Binary

// void convertBinary(int octal) {
// 	int i = 0, decimal = 0;

// 	//converting octal to decimal
// 	while (octal != 0) {
// 		int digit = octal % 10;
// 		decimal += digit * pow (8, i);
// 		octal /= 10;
// 		i++;
// 	}
// 	printf ("Decimal Value: %d\n", decimal);
// 	long long binary = 0;
// 	int rem;
// 	i = 1;
// 	// converting decimal to binary here
// 	while (decimal != 0)
// 	{
// 		rem = decimal % 2;
// 		decimal /= 2;
// 		binary += rem * i;
// 		// moving to next position ex: units -> tens
// 		i *= 10;

// 	}
// 	cout << binary;
// }

int main(int argc, char const *argv[])
{
	int octal;
	cout << "Enter an octal number: ";
	cin >> octal;

	cout << "Binary Conversion of octal number " << octal << " is: ";
	convertBinary(octal);
	return 0;
}