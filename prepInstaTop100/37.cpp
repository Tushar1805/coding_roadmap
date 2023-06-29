// 37. Binary to Octal conversion

#include<iostream>
#include<math.h>
using namespace std;

void convertOctal(int binary){
	int octal = 0, i = 0, count = 1;
	int octalArray[32] = {0};
	int pos = 0;

	while(binary != 0){
		int digit = binary % 10;
		octal += digit * pow(2, i);
		i++;
		binary /= 10;
		octalArray[pos] = octal; 

		// whenever we have read next 3 digits
        // setting values to default
        // increasing pos so next values can be placed at next array index

		if(count % 3 == 0){
			octal = 0;
			i = 0;
			pos++;
		}
		count++;
	}
	for (int j = pos ; j >= 0; j--)
		cout<<octalArray[j];
}

int main(int argc, char const *argv[])
{
	int binary;
	cout<<"Enter the binary number: ";
	cin>>binary;
	cout<<"\nOctal conversion of the Binary "<<binary<<" is: ";
	convertOctal(binary);
	return 0;
}