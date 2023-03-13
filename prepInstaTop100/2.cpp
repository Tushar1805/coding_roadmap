// https://prepinsta.com/cpp-program/to-check-whether-a-number-is-even-or-odd/

#include<iostream>
using namespace std;

int isEven(int n){
	return (!(n &&1));
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter any positive number: ";
	cin>>n;

	// Brute Force Method
	if (n%2 == 0)
		printf("\nNumber is Even");
	else
		printf("\nNumber is Odd");

	cout<<endl<<endl;
	//Using ternary Operator
	//Checking if the number is divisible by 2
    n % 2 == 0 ? cout << "Even":cout << "Odd";

    cout<<endl<<endl;
    // Bitwise operator
    if(isEven(n))
        cout << "Even";
    else
        cout << "Odd";
	return 0;
}