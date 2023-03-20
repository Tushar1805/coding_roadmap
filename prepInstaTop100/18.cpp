// Power of a number

#include <iostream>
#include <math.h>
using namespace std;

double power(double b, double e){
	if(e>0)
		return b * power(b, e - 1);
	else if(e<0)
		return b / power(b, e + 1);
	else
		return 1; 
}

int main(int argc, char const *argv[])
{
	double b, e;
	cout<<"Enter the base and exponent value: ";
	cin>>b>>e;
	double p = 1.0;
	double orgE = e;

	// simple iterative method
	// for (int i = 0; i < e; ++i)
	// {
	// 	p *= b;
	// }

	// Using math.h library function
	// p = pow(b, e);

	// Enhanced loops for calculating the power of negative values
	// while (e > 0) {
    //     p *= b;
	//     e--;
	// }
	    
	// while (e < 0) {
	// 		p /= b;
	// 	    e++;
	// }

	// Using Recursion
	p = power(b, e);
	cout<<"\n"<<b<<" to the power of "<<orgE<<" equals to: "<<p;
	return 0;
}