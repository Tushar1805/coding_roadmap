// Factorial of a number

#include<iostream>
using namespace std;

long long int factorial(int n){
	if(n==0)
		return 1;
	return n * factorial(n-1);
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the number to find the factorial of: ";
	cin>>n;
	long long int fact = 1;

	// Iterative method
	// for(int i = 1; i<=n; i++){
	// 	fact *= i;
	// }

	// Recursive method
	fact = factorial(n);
	cout<<"\nFactorial of "<<n<<" is: "<<fact;
	return 0;
}