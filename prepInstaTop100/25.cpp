// Harshad Number || Niven number

// A Harshad number is a positive integer that is divisible by the sum of the digits of the integer. 
// It is also called the Niven number.

// For Example : 153
// Sum of digits = 1 + 5 + 3 = 9

// 153is divisible by 9 so 153 is a Harshad Number.

#include<iostream>
using namespace std;

int isHarshadNumber(int n, int org){
	int sum = 0;
	int rem;
	while(n!=0){
		rem = n % 10;
		sum += rem;
		n /= 10;
	}
	if(org%sum == 0)
		return sum;
	return 0;
}

int main(int argc, char const *argv[])
{
	int n, res;
	cout<<"Enter any positive number to check: ";
	cin>>n;
	res = isHarshadNumber(n, n);
	if(res != 0)
		cout<<endl<<n<<" is divisible by "<<res<<" so "<<n<<" is a Harshad Number";
	else
		cout<<endl<<n<<" is not a Harshad Number";
	return 0;
}