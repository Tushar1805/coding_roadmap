// Highest Common Factor(HCF)

#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b;
	cout<<"Enter the two numbers to find the HCF of: ";
	cin>>a>>b;
	int n = min(a, b);
	int num1 = a, num2 = b;
	int hcf = 1;

	// Bruete Force approach
	// if( a % n == 0 and b % n == 0){
	// 	hcf = n;
	// }else{
	// 	for (int i = n/2; i >= 1; i--)
	// 	{
	// 		if(a % i == 0 && b % i == 0){
	// 			hcf = i;
	// 			break;
	// 		}
	// 	}
	// }

	// Optimized approach
	while(a!=b){
		if(a<b){
			b -= a;
		}else{
			a -= b;
		}
	}
	cout<<"\nHCF of "<<num1<<" & "<<num2<<": "<<a;
	return 0;
}