// https://prepinsta.com/cpp-program/to-check-whether-a-number-is-armstrong-number-or-not/

#include<iostream>
#include<math.h>
using namespace std;

float armstrong(int n, int d){
	if(n>0)
    	return (pow(n%10, d) + armstrong(n/10, d));
}

int main(int argc, char const *argv[])
{
	int n, arm = 0, d, rem;
	cout<<"Enter any positive number to check: ";
	cin>>n;
	int org = n;
	d = log10(n);

	// This gets the number of digits in the given number
	d = d + 1;

	// Using loop
	while(n != 0){
		rem = n%10;
		arm = arm + pow(rem, d);
		n /= 10;
	}

	// Using Recursion
	// arm = (int) armstrong(n, d);

	if (arm == org)
		cout<<"\nArmstrong Number";
	else
		cout<<"\nNot an Armstrong Number";
	return 0;
}