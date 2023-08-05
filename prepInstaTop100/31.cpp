// 31. Binary to Decimal to conversion

#include<iostream>
#include<math.h>
using namespace std;

long long int getDecimal(int num) {
	int i = 0;
	int result = 0;

	//converting binary to decimal
	while (num != 0) {
		int digit = num % 10;
		result += digit * pow(2, i);
		num /= 10;
		i++;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	long long int binary;
	cout << "Enter the binary number: ";
	cin >> binary;
	// long long int res = getDecimal(binary);
	cout << "\n\nDecimal Conversion of " << binary << " is: " << getDecimal(binary);
	return 0;
}